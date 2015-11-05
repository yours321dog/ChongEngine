/*!
 * \file Tank.h
 * \date 2015/10/20
 * \author Lv Luan
 * \brief This file is the header of file tank.cpp, which is used to describe a tank model
*/

#include "IBaseObject.h"
#include <stdlib.h>
#include "GL/glew.h"

class Tank : public IBaseObject
{
public:
	//****************************************************************
	// Method:    Tank
	// FullName:  Tank::Tank
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of tank model
	//****************************************************************
	Tank();

	//****************************************************************
	// Method:    ~Tank
	// FullName:  Tank::~Tank
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The destructor of tank model
	//****************************************************************
	~Tank();

	//****************************************************************
	// Method:    RunForward
	// FullName:  Tank::RunForward
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Translate the tank forward
	//****************************************************************
	void RunForward();

	//****************************************************************
	// Method:    RunForward
	// FullName:  Tank::RunForward
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Translate the tank backward
	//****************************************************************
	void RunBackward();

	//****************************************************************
	// Method:    UpliftAxisThree
	// FullName:  Tank::UpliftAxisThree
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Uplift the axis 3 of tank
	//****************************************************************
	void UpliftAxisThree();

	//****************************************************************
	// Method:    LowerAxisThree
	// FullName:  Tank::LowerAxisThree
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Lower the axis 3 of tank
	//****************************************************************
	void LowerAxisThree();

	//****************************************************************
	// Method:    RotateAxisTwo
	// FullName:  Tank::RotateAxisTwo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Rotate the axis 2 of tank
	//****************************************************************
	void RotateAxisTwo();

	//****************************************************************
	// Method:    ResetPosition
	// FullName:  Tank::ResetPosition
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Reset the position of tank
	//****************************************************************
	void ResetPosition();

	//****************************************************************
	// Method:    ChangeMode
	// FullName:  Tank::ChangeMode
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Change the draw mode
	//****************************************************************
	void ChangeMode();

	//****************************************************************
	// Method:    Draw
	// FullName:  Tank::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Draw the model
	//****************************************************************
	virtual void Draw();

private:
	float m_fAxisThreeRotateFactor;
	float m_fAxisTwoRotateFactor;
	float m_fTankTranslateFactor;

	int m_nPolygonMode;

	GLUquadricObj *m_iCylinder;

	//****************************************************************
	// Method:    DrawWireAxisOne
	// FullName:  Tank::DrawWireAxisOne
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Draw the axis 1
	//****************************************************************
	void DrawAxisOne();

	//****************************************************************
	// Method:    DrawWireAxisOne
	// FullName:  Tank::DrawWireAxisOne
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Draw the axis 2
	//****************************************************************
	void DrawAxisTwo();

	//****************************************************************
	// Method:    DrawWireAxisOne
	// FullName:  Tank::DrawWireAxisOne
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Description: Draw the axis 3
	//****************************************************************
	void DrawAxisThree();
};
