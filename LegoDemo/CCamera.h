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
	CCamera(i32 nWindowWidth, i32 nWindowHeight);

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
	CCamera(i32 nWindowWidth, i32 nWindowHeight, const Vector3f& vecPos, const Vector3f& vecTarget,
		const Vector3f& vecUp);

	//bool OnKeyboard(OGLDEV_KEY Key);

	//void OnMouse(i32 x, i32 y);

	//****************************************************************
	// Method:    OnRender
	// FullName:  CCamera::OnRender
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	void OnRender();

	//****************************************************************
	// Method:    GetPos
	// FullName:  CCamera::GetPos
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetPos() const
	{
		return m_vecPos;
	}

	//****************************************************************
	// Method:    GetTarget
	// FullName:  CCamera::GetTarget
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetTarget() const
	{
		return m_vecTarget;
	}

	//****************************************************************
	// Method:    GetUp
	// FullName:  CCamera::GetUp
	// Access:    public 
	// Returns:   const Vector3f&
	// Qualifier: const
	// Description: 
	//****************************************************************
	const Vector3f& GetUp() const
	{
		return m_vecUp;
	}

private:

	void Init();
	void Update();

	Vector3f m_vecPos;
	Vector3f m_vecTarget;
	Vector3f m_vecUp;

	i32 m_nWindowWidth;
	i32 m_nWindowHeight;

	f32 m_fAngleH;
	f32 m_fAngleV;

	bool m_bOnUpperEdge;
	bool m_bOnLowerEdge;
	bool m_bOnLeftEdge;
	bool m_bOnRightEdge;

	Vector2i m_vecMousePos;
};

#endif // _CCAMERA_H_