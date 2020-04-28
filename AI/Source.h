#pragma once
class Source {
public:
	int* data;
	int length;

	Source();
	Source(int length);
	Source(int* data, int length);
	~Source();

	Source* random();
	Source* random(unsigned int seed);
	Source* crossover(Source& src, int start, int length);
	Source* zero();
	Source* copy();
};

