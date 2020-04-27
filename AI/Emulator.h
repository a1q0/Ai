#pragma once
class Emulator {
public:
	Emulator();
	~Emulator();

	virtual void run(int* memory, int length) = 0;
};

