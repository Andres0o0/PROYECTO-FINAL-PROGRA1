#include <Servo.h>

int cinta_transportadora = 8;
char datos;
Servo Caja;
int trigPin = 5;  //Definimos los pines con los que trabajaremos
int echoPin = 9;
int LEDR = 8;
int LEDV = 11;
float velocidad = 0.0343;  //velocidad del sonido en cm/us
long duracion, distancia ;

void setup() {
  Serial.begin(9600);
  pinMode(cinta_transportadora, OUTPUT);
  Caja.attach(6);

  pinMode(trigPin, OUTPUT);  //Declaramos el pin digital 7 como salida
  pinMode(echoPin, INPUT);   //Declaramos el pin digital 8 como entrada
  //pinMode(cinta_transportadora, OUTPUT);   //Declaramos el pin digital 10 como salida
  //pinMode(cinta_apagada, OUTPUT);   //Declaramos el pin digital 11 como salida 
  digitalWrite (cinta_transportadora , LOW);  //Definimos la salida digital 10 con un estado bajo
  //digitalWrite (cinta_apagada , LOW);  //Definimos la salida digital 11 con un estado bajo
  
}
void loop() {
    digitalWrite(trigPin, LOW);        // Nos aseguramos de que el trigger está desactivado
    delayMicroseconds(2);              // Para asegurarnos de que el trigger está LOW
    digitalWrite(trigPin, HIGH);       // Activamos el pulso de salida
    delayMicroseconds(10);             // Esperamos 10µs. El pulso sigue active este tiempo
    digitalWrite(trigPin, LOW);        // Cortamos el pulso y a esperar el ECHO
    duracion = pulseIn(echoPin, HIGH) ; //pulseIn mide el tiempo que pasa entre que el pin declarado (echoPin) cambia de estado bajo a alto (de 0 a 1)
    distancia = velocidad* duracion / 2;
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
    }

    if (datos == '4' )
    {
    Caja.write(90);
    }


     if (datos == '1' == distancia < 20){
        digitalWrite (LEDR , HIGH);     //Si el sensor detecta una distancia menor a 20 cm enciende el LED Rojo
        digitalWrite (LEDV , LOW);      // y apaga el verde
    }
    else{       // de lo contrario
        digitalWrite (LEDR , LOW);    //apaga el rojo
        digitalWrite (LEDV , HIGH);   //enciende el verde
        }
   

    if (datos == '6')
    {
    digitalWrite(cinta_transportadora,LOW);
    Caja.write(90);
    delay(1000);
    }
    
    }
  
