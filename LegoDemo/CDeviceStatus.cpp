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
{

}

CDeviceStatus::CDeviceStatus(const CDeviceStatus &)
{

}

CDeviceStatus& CDeviceStatus::operator=(const CDeviceStatus & deviceStatus)
{
	return *this;
}

CDeviceStatus * CDeviceStatus::getInstance()
{
	//If the CDeviceStatus hasn't been created, just create it
	if (ms_pInstance == NULL)
	{
		ms_pInstance = new CDeviceStatus();
	}

	return ms_pInstance;
}