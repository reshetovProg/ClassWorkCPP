#pragma once
#include "Manager.h"
#include "GamePcConstructor.h"
class ManagerGamePc: public Manager
{
public:
	PcConstructor* createPc();
};

