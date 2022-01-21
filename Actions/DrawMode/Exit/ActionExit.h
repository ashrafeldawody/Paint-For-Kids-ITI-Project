#pragma once
#include "../../Action.h"
#include "../../../ApplicationManager.h"
#include"../SaveLoad/ActionSave.h"
class ActionExit : public Action
{
public:
	ActionExit(ApplicationManager* pApp);
	void Execute();
};

