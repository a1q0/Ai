#pragma once

#include "Source.h"

class ArtificialSelection {
public:
	Source target;
	Source source;

	int agents_count;

	ArtificialSelection();
	~ArtificialSelection();

	void train();

	
};

