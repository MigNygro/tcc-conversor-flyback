# tcc-conversor-flyback
"Projeto de TCC: Desenvolvimento de Conversor Flyback e Automação de Dados.


PROJETO DE TCC: CONVERSOR FLYBACK CC-CC - CONTROLE DIGITAL E ESTABILIDADE
Autor: Miguel Nigro e Luis Fernando | Engenharia Elétrica - UFMS | 2026
===============================================================================

1. DESCRIÇÃO DO PROJETO
-----------------------
Este repositório contém o desenvolvimento técnico completo de um conversor 
Flyback, integrando hardware, controle PID via Arduino e análise de 
estabilidade via Python. O foco principal é a proteção do MOSFET e a 
sintonia fina da malha de feedback.

2. ESTRUTURA DE DIRETÓRIOS (APÊNDICES)
--------------------------------------
O projeto está organizado em 5 pastas principais:

[Pasta]             [Conteúdo]
/01_Simulacao       Script Python (.ipynb) para teste de curvas PID.
/02_Firmware        Código-fonte Arduino (.ino) em C++.
/03_Calculos        Planilha Excel com dimensionamento de componentes.
/04_Esquemas        Diagramas de circuito e layout da placa.

3. DETALHES DO FIRMWARE (APÊNDICE 2)
------------------------------------
Localização: /02_Firmware/flyback_final.ino

O firmware gerencia o controle em malha fechada. Pontos críticos:
- ANTI-WINDUP: Impede o acúmulo excessivo do erro integral.
- SOFT-START: Limita a rampa de subida do PWM em 2% por ciclo.
- SEGURANÇA: Duty Cycle limitado em 45% (hardcoded) para proteção.
- AMOSTRAGEM: Operação em 50Hz (20ms) para estabilidade térmica e de sinal.

4. SIMULAÇÃO E ESTABILIDADE (APÊNDICE 1)
----------------------------------------
Localização: /01_Simulacao/Python_TCC_2.0.ipynb

O script permite prever o comportamento do hardware:
- ANALISE: Gera gráficos de resposta ao degrau (V vs Tempo).
- SINTONIA: Teste de ganhos Kp, Ki e Kd sem risco de queima física.
- MÉTRICAS: Identifica automaticamente o tempo de estabilização.

5. COMO REPLICAR ESTE PROJETO
-----------------------------
Passo 1: Utilize a planilha em /03_Calculos para dimensionar o transformador.
Passo 2: Rode a simulação em /01_Simulacao para validar seus ganhos PID.
Passo 3: Carregue o código em /02_Firmware para o Arduino.

6. REQUISITOS TÉCNICOS
----------------------
- IDE Arduino 2.x ou superior.
- Python 3.10+ (Bibliotecas: Pandas, Matplotlib).
- Microsoft Excel ou similar para as memórias de cálculo.

7. LICENÇA
----------
Este projeto está sob a Licença MIT - Sinta-se livre para usar e aplicar,
desde que cite a fonte original.


Gerado para fins de documentação técnica de Engenharia Elétrica.
