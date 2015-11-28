/*!
 * \file DemoObject.h
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This is the header of file DemoObject.cpp, which is used to
 *		  describe the detail of model.
*/

#ifndef _IBASEOBJECT_H_
#define _IBASEOBJECT_H_

#include "ChongMath.h"
#include "ChongConstant.h"

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
	// Method:    InitialPosition
	// FullName:  IDemoObject::InitialPosition
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Initial the object position
	//****************************************************************
	void InitialPosition();

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
	virtual void Rotate(f32 fRotateAngleX, f32 fRotateAngleY, f32 fRotateAngleZ,
		f32 fRotatePointX, f32 fRotatePointY, f32 fRotatePointZ);

	//****************************************************************
	// Method:    ScaleTo
	// FullName:  IBaseObject::ScaleTo
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fScale
	// Description: 
	//****************************************************************
	virtual void ScaleTo(f32 fScale);

	//****************************************************************
	// Method:    ScaleTo
	// FullName:  IBaseObject::ScaleTo
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fScaleX
	// Parameter: f32 fScaleY
	// Parameter: f32 fScaleZ
	// Description: 
	//****************************************************************
	virtual void ScaleTo(f32 fScaleX, f32 fScaleY, f32 fScaleZ);

	//****************************************************************
	// Method:    ScaleBy
	// FullName:  IBaseObject::ScaleBy
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fScale
	// Description: 
	//****************************************************************
	virtual void ScaleBy(f32 fScale);

	//****************************************************************
	// Method:    ScaleBy
	// FullName:  IBaseObject::ScaleBy
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fScaleX
	// Parameter: f32 fScaleY
	// Parameter: f32 fScaleZ
	// Description: 
	//****************************************************************
	virtual void ScaleBy(f32 fScaleX, f32 fScaleY, f32 fScaleZ);

	//****************************************************************
	// Method:    GetTransformMatrix
	// FullName:  IBaseObject::GetTransformMatrix
	// Access:    public 
	// Returns:   Matrix4f
	// Qualifier: const
	// Description: Return the transform matrix
	//****************************************************************
	Matrix4f GetTransformMatrix();

	//****************************************************************
	// Method:    Register
	// FullName:  IBaseObject::Register
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	// Description: Register an object to the system
	//****************************************************************
	virtual bool Register();

	i32 m_nObjectType;

protected:
	Matrix4f m_matTRTransform;
	Vector3f m_vecWorldPosition;
	Vector3f m_vecScale;

	bool m_bIsRegisted;
	ui32 m_nObjectID[2];
	float m_fCurrentPosition[3];

	//****************************************************************
	// Method:    BeforeDraw
	// FullName:  IBaseObject::BeforeDraw
	// Access:    virtual protected 
	// Returns:   void
	// Qualifier:
	// Description: Do something before draw
	//****************************************************************
	virtual void BeforeDraw();

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
	// Method:    AfterDraw
	// FullName:  IBaseObject::AfterDraw
	// Access:    virtual protected 
	// Returns:   void
	// Qualifier:
	// Description: Do something after draw
	//****************************************************************
	virtual void AfterDraw();

	//****************************************************************
	// Method:    GenerateObjectID
	// FullName:  IBaseObject::GenerateObjectID
	// Access:    virtual protected 
	// Returns:   void
	// Qualifier:
	// Parameter: const i32 & nObjectType
	// Description: Generate an ID from the system
	//****************************************************************
	virtual void GenerateObjectID();

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

	float m_fTranslateFactors[3];
	float m_fRotateFactors[3];
	float m_fScaleFactors[3];
	float m_fRotatePoint[3];
};

#endif