//Digital Watch using CPP
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <ctime>    

using namespace std;

int main()
{
	auto CurrentTime = chrono::system_clock::now();
	while (true) {
		CurrentTime = chrono::system_clock::now();
		time_t Current_T = chrono::system_clock::to_time_t(CurrentTime);
		cout << "Date & Time : " << ctime(&Current_T) << "\n";
		system("cls");
	}
	return 0;
}