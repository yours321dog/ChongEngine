/*!
 * \file DemoScene.h
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This is the header of file DemoScene.cpp
*/

#ifndef _CDEMOSCENE_H_
#define _CDEMOSCENE_H_

#include <vector>
#include "IBaseObject.h"

using std::vector;

class CSceneManager
{
public:
	//****************************************************************
	// Method:    CDemoScene
	// FullName:  CDemoScene::CDemoScene
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of class CDemoScene
	//****************************************************************
	CSceneManager();

	//****************************************************************
	// Method:    ~CDemoScene
	// FullName:  CDemoScene::~CDemoScene
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The destructor of class CDemoScene
	//****************************************************************
	~CSceneManager();

	//****************************************************************
	// Method:    Draw
	// FullName:  CDemoScene::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Render the models in the scene
	//****************************************************************
	virtual void Draw();

	//****************************************************************
	// Method:    AddDemoObject
	// FullName:  CDemoScene::AddDemoObject
	// Access:    virtual public 
	// Returns:   IDemoObject *
	// Qualifier:
	// Parameter: IDemoObject * demoObject
	// Description: Add objects to the scene
	//****************************************************************
	virtual IBaseObject *AddDemoObject(IBaseObject *demoObject);

private:
	vector<IBaseObject *> m_vDemoObjects;
};

#endif