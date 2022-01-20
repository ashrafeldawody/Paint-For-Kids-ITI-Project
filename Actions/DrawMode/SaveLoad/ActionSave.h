#pragma once
#include "../../Action.h"
#include<fstream>

class ActionSave : public Action
{
	GUI* pGUI;
	string FileName;
	int FigCnt;

public:
	ActionSave(ApplicationManager* pApp , int FigCount);
	void Execute();

};
