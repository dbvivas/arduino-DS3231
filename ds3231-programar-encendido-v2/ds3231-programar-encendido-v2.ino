#include <Wire.h>
#include <LiquidCrystal.h>
#include <RTClib.h>

DateTime now;
RTC_DS3231 rtc;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (rs, e, d4, d5, d6, d7)

int hora = 0;
int minuto = 0;
int minutoMod = 0;
int segundo = 0;

//para hacer pruebas
int horaI = 0;
int minutoI = 0; //se activar la alarma al minuto
int segundoI = 0;
int segundoF = 0;
int segundosE = 0;

const int pinRelay = 8;



void displayDate(void);
void displayTime(void);

void setup ()
{

  pinMode(pinRelay , OUTPUT);  //definir pin como salida
  //digitalWrite(ledPIN , HIGH);
  digitalWrite(pinRelay , HIGH);

  Serial.begin(9600);
  lcd.begin(16, 2);
  if (! rtc.begin())
  {
    Serial.println(" Modulo RTC NO Detetado");
    while (1);
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC fallo de energia, reiniciando el tiempo!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}


void loop ()
{
  now = rtc.now();
  displayDate();
  displayTime();
}


void displayDate()
{
  lcd.setCursor(0, 0);
  lcd.print("Fecha:");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
}


void displayTime()
{

  //DEMOSTRACION
  //para hacer pruebas
  
  horaI = 9; //hora de activacion
  minutoI = 32; //minuto de activacion
  segundoI = 20; //segundo de activacion
  segundosE = 5; //cantos segundos quieres que este activa la alarma
    
  segundoF = segundoI + segundosE; //segundo se desactiva

  hora = now.hour();
  minuto = now.minute();
  segundo = now.second();

  lcd.setCursor(0, 1);
  lcd.print("Hora:");
  lcd.print(hora);
  lcd.print(':');
  lcd.print(minuto);
  lcd.print(':');
  lcd.print(segundo);
  lcd.print("    ");


  //DEMOSTRACION

  if (hora == horaI && minuto == minutoI && segundo == segundoI) {
    //digitalWrite(ledPIN , HIGH);
    digitalWrite(pinRelay , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }

  if (hora == horaI && minuto == minutoI && segundo == segundoI) {
    //digitalWrite(ledPIN , HIGH);
    digitalWrite(pinRelay , HIGH);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }



  //HORARIOS
  //07:00 - 07:45
  if (hora == 7 && minuto == 45 && segundo == 0) {    
    digitalWrite(pinRelay , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }
  if (hora == 7 && minuto == 45 && segundo == 5) {    
    digitalWrite(pinRelay , HIGH);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }


    //07:45 - 08:30
  if (hora == 8 && minuto == 30 && segundo == 0) {    
    digitalWrite(pinRelay , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }
  if (hora == 8 && minuto == 30 && segundo == 5) {    
    digitalWrite(pinRelay , HIGH);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }


    //08:30 - 08:55
  if (hora == 8 && minuto == 45 && segundo == 0) {    
    digitalWrite(pinRelay , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }
  if (hora == 8 && minuto == 45 && segundo == 5) {    
    digitalWrite(pinRelay , HIGH);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }


    //08:55 - 09:40
  if (hora == 9 && minuto == 40 && segundo == 0) {
    //digitalWrite(ledPIN , HIGH);
    digitalWrite(pinRelay , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }
  if (hora == 8 && minuto == 30 && segundo == 5) {
    //digitalWrite(ledPIN , HIGH);
    digitalWrite(pinRelay , HIGH);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
  }


}
