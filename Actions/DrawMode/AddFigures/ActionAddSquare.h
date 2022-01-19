#pragma once
#include "..\..\Action.h"
#include "..\..\..\Figures\CSquare.h"
//Add Square Action class
class ActionAddSquare: public Action
{
public:
	ActionAddSquare(ApplicationManager *pApp);
	
	//Add Square to the ApplicationManager
	void Execute() ;
	
};
