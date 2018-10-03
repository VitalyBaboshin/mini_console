#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Massiv.h"

using namespace std;
char ch;

//��� �������������� �� 16 � 10 ����. ���������
int charToInt(char chr);
void Initialize(HANDLE hOut);
void cls(HANDLE hConsole)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	// Get the number of character cells in the current buffer. 
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}
	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}
	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}
	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}
int main(int argc, char **argv)
{
	//��������� ������ � ������� ����
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ��������� No. �������
	CONSOLE_FONT_INFOEX consoleFont;
	system("mode con cols=250 lines=59"); //������ ����, ����� ������� ���������� ����� � �������
	consoleFont.cbSize = sizeof(CONSOLE_FONT_INFOEX);  // consoleFont.cbSize          = sizeof(consoleFont);
	consoleFont.dwFontSize.Y = 10; 
	wcscpy_s(consoleFont.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(hOut, false, &consoleFont);    // ���������� ����� �����


	for (int i = 0; i < rowsCount; i++)			////
		for (int j = 0; j < columnsCount; j++) { //// ��������� ������ �������� ���������
			buffer[i][j] = ' ';					////
			bufferColor[i][j] = '7';
			bufferColorTop[i][j] = '7';
		}

	//������� �� ����� ������� ���������
	/*for (int i = 0; i < rowsCount; i++) {
		for (int j = 0; j < columnsCount; j++) {
			SetConsoleTextAttribute(hOut, bufferColor[i][j]-'0');
			cout << bufferColor[i][j];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hOut, 0x00f );*/

	
	fstream inp("1.txt");
	fstream inp1("2.txt");
	fstream inp2("roadColor.txt");
	char buf[256];
	int count = 0;

	while (inp.getline(buf, 256))
		count++;
	cout << "file 1: "<<count << endl;
	count = 0;

	while (inp1.getline(buf, 256))
		count++;
	cout << "file 2: " << count << endl;

	count = 0;
	while (inp2.getline(buf, 256))
		count++;
	cout << "file roadColor: " << count << endl;

	inp.close();
	inp1.close();
	inp2.close();

	ifstream fs("2.txt");
	if (!fs.is_open())
	{
		cout << "Error open file" << endl;
		return 0;
	}

	while (!fs.eof()) {
		for (int i = 0; i < rowsCount; i++) {
			ch = fs.get();
			for (int j = 0; j < columnsCount && ch != '\n'; j++) {
				if (ch != '\n'&& ch!=' ')
					buffer[i][j] = ch;
					bufferColor[i][j] = '7';
				ch = fs.get();
			}
		}
	}

	fs.close();








	////��������� ������
	//� ����� �� ����� ������� ������
	ifstream fs1c("roadColor.txt");
	if (!fs1c.is_open())
	{
		cout << "Error open file" << endl;
		return 0;
	}

	while (!fs1c.eof()) {
		for (int i = 0; i < rowsCount; i++) {
			ch = fs1c.get();
			for (int j = 0; j < columnsCount && ch != '\n'; j++) {
				if (ch != '\n'&& ch != ' ')
					bufferColorTop[i][j] = int(ch) ;
				if (fs1c.eof())
					break;
				ch = fs1c.get();
			}
			if (fs1c.eof())
				break;
		}
	}

	//����������� �� ����� ����� ������ � ����
	ifstream fs1("road.txt");
	if (!fs1.is_open())
	{
		cout << "Error open file" << endl;
		return 0;
	}

	while (!fs1.eof()) {
		for (int i = 33; i < rowsCount, !fs1.eof(); i++) {
			ch = fs1.get();
			for (int j = 0; j < columnsCount && ch != '\n'; j++) {
				if (ch != ' ') {
					buffer[i][j] = ch;

					//bufferColor[i][j] = 6;
					bufferColor[i][j] = char(bufferColorTop[i][j]);
				}
				if (ch == '&')
					buffer[i][j] = ' ';
				ch = fs1.get();
				if (fs1.eof())
					break;
			}
			if (fs1.eof())
				break;
		}
	}

	fs1.close();





	//��������� ����� �� �������� ����
	ifstream fs2("1.txt");
	if (!fs2.is_open())
	{
		cout << "Error open file" << endl;
		return 0;
	}

	while (!fs2.eof()) {
		for (int i = 32; i < rowsCount , !fs2.eof(); i++) {
			ch = fs2.get();
			for (int j = 0; j < columnsCount && ch != '\n'; j++) {
				if (ch != ' ') {
					buffer[i][j] = ch;
					bufferColor[i][j] = '3';
				}
				if (ch == '&')
					buffer[i][j] = ' ';
				ch = fs2.get();
				if (fs2.eof())
					break;
			}
		}
	}

	fs2.close();
	//��������� �����

	for (int j = 0; j < columnsCount; j++) {
		buffer[0][j] = 178;
		bufferColor[0][j] = '2';
	}
	for (int j = 0; j < columnsCount; j++) {
		buffer[56][j] = 178;
		bufferColor[56][j] = '2';
	}
	for (int i = 1; i< rowsCount ; i++) {
			buffer[i][0] = 178;
			bufferColor[i][0] = '2';
			buffer[i][249] = 178;
			bufferColor[i][249] = '2';

	}




	//������� �� ����� ��������
	/*void render(const int rowsCount,const int columnsCount,const char &buffer, const char &bufferColor) {


	}*/
	for (int i = 0; i < rowsCount; i++) {
		for (int j = 0; j < columnsCount; j++) {
			SetConsoleTextAttribute(hOut, charToInt(bufferColor[i][j]));
			cout << buffer[i][j];
		}
		cout << endl;
	}

	cout << "\n\n\t\t";
	system("pause");
	
	return 0;
}

int charToInt(char chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';
	else if (chr >= 'A' && chr <= 'F')
		return chr - 'A' + 10;
	else if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;
	return -1;
}


void Initialize(HANDLE hOut) {
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 3;
	SetConsoleCursorPosition(hOut, cursorCoord);

	for (int i = 0; i < rowsCount; i++) {
		for (int j = 0; j < columnsCount; j++) {
			SetConsoleTextAttribute(hOut, charToInt(bufferColor[i][j]));
			cout << buffer[i][j];
		}
		cout << endl;
	}
}