/*!
 * \file CLightManager.cpp
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is the implement of CLightManager
*/

#include "CLightManager.h"

CLight *CLightManager::AddLight(CLight *pLight)
{
	//If light is already in the list, then just return it
	for (unsigned int i = 0; i < m_lights.size(); i++)
	{
		if (pLight == m_lights[i])
		{
			return pLight;
		}
	}

	pLight->Register();
	
	m_lights.push_back(pLight);
	m_lightsBuffer.push_back(pLight->GetLightCont());

	return pLight;
}

void CLightManager::RenderAllLights()
{

}
