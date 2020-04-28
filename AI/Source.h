#pragma once
class Source {
public:
	/// <summary>
	/// The data
	/// </summary>
	int* data;
	int length;

	Source(int length);
	~Source();

	Source& random();
	Source& random(unsigned int seed);
	Source& crossover(Source& src, Source& dst, int start, int length);
};

