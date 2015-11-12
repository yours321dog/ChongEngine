/*!
 * \file CRenderStatue.h
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the header of CRenderStatus, which is used to store the status that rendering 
 *		  need.
 */

#ifndef _CRENDERSTATUS_H_
#define _CRENDERSTATUS_H_

#include "ChongUtils.h"
#include "CLightShader.h"
#include "CPipeline.h"
class CRenderStatus
{
public:
	//****************************************************************
	// Method:    CRenderStatus
	// FullName:  CRenderStatus::CRenderStatus
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of CRenderStatus
	//****************************************************************
	CRenderStatus();

	//****************************************************************
	// Method:    ~CRenderStatus
	// FullName:  CRenderStatus::~CRenderStatus
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	~CRenderStatus();

	//****************************************************************
	// Method:    GetInstance
	// FullName:  CRenderStatus::GetInstance
	// Access:    public static 
	// Returns:   CRenderStatus *
	// Qualifier:
	// Description: Return the singleton instance of CRenderStatus
	//****************************************************************
	static CRenderStatus *GetInstance();

	//****************************************************************
	// Method:    GetLightShader
	// FullName:  CRenderStatus::GetLightShader
	// Access:    public 
	// Returns:   CLightShader *
	// Qualifier: const
	// Description: Return the light shader manager
	//****************************************************************
	IBaseShader *GetRenderShader() const;

	//****************************************************************
	// Method:    GetPipeline
	// FullName:  CRenderStatus::GetPipeline
	// Access:    public 
	// Returns:   CPipeline *
	// Qualifier: const
	// Description: Return the pipeline manager
	//****************************************************************
	CPipeline *GetPipeline() const;
private:
	static CRenderStatus *ms_pInstance;

	IBaseShader *m_pRenderShader;
	CPipeline *m_pPipeline;
};

#endif // _CRENDERSTATUS_H_