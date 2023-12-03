#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

#define _ESC 0x1B
#define _US 0x1F
#define _CR 0x0D
#define _CLR 0x0C 
#define _CAN 0x18
#define _MD1 0x01
#define _MD2 0x02
#define _MD3 0x03

class DPD201 {
	public:
		DPD201(byte txPin, int baudrate = 9600);
		void clearScreen();
		void selfTest();
		void clearCursorLine();
		void initializeDisplay();
		void write(char* val);
    void write(char val);
    void write(byte val);
		void brightnessAdjustment(byte val);  // 1 - 4
    void resetAnnunciators();
		void switchAnnunciator(byte column, bool state); 
    void cursorTo(byte position);
    void cursorToEnd();
    void cursorToRight();
		void cursorToPosition(byte row, byte column);
    void setBlinkInterval(byte val);
    void enableDisplay(bool enabled);
	private:
		SoftwareSerial _dpd_201 = SoftwareSerial(255, 255);
};