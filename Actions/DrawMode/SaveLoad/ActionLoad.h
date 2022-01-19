#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
class ActionLoad : public Action
{
public:
	ActionLoad(ApplicationManager* pApp);
	void Execute();

};
