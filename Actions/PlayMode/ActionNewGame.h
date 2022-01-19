#pragma once

#include "..\Action.h"

class ActionNewGame : public Action
{

public:
	ActionNewGame(ApplicationManager* pApp);
	void Execute();
};
