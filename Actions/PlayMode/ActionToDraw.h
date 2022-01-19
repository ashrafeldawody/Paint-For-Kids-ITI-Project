#pragma once

#include "..\Action.h"

class ActionToDraw : public Action
{

public:
	ActionToDraw(ApplicationManager* pApp);
	void Execute();
};
