/*!
 * \file DemoObject.h
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This is the header of file DemoObject.cpp, which is used to
 *		  describe the detail of model.
*/

#ifndef _IBASEOBJECT_H_
#define _IBASEOBJECT_H_

class IBaseObject
{
public:
	//****************************************************************
	// Method:    IDemoObject
	// FullName:  IDemoObject::IDemoObject
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of IDemoProject
	//****************************************************************
	IBaseObject();

	//****************************************************************
	// Method:    Draw
	// FullName:  CDemoObject::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: This function is used to draws the model
	//****************************************************************
	virtual void Draw() = 0;

	//****************************************************************
	// Method:    Render
	// FullName:  IDemoObject::Render
	// Access:    virtual public 
	// Returns:   void
	// Qualifier: 
	// Description: This function is used to render the model with
	//				the transforms
	//****************************************************************
	virtual void Render();

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
	virtual void TranslateBy(float fTranslateX, float fTranslateY, float fTranslateZ);

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
	virtual void TranslateTo(float fTranslateX, float fTranslateY, float fTranslateZ);

	//****************************************************************
	// Method:    Rotate
	// FullName:  IDemoObject::Rotate
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: float fRotateAngleX
	// Parameter: float fRotateAngleY
	// Parameter: float fRotateAngleZ
	// Parameter: float fRotatePointX
	// Parameter: float fRotatePointY
	// Parameter: float fRotatePointZ
	// Description: Rotate the object by the angle with the circle, rotate point
	//****************************************************************
	virtual void Rotate(float fRotateAngleX, float fRotateAngleY, float fRotateAngleZ,
		float fRotatePointX, float fRotatePointY, float fRotatePointZ);

private:
	//****************************************************************
	// Method:    InitialFactors
	// FullName:  IDemoObject::InitialFactors
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Initial the transform factors
	//****************************************************************
	void InitialFactors();

	//****************************************************************
	// Method:    InitialPosition
	// FullName:  IDemoObject::InitialPosition
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Initial the object position
	//****************************************************************
	void InitialPosition();

	float m_fTranslateFactors[3];
	float m_fRotateFactors[3];
	float m_fScaleFactors[3];
	float m_fOldPosition[3];
	float m_fRotatePoint[3];
};

#endif