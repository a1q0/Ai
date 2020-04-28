#pragma once
class Source {
public:
	int* data;
	unsigned int length;

	Source();
	Source(unsigned int length);
	Source(int* data, unsigned int length);
	~Source();

	Source* random();
	Source* random(unsigned int seed);
	Source* crossover(Source& src, int start, int length);
	Source* zero();
	Source* copy();
};

