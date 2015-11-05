/*!
 * \file DemoProject.h
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This is the header of CChongDevice.cpp.
*/

#ifndef _CDEMOPROJECT_H_
#define _CDEMOPROJECT_H_

#include "CSceneManager.h"

class CChongDevice
{
public:
	//****************************************************************
	// Method:    CDemoProject
	// FullName:  CDemoProject::CDemoProject
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: int nWindowWidth The width of display window
	// Parameter: int nWindowLength The height of display window
	// Parameter: int nWindowPosX The X coordinate of left edge of window
	// Parameter: int nWindowPosY The Y coordinate of top edge of window
	// Parameter: char * sWindowName The title of display window
	// Description: The constructor of DemoProject
	//****************************************************************
	CChongDevice(int nWindowWidth = 1024, int nWindowLength = 768, int nWindowPosX = 100, 
		int nWindowPosY = 100, char *sWindowName = "ProjectTest");

	//****************************************************************
	// Method:    ~CDemoProject
	// FullName:  CDemoProject::~CDemoProject
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The destructor of DemoProject
	//****************************************************************
	~CChongDevice();

	//****************************************************************
	// Method:    Build
	// FullName:  DemoProject::Build
	// Access:    virtual public 
	// Returns:   int
	// Qualifier:
	// Description: This function is used to initial the environment 
	//				for 3D rendering
	//****************************************************************
	virtual int Build(int argc, char** argv);

	//****************************************************************
	// Method:    Draw
	// FullName:  DemoProject::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: This function is used to wait for the event
	//****************************************************************
	virtual void DoLoop();

	//****************************************************************
	// Method:    Redraw
	// FullName:  CDemoProject::Redraw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Redraw the scene in the project
	//****************************************************************
	virtual void Redraw();

	//****************************************************************
	// Method:    GetDemoScene
	// FullName:  CDemoProject::GetDemoScene
	// Access:    public 
	// Returns:   CDemoScene *
	// Qualifier:
	// Description: Return the demo scene object
	//****************************************************************
	CSceneManager *GetDemoScene();
	
	//****************************************************************
	// Method:    SetWindowSize
	// FullName:  CDemoProject::SetWindowSize
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int nWindowWidth
	// Parameter: int nWindowHeight
	// Description: Change the size of window before creation
	//****************************************************************
	void SetWindowSize(int nWindowWidth, int nWindowHeight);

	//****************************************************************
	// Method:    SetKeyBoardEvent
	// FullName:  CDemoProject::SetKeyBoardEvent
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: void
	// Parameter: * func
	// Parameter: unsigned char key
	// Parameter: int x
	// Parameter: int y
	// Description: Set the keyboard event
	//****************************************************************
	virtual void SetKeyBoardEvent(void(*func)(unsigned char key, int x, int y));

	//****************************************************************
	// Method:    SetWindowPosition
	// FullName:  CDemoProject::SetWindowPosition
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int nWindowPosX
	// Parameter: int nWindowPosY
	// Description: Change the position of window before creation
	//****************************************************************
	void SetWindowPosition(int nWindowPosX, int nWindowPosY);

	int GetWindowWidth() const { return m_nWindowWidth; }
	void SetWindowWidth(int val) { m_nWindowWidth = val; }
	
	int GetWindowHeight() const { return m_nWindowHeight; }
	void SetWindowHeight(int val) { m_nWindowHeight = val; }

	int GetWindowPosX() const { return m_nWindowPosX; }
	void SetWindowPosX(int val) { m_nWindowPosX = val; }

	int GetWindowPosY() const { return m_nWindowPosY; }
	void SetWindowPosY(int val) { m_nWindowPosY = val; }

	void SetWindowName(char * val) { m_sWindowName = val; }

	void SetCurrentProject() { sm_rCurrentProject = this; }

	//****************************************************************
	// Method:    DrawHelper
	// FullName:  CDemoProject::DrawHelper
	// Access:    public static 
	// Returns:   void
	// Qualifier:
	// Description: Help the class to callback scene draw function
	//****************************************************************
	static void DrawHelper();

private:
	int m_nWindowWidth;
	int m_nWindowHeight;
	int m_nWindowPosX;
	int m_nWindowPosY;
	char *m_sWindowName;
	CSceneManager *m_pDemoScene;
	static CChongDevice *sm_rCurrentProject;
};

#endif