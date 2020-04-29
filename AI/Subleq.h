#pragma once
#include "Emulator.h"

class Subleq : public Emulator {
public:
	Subleq();
	~Subleq();

	void run(unsigned int* memory, unsigned int length);
};

