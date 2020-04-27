#include "pch.h"

class Subleq {
	int EIP, a, b, c;
	
	void run(int* memory) {
		while (EIP >= 0) {
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
};