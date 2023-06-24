/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

SoftwareSerial BTserial(2, 3); // RX | TX
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

double Temperatura;
double CorrecTemp = -3.3; 
float duration;
const int trigPin = 9;
const int echoPin = 10;
void setup() {
pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 
Serial.begin(9600);    
BTserial.begin(9600); 
  sensors.begin();
}
 
void loop(){ 
  sensors.requestTemperatures(); 
  Temperatura = sensors.getTempCByIndex(0) + CorrecTemp;   
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
         BTserial.print("<");
         BTserial.print(duration);BTserial.print(" ");
         BTserial.print(Temperatura);BTserial.print(" ");
         BTserial.println(">");

delay(150); 
}
