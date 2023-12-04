/**
  Данная программа демонстрирует работу указателей внизу индикатора
  путём реализации бегущего огонька
**/

#include <D010107.h>

DPD201 display = DPD201(2);

void setup() {
  display.initializeDisplay();
  display.clearScreen();
}

int i = 0;

void loop() {
  display.switchAnnunciator(i, true);
  if (i > 0) {
    display.switchAnnunciator(i - 1, false);
  }
  delay (100);
  if (i == 20) {
     display.switchAnnunciator(i, false);
    i = 0;
    return;
  }
  i++;
}
