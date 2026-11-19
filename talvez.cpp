#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// Criação dos quatro objetos
Servo motorDireita, motorEsquerda, motorBase, motorGarra;

// Limites dos pulsos
int minUs = 1000;
int maxUs = 2000;

// Configuração da rede Wi-Fi
const char* nomeRede = "bagaceira";
const char* senha = "MAT2@clo";

// Servidor HTTP
WebServer servidor(80);

// Pinos dos motores
int motorDireitaPino = 18;
int motorEsquerdaPino = 19;
int motorBasePino = 23;
int motorGarraPino = 22;

// Posições iniciais
int posicaoMotorDireita = 0;
int posicaoMotorEsquerda = 0;
int posicaoMotorBase = 0;
int posicaoMotorGarra = 80;

void setup() {

    Serial.begin(115200);

    WiFi.softAP(nomeRede, senha);

    Serial.println("Rede Wi-Fi criada com sucesso!");
    Serial.println("IP DA ESP: ");
    Serial.println(WiFi.softAPIP());

    servidor.on("/motorDireitaMais", motorDireitaMais);
    servidor.on("/motorDireitaMenos", motorDireitaMenos);

    servidor.on("/motorEsquerdaMais", motorEsquerdaMais);
    servidor.on("/motorEsquerdaMenos", motorEsquerdaMenos);

    servidor.on("/motorGarraMais", motorGarraMais);
    servidor.on("/motorGarraMenos", motorGarraMenos);

    servidor.on("/motorBaseMais", motorBaseMais);
    servidor.on("/motorBaseMenos", motorBaseMenos);

    motorDireita.setPeriodHertz(50);
    motorEsquerda.setPeriodHertz(50);
    motorBase.setPeriodHertz(50);
    motorGarra.setPeriodHertz(50);

    motorDireita.attach(motorDireitaPino, minUs, maxUs);
    motorEsquerda.attach(motorEsquerdaPino, minUs, maxUs);
    motorBase.attach(motorBasePino, minUs, maxUs);
    motorGarra.attach(motorGarraPino, minUs, maxUs);

    motorDireita.write(posicaoMotorDireita);
    motorEsquerda.write(posicaoMotorEsquerda);
    motorBase.write(posicaoMotorBase);
    motorGarra.write(posicaoMotorGarra);

    servidor.begin();
}

void loop() {
    servidor.handleClient();
}

void motorDireitaMais() {

    if(posicaoMotorDireita < 170) {
        posicaoMotorDireita++;
    } else {
        posicaoMotorDireita = 170;
    }

    motorDireita.write(posicaoMotorDireita);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorDireitaMenos() {

    if(posicaoMotorDireita > 0) {
        posicaoMotorDireita--;
    } else {
        posicaoMotorDireita = 0;
    }

    motorDireita.write(posicaoMotorDireita);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorEsquerdaMais() {

    if(posicaoMotorEsquerda < 170) {
        posicaoMotorEsquerda++;
    } else {
        posicaoMotorEsquerda = 170;
    }

    motorEsquerda.write(posicaoMotorEsquerda);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorEsquerdaMenos() {

    if(posicaoMotorEsquerda > 0) {
        posicaoMotorEsquerda--;
    } else {
        posicaoMotorEsquerda = 0;
    }

    motorEsquerda.write(posicaoMotorEsquerda);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorGarraMais() {

    if(posicaoMotorGarra < 105) {
        posicaoMotorGarra++;
    } else {
        posicaoMotorGarra = 105;
    }

    motorGarra.write(posicaoMotorGarra);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorGarraMenos() {

    if(posicaoMotorGarra > 80) {
        posicaoMotorGarra--;
    } else {
        posicaoMotorGarra = 80;
    }

    motorGarra.write(posicaoMotorGarra);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorBaseMais() {

    if(posicaoMotorBase < 170) {
        posicaoMotorBase++;
    } else {
        posicaoMotorBase = 170;
    }

    motorBase.write(posicaoMotorBase);

    servidor.send(200, "text/plain", "Comando executado!");
}

void motorBaseMenos() {

    if(posicaoMotorBase > 0) {
        posicaoMotorBase--;
    } else {
        posicaoMotorBase = 0;
    }

    motorBase.write(posicaoMotorBase);

    servidor.send(200, "text/plain", "Comando executado!");
}
