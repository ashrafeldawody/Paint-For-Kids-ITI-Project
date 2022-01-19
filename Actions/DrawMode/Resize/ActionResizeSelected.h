#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
class ActionResizeSelected : public Action
{
	float resizeFactor;
public:
	ActionResizeSelected(ApplicationManager* pApp, float);
	void Execute();

};
