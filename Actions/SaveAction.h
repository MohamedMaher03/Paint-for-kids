#pragma once
#include "Action.h"
class SaveAction :
    public Action
{
    string FileName;
	
public:
	SaveAction(ApplicationManager* pApp ); //Reads select parameters
	
	virtual void ReadActionParameters();


	virtual void Execute();

	~SaveAction();
};

