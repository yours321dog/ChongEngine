/*!
 * \file CLight.cpp
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is the implement of CLight
*/
#include "CLight.h"

CLight::CLight()
{

}

CLight::~CLight()
{

}

void CLight::Draw()
{

}

void CLight::TranslateBy(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ)
{
	m_light.position += Vector3f(fTranslateX, fTranslateY, fTranslateZ);
}

void CLight::TranslateTo(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ)
{
	m_light.position = Vector3f(fTranslateX, fTranslateY, fTranslateZ);
}

Light & CLight::GetLightCont()
{
	return m_light;
}

void CLight::SetColor(f32 fColorX, f32 fColorY, f32 fColorZ)
{
	m_light.color = Vector3f(fColorX, fColorY, fColorZ);
}

void CLight::SetDirection(f32 fDirectionX, f32 fDirectionY, f32 fDirectionZ)
{
	m_light.color = Vector3f(fDirectionX, fDirectionY, fDirectionZ);
}

void CLight::SetAttenuation(f32 fConstant, f32 fLinear, f32 fExp)
{
	m_light.atten.constant = fConstant;
	m_light.atten.linear = fLinear;
	m_light.atten.exp = fExp;
}

void CLight::SetCutoff(f32 cutoff)
{
	m_light.cutoff = cutoff;
}
