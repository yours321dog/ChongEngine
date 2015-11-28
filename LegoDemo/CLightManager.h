/*!
 * \file CLightManager.h
 * \date 2015/11/28
 * \author Lv Luan
 * \brief This is the header of CLightManger, which is used to manage the lights
*/

#include "CLight.h"
#include "ChongElements.h"
#include <vector>

class CLightManager
{
public:
	//****************************************************************
	// Method:    CLightManager
	// FullName:  CLightManager::CLightManager
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	CLightManager();

	//****************************************************************
	// Method:    ~CLightManager
	// FullName:  CLightManager::~CLightManager
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	~CLightManager();

	//****************************************************************
	// Method:    AddLight
	// FullName:  CLightManager::AddLight
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: CLight * light
	// Description: Add a new light to the manager
	//****************************************************************
	CLight *AddLight(CLight *light);

	//****************************************************************
	// Method:    RenderAllLights
	// FullName:  CLightManager::RenderAllLights
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	void RenderAllLights();

private:
	vector<CLight *> m_lights;
	vector<Light> m_lightsBuffer;
};