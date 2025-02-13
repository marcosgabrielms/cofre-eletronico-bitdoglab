Cofre Simulado com RP2040
Este projeto implementa um cofre eletrônico simulado utilizando o microcontrolador RP2040. O cofre vem pré-configurado com uma senha de 4 dígitos, inserida pelo usuário através de dois botões. Após 3 tentativas consecutivas incorretas, o sistema entra em modo de bloqueio. Se a senha for inserida corretamente, o cofre é desbloqueado, indicado por um LED verde piscante.

Funcionalidades
Simulação de cofre eletrônico: Verificação de senha via botões.

Controles de entrada:

Botão A (GPIO5): Insere o dígito "1".

Botão B (GPIO6): Insere o dígito "2".

Joystick (GPIO22): Confirma a senha inserida.

Segurança da senha:

Senha pré-definida de 4 dígitos.

3 tentativas incorretas ativam um bloqueio temporário.

Modo de bloqueio impede novas tentativas por um período definido.

Feedback:

Visual: LED verde pisca ao desbloquear.

Auditivo: Buzzer (GPIO21) emite sons distintos para sucesso (bipe) e erro (zumbido).

Tratamento eficiente de entradas:

Usa interrupções para botões e polling para o joystick.

Modos especiais:

Modo Bootsel: Pressione Botão A + B simultaneamente para entrar no modo de atualização de firmware.

Configuração do Hardware
Componentes
Microcontrolador: Raspberry Pi Pico (RP2040).

Entradas:

2x Botões táteis (para dígitos "1" e "2").

Joystick com botão integrado (para confirmação).

Saídas:

LED (verde para indicação de desbloqueio).

Buzzer (para feedback sonoro).

Conexões:

Botões conectados a GPIO5 (Botão A) e GPIO6 (Botão B) com resistores de pull-down.

Botão do joystick conectado a GPIO22.

Buzzer conectado a GPIO21.

LED conectado a um GPIO com suporte a PWM (ex: GPIO16).

Tecnologias Utilizadas
Microcontrolador: Raspberry Pi Pico (RP2040).

Linguagem de Programação: C (usando o Pico SDK).

Ferramentas de Desenvolvimento:

Visual Studio Code (com extensões do Pico SDK).

CMake (para configuração de compilação).

Compilador ARM GCC.

Instalação
Pré-requisitos
Visual Studio Code com as extensões:

C/C++

CMake Tools

Pico SDK e toolchain (guia de instalação (em inglês).

CMake (versão 3.12 ou superior).