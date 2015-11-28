/*!
 * \file CSimpleLight.h
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is header of simple light
*/

#include "CLight.h"

class CSimpleLight : public CLight
{
public:
	//****************************************************************
	// Method:    CSimpleLight
	// FullName:  CSimpleLight::CSimpleLight
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	CSimpleLight();

	//****************************************************************
	// Method:    ~CSimpleLight
	// FullName:  CSimpleLight::~CSimpleLight
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	~CSimpleLight();

	//****************************************************************
	// Method:    BeforeDraw
	// FullName:  CSimpleLight::BeforeDraw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	virtual void BeforeDraw();
};