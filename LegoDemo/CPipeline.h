/*!
 * \file CPipeline.h
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This is the pipeline of this engine
 */

#ifndef _CPIPELINE_H_
#define _CPIPELINE_H_

#include "ChongMath.h"
#include "CCamera.h"

class CPipeline
{
public:
	CPipeline()
	{
		m_vecScale = Vector3f(1.0f, 1.0f, 1.0f);
		m_vecWorldPos = Vector3f(0.0f, 0.0f, 0.0f);
		m_vecRotateInfo = Vector3f(0.0f, 0.0f, 0.0f);
	}

	//****************************************************************
	// Method:    ScaleBy
	// FullName:  CPipeline::ScaleBy
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Scale the whole world by the scale of current size
	//****************************************************************
	void ScaleBy(f32 fScale);
	void ScaleBy(const Vector3f &vecScale);
	void ScaleBy(f32 fScaleX, f32 fScaleY, f32 fScaleZ);

	//****************************************************************
	// Method:    ScaleTo
	// FullName:  CPipeline::ScaleTo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Scale the whole world to the scale of original size
	//****************************************************************
	void ScaleTo(f32 fScale);
	void ScaleTo(const Vector3f &vecScale);
	void ScaleTo(f32 fScaleX, f32 fScaleY, f32 fScaleZ);

	//****************************************************************
	// Method:    WorldPosBy
	// FullName:  CPipeline::WorldPosBy
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Transform the world by the distance
	//****************************************************************
	void WorldPosBy(f32 x, f32 y, f32 z);
	void WorldPosBy(const Vector3f &vecDistance);

	//****************************************************************
	// Method:    WorldPosTo
	// FullName:  CPipeline::WorldPosTo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Transform the world to the new position
	//****************************************************************
	void WorldPosTo(f32 x, f32 y, f32 z);
	void WorldPosTo(const Vector3f &vecWorldPos);


	//****************************************************************
	// Method:    RotateBy
	// FullName:  CPipeline::RotateBy
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Rotate the whole world by the angle
	//****************************************************************
	void RotateBy(f32 x, f32 y, f32 z);
	void RotateBy(const Vector3f &vecRotate);

	//****************************************************************
	// Method:    RotateTo
	// FullName:  CPipeline::RotateTo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Rotate the world to the angle
	//****************************************************************
	void RotateTo(f32 x, f32 y, f32 z);
	void RotateTo(const Vector3f &vecRotate);

	void SetPerspectiveProj(const PersProjInfo& p)
	{
		m_persProjInfo = p;
	}

	void SetCamera(const Vector3f& vecPos, const Vector3f& vecTarget, const Vector3f& vecUp)
	{
		m_Camera.SetPosition(vecPos);
		m_Camera.SetTarget(vecTarget);
		m_Camera.SetUp(vecUp);
	}

	const Matrix4f& GetWPTrans();
	const Matrix4f& GetWVTrans();
	const Matrix4f& GetVPTrans();
	const Matrix4f& GetWVPTrans();
	const Matrix4f& GetWorldTrans();
	const Matrix4f& GetViewTrans();
	const Matrix4f& GetProjTrans();

	//****************************************************************
	// Method:    UseOrthoProject
	// FullName:  CPipeline::UseOrthoProject
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Use orthographic project
	//****************************************************************
	void UseOrthoProject();

	//****************************************************************
	// Method:    UsePersProject
	// FullName:  CPipeline::UsePersProject
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Use perspective project
	//****************************************************************
	void UsePersProject();

private:
	Vector3f m_vecScale;
	Vector3f m_vecWorldPos;
	Vector3f m_vecRotateInfo;

	PersProjInfo m_persProjInfo;

	CCamera m_Camera;

	Matrix4f m_matWVPTransform;
	Matrix4f m_matVPTransform;
	Matrix4f m_matWPTransform;
	Matrix4f m_matWVTransform;
	Matrix4f m_matWTransform;
	Matrix4f m_matViewTransform;
	Matrix4f m_matProjTransform;
};

#endif // _CPIPELINE_H_