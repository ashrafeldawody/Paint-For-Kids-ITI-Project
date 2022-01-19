#pragma once

#include "..\..\Action.h"

#include"..\..\..\ApplicationManager.h"
class ChangeBGColor : public Action
{
	color bgColor;
public:
	ChangeBGColor(ApplicationManager* pApp,color);
	void Execute();
};
