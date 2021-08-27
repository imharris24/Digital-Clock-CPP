//Digital Clock using CPP
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<chrono>
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;

void SetConsoleSize(int Width, int Height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, Width, Height, TRUE);
}

class Clock {
public:
	static void DisplayTime() {
		char Stop = '\0';
		auto CurrentTime = chrono::system_clock::now();
		while (true) {
			CurrentTime = chrono::system_clock::now();
			time_t Current_T = chrono::system_clock::to_time_t(CurrentTime);
			cout << "Date & Time : " << ctime(&Current_T) << "\n";
			cout << "\n\nPress Any Key to return to Menu...";
			Sleep(1000);
			if (_kbhit()) {
				switch (_getch()) {
				default: return;
				}
			}
			system("cls");
		}
	}
};

class DigitalClock {
private:
	char MainMenuOPT;
	void MainMenu() {
		cout << "\n\t\t\tWELCOME TO DIGITAL CLOCK\n" << endl;
		cout << "\n\tMenu" << endl;
		cout << "\t-> 1. Clock" << endl;
		cout << "\t-> 2. Timer" << endl;
		cout << "\t-> 3. Stop Watch" << endl;
		cout << "\n\t Option : ";
		MainMenuOPT = _getche();
	}
public:
	void RunProgram() {
		SetConsoleSize(640, 500);
	Start:
		system("cls");
		MainMenu();
		switch (MainMenuOPT) {
		case '1' : 
			system("cls");
			Clock::DisplayTime();
			goto Start;
			break;
		}
	}
	DigitalClock() {
		MainMenuOPT = '\0';
	}
};


int main() {
	DigitalClock D;
	D.RunProgram();
	return 0;
}
