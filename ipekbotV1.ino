    ////////////////////////////////////////////////////////
   //                İPEK YAĞMUR                         //             
  //                İpek LineBot v1.0                   //
 //                İpek Çizgi Takip Robotu             //
////////////////////////////////////////////////////////

//Kütüphane Eklentisi
#include <AFMotor.h>

//Değişken ve Pinlerin Tanımlanması
#define lefts A4 
#define rights A5 

//Motorların Tanımlanması
AF_DCMotor motor1(4, MOTOR12_1KHZ); 
AF_DCMotor motor2(3, MOTOR12_1KHZ);
/*
AF_DCMotor motor1(3, MOTOR12_1KHZ); 
AF_DCMotor motor2(4, MOTOR12_1KHZ);
 */

void setup() {
  //Motor hızlarının ayarlanması
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  //Pinlerin iş tanımı
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //Seri iletişim başlangıcı
  Serial.begin(9600);
  
}

void loop(){
  //Seri Bağlantı izleme ekranına sensörlerin değerlerinin yazılması
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  //Çizgi her iki sensör tarafından algılanırsa
  if(analogRead(lefts)>1000 && analogRead(rights)>1000){
    //durdur
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  //Çizgi sol sensör tarafından algılanırsa
  else if(analogRead(lefts)>1000 && analogRead(rights)<1000){
    //Sola dön
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    /*
    motor1.run(RELEASE);
    motor2.run(FORWARD);
     */
  }
  //Çizgi sağ sensör tarafından algılanırsa
  else if(analogRead(lefts)<1000 && analogRead(rights)>1000){
    //Sağa dön
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
  }
  //Çizgi sensörler tarafından algılanmazsa
  else if(analogRead(lefts)<1000 && analogRead(rights)<1000){
    //İlerle
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    /*
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
     */
  }
  
}
