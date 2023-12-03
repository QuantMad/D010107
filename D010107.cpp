#include "D010107.h"

DPD201::DPD201(byte txPin, int baudrate = 9600) {
  _dpd_201 = SoftwareSerial(255, txPin);
  _dpd_201.begin(baudrate);
}

void DPD201::clrScr() {
  _dpd_201.write(0x0C);
}

void DPD201::resetAnnunciators() {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x7A);
}

void DPD201::selfTest() {
  _dpd_201.write(0x1F);
  _dpd_201.write(0x40);
}

void DPD201::clearCursorLine() {
  _dpd_201.write(0x18);
}

void DPD201::initializeDisplay() {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x40);
}

void DPD201::brightnessAdjustment(byte val) {
  if (val <= 0 || val > 4) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x58);
  _dpd_201.write(val);  
}

void DPD201::switchAnnunciator(byte column, bool state) {
  if (column <= 0 || column > 0x14) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x23);
  _dpd_201.write(state ? (byte)1 : (byte)0);
  _dpd_201.write(column);
}

void DPD201::cursorToPosition(byte row, byte column) {
  if (row < 1 || row > 2) return;
  if (column > 0x14) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x24);
  _dpd_201.write(column);
  _dpd_201.write(row);
}

void DPD201::cursorTo(byte position) {
  if (position >= 0x27) return;
  _dpd_201.write(_ESC);
  _dpd_201.write(0x48);
  _dpd_201.write(position);
}

void DPD201::write(char* val) {
  _dpd_201.write(val);
}