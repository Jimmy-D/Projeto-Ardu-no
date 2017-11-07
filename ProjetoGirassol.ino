#include <Servo.h>
 
#define SERVO_GRANDE 6
#define SERVO_PEQUENO 5
#define SENSOR_ESQUERDA 0
#define SENSOR_CIMA 1
#define SENSOR_DIREITA 2
#define SENSOR_BAIXO 3
 
Servo sG;
Servo sP;

int esquerda;
int cima;
int direita;
int baixo;

int posicaoSG = 90;
int posicaoSP = 90;

int posicionar;

void setup ()
{
  Serial.begin(9600);
  sG.attach(SERVO_GRANDE);
  sP.attach(SERVO_PEQUENO);
  Serial.begin(9600);
  sG.write(posicaoSG);
  sP.write(posicaoSP);
}
 
void loop()
{
  direita = analogRead(SENSOR_DIREITA);
  baixo = analogRead(SENSOR_BAIXO);
  esquerda = analogRead(SENSOR_ESQUERDA);
  cima = analogRead(SENSOR_CIMA);

//  Serial.print("\ndireita: ");
//  Serial.println(direita);
//  Serial.print("baixo: ");
//  Serial.println(baixo);
//  Serial.print("esquerda: ");
//  Serial.println(esquerda);
//  Serial.print("cima: ");
//  Serial.println(cima);
//  delay(5000);

  if(esquerda > direita + 50){
    if(posicaoSG <= 170){
        posicaoSG = posicaoSG + 2;
        sG.write(posicaoSG);
    }
  }
  if(direita > esquerda + 50){
    if(posicaoSG >= 10){
        posicaoSG = posicaoSG - 2;
        sG.write(posicaoSG);
    }
  }
  if(cima > baixo + 50){
    if(posicaoSP <= 170){
        posicaoSP = posicaoSP + 2;
        sP.write(posicaoSP);
    }
  }
  if(baixo > cima + 50){
    if(posicaoSP >= 10){
        posicaoSP = posicaoSP - 2;
        sP.write(posicaoSP);
    }
  }
  delay(250);
}


