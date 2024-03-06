#include "ManagerGamePc.h"

PcConstructor* ManagerGamePc::createPc()
{
    return new GamePcConstructor;
}
