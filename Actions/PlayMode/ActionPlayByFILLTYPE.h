#pragma once

#include "..\Action.h"

class ActionPlayByFILLTYPE : public Action
{

public:
	ActionPlayByFILLTYPE(ApplicationManager* pApp);
	void Execute();
};
