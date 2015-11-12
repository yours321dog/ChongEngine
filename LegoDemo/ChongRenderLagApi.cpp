/*!
 * \file CChongRenderLagApi.cpp
 * \date 2015/11/06
 * \author Lv Luan
 * \brief The is the implement of render interface
 */

#include "ChongRenderLagApi.h"
#include "CLightShader.h"
#include "CDeviceStatus.h"
#include "CRenderStatus.h"
#include "GL/glew.h"
#include "GL/glut.h"

void InitialDevice(i32 argc, char **argv)
{
	glutInit(&argc, argv);
}

void CreateViewWindow(i32 nWindowWidth /*= 1024*/, i32 nWindowLength /*= 768*/, i32 nWindowPosX /*= 100*/,
	i32 nWindowPosY /*= 100*/, char *sWindowName /*= "ProjectTest"*/)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(nWindowWidth, nWindowLength);
	glutInitWindowPosition(nWindowPosX, nWindowPosY);
	glutCreateWindow(sWindowName);
}

void InitalRenderEnvironment()
{
	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		exit(0);
	}

	printf("GL version: %s\n", glGetString(GL_VERSION));

	//Init the shader
	CRenderStatus::GetInstance()->GetRenderShader()->Init();
}

void InitialView(f32 fEyeAngle, f32 fZNear, f32 fZFar)
{
	CDeviceStatus::GetInstance()->SetEyeAngle(fEyeAngle);
	CDeviceStatus::GetInstance()->SetClipPlaneZNear(fZNear);
	CDeviceStatus::GetInstance()->SetClipPlaneZFar(fZFar);
}

void WindowReshape(i32 nWindowWidth, i32 nWindowHeight)
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glViewport(0, 0, (GLsizei)nWindowWidth, (GLsizei)nWindowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(CDeviceStatus::GetInstance()->GetEydAngle(), (GLfloat)nWindowWidth / (GLfloat)nWindowHeight,
		CDeviceStatus::GetInstance()->GetClipPlaneZNear(), CDeviceStatus::GetInstance()->GetClipPlaneZFar());

	//Change the value of the device status
	CDeviceStatus::GetInstance()->SetWindowWidth(nWindowWidth);
	CDeviceStatus::GetInstance()->SetWindowHeight(nWindowHeight);

	glPopAttrib();
}

void EnableWindowReshapeFunc()
{
	glutReshapeFunc(WindowReshape);
}

void SetCamera(f32 fPositionX, f32 fPositionY, f32 fPositionZ, f32 fViewpointX, f32 fViewpointY, 
	f32 fViewpointZ, f32 fTopX /*= 0.0f*/, f32 fTopY /*= 1.0f*/, f32 fTopZ /*= 0.0f*/)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(fPositionX, fPositionY, fPositionZ, fViewpointX, fViewpointY, fViewpointZ, fTopX, fTopY, fTopZ);


}

void SetDisplayFunc(void(*func)())
{
	glutDisplayFunc(func);
}

void SetKeyBoardFunc(void(*func)(unsigned char key, i32 x, i32 y))
{
	glutKeyboardFunc(func);
}

void EnableSimpleLight()
{
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void EnableSimpleDepth()
{
	glEnable(GL_DEPTH_TEST);
}

void RedisplayWindow()
{
	glutPostRedisplay();
}

void DoMainLoop()
{
	glutMainLoop();
}