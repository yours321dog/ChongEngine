/*!
 * \file CRenderStatus.cpp
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the implement of class CRenderStatus
 */

#include "CRenderStatus.h"

CRenderStatus::CRenderStatus()
{
	m_pRenderShader = new CLightShader();
	m_pPipeline = new CPipeline();
}

CRenderStatus::~CRenderStatus()
{
	delete m_pRenderShader;
	delete m_pPipeline;
}

CRenderStatus * CRenderStatus::GetInstance()
{
	if (ms_pInstance == NULL)
	{
		ms_pInstance = new CRenderStatus();
	}

	return ms_pInstance;
}

IBaseShader * CRenderStatus::GetRenderShader() const
{
	return m_pRenderShader;
}

CPipeline * CRenderStatus::GetPipeline() const
{
	return m_pPipeline;
}

CRenderStatus * CRenderStatus::ms_pInstance = NULL;