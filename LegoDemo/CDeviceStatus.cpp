/*!
 * \file CDeviceStatus.cpp
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This is the implement of class CDeviceStatus
 */

#include <stdlib.h>
#include "CDeviceStatus.h"

CDeviceStatus *CDeviceStatus::ms_pInstance = NULL;

CDeviceStatus::CDeviceStatus()
:m_nWindowWidth(1024),
m_nWindowHeight(768),
m_fEyeAngle(65.0f),
m_fClipPlaneZNear(1.0f),
m_fClipPlaneZFar(20.0f)
{

}

CDeviceStatus::CDeviceStatus(const CDeviceStatus &deviceStatus)
{
	this->m_nWindowWidth = deviceStatus.m_nWindowWidth;
	this->m_nWindowHeight = deviceStatus.m_nWindowHeight;
	this->m_fEyeAngle = deviceStatus.m_fEyeAngle;
	this->m_fClipPlaneZNear = deviceStatus.m_fClipPlaneZNear;
	this->m_fClipPlaneZFar = deviceStatus.m_fClipPlaneZFar;
}

CDeviceStatus& CDeviceStatus::operator=(const CDeviceStatus &deviceStatus)
{
	this->m_nWindowWidth = deviceStatus.m_nWindowWidth;
	this->m_nWindowHeight = deviceStatus.m_nWindowHeight;
	this->m_fEyeAngle = deviceStatus.m_fEyeAngle;
	this->m_fClipPlaneZNear = deviceStatus.m_fClipPlaneZNear;
	this->m_fClipPlaneZFar = deviceStatus.m_fClipPlaneZFar;

	return *this;
}

CDeviceStatus *CDeviceStatus::GetInstance()
{
	//If the CDeviceStatus hasn't been created, just create it
	if (ms_pInstance == NULL)
	{
		ms_pInstance = new CDeviceStatus();
	}

	return ms_pInstance;
}

ui32 CDeviceStatus::GetWindowWidth() const
{
	return m_nWindowWidth;
}

void CDeviceStatus::SetWindowWidth(ui32 nWindowWidth)
{
	m_nWindowWidth = nWindowWidth;
}

ui32 CDeviceStatus::GetWindowHeight() const
{
	return m_nWindowHeight;
}

void CDeviceStatus::SetWindowHeight(ui32 nWindowHeight)
{
	m_nWindowHeight = nWindowHeight;
}

f32 CDeviceStatus::GetEydAngle() const
{
	return m_fEyeAngle;
}

void CDeviceStatus::SetEyeAngle(f32 fEyeAngle)
{
	m_fEyeAngle = fEyeAngle;
}

f32 CDeviceStatus::GetClipPlaneZNear() const
{
	return m_fClipPlaneZNear;
}

void CDeviceStatus::SetClipPlaneZNear(f32 fClipPlaneZNear)
{
	m_fClipPlaneZNear = fClipPlaneZNear;
}

f32 CDeviceStatus::GetClipPlaneZFar() const
{
	return m_fClipPlaneZFar;
}

void CDeviceStatus::SetClipPlaneZFar(f32 fClipPlaneZFar)
{
	m_fClipPlaneZFar = fClipPlaneZFar;
}