#pragma once
class Emulator {
public:
	Emulator();
	~Emulator();

	virtual void run(unsigned int* memory, int length) = 0;
};

