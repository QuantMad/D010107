#include <D010107.h>

DPD201 display = DPD201(2);

void setup() {
  display.initializeDisplay();
  display.clearScreen();
}

int i = 0;

void loop() {
  // демонстрирует режим перезаписи содержимого экрана
  display.clearScreen();
  display.write("Owerwrite mode demo");
  display.selectOverwriteMode();
  delay(1000);
  for (int i = 0; i < 80; i++) {
    display.write((byte)random(0x21, 0xFE));
    delay(150);
  }

  // // демонстрирует режим горизонтального сдвига текста для верхней строки
  display.clearScreen();
  display.write("H-Scroll mode demo 1");
  display.selectHorizontalScrollMode();
  delay(1000);
  for (int i = 0; i < 80; i++) {
    display.write((byte)random(0x21, 0xFE));
    delay(150);
  }
  // демонстрирует режим горизонтального сдвига текста для нижней строки
  display.cursorToPosition(2, 1);
  display.write("H-Scroll mode demo 2");
  delay(1000);
  for (int i = 0; i < 80; i++) {
    display.write((byte)random(0x21, 0xFE));
    delay(150);
  }

  // демонстрирует режим вертикального сдвига текста
  display.clearScreen();
  display.write("V-Scroll mode demo");
  display.selectVerticalScrollMode();
  delay(1000);
  for (int i = 0; i < 80; i++) {
    display.write((byte)random(0x21, 0xFE));
    delay(150);
  }
}
