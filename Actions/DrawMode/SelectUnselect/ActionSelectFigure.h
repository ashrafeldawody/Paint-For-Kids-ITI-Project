#include "..\..\Action.h"

#include"..\..\..\ApplicationManager.h"
class ActionSelectFigure : public Action
{
private:
	Point P;
	GfxInfo* SelectGfxInfo;
public:
	ActionSelectFigure(ApplicationManager* pApp);
	void Execute();
};
