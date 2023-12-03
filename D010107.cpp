#include "D010107.h"

DPD201::DPD201(byte txPin, int baudrate = 9600) {
  _dpd_201 = SoftwareSerial(255, txPin);
  _dpd_201.begin(baudrate);
}

void DPD201::clearScreen() {
  _dpd_201.write(_CLR);
}

void DPD201::resetAnnunciators() {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x7A); // z
}

void DPD201::selfTest() {
  _dpd_201.write(_US);
  _dpd_201.write(0x40); // @
}

void DPD201::clearCursorLine() {
  _dpd_201.write(_CAN);
}

void DPD201::initializeDisplay() {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x40); // @
}

void DPD201::brightnessAdjustment(byte val) {
  if (val <= 0 || val > 4) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x58); // X
  _dpd_201.write(val);  
}

void DPD201::switchAnnunciator(byte column, bool state) {
  if (column <= 0 || column > 0x14) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x23); // #
  _dpd_201.write(state ? (byte)1 : (byte)0);
  _dpd_201.write(column);
}

void DPD201::cursorToPosition(byte row, byte column) {
  if (row < 1 || row > 2) return;
  if (column > 0x14) return;

  _dpd_201.write(_US);
  _dpd_201.write(0x24); // $
  _dpd_201.write(column);
  _dpd_201.write(row);
}

void DPD201::cursorTo(byte position) {
  if (position >= 0x27) return;
  _dpd_201.write(_ESC);
  _dpd_201.write(0x48); // H
  _dpd_201.write(position);
}

void DPD201::write(char* val) {
  _dpd_201.write(val);
}

void DPD201::write(char val) {
  _dpd_201.write(val);
}

void DPD201::write(byte val) {
  _dpd_201.write(val);
}

void DPD201::cursorToRight() {
  _dpd_201.write(_US);
  _dpd_201.write(_CR);
}

void DPD201::cursorToEnd() {
  _dpd_201.write(_US);
  _dpd_201.write(0x42); // B
}

void DPD201::setBlinkInterval(byte val) {
  _dpd_201.write(_US);
  _dpd_201.write(0x45);
  _dpd_201.write(val);
}

void DPD201::enableDisplay(bool enabled) {
  this->setBlinkInterval(enabled ? 0 : 255);
}
