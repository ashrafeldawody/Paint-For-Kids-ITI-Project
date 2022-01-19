#pragma once

#include "..\..\Action.h"

#pragma once

#include "..\..\Action.h"

#include"..\..\..\ApplicationManager.h"
class ChangeDrawColor : public Action
{
	color drawColor;
public:
	ChangeDrawColor(ApplicationManager* pApp,color);
	void Execute();
};
