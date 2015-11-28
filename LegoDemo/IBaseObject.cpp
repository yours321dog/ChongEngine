/*!
 * \file IDemoObject.cpp
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This file is the implementation of class DemoScene, which is used to
 *		  describe what functions an object should include.
 */

#include "IBaseObject.h"
#include "ChongRenderLagApi.h"
#include "GL/glew.h"

IBaseObject::IBaseObject()
:m_vecScale(1.0),
m_bIsRegisted(false)
{
	InitialPosition();
	InitialFactors();
	m_matTRTransform.InitIdentity();
}

void IBaseObject::Render()
{
	//glPushMatrix();
	//{
	//	glTranslatef(m_fTranslateFactors[0], m_fTranslateFactors[1], m_fTranslateFactors[2]);
	//	glScalef(m_fScaleFactors[0], m_fScaleFactors[1], m_fScaleFactors[2]);
	//	
	//	//Rotate the object with the point
	//	glTranslatef(m_fRotatePoint[0] - m_fOldPosition[0], m_fRotatePoint[1] - m_fOldPosition[1],
	//		m_fRotatePoint[2] - m_fOldPosition[2]);
	//	glRotatef(m_fRotateFactors[0], 1.0f, 0.0f, 0.0f);
	//	glRotatef(m_fRotateFactors[1], 0.0f, 1.0f, 0.0f);
	//	glRotatef(m_fRotateFactors[2], 0.0f, 0.0f, 1.0f);
	//	glTranslatef(m_fOldPosition[0] - m_fRotatePoint[0], m_fOldPosition[1] - m_fRotatePoint[1],
	//		m_fOldPosition[2] - m_fRotatePoint[2]);

	//	Draw();
	//}
	//glPopMatrix();

	BeforeDraw();

	Draw();

	AfterDraw();
}

void IBaseObject::TranslateBy(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ)
{
	//m_fOldPosition[0] = m_fTranslateFactors[0];
	//m_fOldPosition[1] = m_fTranslateFactors[1];
	//m_fOldPosition[2] = m_fTranslateFactors[2];

	//m_fTranslateFactors[0] += fTranslateX;
	//m_fTranslateFactors[1] += fTranslateY;
	//m_fTranslateFactors[2] += fTranslateZ;

	Matrix4f transform;
	transform.InitTranslationTransform(fTranslateX, fTranslateY, fTranslateZ);
	m_matTRTransform = transform * m_matTRTransform;

	m_vecWorldPosition.x += fTranslateX;
	m_vecWorldPosition.y += fTranslateY;
	m_vecWorldPosition.z += fTranslateZ;
}

void IBaseObject::TranslateTo(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ)
{
	//m_fTranslateFactors[0] = fTranslateX;
	//m_fTranslateFactors[1] = fTranslateY;
	//m_fTranslateFactors[2] = fTranslateZ;

	Matrix4f transform;
	transform.InitTranslationTransform(fTranslateX - m_vecWorldPosition.x, fTranslateY - m_vecWorldPosition.y,
		fTranslateZ - m_vecWorldPosition.z);
	m_matTRTransform = transform * m_matTRTransform;

	m_vecWorldPosition.x = fTranslateX;
	m_vecWorldPosition.y = fTranslateY;
	m_vecWorldPosition.z = fTranslateZ;
}

void IBaseObject::Rotate(f32 fRotateAngleX, f32 fRotateAngleY, f32 fRotateAngleZ, f32 fRotatePointX,
	f32 fRotatePointY, f32 fRotatePointZ)
{
	//m_fRotateFactors[0] += fRotateAngleX;
	//m_fRotateFactors[1] += fRotateAngleY;
	//m_fRotateFactors[2] += fRotateAngleZ;

	Matrix4f transform;
	transform.InitTranslationTransform(-fRotatePointX, -fRotatePointY, -fRotatePointX);
	m_matTRTransform = transform * m_matTRTransform;
	transform.InitRotateTransform(fRotateAngleX, fRotateAngleY, fRotateAngleZ);
	m_matTRTransform = transform * m_matTRTransform;
	transform.InitTranslationTransform(fRotatePointX, fRotatePointY, fRotatePointX);
	m_matTRTransform = transform * m_matTRTransform;
}

void IBaseObject::ScaleTo(f32 fScale)
{
	ScaleTo(fScale, fScale, fScale);
}

void IBaseObject::ScaleTo(f32 fScaleX, f32 fScaleY, f32 fScaleZ)
{
	m_vecScale.x = fScaleX;
	m_vecScale.y = fScaleY;
	m_vecScale.z = fScaleZ;
}

void IBaseObject::ScaleBy(f32 fScale)
{
	ScaleBy(fScale, fScale, fScale);
}

void IBaseObject::ScaleBy(f32 fScaleX, f32 fScaleY, f32 fScaleZ)
{
	m_vecScale.x *= fScaleX;
	m_vecScale.y *= fScaleY;
	m_vecScale.z *= fScaleZ;
}

Matrix4f IBaseObject::GetTransformMatrix()
{
	Matrix4f scaleTransform;
	scaleTransform.InitScaleTransform(m_vecScale.x, m_vecScale.y, m_vecScale.z);
	m_matTRTransform = m_matTRTransform * scaleTransform;
	return m_matTRTransform;
}

bool IBaseObject::Register()
{
	GenerateObjectID();

	m_bIsRegisted = true;

	return true;
}

void IBaseObject::BeforeDraw()
{
	Matrix4f matTransform;
	matTransform.InitScaleTransform(m_vecScale.x, m_vecScale.y, m_vecScale.z);
	matTransform = m_matTRTransform * matTransform;
	SetCurrentObjectTran(m_matTRTransform);
}

void IBaseObject::AfterDraw()
{

}

void IBaseObject::GenerateObjectID()
{
	GetUniqueObjectID(m_nObjectType, m_nObjectID);
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
		m_fCurrentPosition[i] = 0.0f;
	}

	m_vecWorldPosition = Vector3f(0.0f);
}
