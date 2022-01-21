#include "ApplicationManager.h"

#include "Actions/DrawMode/AddFigures/ActionAddSquare.h"
#include "Actions/DrawMode/AddFigures/ActionAddEllipse.h"
#include "Actions/DrawMode/AddFigures/ActionAddHexagon.h"

#include "Actions/DrawMode/SelectUnselect/ActionSelectFigure.h"
#include "Actions/DrawMode/ChangeColors/ChangeBGColor.h"
#include "Actions/DrawMode/ChangeColors/ChangeDrawColor.h"
#include "Actions/DrawMode/ChangeColors/ChangeFillColor.h"
#include "Actions/DrawMode/Resize/ActionResizeSelected.h"
#include "Actions/DrawMode/Delete/ActionDeleteSelected.h"
#include "Actions/DrawMode/SendBackBringFront/ActionBringFront.h"
#include "Actions/DrawMode/SendBackBringFront/ActionSendBack.h"
#include "Actions/DrawMode/SaveLoad/ActionLoad.h"
#include "Actions/DrawMode/SaveLoad/ActionSave.h"
#include "Actions/DrawMode/ActionToPlay.h"
#include "Actions/DrawMode/Exit/ActionExit.h"

#include "Actions/PlayMode/ActionPlayByFill.h"
#include "Actions/PlayMode/ActionPlayByType.h"
#include "Actions/PlayMode/ActionPlayByFILLTYPE.h"
#include "Actions/PlayMode/ActionToDraw.h"
#include "Actions/PlayMode/ActionNewGame.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		FigListBackup[i] = NULL;
	}


}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	} while (ActType != EXIT);
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		//draw actions
		case ACTION_DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		case ACTION_DRAW_ELLIPSE:
			newAct = new ActionAddEllipse(this);
			break;
		case ACTION_DRAW_HEXAGON:
			newAct = new ActionAddHexagon(this);
			break;

		//toolbar main actions
		case ACTION_SELECT:
			newAct = new ActionSelectFigure(this);
			
			break;
		case ACTION_CHNG_BG_CLR:
			pGUI->CreateBGColorToolBar();
			break;
		case ACTION_CHNG_DRAW_CLR:
			pGUI->CreateDrawColorToolBar();
			break;
		case ACTION_CHNG_FILL_CLR:
			pGUI->CreateFillColorToolBar();
			break;
		case ACTION_RESIZE:
			pGUI->CreateResizeToolBar();
			break;
		case ACTION_DELETE:
			newAct = new ActionDeleteSelected(this);
			break;
		case ACTION_SEND_BACK:
			newAct = new ActionSendBack(this);
			break;
		case ACTION_BRNG_FRNT:
			newAct = new ActionBringFront(this);
			break;
		case ACTION_SAVE:
			if (FigCount == 0 && Helpers::getColorName(UI.BkGrndColor) == "LIGHTGOLDENRODYELLOW")
				pGUI->PrintMessage("You must first make some changes in order to save them");
			else
				newAct = new ActionSave(this, FigCount);
			break;
		case ACTION_LOAD:
			newAct = new ActionLoad(this);
			break;


		//Draw Colors
		case ACTION_DRAW_BLACK:
			newAct = new ChangeDrawColor(this, BLACK);
			break;
		case ACTION_DRAW_RED:
			newAct = new ChangeDrawColor(this, DARKCYAN);
			break;
		case ACTION_DRAW_CHOCOLATE:
			newAct = new ChangeDrawColor(this, CHOCOLATE);
			break;
		case ACTION_DRAW_DARKGOLDENROD:
			newAct = new ChangeDrawColor(this, DARKGOLDENROD);
			break;
		case ACTION_DRAW_DARKRED:
			newAct = new ChangeDrawColor(this, DARKRED);
			break;
		case ACTION_DRAW_DEEPPINK:
			newAct = new ChangeDrawColor(this, DEEPPINK);
			break;
		case ACTION_DRAW_OLIVEDRAB:
			newAct = new ChangeDrawColor(this, OLIVEDRAB);
			break;

		//Fill Colors
		case ACTION_FILL_NONE:
			newAct = new ChangeFillColor(this, NULL);
			break;
		case ACTION_FILL_DARKCYAN:
			newAct = new ChangeFillColor(this, DARKCYAN);
			break;
		case ACTION_FILL_DARKMAGENTA:
			newAct = new ChangeFillColor(this, DARKMAGENTA);
			break;
		case ACTION_FILL_GREEN:
			newAct = new ChangeFillColor(this, GREEN);
			break;
		case ACTION_FILL_HOTPINK:
			newAct = new ChangeFillColor(this, HOTPINK);
			break;
		case ACTION_FILL_INDIAN:
			newAct = new ChangeFillColor(this, INDIAN);
			break;
		case ACTION_FILL_LIGHTCORAL:
			newAct = new ChangeFillColor(this, LIGHTCORAL);
			break;
		case ACTION_FILL_PERU:
			newAct = new ChangeFillColor(this, PERU);
			break;
		case ACTION_FILL_SIENNA:
			newAct = new ChangeFillColor(this, SIENNA);
			break;
		case ACTION_FILL_SPRINGGREEN:
			newAct = new ChangeFillColor(this, SPRINGGREEN);
			break;
		case ACTION_FILL_TOMATO:
			newAct = new ChangeFillColor(this, TOMATO);
			break;

		//BG COLORS
		case ACTION_BG_BURLYWOOD:
			newAct = new ChangeBGColor(this, BURLYWOOD);
			break;
		case ACTION_BG_LIGHTGREEN:
			newAct = new ChangeBGColor(this, LIGHTGREEN);
			break;
		case ACTION_BG_LIGHTYELLOW:
			newAct = new ChangeBGColor(this, LIGHTYELLOW);
			break;
		case ACTION_BG_THISTLE:
			newAct = new ChangeBGColor(this, THISTLE);
			break;
		case ACTION_BG_WHEAT:
			newAct = new ChangeBGColor(this, WHEAT);
			break;	

		//resize
		case ACTION_QUARTAR:
			newAct = new ActionResizeSelected(this, 0.25);
			break;
		case ACTION_HALF:
			newAct = new ActionResizeSelected(this, 0.5);
			break;
		case ACTION_DOUBLE:
			newAct = new ActionResizeSelected(this, 2);
			break;
		case ACTION_2DOUBLE:
			newAct = new ActionResizeSelected(this, 4);
			break;


		case ACTION_TO_PLAY:
			newAct = new ActionToPlay(this);
			break;

		//play mode
		case ACTION_PLAY_FILL:
			newAct = new ActionPlayByFill(this);
			break;
		case ACTION_PLAY_TYPE:
			newAct = new ActionPlayByType(this);
			break;
		case ACTION_PLAY_TYPEFILL:
			newAct = new ActionPlayByFILLTYPE(this);
			break;
		case ACTION_TO_DRAW:
			newAct = new ActionToDraw(this);
			break;
		case ACTION_PLAY_RESET:
			newAct = new ActionNewGame(this);
			break;
		case EXIT:
			if (FigCount != 0 || Helpers::getColorName(UI.BkGrndColor) != "LIGHTGOLDENRODYELLOW")
				newAct = new ActionExit(this);
				
			break;

		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}

//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		pFig->SetID(FigCount + 1);
		FigList[FigCount++] = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->PointInFigure(x, y))
		{
			string shapeData = FigList[i]->GetShapeInfo();
			pGUI->PrintMessage(shapeData);
			return FigList[i];
		}
	return NULL;
}
void ApplicationManager::UnselectAll() {
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetSelected(false);		//Call Draw function (virtual member fn)
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pGUI->ClearDrawArea();
	for(int i=0; i<FigCount; i++){
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{
	return pGUI; 
}

CFigure* ApplicationManager::getSelected() const
{
	int index = getSelectedIndex();
	if (index >= 0)
		return FigList[index];
	return NULL;
}
int ApplicationManager::getSelectedIndex() const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}

void ApplicationManager::figListStringArray(string strList[])
{
	for (int i = 0; i < FigCount; i++)
	{
		strList[i] = "";
	}
}
//==================================================================================//
//							Bring To Front											//
//==================================================================================//

void ApplicationManager::BringToFront(int selectedIndex)
{
	if (selectedIndex != FigCount - 1)
	{
		CFigure* spare = FigList[FigCount - 1];
		FigList[FigCount - 1] = FigList[selectedIndex];
		FigList[selectedIndex] = spare;
	}
}

//==================================================================================//
//							Send To Back											//
//==================================================================================//

void ApplicationManager::SendToBack(int selectedIndex) 
{
	if (selectedIndex != 0)
	{
		CFigure * spare = FigList[0];
		FigList[0] = FigList[selectedIndex];
		FigList[selectedIndex] = spare;
	}
}


//==================================================================================//
//									Play Mode										//
//==================================================================================//
void ApplicationManager::backupFigList()
{
	for (int i = 0; i < FigCount; i++){
		FigListBackup[i] = FigList[i]->Clone();
	}
	FigCountBackup = FigCount;
}
void ApplicationManager::restoreFigList()
{
	for (int i = 0; i < FigCountBackup; i++){
		FigList[i] = FigListBackup[i]->Clone();
	}
	FigCount = FigCountBackup;
	UpdateInterface();

}

void ApplicationManager::clearFigListBackup() {
	for (int i = 0; i < FigCountBackup; i++){
		delete FigListBackup[i];
	}
	FigCountBackup = 0;

}
int ApplicationManager::numberOfShapes()
{
	return FigCount;
}
int ApplicationManager::countByColor(string color){
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getFillColor() == Helpers::getColorFromString(color))
			count++;
	return count;
}
int ApplicationManager::countByType(string type) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getShapeType() == type)
			count++;
	return count;
}
int ApplicationManager::countByTypeAndColor(string type,string color) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getShapeType() == type && FigList[i]->getFillColor() == Helpers::getColorFromString(color))
			count++;
	return count;
}

string ApplicationManager::getRandomExistingColor()
{
	//generating Random index 
	int RandomIndex = rand() % FigCount;

	color tempClr = FigList[RandomIndex]->getFillColor();

	return Helpers::getColorName(tempClr);

}
string ApplicationManager::getRandomExistingType()
{
	//generating Random index 
	int RandomIndex = rand() % FigCount;
	return FigList[RandomIndex]->getShapeType();
}
void ApplicationManager::getRandomColorAndType(string &type,string &color)
{
	//generating Random index 
	int RandomIndex = rand() % FigCount;
	type = FigList[RandomIndex]->getShapeType();
	color = Helpers::getColorName(FigList[RandomIndex]->getFillColor());
}


//==================================================================================//
//							For Single Figure Deleted								//
//==================================================================================//
void ApplicationManager::singleFigureDeleted()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			shiftFigList(i);
			break;
		}
	}
}


//==================================================================================//
//			  to shift all next item in FigList and remove null items				//
//==================================================================================//
void ApplicationManager::shiftFigList(int _figCount)
{
	for (int j = _figCount; j < FigCount; j++)
	{
		FigList[j] = FigList[j + 1];
	}
}


//==================================================================================//
//				     	Call the Save function for each Figure						//
//==================================================================================//
void ApplicationManager::SaveFig(ofstream& Out)   
{
	for (int i = 0; i < FigCount; ++i)
		FigList[i]->Save(Out);
}


//==================================================================================//
//			  		for each figure FigList, make it points to NULL					//
//==================================================================================//
void ApplicationManager::LoadFig()  
{
	for (int i = 0; i < FigCount; ++i)
		FigList[i] = NULL;
		FigCount = 0;
}


//==================================================================================//
//			  						Destructor										//
//==================================================================================//
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		delete FigListBackup[i];
	}
	delete pGUI;
}