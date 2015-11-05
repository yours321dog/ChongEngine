/*!
 * \file IDemoObject.cpp
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This file is the implementation of class DemoScene, which is used to
 *		  describe what functions an object should include.
 */

#include "IBaseObject.h"
#include "GL/glew.h"

IBaseObject::IBaseObject()
{
	InitialPosition();
	InitialFactors();
}

void IBaseObject::Render()
{
	glPushMatrix();
	{
		glTranslatef(m_fTranslateFactors[0], m_fTranslateFactors[1], m_fTranslateFactors[2]);
		glScalef(m_fScaleFactors[0], m_fScaleFactors[1], m_fScaleFactors[2]);
		
		//Rotate the object with the point
		glTranslatef(m_fRotatePoint[0] - m_fOldPosition[0], m_fRotatePoint[1] - m_fOldPosition[1],
			m_fRotatePoint[2] - m_fOldPosition[2]);
		glRotatef(m_fRotateFactors[0], 1.0f, 0.0f, 0.0f);
		glRotatef(m_fRotateFactors[1], 0.0f, 1.0f, 0.0f);
		glRotatef(m_fRotateFactors[2], 0.0f, 0.0f, 1.0f);
		glTranslatef(m_fOldPosition[0] - m_fRotatePoint[0], m_fOldPosition[1] - m_fRotatePoint[1],
			m_fOldPosition[2] - m_fRotatePoint[2]);

		Draw();
	}
	glPopMatrix();
}

void IBaseObject::TranslateBy(float fTranslateX, float fTranslateY, float fTranslateZ)
{
	m_fOldPosition[0] = m_fTranslateFactors[0];
	m_fOldPosition[1] = m_fTranslateFactors[1];
	m_fOldPosition[2] = m_fTranslateFactors[2];

	m_fTranslateFactors[0] += fTranslateX;
	m_fTranslateFactors[1] += fTranslateY;
	m_fTranslateFactors[2] += fTranslateZ;
}

void IBaseObject::TranslateTo(float fTranslateX, float fTranslateY, float fTranslateZ)
{
	m_fTranslateFactors[0] = fTranslateX;
	m_fTranslateFactors[1] = fTranslateY;
	m_fTranslateFactors[2] = fTranslateZ;
}

void IBaseObject::Rotate(float fRotateAngleX, float fRotateAngleY, float fRotateAngleZ, float fRotatePointX,
	float fRotatePointY, float fRotatePointZ)
{
	m_fRotateFactors[0] += fRotateAngleX;
	m_fRotateFactors[1] += fRotateAngleY;
	m_fRotateFactors[2] += fRotateAngleZ;
}

void IBaseObject::InitialFactors()
{
	for (int i = 0; i < 3; i++)
	{
		m_fTranslateFactors[i] = 0.0f;
		m_fRotateFactors[i] = 0.0f;
		m_fScaleFactors[i] = 1.0f;
		m_fRotatePoint[i] = 0.0f;
	}
}

void IBaseObject::InitialPosition()
{
	for (int i = 0; i < 3; i++)
	{
		m_fOldPosition[i] = 0.0f;
	}
}
