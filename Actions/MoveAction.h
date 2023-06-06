#pragma once
#include "Action.h"
class MoveAction : public Action
{
private:
	Point P1;// point that user click on draw area 
	int diffX; //distance moved in x direction
	int diffY; //distance moved in y direction
public:
	MoveAction(ApplicationManager* pApp);

	//Reads move parameters
	virtual void ReadActionParameters();


	virtual void Execute();

};



