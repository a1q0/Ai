#pragma once
class Emulator {
public:
	Emulator();
	~Emulator();

	virtual void run(unsigned int* memory, unsigned int length) = 0;
};

