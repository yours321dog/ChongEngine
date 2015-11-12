/*!
 * \file CCamera.h
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This is the define of the world camera
 */

#ifndef _CCAMERA_H_
#define _CCAMERA_H_

#include "ChongMath.h"
#include "ChongUtils.h"

class CCamera
{
public:
	//****************************************************************
	// Method:    CCamera
	// FullName:  CCamera::CCamera
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: i32 nWindowWidth
	// Parameter: i32 nWindowHeight
	// Description: 
	//****************************************************************
	CCamera();

	//****************************************************************
	// Method:    CCamera
	// FullName:  CCamera::CCamera
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: i32 nWindowWidth
	// Parameter: i32 nWindowHeight
	// Parameter: const Vector3f & vecPos
	// Parameter: const Vector3f & vecTarget
	// Parameter: const Vector3f & vecUp
	// Description: 
	//****************************************************************
	CCamera(const Vector3f& vecPos, const Vector3f& vecTarget, const Vector3f& vecUp);

	//****************************************************************
	// Method:    GetPos
	// FullName:  CCamera::GetPos
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetPos() const;

	//****************************************************************
	// Method:    GetTarget
	// FullName:  CCamera::GetTarget
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetTarget() const;

	//****************************************************************
	// Method:    GetUp
	// FullName:  CCamera::GetUp
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetUp() const;

	//****************************************************************
	// Method:    SetPosition
	// FullName:  CCamera::SetPosition
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecPosition
	// Description: 
	//****************************************************************
	void SetPosition(const Vector3f vecPosition);

	//****************************************************************
	// Method:    SetTarget
	// FullName:  CCamera::SetTarget
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecTarget
	// Description: 
	//****************************************************************
	void SetTarget(const Vector3f vecTarget);

	//****************************************************************
	// Method:    SetUp
	// FullName:  CCamera::SetUp
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecUp
	// Description: 
	//****************************************************************
	void SetUp(const Vector3f vecUp);

private:
	Vector3f m_vecPos;
	Vector3f m_vecTarget;
	Vector3f m_vecUp;
};

#endif // _CCAMERA_H_