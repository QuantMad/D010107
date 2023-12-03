#include "D010107.h"

DPD201 display = DPD201(2);

double voltage1 = 8.1;
double current1 = 1.4;

double voltage2 = 12.2;
double current2 = 0.51;

void setup() {
  display.initializeDisplay();
  display.clrScr();
  display.write("     V      A      W\0");
  display.write("     V      A      W\0");
  display.cursorToPosition(0, 0);

  printValueAt(voltage1, 1, 1);
  printValueAt(current1, 1, 8);
  printValueAt(voltage1 * current1, 1, 15);

  printValueAt(voltage2, 2, 1);
  printValueAt(current2, 2, 8);
  printValueAt(voltage2 * current2, 2, 15);
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

void printValueAt(double val, byte row, byte col) {
  char buf[6];
  sprintf(buf, "%02d.%02d\0", (int)val, (int)(val * 100) % 100);
  display.cursorToPosition(row, col);
  display.write(buf);
}