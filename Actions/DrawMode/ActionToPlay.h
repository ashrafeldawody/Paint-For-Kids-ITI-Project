#pragma once

#include "..\Action.h"

class ActionToPlay : public Action
{

public:
	ActionToPlay(ApplicationManager* pApp);
	void Execute();
};
