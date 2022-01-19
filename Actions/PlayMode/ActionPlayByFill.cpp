#include "ActionPlayByFill.h"

ActionPlayByFill::ActionPlayByFill(ApplicationManager* pApp):Action(pApp)
{
	correct = wrong = 0;
}

void ActionPlayByFill::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pManager->backupFigList();
	if(pManager->numberOfShapes() > 0) {
		string color = pManager->getRandomExistingColor();
		int numberOfShapesOfColor = pManager->countByFillColor(color);

		pGUI->PrintMessage("Pick All "+ color + " Shapes" + to_string(numberOfShapesOfColor));
		for (int i = 0; i < numberOfShapesOfColor; i++) {
			int x, y;
			pGUI->getPointInsideDrawArea(x,y);
			CFigure* fig = pManager->GetFigure(x, y);
			while (fig == NULL) {
				pGUI->PrintMessage("No Shape Found, Please Click on shape");
				pGUI->getPointInsideDrawArea(x, y);
				fig = pManager->GetFigure(x, y);
			}
			if (fig != NULL && Helpers::getColorName(fig->getFillColor()) == color) {
				correct++;
				//delete figure on click
				pManager->UnselectAll();
				fig->SetSelected(true);
				pManager->singleFigureDeleted();
				pManager->UpdateInterface();
			}
			else {
				wrong++;
			}
			pGUI->PrintMessage("Correct: "+ to_string(correct) + " || Wrong:" + to_string(wrong));
		}
	}
	else {
		pGUI->PrintMessage("There is no shapes");
	}
	if (correct > wrong) {
		pGUI->PrintMessage("You Won ^_^");
	}
	else {
		pGUI->PrintMessage("You Lost :(");
	}
}
