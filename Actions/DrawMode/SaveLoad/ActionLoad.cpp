#include "ActionLoad.h"


ActionLoad::ActionLoad(ApplicationManager* pApp):Action(pApp)
{
	pGUI = pManager->GetGUI();
}

void ActionLoad::Execute()
{
	ifstream InFile;         //object of ifstream class
	bool flag = false;
	string name, BkGrndColor ,DrawClr, FillClr;
	int counter;
	CFigure* figure;

	pGUI->PrintMessage("Please write the file name : ");
	FileName = pGUI->GetString(pGUI);  //read the file name

	InFile.open(FileName + ".txt"); //open the file on the disk with FileName name and .txt exetension
	pGUI->ClearDrawArea();    //Clear current graph

	if (InFile.fail())       //Check if the FileName is a valid name
	{
		pGUI->PrintMessage("Invalid Name");
		return;
	}

	InFile >> BkGrndColor >> DrawClr >> FillClr;     //Read the Current FillColor and DrawColor
	//to Convert color from String color to Enum Color
	UI.BkGrndColor = Helpers::getColorFromString(BkGrndColor);  
	UI.DrawColor = Helpers::getColorFromString(DrawClr);		
	UI.FillColor = Helpers::getColorFromString(FillClr);		

	pManager->LoadFig();        //Delete The figure list
	InFile >> counter;    //read the Number of Figures
	while (counter)            //For each line on the file we will read it and determine its type
	{
		InFile >> name;	//to get name of figure

		if (name == "Square")
			figure = new CSquare;
		else if (name == "Ellipse")
			figure = new CEllipse;
		else if (name == "Hexagon")
			figure = new CHexagon;
		
		figure->Load(InFile);  //Now we created the object and we should load it
		pManager->AddFigure(figure); //Add to the figure list
		counter--; //decrease the count 
	}
	pManager->UpdateInterface();     //Draw the figure list
	pGUI->PrintMessage("Graph Loaded Successfully");
	pGUI->ClearStatusBar();
	pGUI->CreateStatusBar();

}
