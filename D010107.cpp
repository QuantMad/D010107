#include "D010107.h"

DPD201::DPD201(byte txPin, int baudrate = 9600) {
  _dpd_201 = SoftwareSerial(255, txPin);
  _dpd_201.begin(baudrate);
}

void DPD201::defineUserChar(byte b1, byte b2, byte b3, byte b4, byte b5, byte codeLocation) {
  if (codeLocation <= 0x20 || codeLocation >= 0x7E) return;
  _dpd_201.write(_ESC);
  _dpd_201.write(0x26); // &
  _dpd_201.write(codeLocation);
  _dpd_201.write(b1);
  _dpd_201.write(b2);
  _dpd_201.write(b3);
  _dpd_201.write(b4);
  _dpd_201.write(b5);
}

void DPD201::selectOverwriteMode() {
  _dpd_201.write(_US);
  _dpd_201.write(_MD1);
}

void DPD201::selectVerticalScrollMode() {
  _dpd_201.write(_US);
  _dpd_201.write(_MD2);
}

void DPD201::selectHorizontalScrollMode() {
  _dpd_201.write(_US);
  _dpd_201.write(_MD3);
}

void DPD201::defineUserChar(bool bits[], byte codeLocation) {
  if (codeLocation <= 0x20 || codeLocation >= 0x7E) return;
  _dpd_201.write(_ESC);
  _dpd_201.write(0x26); // &
  _dpd_201.write(codeLocation);

  int bitNumber = 0;
  char resultChar = 0;
  for (int i = 0; i < 40; i++) {
      resultChar += (bits[i] << (7 - bitNumber));
      bitNumber++;

      if (bitNumber == 8) {
        bitNumber = 0;
        _dpd_201.write(resultChar);
        resultChar = 0;
      }
  }
}

void DPD201::selectUserCharSet(bool value) {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x25); // %
  _dpd_201.write(value ? 1 : 0);
}

void DPD201::writeUserChar(byte val) {
  this->selectUserCharSet(1);
  _dpd_201.write(val);
  this->selectUserCharSet(0);
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
  if (column < 1 || column > 0x14) return;

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

void DPD201::write(int val) {
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
  _dpd_201.write(0x45); // E
  _dpd_201.write(val);
}

void DPD201::enableDisplay(bool enabled) {
  this->setBlinkInterval(enabled ? 0 : 255);
}

void DPD201::selectCharacterTable(byte n) {
  if (n > 1) return;

  _dpd_201.write(_ESC);
  _dpd_201.write(0x74); // t
  _dpd_201.write(n);
}

void DPD201::selectInternationalCharacterSet(byte code) {
  _dpd_201.write(_ESC);
  _dpd_201.write(0x52); // R
  _dpd_201.write(code);
}