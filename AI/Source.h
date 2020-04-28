#pragma once
class Source {
public:
	int* data;
	int length;

	Source(int length);
	~Source();

	/// <summary>
	/// Generate a random source.
	/// </summary>
	/// <returns></returns>
	Source& random();
	/// <summary>
	/// Generate a random source from the specified seed.
	/// </summary>
	/// <param name="seed">The seed used to randomize the source.</param>
	/// <returns></returns>
	Source& random(unsigned int seed);
	Source& crossover(Source& src, Source& dst, int start, int length);
};

