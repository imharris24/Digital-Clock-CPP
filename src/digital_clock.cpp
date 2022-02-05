#include "digital_clock.h"

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<chrono>
#include<ctime>
#include<Windows.h>
using namespace std;

void DisplayTime()
{
	auto CurrentTime = chrono::system_clock::now();
	while (true)
	{
		system("cls");
		CurrentTime = chrono::system_clock::now();
		time_t Current_T = chrono::system_clock::to_time_t(CurrentTime);
		cout << "\n\tDate & Time : " << ctime(&Current_T) << "\n";
		Sleep(999);
	}
}