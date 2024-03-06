#include "Manager.h"

void Manager::release()
{
	PcConstructor* pc = createPc();
	pc->buildPc();
	pc->setPrice();
	pc->releasePc();
}


