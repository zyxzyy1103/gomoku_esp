// _display_h for 4*8*8雙色LED點矩陣

// 雙色 LED 點矩陣控制腳位
const uint8_t rowData[8] = {32, 33, 25, 26, 27, 14, 12, 13};
const uint8_t rowScan[2] = {5, 18};
const uint8_t colData[4] = {0, 4, 16, 17};
const uint8_t colScan[2] = {15, 2};

// ic74154 真值表
const bool ic74154[16][4] = {
  {0, 0, 0, 0},
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {0, 0, 1, 0},
  {1, 0, 1, 0},
  {0, 1, 1, 0},
  {1, 1, 1, 0},
  {0, 0, 0, 1},
  {1, 0, 0, 1},
  {0, 1, 0, 1},
  {1, 1, 0, 1},
  {0, 0, 1, 1},
  {1, 0, 1, 1},
  {0, 1, 1, 1},
  {1, 1, 1, 1}
};

void SetupDisplayIO() {
	uint8_t i;
  for(i = 0; i < 8; i++) pinMode(rowData[i], OUTPUT);
  for(i = 0; i < 2; i++) pinMode(rowScan[i], OUTPUT);
  for(i = 0; i < 4; i++) pinMode(colData[i], OUTPUT);
  for(i = 0; i < 2; i++) pinMode(colScan[i], OUTPUT);
}

void Display() {
  static uint8_t cycle = 0;
  uint8_t i;
  
  for(i = 0; i < 8; i++) digitalWrite(rowData[i], HIGH);
  digitalWrite(rowScan[1], LOW);
  digitalWrite(rowScan[1], HIGH);
  for(i = 0; i < 8; i++) digitalWrite(rowData[i], HIGH);
  digitalWrite(rowScan[0], LOW);
  digitalWrite(rowScan[0], HIGH);

  for(i = 0; i < 4; i++) digitalWrite(colData[i], ic74154[cycle][i]);
  digitalWrite(colScan[0], HIGH);
  digitalWrite(colScan[1], LOW);

  if(++cycle == 16) cycle = 0;

  delay(1);
}
