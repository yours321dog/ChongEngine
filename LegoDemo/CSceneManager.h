/*!
 * \file DemoScene.h
 * \date 2015/10/19
 * \author Lv Luan
 * \brief This is the header of file DemoScene.cpp
*/

#ifndef _CSCENEMANAGER_H_
#define _CSCENEMANAGER_H_

#include <vector>
#include "IBaseObject.h"
#include "ICommonObject.h"

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

	//****************************************************************
	// Method:    AddCommonObject
	// FullName:  CSceneManager::AddCommonObject
	// Access:    virtual public 
	// Returns:   ICommonObject *
	// Qualifier:
	// Parameter: ICommonObject * pCommonObject
	// Description: Add the common objects to the scene
	//****************************************************************
	virtual ICommonObject *AddCommonObject(ICommonObject *pCommonObject);

private:
	vector<IBaseObject *> m_vDemoObjects;
	vector<ICommonObject *> m_listCommonObjects;
};

#endif