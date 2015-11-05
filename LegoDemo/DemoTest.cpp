/*!
 * \file DemoTest.cpp
 * \date 2015/11/05
 * \author Lv Luan
 * \brief The file is used to test the correctness of function
 */

#include "CChongDevice.h"
#include "CSceneManager.h"
#include "Tank.h"

CChongDevice *g_pDempProject;
Tank *g_pTank;


//****************************************************************
// Method:    keyboard
// FullName:  keyboard
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: unsigned char key
// Parameter: int x
// Parameter: int y
// Description: The key event function of the project
//****************************************************************
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		g_pTank->ChangeMode();
		g_pDempProject->Redraw();
		break;
	case 't':
		g_pTank->RotateAxisTwo();
		g_pDempProject->Redraw();
		break;
	case 'u':
		g_pTank->UpliftAxisThree();
		g_pDempProject->Redraw();
		break;
	case 'd':
		g_pTank->LowerAxisThree();
		g_pDempProject->Redraw();
		break;
	case 'f':
		//g_pTank->RunForward();
		g_pTank->TranslateTo(1.0f, 0.0f, 0.0f);
		g_pDempProject->Redraw();
		break;
	case 'b':
		//g_pTank->RunBackward();
		g_pTank->TranslateTo(-1.0f, 0.0f, 0.0f);
		g_pDempProject->Redraw();
		break;
	case 'r':
		g_pTank->ResetPosition();
		g_pDempProject->Redraw();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void main(int argc, char *argv[])
{
	//Initial the whole project
	g_pDempProject = new CChongDevice();
	g_pDempProject->Build(argc, argv);

	//Get the scene manager of the project
	CSceneManager *demoScene = g_pDempProject->GetDemoScene();

	//initial the tank and ground object, then add them to the scene
	g_pTank = new Tank();

	demoScene->AddDemoObject(g_pTank);

	//set the key event
	g_pDempProject->SetKeyBoardEvent(keyboard);

	//loop the project and wait for the events
	g_pDempProject->DoLoop();
}