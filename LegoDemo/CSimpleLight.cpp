/*!
 * \file CSimpleLight.cpp
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is the implement of CSimpleLight
 */

#include "CSimpleLight.h"
#include "limits.h"

CSimpleLight::CSimpleLight()
{
	m_light.color = Vector3f(1.0, 1.0, 1.0);
	m_light.cutoff = 180;
	m_light.direction = Vector3f(0.0, 0.0, -1.0);
	m_light.position = m_light.direction * INT_MAX;
	m_light.atten.constant = 1.0;
	m_light.atten.linear = 0.0;
	m_light.atten.exp = 0.0;
}

CSimpleLight::~CSimpleLight()
{

}

void CSimpleLight::BeforeDraw()
{
	m_light.color = Vector3f(1.0, 1.0, 1.0);
	m_light.cutoff = 180;
	m_light.position = m_light.direction * INT_MAX;
	m_light.atten.constant = 1.0;
	m_light.atten.linear = 0.0;
	m_light.atten.exp = 0.0;
}
