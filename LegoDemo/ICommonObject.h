/*!
 * \file ICommonObject.h
 * \date 2015/11/13
 * \author Lv Luan
 * \brief This is the header of ICommonObject, which is used to describe common object
 */

#include <vector>
#include "ChongElements.h"
#include "IBaseObject.h"

class ICommonObject : public IBaseObject
{
public:
	//****************************************************************
	// Method:    ICommonObject
	// FullName:  ICommonObject::ICommonObject
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of ICommonObject
	//****************************************************************
	ICommonObject();

	//****************************************************************
	// Method:    ~ICommonObject
	// FullName:  ICommonObject::~ICommonObject
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The destructor of ICommonObject
	//****************************************************************
	~ICommonObject();

	//****************************************************************
	// Method:    Register
	// FullName:  ICommonObject::Register
	// Access:    virtual public 
	// Returns:   bool
	// Qualifier:
	// Description: 
	//****************************************************************
	virtual bool Register();

	//****************************************************************
	// Method:    Draw
	// FullName:  ICommonObject::Draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	virtual void Draw();

	//****************************************************************
	// Method:    Load
	// FullName:  ICommonObject::Load
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Set the value of vertex
	//****************************************************************
	virtual void Load() = 0;

protected:
	vector<Vertex> m_vertices;
	vector<Mesh> m_meshes;
	vector<Material> m_materials;

	bool m_bIsLoad;
};
