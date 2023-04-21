###Controle de robô seguidor de linha

Este é um código de exemplo para controle de um robô seguidor de linha utilizando três sensores de reflexão infravermelhos.
Funcionalidades

O código realiza as seguintes funções:

    Configuração dos pinos dos sensores de reflexão infravermelhos (A1, A0 e A2), pontes H (ponte12 e ponte34), entradas (entrada1, entrada2, entrada3 e entrada4), botão (botao) e LED (led)
    Leitura do estado do botão e acionamento do LED de acordo com o botão pressionado
    Identificação da posição do robô em relação à linha através dos sensores de reflexão
    Ajuste do movimento do robô de acordo com a posição em relação à linha
    Parada do robô em caso de erro ou falta de sinal dos sensores

Como utilizar

Antes de utilizar este código, é necessário configurar os pinos correspondentes aos componentes do seu robô seguidor de linha. Além disso, é preciso definir o comportamento do robô de acordo com a lógica do seu projeto.

Para acionar o botão e verificar o LED, basta pressionar o botão ligado ao pino 4. O LED ligado ao pino 5 irá acender ou apagar de acordo com o estado do botão.
Observações

Este código é apenas um exemplo simples.
