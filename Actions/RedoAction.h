#pragma once
#include "Action.h"
class RedoAction :public Action
{
private:
	Action* pCurrentA;
	int actual;
	int undoCount;
public:
	RedoAction(ApplicationManager* pApp, Action** pActList, int mUndoCount, int mActual);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void UndoFun();
	virtual void Redo();

};

