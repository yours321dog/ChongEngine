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

struct Orientation
{
	Vector3f m_vecScale;
	Vector3f m_vecRotation;
	Vector3f m_vecPos;

	//****************************************************************
	// Method:    Orientation
	// FullName:  Orientation::Orientation
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	Orientation()
	{
		m_vecScale = Vector3f(1.0f, 1.0f, 1.0f);
		m_vecRotation = Vector3f(0.0f, 0.0f, 0.0f);
		m_vecPos = Vector3f(0.0f, 0.0f, 0.0f);
	}
};


class CPipeline
{
public:
	CPipeline()
	{
		m_vecScale = Vector3f(1.0f, 1.0f, 1.0f);
		m_vecWorldPos = Vector3f(0.0f, 0.0f, 0.0f);
		m_vecRotateInfo = Vector3f(0.0f, 0.0f, 0.0f);
	}

	void Scale(float s)
	{
		Scale(s, s, s);
	}


	void Scale(const Vector3f& scale)
	{
		Scale(scale.x, scale.y, scale.z);
	}

	void Scale(float ScaleX, float ScaleY, float ScaleZ)
	{
		m_vecScale.x = ScaleX;
		m_vecScale.y = ScaleY;
		m_vecScale.z = ScaleZ;
	}

	void WorldPos(float x, float y, float z)
	{
		m_vecWorldPos.x = x;
		m_vecWorldPos.y = y;
		m_vecWorldPos.z = z;
	}

	void WorldPos(const Vector3f& Pos)
	{
		m_vecWorldPos = Pos;
	}

	void Rotate(float RotateX, float RotateY, float RotateZ)
	{
		m_vecRotateInfo.x = RotateX;
		m_vecRotateInfo.y = RotateY;
		m_vecRotateInfo.z = RotateZ;
	}

	void Rotate(const Vector3f& r)
	{
		Rotate(r.x, r.y, r.z);
	}

	void SetPerspectiveProj(const PersProjInfo& p)
	{
		m_persProjInfo = p;
	}

	void SetCamera(const Vector3f& Pos, const Vector3f& Target, const Vector3f& Up)
	{
		m_camera.Pos = Pos;
		m_camera.Target = Target;
		m_camera.Up = Up;
	}

	void SetCamera(const CCamera& camera)
	{
		SetCamera(camera.GetPos(), camera.GetTarget(), camera.GetUp());
	}

	void Orient(const Orientation& o)
	{
		m_vecScale = o.m_vecScale;
		m_vecWorldPos = o.m_vecPos;
		m_vecRotateInfo = o.m_vecRotation;
	}

	const Matrix4f& GetWPTrans();
	const Matrix4f& GetWVTrans();
	const Matrix4f& GetVPTrans();
	const Matrix4f& GetWVPTrans();
	const Matrix4f& GetWVOrthoPTrans();
	const Matrix4f& GetWorldTrans();
	const Matrix4f& GetViewTrans();
	const Matrix4f& GetProjTrans();

private:
	Vector3f m_vecScale;
	Vector3f m_vecWorldPos;
	Vector3f m_vecRotateInfo;

	PersProjInfo m_persProjInfo;

	struct {
		Vector3f Pos;
		Vector3f Target;
		Vector3f Up;
	} m_camera;

	Matrix4f m_matWVPtransformation;
	Matrix4f m_matVPtransformation;
	Matrix4f m_matWPtransformation;
	Matrix4f m_matWVtransformation;
	Matrix4f m_matWtransformation;
	Matrix4f m_matVtransformation;
	Matrix4f m_matProjTransformation;
};

#endif // _CPIPELINE_H_