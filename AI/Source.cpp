#include "pch.h"

#include <stdlib.h>
#include <math.h>

#include "Source.h"
#include "Logger.h"

#include <iostream>

Source::Source(unsigned int length) {
	this->length = length;
	
	std::cout << "length: " << length << std::endl;

	if (length != 0)
		this->data = new int[length];
	else
		this->data = nullptr;
}

Source::Source(int* data, unsigned int length) {
	std::cout << "length: " << length << std::endl;

	this->data = new int[length];
	this->length = length;
	memcpy(this->data, data, length);
}

Source::~Source() {
	delete[] data;
}

Source* Source::random() {
	for (unsigned int i = 0; i < this->length; i++)
		this->data[i] = rand() % (int) pow(2, sizeof(data[0]) * 8);
	
	return this;
}

Source* Source::random(unsigned int seed) {
	srand(seed);

	for (unsigned int i = 0; i < this->length; i++)
		this->data[i] = rand() % (int)pow(2, sizeof(data[0]) * 8);

	return this;
}

Source* Source::zero() {
	for (unsigned int i = 0; i < this->length; i++)
		this->data[i] = 0;

	return this;
}

Source* Source::crossover(Source& src, int start, unsigned int length) {
	if (src.length != this->length) {
		Logger::error("Source", "crossover() source and destination length are not equal.");
		exit(-1);
	}

	if (length < 0) {
		Logger::error("Source", "crossover() crossover length is negative.");
		exit(-1);
	}

	if (start == src.length)
		Logger::debug("Source", "crossover() crossover start at end of source.");
	
	if (length == 0)
		Logger::debug("Source", "crossover() crossover length is zero.");

	for (unsigned int i = start; i < this->length; i++)
		this->data[i] = src.data[i];
	
	return this;
}

Source* Source::copy() {
	std::cout << this->length << std::endl;
	return new Source(this->data, this->length);
}


