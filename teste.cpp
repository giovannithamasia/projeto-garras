// #include <BTAddress.h>
// #include <BTAdvertisedDevice.h>
// #include <BTScan.h>
//#include <BluetoothSerial.h>
//BluetoothSerial SerialBT;

#include <WiFi.h>
#include  <WebServer.h>
#include <ESP32Servo.h>

//Criação de 04 objetos, um para cada servo do braço robótico 
Servo motorDireita, motorEsquerda, motorBase, motorGarra;

/* definição das posições 0º e 180º, respectivamente,
com base no tempo de envio do pulso elétrico em microssegundos (µs)*/
int minUs = 1000; //pulso alto equivalente a 0º
int maxUs = 2000; //puslo baixo equivalente a 180º

const char* nomeRede = "bagaceira";
const char* senha = "MAT2@clo";

WebServer servidor(80);

// Melhores pinos 2,4,12-19,21-23,25-27,32-33
int motorDireitaPino = 18;
int motorEsquerdaPino = 19;
int motorBasePino = 23;
int motorGarraPino = 22;

int posicaoMotorDireita, posicaoMotorEsquerda, posicaoMotorBase, posicaoMotorGarra; //ângulo em graus


void setup() {
  Serial.begin(115200);

  WiFi.softAP(nomeRede,senha);
   
  Serial.println("Rede Wi-Fi criada com sucesso!");
  Serial.println("IP DA ESP: ");
  Serial.println(WiFi.softAPIP());

  servidor.on("/motorDireitaMais",motorDireitaMais);
  servidor.on("/motorDireitaMenos",motorDireitaMenos);
  servidor.on("/motorEsquerdaMais",motorEsquerdaMais);
  servidor.on("/motorEsquerdaMenos",motorEsquerdaMenos);
  servidor.on("/motorGarraMais",motorGarraMais);
  servidor.on("/motorGarraMenos",motorGarraMenos);
  servidor.on("/motorBaseMais",motorBaseMais);
  servidor.on("/motorBaseMenos",motorBaseMenos);


  motorDireita.setPeriodHertz(50);      // Standard 50hz servo
  motorEsquerda.setPeriodHertz(50);      // Standard 50hz servo
  motorBase.setPeriodHertz(50);      // Standard 50hz servo
  motorGarra.setPeriodHertz(50);      // Standard 50hz servo
  motorDireita.attach(motorDireitaPino, minUs, maxUs);
  motorEsquerda.attach(motorEsquerdaPino, minUs, maxUs);
  motorBase.attach(motorBasePino, minUs, maxUs);
  motorGarra.attach(motorGarraPino, minUs, maxUs);

  servidor.begin();
}

void loop() {
  servidor.handleClient();
}

void motorDireitaMais(){
    if(posicaoMotorDireita<170){
      posicaoMotorDireita++;
    }else{
      posicaoMotorDireita=170;
    }
    motorDireita.write(posicaoMotorDireita);

}

void motorDireitaMenos(){
    if(posicaoMotorDireita>0){
      posicaoMotorDireita--;
    }else{
      posicaoMotorDireita=0;
    }
    motorDireita.write(posicaoMotorDireita);
}

void motorEsquerdaMais(){
    if(posicaoMotorEsquerda<170){
      posicaoMotorEsquerda++;
    }else{
      posicaoMotorEsquerda=170;
    }
    motorEsquerda.write(posicaoMotorEsquerda);
}

void motorEsquerdaMenos(){
    if(posicaoMotorEsquerda>0){
      posicaoMotorEsquerda--;
    }else{
      posicaoMotorEsquerda=0;
    }
    motorEsquerda.write(posicaoMotorEsquerda);
}

void motorGarraMais(){
    if(posicaoMotorGarra<105){
      posicaoMotorGarra++;
    }else{
      posicaoMotorGarra=105;
    }
    motorGarra.write(posicaoMotorGarra);
}

void motorGarraMenos(){
    if(posicaoMotorGarra>80){
      posicaoMotorGarra--;
    }else{
      posicaoMotorGarra=80;
    }
    motorGarra.write(posicaoMotorGarra);
}

void motorBaseMais(){
   if(posicaoMotorBase<170){
      posicaoMotorBase++;
    }else{
      posicaoMotorBase=170;
    }
    motorBase.write(posicaoMotorBase);
}

void motorBaseMenos(){
   if(posicaoMotorBase>0){
      posicaoMotorBase--;
    }else{
      posicaoMotorBase=0;
    }
    motorBase.write(posicaoMotorBase);
}