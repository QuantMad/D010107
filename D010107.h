#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>

#define _ESC 0x1B
#define _US 0x1F

class DPD201 {
	public:
		DPD201(byte txPin, int baudrate = 9600);
		void clrScr();
		void resetAnnunciators();
		void selfTest();
		void clearCursorLine();
		void initializeDisplay();
		void write(char* val);
		void brightnessAdjustment(byte val);
		void switchAnnunciator(byte column, bool state);
		void moveCursorTo(byte row, byte column);
		void cursorTo(byte position);
		void cursorToPosition(byte row, byte column);
	private:
		SoftwareSerial _dpd_201 = SoftwareSerial(255, 255);
};