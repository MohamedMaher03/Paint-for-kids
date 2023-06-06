#pragma once
#include "Action.h"
class Undo :public Action{
private:
	Action* pCurrentA;
	int actual;
	int undoCount;

public:
	Undo(ApplicationManager* pApp, Action** pActList, int mUndoCount, int mActual);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void UndoFun();
	virtual void Redo();
};

