#pragma once
class Source {
public:
	/// Summary:	Pointer to int array where instructions are stored
	int* data;
	/// Summary:	Length of data array
	int length;

	Source(int length);
	~Source();

	Source& random();
	Source& random(unsigned int seed);
	Source& crossover(Source& src, Source& dst, int start, int length);
};

