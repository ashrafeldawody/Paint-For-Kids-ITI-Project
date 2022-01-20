#include "ActionSave.h"


ActionSave::ActionSave(ApplicationManager* pApp, int FigCount):Action(pApp)
{
	pGUI = pManager->GetGUI();
	FileName = "TEST";
	FigCnt = FigCount;    //We need the figure number to write it on the file
}

void ActionSave::Execute()
{
	pGUI->PrintMessage("Please write the file name then press ENTER");
	FileName = pGUI->GetString(pGUI);  //read the file name

	ofstream OutFile;   //object of ofstream to write on the disk
	OutFile.open(FileName + ".txt");  // to create it as a file with extension .txt
	bool flag = false;
	if (OutFile.fail()) //Check the FileName and loop till be Valid name
		flag = true;
	while (flag)
	{
		pGUI->PrintMessage("Please write a valid name then press ENTER");
		FileName = pGUI->GetString(pGUI);
		OutFile.open(FileName + ".txt");	
		if (OutFile.good())
			flag = false;
	}

	//To change the color from Enum color to String Color
	string BkGrndColor = Helpers::getColorName(UI.BkGrndColor);	 //for UI background color
	string DrawColor = Helpers::getColorName(UI.DrawColor);		 //for UI Drawing color
	string fillColor = Helpers::getColorName(UI.FillColor);		 //for UI Filling color

	OutFile << BkGrndColor << "\t" << DrawColor << "\t" << fillColor << "\n";  //Write the Current Draw Color 
	OutFile << FigCnt << "\n";  //and Current Fill Color and in the second line write the number of figures 
	pManager->SaveFig(OutFile);  //Now Start Saving each figure proccess 
	pGUI->PrintMessage("Saved Successfully");  
	OutFile.close(); 
}
