![68747470733a2f2f736f667465782e62722f77702d636f6e74656e742f75706c6f6164732f323032342f30392f456d6261726361546563685f6c6f676f5f417a756c2d31303330783432382e706e67](https://github.com/user-attachments/assets/efd58ef1-331a-4978-bb80-52925d9d4b1b)


**Controle de Servomotor com PWM no Raspberry Pi Pico** 🎛️🔧

Este código controla um servomotor usando um sinal PWM gerado pelo Raspberry Pi Pico. 🏎️⚡

📌 __Principais Funcionalidades__:

✅ Configura o pino GPIO 22 para gerar PWM a 50Hz (frequência padrão para servomotores).

✅ Converte o tempo ativo do sinal (500µs a 2500µs) para a posição do servo (0° a 180°).

✅ Move o servo suavemente entre essas posições usando incrementos pequenos.

✅ Repete o movimento em um loop infinito com pequenas pausas.



🔄 __Fluxo do Programa:__

1️⃣ Configura o PWM no pino 22.

2️⃣ Calcula os valores corretos do PWM para o servo.

3️⃣ Move o servo de 0° a 180° e depois de 180° a 0° suavemente.

4️⃣ Mantém esse movimento em repetição contínua.
