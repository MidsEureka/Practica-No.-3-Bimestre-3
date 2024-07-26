/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5BV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: practica 3 - parte 2 - pantalla oled
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 16 de julio.
*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define width_oled 128
#define height_oled 64
#define pot_pin A0

Adafruit_SSD1306 oled_display(width_oled, height_oled, &Wire, -1);

unsigned int adc_valor;

void setup() {
  
  if (!oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);  
  }

  oled_display.setTextSize(1);
  oled_display.setTextColor(SSD1306_WHITE);
  oled_display.display();
}

void loop() {
  adc_valor = analogRead(pot_pin);

  oled_display.clearDisplay();
  oled_display.setTextSize(1);
  oled_display.setCursor(0, 0);
  oled_display.println("Valor del ADC:");
  oled_display.setTextSize(3);
  oled_display.setCursor(0, 12);
  oled_display.println(adc_valor);
  oled_display.display();

  delay(500); 
}
