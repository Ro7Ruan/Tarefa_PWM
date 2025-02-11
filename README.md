Projeto Servo Controlador com LED RGB
Este projeto foi desenvolvido para controlar um servo motor e um LED RGB utilizando o Raspberry Pi Pico (ou uma placa compatível), com a ajuda do SDK do Raspberry Pi. O servo motor é movido entre os ângulos de 0 a 180 graus, enquanto o brilho do LED RGB é ajustado de acordo com o ângulo do servo. O controle é feito via PWM (Pulse Width Modulation).

O que você vai encontrar neste projeto?
Controle de Servo Motor: Utiliza PWM para movimentar o servo entre os ângulos de 0 a 180 graus.
Controle de LED RGB: O brilho do LED RGB varia conforme a posição do servo motor.
Movimentação suave: O servo move de forma suave entre os ângulos, com um pequeno atraso para suavizar a transição.
Placa Raspberry Pi Pico: O controle é realizado através da placa Raspberry Pi Pico, utilizando os pinos GPIO e o módulo PWM.

Como funciona?
Servo Motor: O servo motor é controlado utilizando sinais PWM (modulação por largura de pulso). A largura do pulso determina a posição do servo:

500µs para 0 graus
1470µs para 90 graus
2400µs para 180 graus
LED RGB: O brilho do LED é ajustado em função da posição do servo. Quando o servo está em 180 graus (2400µs), o brilho do LED é máximo. À medida que o servo se move para 0 graus (500µs), o brilho do LED diminui proporcionalmente.
Como configurar e rodar o projeto?
Passo 1: Instalar o SDK do Raspberry Pi Pico
Primeiro, é necessário ter o SDK do Raspberry Pi Pico instalado. Você pode seguir a documentação oficial para isso. Certifique-se de que a variável de ambiente PICO_SDK_PATH esteja configurada corretamente.

Passo 2: Configuração do projeto
Clone o repositório do projeto:

bash
Copiar
Editar
git clone https://github.com/Ro7Ruan/Tarefa_PWM
cd <diretório-do-projeto>
Abra o terminal na pasta do projeto e execute o comando abaixo para criar o diretório de compilação e compilar o código:

bash
Copiar
Editar
mkdir build
cd build
cmake ..
make
Passo 3: Conectar o hardware
Conecte os componentes à sua placa Raspberry Pi Pico da seguinte forma:

Servo Motor:
Conecte o sinal PWM do servo ao pino GPIO 22.
Conecte a alimentação (5V) e o terra (GND) do servo.
LED RGB:
Conecte o pino de controle do LED RGB ao pino GPIO 12.
Conecte as alimentações (VCC e GND) conforme necessário.
Passo 4: Enviar o código para a placa
Depois de compilar o código, você pode gravá-lo na sua placa utilizando o Raspberry Pi Imager ou qualquer outro método de upload que preferir.

Passo 5: Executar o código
Quando o código for carregado, o servo motor começará a se mover entre os ângulos de 0 a 180 graus, e o brilho do LED RGB será ajustado conforme a posição do servo. As transições serão suaves devido ao atraso de 10ms entre os ajustes do ciclo de trabalho do PWM.

O que acontece no código?
Controle do Servo: O código configura o PWM no pino GPIO 22, com uma frequência de 50Hz (20ms), ajustando o ciclo de trabalho para movimentar o servo entre os ângulos.
Controle do LED RGB: O código também ajusta o brilho do LED RGB (conectado ao GPIO 12), alterando-o conforme o ciclo de trabalho do servo.
Movimento suave: O servo é movido de forma suave, incrementando o ciclo de trabalho de 5µs a cada 10ms.
Resultados esperados
O servo se moverá entre 0 e 180 graus.
O LED RGB terá o brilho ajustado de acordo com o ângulo do servo. Quando o servo estiver a 180 graus, o brilho será máximo, e quando estiver a 0 graus, o LED apagará.
Observações
Certifique-se de que o servo motor seja compatível com os sinais PWM gerados pela placa.
O código foi projetado para a placa Raspberry Pi Pico, mas pode ser adaptado para outras placas compatíveis com o SDK do Raspberry Pi.
