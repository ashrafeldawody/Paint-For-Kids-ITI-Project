#pragma once

#include "..\Action.h"

class ActionPlayByType : public Action
{

public:
	ActionPlayByType(ApplicationManager* pApp);
	void Execute();
};
