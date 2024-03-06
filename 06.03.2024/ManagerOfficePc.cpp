#include "ManagerOfficePc.h"

PcConstructor* ManagerOfficePc::createPc()
{
    return new OfficePcConstructor;
}
