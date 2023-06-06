#pragma once
#include "Action.h"
class LoadAction :public Action
{
	string FileName;
public:
	LoadAction(ApplicationManager* pApp ); //Reads select parameters
	
	virtual void ReadActionParameters();
	virtual void UndoFun() {};
	virtual void Redo() {};

	virtual void Execute();
};

