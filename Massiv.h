#pragma once

//�������� ����� 70*250 ��������
const int rowsCount = 57;
const int columnsCount = 250;

//����� (�� ������ ��� 64*64 � 12 ������)
const int rowsCountPlayer = 64;
const int columnsCountPlayer = 64;
const int cadrCountPlayer = 12;

//�������? ��������
char buffer[rowsCount][columnsCount];
char bufferColor[rowsCount][columnsCount];

//����� ����� �� �����
char bufferScreen[rowsCount][columnsCount];
short bufferColorScreen[rowsCount][columnsCount];
bool bufferWall[rowsCount][columnsCount];

//����� ������� ����
char bufferBackground[rowsCount][columnsCount];
short  bufferColorBackground[rowsCount][columnsCount];

//����� �������� ����
char bufferMiddle[rowsCount][columnsCount];
short  bufferColorMiddle[rowsCount][columnsCount];

//����� ��������� ���� + ���� ���� ��� �������������� � �������
char bufferTop[rowsCount][columnsCount];
char bufferColorTop[rowsCount][columnsCount];
bool bufferWallTop[rowsCount][columnsCount];

//����� ������
char bufferPlayer[cadrCountPlayer][rowsCountPlayer][columnsCountPlayer];
short bufferColorPlayer[cadrCountPlayer][rowsCountPlayer][columnsCountPlayer];