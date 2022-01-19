#pragma once

#include "..\..\Action.h"

#pragma once

#include "..\..\Action.h"

#include"..\..\..\ApplicationManager.h"
class ChangeFillColor : public Action
{
	color fillColor;
public:
	ChangeFillColor(ApplicationManager* pApp,color);
	void Execute();
};
