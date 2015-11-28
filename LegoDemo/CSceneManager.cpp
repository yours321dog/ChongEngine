/*!
 * \file CDemoScene.cpp
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This file is the implementation of class DemoScene, which is used to
 *		  control creation and option of 3D models.
*/

#include "CSceneManager.h"
#include "ChongRenderLagApi.h"

CSceneManager::CSceneManager()
{

}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Draw()
{
	BeforeDrawAllInScene();

	

	for (unsigned int i = 0; i < m_listCommonObjects.size(); i++)
	{
		m_listCommonObjects[i]->Render();
	}

	DrawALLInScene();
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

ICommonObject * CSceneManager::AddCommonObject(ICommonObject *pCommonObject)
{
	//If demoObject is already in the list, then just return it
	for (unsigned int i = 0; i < m_vDemoObjects.size(); i++)
	{
		if (pCommonObject == m_listCommonObjects[i])
		{
			return pCommonObject;
		}
	}

	//Otherwise, put it in the demo object list
	m_listCommonObjects.push_back(pCommonObject);

	if (pCommonObject->Register())
	{
		pCommonObject->Load();
	}

	return pCommonObject;
}

CLight * CSceneManager::AddLightObject(CLight *pLight)
{
	return m_lightManager.AddLight(pLight);
}

