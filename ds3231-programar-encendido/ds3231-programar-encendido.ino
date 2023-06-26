#include <Wire.h>
#include "RTClib.h"

// RTC_DS1307 rtc;
RTC_DS3231 rtc;

String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
int hora = 0;
int minuto = 0;
int segundo = 0;

void setup() {
  Serial.begin(9600);
  delay(1000); 

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
  Serial.print(minuto);
  Serial.print(':');
  
  segundo = date.second();
  Serial.print(segundo);  
  Serial.println();

  if (hora == 11 && minuto == 47){
    Serial.println();
    Serial.print("alarma activada a las 11 y 47");
    Serial.println();
  }
  
  
}

void loop() {
  // Obtener fecha actual y mostrar por Serial
  DateTime now = rtc.now();
  printDate(now);

  delay(1000);
}
