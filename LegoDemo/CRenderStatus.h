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
#include <map>

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
	CLightShader *GetRenderShader() const;

	//****************************************************************
	// Method:    GetPipeline
	// FullName:  CRenderStatus::GetPipeline
	// Access:    public 
	// Returns:   CPipeline *
	// Qualifier: const
	// Description: Return the pipeline manager
	//****************************************************************
	CPipeline *GetPipeline() const;

	//****************************************************************
	// Method:    GetObjectTransform
	// FullName:  CRenderStatus::GetObjectTransform
	// Access:    public 
	// Returns:   Matrix4f
	// Qualifier: const
	// Description: Get the matrix value of object transform
	//****************************************************************
	Matrix4f GetObjectTransform() const;

	//****************************************************************
	// Method:    SetObjectTransform
	// FullName:  CRenderStatus::SetObjectTransform
	// Access:    public 
	// Returns:   Matrix4f
	// Qualifier:
	// Parameter: const Matrix4f &
	// Description: Set the matrix value of object transform
	//****************************************************************
	void SetObjectTransform(const Matrix4f &);

private:
	static CRenderStatus *ms_pInstance;

	CLightShader *m_pRenderShader;
	CPipeline *m_pPipeline;
	Matrix4f m_matObjectTransform;
};

#endif // _CRENDERSTATUS_H_