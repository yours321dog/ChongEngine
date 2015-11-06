/*!
 * \file CDeviceStatus.h
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This is the header of CDeviceStatus.cpp, which is used to save the 
 *		  status of device
 */

#ifndef _CDEVICESTATUS_h_
#define _CDEVICESTATUS_h_

#include "ChongUtils.h"

class CDeviceStatus
{
private:
	//****************************************************************
	// Method:    CDeviceStatus
	// FullName:  CDeviceStatus::CDeviceStatus
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of CDeviceStatus
	//****************************************************************
	CDeviceStatus();

	//****************************************************************
	// Method:    CDeviceStatus
	// FullName:  CDeviceStatus::CDeviceStatus
	// Access:    private 
	// Returns:   
	// Qualifier:
	// Parameter: const CDeviceStatus &
	// Description: The constructor of CDeviceStatus
	//****************************************************************
	CDeviceStatus(const CDeviceStatus &);

	//****************************************************************
	// Method:    operator=
	// FullName:  CDeviceStatus::operator=
	// Access:    private 
	// Returns:   CDeviceStatus&
	// Qualifier:
	// Parameter: const CDeviceStatus &
	// Description: 
	//****************************************************************
	CDeviceStatus& operator = (const CDeviceStatus &);

public:
	//****************************************************************
	// Method:    getInstance
	// FullName:  CDeviceStatus::getInstance
	// Access:    public static 
	// Returns:   CDeviceStatus *
	// Qualifier:
	// Description: Return the singleton of this class
	//****************************************************************
	static CDeviceStatus *GetInstance();

	//****************************************************************
	// Method:    GetWindowWidth
	// FullName:  CDeviceStatus::GetWindowWidth
	// Access:    public 
	// Returns:   ui32
	// Qualifier: const
	// Description: Return the value of window width
	//****************************************************************
	ui32 GetWindowWidth() const;

	//****************************************************************
	// Method:    SetWindowWidth
	// FullName:  CDeviceStatus::SetWindowWidth
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: ui32 nWindowWidth
	// Description: Set the value of window width
	//****************************************************************
	void SetWindowWidth(ui32 nWindowWidth);

	//****************************************************************
	// Method:    GetWindowHeight
	// FullName:  CDeviceStatus::GetWindowHeight
	// Access:    public 
	// Returns:   ui32
	// Qualifier: const
	// Description: Return the value of window height
	//****************************************************************
	ui32 GetWindowHeight() const;

	//****************************************************************
	// Method:    SetWindowHeight
	// FullName:  CDeviceStatus::SetWindowHeight
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: ui32 nWindowHeight
	// Description: Set the value of window height
	//****************************************************************
	void SetWindowHeight(ui32 nWindowHeight);

	//****************************************************************
	// Method:    GetEydAngle
	// FullName:  CDeviceStatus::GetEydAngle
	// Access:    public 
	// Returns:   f32
	// Qualifier: const
	// Description: Return the value of viewing angle
	//****************************************************************
	f32 GetEydAngle() const;

	//****************************************************************
	// Method:    SetEyeAngle
	// FullName:  CDeviceStatus::SetEyeAngle
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fEyeAngle
	// Description: Set the value of viewing angle
	//****************************************************************
	void SetEyeAngle(f32 fEyeAngle);

	//****************************************************************
	// Method:    GetClipPlaneZNear
	// FullName:  CDeviceStatus::GetClipPlaneZNear
	// Access:    public 
	// Returns:   f32
	// Qualifier: const
	// Description: Return the value of clip plane z near
	//****************************************************************
	f32 GetClipPlaneZNear() const;

	//****************************************************************
	// Method:    SetClipPlaneZNear
	// FullName:  CDeviceStatus::SetClipPlaneZNear
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fClipPlaneZNear
	// Description: Set the value of clip plane z near
	//****************************************************************
	void SetClipPlaneZNear(f32 fClipPlaneZNear);

	//****************************************************************
	// Method:    GetClipPlaneZFar
	// FullName:  CDeviceStatus::GetClipPlaneZFar
	// Access:    public 
	// Returns:   f32
	// Qualifier: const
	// Description: Return the value of clip plane z far
	//****************************************************************
	f32 GetClipPlaneZFar() const;

	//****************************************************************
	// Method:    SetClipPlaneZFar
	// FullName:  CDeviceStatus::SetClipPlaneZFar
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fClipPlaneZFar
	// Description: Set the value of clip plane z far
	//****************************************************************
	void SetClipPlaneZFar(f32 fClipPlaneZFar);

private:
	static CDeviceStatus *ms_pInstance;

	ui32 m_nWindowWidth;
	ui32 m_nWindowHeight;

	f32 m_fEyeAngle;

	f32 m_fClipPlaneZNear;
	f32 m_fClipPlaneZFar;
};

#endif // _CDEVICESTATUS_h_