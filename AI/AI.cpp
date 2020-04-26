// AI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>

class Agent {
	private:
		
};

class AI {
	
	public:
		AI(void);
};

AI::AI(void) {
		
}

int main(int argc, TCHAR *argv[]) {
	if (argc == 1) {
		for (int i = 0; i < argc; i++) {
			std::cout << argv[i] << std::endl;
		}
		std::cout << "Hello you are in the parent process" << std::endl;
	}
	else {
		for (int i = 0; i < argc; i++) {
			std::cout << argv[i] << std::endl;
		}
		std::cout << "Welcome to the child process" << std::endl;
		std::cout << argc << std::endl;
	}

	AI ai;
	LPCWSTR lpApplicationName = _T("AI.exe");
	LPWSTR* lpCmd = "";
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	BOOL result = CreateProcess(lpApplicationName, lpCmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	
	if (!result) {
		std::cout << "Failed to create process" << std::endl;
	}
	else {
		std::cout << "Child process successfully created" << std::endl;
	}

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
