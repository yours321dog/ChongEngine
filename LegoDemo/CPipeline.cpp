#include "CPipeline.h"

const Matrix4f& CPipeline::GetProjTrans()
{
	return m_matProjTransform;
}


void CPipeline::UseOrthoProject()
{
	m_matProjTransform.InitOrthoProjTransform(m_persProjInfo);
}


void CPipeline::UsePersProject()
{
	m_matProjTransform.InitPersProjTransform(m_persProjInfo);
}

const Matrix4f& CPipeline::GetVPTrans()
{
	GetViewTrans();
	GetProjTrans();

	m_matVPTransform = m_matProjTransform * m_matViewTransform;
	return m_matVPTransform;
}

const Matrix4f& CPipeline::GetWorldTrans()
{
	Matrix4f scaleTrans, rotateTrans, translationTrans;

	scaleTrans.InitScaleTransform(m_vecScale.x, m_vecScale.y, m_vecScale.z);
	rotateTrans.InitRotateTransform(m_vecRotateInfo.x, m_vecRotateInfo.y, m_vecRotateInfo.z);
	translationTrans.InitTranslationTransform(m_vecWorldPos.x, m_vecWorldPos.y, m_vecWorldPos.z);

	m_matWTransform = translationTrans * rotateTrans * scaleTrans;
	return m_matWTransform;
}

const Matrix4f& CPipeline::GetViewTrans()
{
	Matrix4f cameraTranslationTrans, cameraRotateTrans;

	cameraTranslationTrans.InitTranslationTransform(-m_Camera.GetPos().x, -m_Camera.GetPos().y, -m_Camera.GetPos().z);
	cameraRotateTrans.InitCameraTransform(m_Camera.GetTarget(), m_Camera.GetUp());

	m_matViewTransform = cameraRotateTrans * cameraTranslationTrans;

	return m_matViewTransform;
}

const Matrix4f& CPipeline::GetWVPTrans()
{
	GetWorldTrans();
	GetVPTrans();

	m_matWVPTransform = m_matVPTransform * m_matWTransform;
	return m_matWVPTransform;
}

const Matrix4f& CPipeline::GetWVTrans()
{
	GetWorldTrans();
	GetViewTrans();

	m_matWVTransform = m_matViewTransform * m_matWTransform;
	return m_matWVTransform;
}


void CPipeline::ScaleBy(f32 fScale)
{
	ScaleBy(fScale, fScale, fScale);
}

void CPipeline::ScaleBy(const Vector3f &vecScale)
{
	ScaleBy(vecScale.x, vecScale.y, vecScale.z);
}

void CPipeline::ScaleBy(f32 fScaleX, f32 fScaleY, f32 fScaleZ)
{
	m_vecScale.x += fScaleX;
	m_vecScale.y += fScaleY;
	m_vecScale.z += fScaleZ;
}

void CPipeline::ScaleTo(f32 fScale)
{
	ScaleBy(fScale, fScale, fScale);
}

void CPipeline::ScaleTo(const Vector3f &vecScale)
{
	ScaleBy(vecScale.x, vecScale.y, vecScale.z);
}

void CPipeline::ScaleTo(f32 fScaleX, f32 fScaleY, f32 fScaleZ)
{
	m_vecScale.x = fScaleX;
	m_vecScale.y = fScaleY;
	m_vecScale.z = fScaleZ;
}

void CPipeline::WorldPosBy(f32 x, f32 y, f32 z)
{
	m_vecWorldPos.x += x;
	m_vecWorldPos.y += y;
	m_vecWorldPos.z += z;
}

void CPipeline::WorldPosBy(const Vector3f &vecDistance)
{
	WorldPosBy(vecDistance.x, vecDistance.y, vecDistance.z);
}

void CPipeline::WorldPosTo(f32 x, f32 y, f32 z)
{
	m_vecWorldPos.x = x;
	m_vecWorldPos.y = y;
	m_vecWorldPos.z = z;
}

void CPipeline::WorldPosTo(const Vector3f &vecDistance)
{
	WorldPosBy(vecDistance.x, vecDistance.y, vecDistance.z);
}

void CPipeline::RotateBy(f32 x, f32 y, f32 z)
{
	m_vecRotateInfo.x += x;
	m_vecRotateInfo.y += y;
	m_vecRotateInfo.z += z;
}

void CPipeline::RotateBy(const Vector3f &vecRotate)
{
	RotateBy(vecRotate.x, vecRotate.y, vecRotate.z);
}

void CPipeline::RotateTo(f32 x, f32 y, f32 z)
{
	m_vecRotateInfo.x = x;
	m_vecRotateInfo.y = y;
	m_vecRotateInfo.z = z;
}

void CPipeline::RotateTo(const Vector3f &vecRotate)
{
	RotateBy(vecRotate.x, vecRotate.y, vecRotate.z);
}

const Matrix4f& CPipeline::GetWPTrans()
{
	Matrix4f PersProjTrans;

	GetWorldTrans();
	PersProjTrans.InitPersProjTransform(m_persProjInfo);

	m_matWPTransform = PersProjTrans * m_matWTransform;
	return m_matWPTransform;
}