#pragma once
#include "Emulator.h"
class Subleq : public Emulator {
public:
	Subleq();
	~Subleq();

	void run(int* memory, int length);
};

