#include "pch.h"

#include <stdlib.h>
#include <math.h>

#include "Source.h"
#include "Logger.h"


Source::Source(int length) {
	this->length = length;
	
	if (length != 0)
		this->data = new int[length];
	else
		this->data = nullptr;
}

Source::Source() : Source(0) {
}

Source::~Source() {
	delete data;
}

Source& Source::random() {
	for (int i = 0; i < this->length; i++)
		this->data[i] = rand() % (int) pow(2, sizeof(data[0]) * 8);
	
	return *this;
}

Source& Source::random(unsigned int seed) {
	srand(seed);

	for (int i = 0; i < this->length; i++)
		this->data[i] = rand() % (int) pow(2, sizeof(data[0]) * 8);
	
	return *this;
}

Source& Source::crossover(Source& src, int start, int length) {
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

	for (int i = start; i < this->length; i++)
		this->data[i] = src.data[i];
	
	return *this;
}


