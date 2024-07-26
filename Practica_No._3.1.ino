
#include <LedControl.h> 
#define din_matrix 3   
#define cs_matrix  2   
#define clk_matrix 4  
LedControl PacmanMatrix = LedControl(din_matrix, clk_matrix, cs_matrix, 1);


byte pacman_boca_abierta[8] = {
  B00111000,
  B01000100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000
};

byte pacman_boca_cerrada[8] = {
  B00111000,
  B01000100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000
};

int delayTime = 500;

void setup() {
  PacmanMatrix.shutdown(0, false);
  PacmanMatrix.setIntensity(0, 15);
  PacmanMatrix.clearDisplay(0);
}

void loop() {
  int potValue = analogRead(A0);
  
  delayTime = map(potValue, 0, 1023, 100, 1000); 
  
  displayPacMan(pacman_boca_abierta);
  delay(delayTime);
  
  displayPacMan(pacman_boca_cerrada);
  delay(delayTime);
}

void displayPacMan(byte pattern[]) {
  for (int i = 0; i < 8; i++) {
    PacmanMatrix.setRow(0, i, pattern[i]);
  }
}
