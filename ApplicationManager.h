#pragma once
#include "DEFS.h"
#include "Figures/CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures


private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	int FigCountBackup;		//Actual number of figures
	CFigure* FigListBackup[MaxFigCount];	//Clone version of FigList (Array of pointers)
	
	//Pointers to Input and Output classes
	GUI* pGUI;

public:	
	ApplicationManager(); 
	string getRandomExistingColor();
	~ApplicationManager();


	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	Action* ColorAction(color);
	Action* ResizeAction(float factor);
	void ExecuteAction(Action*&) ; //Execute an action
	//actions
	//get figure if clicked point was inside it
	CFigure* GetFigure(int, int) const;
	CFigure* getSelected() const;
	int getSelectedIndex() const;
	void UnselectAll();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window

	

	// -- For Single Figure Delete
	void singleFigureDeleted();
	void shiftFigList(int _figCount);

	// -- figList to array of strings
	void figListStringArray(string[]);

	void BringToFront(int);
	void SendToBack(int);


	//play mode
	void backupFigList();
	void restoreFigList();
	void clearFigListBackup();
	int numberOfShapes();
	int countByFillColor(string color);
};
