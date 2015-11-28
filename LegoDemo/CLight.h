/*!
 * \file CLight.h
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is the header of CLight, which is used to define the light
*/

#include "IBaseObject.h"
#include "ChongElements.h"

class CLight : public IBaseObject
{
public:
	//****************************************************************
	// Method:    CLight
	// FullName:  CLight::CLight
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	CLight();

	//****************************************************************
	// Method:    ~CLight
	// FullName:  CLight::~CLight
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	~CLight();

	//****************************************************************
	// Method:    Draw
	// FullName:  CLight::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Draw the light
	//****************************************************************
	virtual void Draw();

	//****************************************************************
	// Method:    Translate
	// FullName:  IDemoObject::Translate
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: float fTranslateX
	// Parameter: float fTranslateY
	// Parameter: float fTranslateZ
	// Description: Move the object in three directions by the value of params
	//****************************************************************
	virtual void TranslateBy(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ);

	//****************************************************************
	// Method:    TranslateTo
	// FullName:  IDemoObject::TranslateTo
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: float fTranslateX
	// Parameter: float fTranslateY
	// Parameter: float fTranslateZ
	// Description: Move the object in three directions to the position of params
	//****************************************************************
	virtual void TranslateTo(f32 fTranslateX, f32 fTranslateY, f32 fTranslateZ);

	//****************************************************************
	// Method:    GetLightCont
	// FullName:  CLight::GetLightCont
	// Access:    public 
	// Returns:   Light &
	// Qualifier:
	// Description: Return the values of content
	//****************************************************************
	Light &GetLightCont();

	//****************************************************************
	// Method:    SetColor
	// FullName:  CLight::SetColor
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fColorX
	// Parameter: f32 fColorY
	// Parameter: f32 fColorZ
	// Description: Set the color value of the light
	//****************************************************************
	virtual void SetColor(f32 fColorX, f32 fColorY, f32 fColorZ);

	//****************************************************************
	// Method:    SetDirection
	// FullName:  CLight::SetDirection
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fDirectionX
	// Parameter: f32 fDirectionY
	// Parameter: f32 fDirectionZ
	// Description: Set the direction of the light
	//****************************************************************
	virtual void SetDirection(f32 fDirectionX, f32 fDirectionY, f32 fDirectionZ);

	//****************************************************************
	// Method:    SetAttenuation
	// FullName:  CLight::SetAttenuation
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 constant
	// Parameter: f32 linear
	// Parameter: f32 exp
	// Description: Set the attenuation of the light
	//****************************************************************
	virtual void SetAttenuation(f32 fConstant, f32 fLinear, f32 fExp);

	//****************************************************************
	// Method:    SetCutoff
	// FullName:  CLight::SetCutoff
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 cutoff
	// Description: Set the cutoff of the light
	//****************************************************************
	virtual void SetCutoff(f32 cutoff);

protected:
	Light m_light;
};