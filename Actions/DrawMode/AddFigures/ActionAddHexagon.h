#pragma once
#include "..\..\Action.h"
#include "..\..\..\Figures\CHexagon.h"

class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	void Execute();


};
