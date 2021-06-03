#include <Servo.h>

int cinta_transportadora = 8;
//int caja_registradora = 7;
char datos;
Servo Caja;
void setup() {
  Serial.begin(9600);
  pinMode(cinta_transportadora, OUTPUT);
  //pinMode(caja_registradora,OUTPUT);
  Caja.attach(6);
//  pinMode(apagar_cinta, OUTPUT);
}
void loop() {
  if(Serial.available() > 0)
  { 
    datos = Serial.read();
    if(datos == '1' )
    {
       digitalWrite(cinta_transportadora,HIGH);
       //Caja.write(0);
    } 

    if(datos == '2' )
    {
       digitalWrite(cinta_transportadora,LOW); 
       delay(5000);
    }
    if (datos == '3' )
    {
     Caja.write(0);
     /* for(int x = 0; x < 90; x++){
      Caja.write(x);
      delay(2000);}*/
    }

    if (datos == '4' )
    {
    Caja.write(90);
    //digitalWrite(cinta_transportadora, LOW);
    /*for (int x=90; x >= 0; x--){
    Caja.write(x);
    delay(2000);}*/
    }

    if (datos == '5')
    {
    digitalWrite(cinta_transportadora,LOW);
    Caja.write(90);
    delay(1000);
    }
    
    }
  }
