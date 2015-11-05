/*!
 * \file CDemoScene.cpp
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This file is the implementation of class DemoScene, which is used to
 *		  control creation and option of 3D models.
*/

#include "CSceneManager.h"
#include "GL/glew.h"
#include "GL/glut.h"

CSceneManager::CSceneManager()
{

}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	for (unsigned int i = 0; i < m_vDemoObjects.size(); i++)
	{
		m_vDemoObjects[i]->Render();
	}

	glutSwapBuffers();
}

IBaseObject * CSceneManager::AddDemoObject(IBaseObject * demoObject)
{
	//If demoObject is already in the list, then just return it
	for (unsigned int i = 0; i < m_vDemoObjects.size(); i++)
	{
		if (demoObject == m_vDemoObjects[i])
		{
			return demoObject;
		}
	}

	//Otherwise, put it in the demo object list
	m_vDemoObjects.push_back(demoObject);

	return demoObject;
}

