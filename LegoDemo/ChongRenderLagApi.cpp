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

	PersProjInfo persProjInfo;
	persProjInfo.FOV = fEyeAngle;
	persProjInfo.zNear = fZNear;
	persProjInfo.zFar = fZFar;
	persProjInfo.height = CDeviceStatus::GetInstance()->GetWindowHeight();
	persProjInfo.wdth = CDeviceStatus::GetInstance()->GetWindowWidth();
	CRenderStatus::GetInstance()->GetPipeline()->SetPerspectiveProj(persProjInfo);
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

	CPipeline *pPipeline = CRenderStatus::GetInstance()->GetPipeline();
	pPipeline->SetCamera(Vector3f(fPositionX, fPositionY, fPositionZ), Vector3f(fViewpointX, fViewpointY, fViewpointZ),
		Vector3f(fTopX, fTopY, fTopZ));
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

void SetCurrentObjectTran(const Matrix4f &matObjectTransform)
{
	CRenderStatus::GetInstance()->SetObjectTransform(matObjectTransform);
}

void GetUniqueObjectID(const i32 &nObjectType, ui32 *pObjectID)
{
	switch (nObjectType)
	{
	case OBJECT_TYPE_COMMON:
		glGenBuffers(2, pObjectID);
		break;
	case OBJECT_TYPE_LIGHT:
		pObjectID[0] = pObjectID[1] = 1 + OBJECT_NUM_EACH_TYPE * OBJECT_TYPE_LIGHT;
		break;
	}
}

void RenderLights(i32 nNumLight, const Light *pLight)
{
	CRenderStatus::GetInstance()->GetRenderShader()->SetLights(nNumLight, pLight);
}

void StoreOjectVertex(ui32 *pObjectID, const i32 nVerticesCount, const Vertex *pVertices,
	const i32 nIndicesCount, const ui32 *pIndices)
{
	glBindBuffer(GL_ARRAY_BUFFER, pObjectID[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pVertices)* nVerticesCount, pVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pObjectID[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nIndicesCount * sizeof(ui32), pIndices, GL_STATIC_DRAW);
}

void RenderVertexObject(ui32 *pObjectID, const i32 nTrianglesCount, const ui32 nStartIndex)
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, pObjectID[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pObjectID[1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

	glDrawElements(GL_TRIANGLES, nTrianglesCount * 3, GL_UNSIGNED_INT, (void *)(sizeof(GLuint) * nStartIndex));

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void DrawALLInScene()
{
	glutSwapBuffers();
}

void BeforeDrawAllInScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
}
