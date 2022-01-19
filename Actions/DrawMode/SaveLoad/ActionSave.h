#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
class ActionSave : public Action
{
public:
	ActionSave(ApplicationManager* pApp);
	void Execute();

};
