/*!
 * \file DemoProject.cpp
 * \author Lv Luan
 * \date 2015/10/19
 * \brief This file is the implementation of class DemoProject, which is used to 
 *		  manager the initialization and rendering of 3D models.
 */

#include "CChongDevice.h"

#include <stdlib.h>
#include "GL/glut.h"

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5, 5, 15, 0, 0, 0, 0, 1, 0);
}

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
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(m_nWindowWidth, m_nWindowHeight);
	glutInitWindowPosition(m_nWindowPosX, m_nWindowPosY);
	glutCreateWindow(m_sWindowName);

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
		glutDisplayFunc(DrawHelper);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutReshapeFunc(reshape);

	return 0;
}

void CChongDevice::DoLoop()
{
	glutMainLoop();
}

void CChongDevice::Redraw()
{
	glutPostRedisplay();
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
	glutKeyboardFunc(func);
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
