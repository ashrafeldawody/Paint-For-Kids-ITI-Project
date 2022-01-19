#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
class ActionBringFront : public Action
{
public:
	ActionBringFront(ApplicationManager* pApp);
	void Execute();

};
