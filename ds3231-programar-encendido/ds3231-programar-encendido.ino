#include <Wire.h>
#include "RTClib.h"

const int ledPIN = 13;

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
int hora = 0;
int minuto = 0;
int minutoMod = 0;
int segundo = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  //digitalWrite(ledPIN , HIGH);
  digitalWrite(ledPIN , HIGH);

  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  // Si se ha perdido la corriente, fijar fecha y hora
  if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
  }
}

void printDate(DateTime date)
{
  Serial.print(date.year(), DEC);
  Serial.print('/');
  Serial.print(date.month(), DEC);
  Serial.print('/');
  Serial.print(date.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
  Serial.print(") ");

  hora = date.hour();
  Serial.print(hora);
  Serial.print(':');

  minuto = date.minute();

  minutoMod = minuto + 8;

  if (minutoMod == 60) {
    minutoMod = 1;
  }
  if (minutoMod == 61) {
    minutoMod = 2;
  }
  if (minutoMod == 62) {
    minutoMod = 3;
  }
  if (minutoMod == 63) {
    minutoMod = 4;
  }
  if (minutoMod == 64) {
    minutoMod = 5;
  }
  if (minutoMod == 65) {
    minutoMod = 6;
  }
  if (minutoMod == 66) {
    minutoMod = 7;
  }
  if (minutoMod == 67) {
    minutoMod = 8;
  }




  Serial.print(minutoMod);
  Serial.print(':');

  segundo = date.second();
  Serial.print(segundo);
  Serial.println();

  //para hacer pruebas
  int hora1 = 19;
  
  int minuto1 = 32; //se activar la alarma al minuto
  
  int segIni = 20;
  int segFin = 25;

  if (hora == hora1 && minutoMod == minuto1 && segundo == segIni) {
    Serial.println();
    Serial.print("alarma activada");
    //digitalWrite(ledPIN , HIGH);
    digitalWrite(ledPIN , LOW);//LOW ACTIVA EL RELAY - CIERRA EL CIRCUITO CIERRA EL INTERRUPTOR
    Serial.println();
    Serial.println();
  }

  if (hora == hora1 && minutoMod == minuto1 && segundo == segFin) {
    Serial.println();
    Serial.print("alarma desactivada");
    //digitalWrite(ledPIN , LOW);
    digitalWrite(ledPIN , HIGH);//HIGH DESACTIVA EL RELAY - ABRE EL CIRCUITO ABRE EL INTERRUPTOR
    Serial.println();
    Serial.println();
  }




  // oficial


  if (hora == 7 && minutoMod == 45 && segundo == 0) {
    Serial.println();
    Serial.print("alarma activada");
    Serial.println();
    Serial.println();
  }

  if (hora == 7 && minutoMod == 45 && segundo == 15) {
    Serial.println();
    Serial.print("alarma desactivar");
    Serial.println();
    Serial.println();
  }




}

void loop() {
  // Obtener fecha actual y mostrar por Serial
  DateTime now = rtc.now();
  printDate(now);

  delay(1000);
}
