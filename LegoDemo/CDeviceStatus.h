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
	static CDeviceStatus *getInstance();

private:
	static CDeviceStatus *ms_pInstance;

	ui32 nWindowWidth;
	ui32 nWindowHeight;
};

#endif // _CDEVICESTATUS_h_