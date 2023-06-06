#include "RedoAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
/*

RedoAction::RedoAction(ApplicationManager* pApp, Action** pActList, int mUndoCount, int mActual) :Action(pApp)
{
	UI.beginrec = false;
	actual = mActual;
	undoCount = mUndoCount;
	pCurrentA = (pActList[mActual - mUndoCount-1]);
}

void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	if (undoCount >= 0)
		pCurrentA->Redo();
	if (pManager->IsRecord())
		pManager->addrecord(this);

}

void RedoAction::UndoFun()
{
}

void RedoAction::Redo()
{
}


*/