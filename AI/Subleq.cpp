#include "pch.h"
#include "Subleq.h"

Subleq::Subleq() {
}

Subleq::~Subleq() {
}

void Subleq::run(int* memory, int length) {
	int EIP = 0, a = 0, b = 0, c = 0;
	
	while (EIP >= 0 && EIP < length) {
		a = memory[EIP];
		b = memory[EIP + 1];
		c = memory[EIP + 2];

		if (a < 0 || b < 0) {
			EIP = -1;
		} else {
			memory[b] = memory[b] - memory[a];
			if (memory[b] > 0) {
				EIP += 3;
			} else {
				EIP = c;
			}
		}
	}
}
