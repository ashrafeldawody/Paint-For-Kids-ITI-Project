#pragma once
#include "..\..\Action.h"
#include "..\..\..\Figures\CEllipse.h"

//Add Square Action class
class ActionAddEllipse: public Action
{
public:
	ActionAddEllipse(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	void Execute();

	
};
