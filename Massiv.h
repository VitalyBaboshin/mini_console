#pragma once

//основной экран 70*250 символов
const int rowsCount = 57;
const int columnsCount = 250;

//игрок (не больше чем 64*64 и 12 кадров)
const int rowsCountPlayer = 64;
const int columnsCountPlayer = 64;
const int cadrCountPlayer = 12;

//удалить? временно
char buffer[rowsCount][columnsCount];
char bufferColor[rowsCount][columnsCount];

//буфер вывод на экран
char bufferScreen[rowsCount][columnsCount];
short bufferColorScreen[rowsCount][columnsCount];
bool bufferWall[rowsCount][columnsCount];

//буфер заднего слоя
char bufferBackground[rowsCount][columnsCount];
short  bufferColorBackground[rowsCount][columnsCount];

//буфер среднего слоя
char bufferMiddle[rowsCount][columnsCount];
short  bufferColorMiddle[rowsCount][columnsCount];

//буфер переднего слоя + слой стен для взаимодействия с игроком
char bufferTop[rowsCount][columnsCount];
char bufferColorTop[rowsCount][columnsCount];
bool bufferWallTop[rowsCount][columnsCount];

//буфер игрока
char bufferPlayer[cadrCountPlayer][rowsCountPlayer][columnsCountPlayer];
short bufferColorPlayer[cadrCountPlayer][rowsCountPlayer][columnsCountPlayer];