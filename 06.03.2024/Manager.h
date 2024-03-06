#pragma once
#include "PcConstructor.h"
class Manager
{
public:
	void release();
private:
	virtual PcConstructor* createPc()=0;
};

