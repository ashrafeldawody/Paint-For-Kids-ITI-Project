#pragma once

#include "..\Action.h"

class ActionPlayByType : public Action
{
	int correct;
	int wrong;
public:
	ActionPlayByType(ApplicationManager* pApp);
	void Execute();
};
