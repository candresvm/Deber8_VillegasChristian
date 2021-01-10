/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *        FICA-CITEL
 *     SISTEMAS EMBEBIDOS
 *     CHRISTIAN VILLEGAS
 *         DEBER 8
 */

#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>

int on=0; 
int tiempo=60; 
int cont=0; 
int j=0;

void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,reloj);
  set_sleep_mode(SLEEP_MODE_STANDBY);
  sleep_enable();
  Serial.println("INICIO DEL SISTEMA");
}

void loop() {
  j=analogRead(0);
  delay(3000);
  Serial.println(String("La lectura es de: ")+String(j));
  delay(1000);
  MsTimer2::start();
  tiempo=0;
  on=0;
  
}

void reloj() {
  cont++;
  power_adc_disable();
  Serial.println(("Lectura en:")+String(60-cont));
  if(cont==tiempo){
    power_adc_enable();
    cont=0;
  }
  if(cont>=60){
    wdt_enable(WDTO_8S);
    sleep_mode();
  }
}
