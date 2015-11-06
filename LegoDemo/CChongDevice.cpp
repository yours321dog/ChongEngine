/*!
 * \file DemoProject.cpp
 * \author Lv Luan
 * \date 2015/10/19
 * \brief This file is the implementation of class DemoProject, which is used to 
 *		  manager the initialization and rendering of 3D models.
 */

#include "CChongDevice.h"
#include "CChongRenderLagApi.h"

using namespace cho::core;

//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(5, 5, 15, 0, 0, 0, 0, 1, 0);
//}

CChongDevice *CChongDevice::sm_rCurrentProject = NULL;

CChongDevice::CChongDevice(int nWindowWidth /*= 1024*/, int nWindowLength /*= 768*/, int nWindowPosX /*= 100*/,
	int nWindowPosY /*= 100*/, char *sWindowName /*= "ProjectTest"*/)
	:m_nWindowWidth(nWindowWidth),
	m_nWindowHeight(nWindowLength),
	m_nWindowPosX(nWindowPosX), 
	m_nWindowPosY(nWindowPosY),
	m_sWindowName(sWindowName)
{

}

CChongDevice::~CChongDevice()
{
}

int CChongDevice::Build(int argc, char** argv)
{
	InitialDevice(argc, argv);
	CreateViewWindow();

	//GLenum res = glewInit();
	//if (res != GLEW_OK) {
	//	fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
	//	return res;
	//}

	//If the demo scene hasn't been created, just create it
	if (m_pDemoScene == NULL)
	{
		m_pDemoScene = new CSceneManager();
	}

	if (m_pDemoScene != NULL)
	{
		SetCurrentProject();
		SetDisplayFunc(DrawHelper);
	}

	EnableSimpleDepth();
	EnableSimpleLight();

	EnableWindowReshapeFunc();

	SetCamera(5, 5, 15, 0, 0, 0, 0, 1, 0);

	return 0;
}

void CChongDevice::DoLoop()
{
	DoMainLoop();
}

void CChongDevice::Redraw()
{
	RedisplayWindow();
}

CSceneManager * CChongDevice::GetDemoScene()
{
	return m_pDemoScene;
}

void CChongDevice::SetWindowSize(int nWindowWidth, int nWindowHeight)
{
	SetWindowWidth(nWindowWidth);
	SetWindowHeight(nWindowHeight);
}

void CChongDevice::SetKeyBoardEvent(void(*func)(unsigned char key, int x, int y))
{
	SetKeyBoardFunc(func);
}

void CChongDevice::SetWindowPosition(int nWindowPosX, int nWindowPosY)
{
	SetWindowPosX(nWindowPosX);
	SetWindowPosY(nWindowPosY);
}

void CChongDevice::DrawHelper()
{
	sm_rCurrentProject->m_pDemoScene->Draw();
}
