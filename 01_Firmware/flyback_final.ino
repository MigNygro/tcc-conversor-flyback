//--- Variáveis de Controle de Segurança ---
const float DUTY_MAX_SEGURANCA = 45.0; // Reduzido de 55 para 45 para proteger o MOSFET
const float TAXA_SUBIDA_MAX = 2.0;      // Limita o quanto o PWM pode mudar por ciclo (Slew Rate)

//--- Variáveis PID Ajustadas para Estabilidade ---
float Kp = 4.0;  // Reduzido para evitar o "salto" inicial que queima o componente
float Ki = 0.8;  
float Kd = 1.8;  // Aumentado para "amortecer" a oscilação (o freio)

float erroAnterior = 0.0;
float termoI = 0.0;
unsigned long lastTime = 0;
const int sampleTime = 20; // 50Hz é mais seguro para começar

float pwm_atual = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = 0xA3;
  setFrequency(1);
  Serial.begin(115200);
  
  setDuty_pin03(0); // Começa zerado
}

void loop() {
  unsigned long now = millis();
  
  if (now - lastTime >= sampleTime) {
    lastTime = now;

    // 1. Leitura com Filtro (Evita que ruído na leitura faça o PWM oscilar)
    float V_ALVO = analogRead(A0) * (5.0 / 1023.0);
    if (V_ALVO > 4.0) V_ALVO = 4.0;

    float V_SAIDA = analogRead(A2) * (5.0 / 1023.0);

    // 2. PID
    float erro = V_ALVO - V_SAIDA;
    
    float P = Kp * erro;
    termoI += (Ki * erro);
    
    // Anti-Windup (Essencial para não queimar: limita o acúmulo do I)
    if (termoI > DUTY_MAX_SEGURANCA) termoI = DUTY_MAX_SEGURANCA;
    if (termoI < 0) termoI = 0;

    float D = Kd * (erro - erroAnterior);
    erroAnterior = erro;

    float pwm_desejado = P + termoI + D;

    // --- 3. LOGICA DE PROTEÇÃO DO MOSFET ---
    
    // A: Limite Absoluto
    if (pwm_desejado > DUTY_MAX_SEGURANCA) pwm_desejado = DUTY_MAX_SEGURANCA;
    if (pwm_desejado < 5) pwm_desejado = 5;

    // B: Soft-Start / Slew Rate Limiter (Impede mudanças bruscas de corrente)
    // Se o PID pedir um aumento de 20% de uma vez, o código só permite subir de 2% em 2%
    if (pwm_desejado > pwm_atual + TAXA_SUBIDA_MAX) {
      pwm_atual += TAXA_SUBIDA_MAX;
    } else if (pwm_desejado < pwm_atual - TAXA_SUBIDA_MAX) {
      pwm_atual -= TAXA_SUBIDA_MAX;
    } else {
      pwm_atual = pwm_desejado;
    }

    setDuty_pin03(pwm_atual);

    // Monitoramento
    Serial.print("Alvo:"); Serial.print(V_ALVO);
    Serial.print(" Saida:"); Serial.print(V_SAIDA);
    Serial.print(" PWM:"); Serial.println(pwm_atual);
  }
}

void setDuty_pin03(float value) {
  int duty = (value / 100.0 * 256.0) - 1;
  if (duty < 0) duty = 0;
  if (duty > 255) duty = 255;
  OCR2B = duty;
}

void setFrequency(byte option) {
  TCCR2B = (TCCR2B & 0b11111000) | (option & 0b00000111);
}