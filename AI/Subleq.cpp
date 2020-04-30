#include "pch.h"
#include "Subleq.h"

#include <iostream>
#include  <iomanip>

#include <string>
#include <iostream>
#include <sstream> 

Subleq::Subleq() {
}

Subleq::~Subleq() {
}

void Subleq::run(unsigned int* memory, unsigned int length) {
	int EIP = 0;
	int a = 0, b = 0, c = 0;
	
	int* _memory = (int*) memory;
	int _length = (int) length;

	while (EIP >= 0 && EIP < length) {
		std::system("CLS");
		std::stringstream ss;
		for (int i = 0; i < length; i++) {
			ss << "0x" << std::setfill('0') << std::setw(8) << std::right << std::hex << _memory[i] << " ";
			
			if ((i+1) % 16 == 0)
				ss << "\n";
		}
		std::cout << ss.str() << std::flush;
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
