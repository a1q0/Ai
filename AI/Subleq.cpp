#include "pch.h"
#include "Subleq.h"

#include <iostream>

Subleq::Subleq() {
}

Subleq::~Subleq() {
}

void Subleq::run(unsigned int* memory, unsigned int length) {
	unsigned int EIP = 0;
	int a = 0, b = 0, c = 0;
	
	int* _memory = (int*) memory;

	while (EIP >= 0 && EIP < length) {
		a = _memory[EIP];
		b = _memory[EIP + 1];
		c = _memory[EIP + 2];

		if (a < 0 || b < 0) {
			EIP = -1;
		} else {
			_memory[b] = _memory[b] - _memory[a];
			if (_memory[b] > 0) {
				EIP += 3;
			} else {
				EIP = c;
			}
		}
	}
}
