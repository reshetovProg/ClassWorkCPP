#pragma once
#include "Manager.h"
#include "OfficePcConstructor.h"
class ManagerOfficePc : public Manager
{
public:
	PcConstructor* createPc();
};

