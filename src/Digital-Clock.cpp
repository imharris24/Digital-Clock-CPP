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

class Timer {
private:
	int Hours, Minutes, Seconds;
	void DisplayTime() {
		cout << "Time -> " << Hours << " : " << Minutes << " : " << Seconds << endl;
	}
	void TimerMenu() {
		cout << "Set Time in 'HH : MM : SS' Format\n";
		cout << "Current Time -> ";
		cin >> Hours;
		system("cls");
		cout << "Enter Time in 'HH : MM : SS' Format\n";
		cout << "Current Time -> " << Hours << " : ";
		cin >> Minutes;
		system("cls");
		cout << "Enter Time in 'HH : MM : SS' Format\n";
		cout << "Current Time -> " << Hours << " : " << Minutes << " : ";
		cin >> Seconds;
		system("cls");
		cout << "Enter Time in 'HH : MM : SS' Format\n";
		cout << "Current Time -> " << Hours << " : " << Minutes << " : " << Seconds << endl;
		Seconds++;
		cout << "\nTimer Set...\n";
		cout << "Press Any Key to Start Timer\n";
		_getch();
	}
	void TimerAlgorithm() {
		while (Minutes > 60 || Seconds > 60 || Minutes < 0 || Seconds == 0) {
			if (Seconds > 60) {
				Seconds -= 60;
				Minutes++;
			}
			if (Seconds == 0) {
				Minutes--;
				Seconds += 60;
			}
			if (Minutes > 60) {
				Minutes -= 60;
				Hours++;
			}
			if (Minutes < 0) {
				Hours--;
				Minutes += 60;
			}
		}
		Seconds--;
	}
	void RunTimer() {
		TimerMenu();
		while (true) {
			if (Hours == 0 && Minutes == 0 && Seconds == 0) {
				return;
			}
			system("cls");
			TimerAlgorithm();
			DisplayTime();
			Sleep(1000);
		}
	}
public:
	void ExecuteTimer() {
		RunTimer();
		cout << "\n\nAlarm...\nPress Any Key to Stop Alarm and Return to Menu";
		while (true) {
			cout << "\a";
			Sleep(1600);
			if (_kbhit()) {
				switch (_getch()) {
				default: return;
				}
			}
		}
	}
	Timer() {
		Hours = 0;
		Minutes = 0;
		Seconds = 0;
	}
};

class DigitalClock {
private:
	Clock C;
	Timer T;
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
			C.DisplayTime();
			goto Start;
			break;
		case '2':
			system("cls");
			T.ExecuteTimer();
			goto Start;
			break;
		default: 
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
