# tcc-conversor-flyback
Projeto de TCC: Desenvolvimento de Conversor Flyback e Automação de Dados.

-------------------------------------------------------------------------------
    CONVERSOR FLYBACK CC-CC: PLATAFORMA DE ENSINO E CONTROLE DIGITAL
-------------------------------------------------------------------------------

[ STATUS: FINALIZADO ]  [ INSTITUIÇÃO: UFMS ]  [ LICENÇA: MIT ]

Este repositório contém o desenvolvimento completo de um conversor estático 
tipo Flyback, projetado como ferramenta didática para o estudo de Eletrônica 
de Potência e Sistemas de Controle. O projeto integra hardware, firmware 
em C++ e análise de estabilidade em Python.

-------------------------------------------------------------------------------
📂 ESTRUTURA DE APÊNDICES (SEQUÊNCIA DO TCC)
-------------------------------------------------------------------------------

O projeto está organizado para guiar o usuário desde o código-fonte até a 
aplicação prática em bancada:

📑 [A] FIRMWARE DO MICROCONTROLADOR
    Pasta: /01_Firmware
    * Código-fonte completo para Arduino (ATmega328P).
    * Implementação de controle PID com frequência de 62,5 kHz.
    * Funções de segurança: Anti-Windup e Soft-Start (Slew Rate).

📊 [B] MEMÓRIA DE CÁLCULO
    Pasta: /02_Calculos
    * Dimensionamento de componentes magnéticos e semicondutores.
    * Análise do ponto de operação para a nova carga de 100 Ohms.
    * Cálculos de indutância e ripple de tensão de saída.

🐍 [C] SCRIPT DE SIMULAÇÃO
    Pasta: /03_Simulacao
    * Jupyter Notebook em linguagem Python.
    * Validação da resposta ao degrau (V vs Tempo).
    * Ferramenta para ajuste fino dos ganhos Kp, Ki e Kd.

🛠️ [D] ESQUEMAS E LAYOUT
    Pasta: /04_Hardware
    * Projeto completo desenvolvido no software EasyEDA.
    * Diagrama esquemático e visualização do Layout da PCB.
    * Lista de Materiais (BOM) para montagem.

🎓 [E] ROTEIRO DE LABORATÓRIO
    Pasta: /05_Roteiro
    * Guia prático para aulas experimentais e comissionamento.
    * Procedimentos de segurança e checklists de energização.
    * Roteiro de observação em Malha Aberta e Malha Fechada.

-------------------------------------------------------------------------------
🛠️ TECNOLOGIAS UTILIZADAS
-------------------------------------------------------------------------------

* C++/Arduino: Lógica de controle em tempo real e registradores.
* Python (Pandas/Matplotlib): Simulação e análise de dados.
* EasyEDA: Design de hardware e layout de placa de circuito.
* Normas ABNT: Estruturação da documentação técnica e apêndices.

-------------------------------------------------------------------------------
🚀 COMO UTILIZAR ESTE PROJETO
-------------------------------------------------------------------------------

1. SIMULAÇÃO: Execute o script em /03_Simulacao para validar o controle.
2. HARDWARE: Utilize os arquivos de /04_Hardware para montagem da PCB.
3. FIRMWARE: Carregue o código de /01_Firmware via IDE do Arduino.
4. AULA PRÁTICA: Siga o roteiro em /05_Roteiro para medições (Osciloscópio).

-------------------------------------------------------------------------------
📄 LICENÇA
-------------------------------------------------------------------------------

Este projeto está sob a Licença MIT. Sinta-se à vontade para utilizar, 
modificar e distribuir para fins acadêmicos e profissionais, desde que a 
fonte original seja devidamente citada.

-------------------------------------------------------------------------------
    Gerado para Documentação Técnica de Engenharia Elétrica - 2026
-------------------------------------------------------------------------------
