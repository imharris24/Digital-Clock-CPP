//Digital Clock using CPP
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<chrono>
#include<ctime>
#include<Windows.h>
using namespace std;

class Clock {
public:
	static void DisplayTime() {
		auto CurrentTime = chrono::system_clock::now();
		while (true) {
			CurrentTime = chrono::system_clock::now();
			time_t Current_T = chrono::system_clock::to_time_t(CurrentTime);
			cout << "Date & Time : " << ctime(&Current_T) << "\n";
			Sleep(1000);
			system("cls");
		}
	}
};

int main()
{
	Clock::DisplayTime();
	return 0;
}
