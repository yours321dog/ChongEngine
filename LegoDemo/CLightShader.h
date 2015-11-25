/*!
 * \file CLightShader.h
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the header of CLightShader, which is used to define the shader of light
 */

#ifndef _CLIGHTSHADER_H_
#define _CLIGHTSHADER_H_

#include "IBaseShader.h"
#include "ChongMath.h"
#include "ChongConstant.h"

struct Attenuation
{
	f32 constant;
	f32 linear;
	f32 exp;
};

struct Light
{
	Vector3f color;
	Vector3f position;
	Vector3f direction;
	Attenuation atten;
	f32 cutoff;
};

class CLightShader : public IBaseShader
{
public:
	//****************************************************************
	// Method:    Init
	// FullName:  CLightShader::Init
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Initial the shader
	//****************************************************************
	virtual bool Init();

	//****************************************************************
	// Method:    SetWVP
	// FullName:  CLightShader::SetWVP
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Matrix4f & matWVP
	// Description: Set the value of WVP
	//****************************************************************
	void SetWVP(const Matrix4f &matWVP);

	//****************************************************************
	// Method:    SetWorldMatrix
	// FullName:  CLightShader::SetWorldMatrix
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Matrix4f * matWorld
	// Description: Set the value of world transform
	//****************************************************************
	void SetWorldMatrix(const Matrix4f *matWorld);

	//****************************************************************
	// Method:    SetTextureUnit
	// FullName:  CLightShader::SetTextureUnit
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: ui32 nTextureUnit
	// Description: Set the texture id of the texture
	//****************************************************************
	void SetTextureUnit(ui32 nTextureUnit);

	//****************************************************************
	// Method:    SetEyeWorldPosition
	// FullName:  CLightShader::SetEyeWorldPosition
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecEyePos
	// Description: Set the position of camera
	//****************************************************************
	void SetEyeWorldPosition(const Vector3f vecEyePos);

	//****************************************************************
	// Method:    SetSpecularPower
	// FullName:  CLightShader::SetSpecularPower
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: f32 fSpecularPower
	// Description: Set the value of specular power
	//****************************************************************
	void SetSpecularPower(f32 fSpecularPower);

	//****************************************************************
	// Method:    SetUseTexture
	// FullName:  CLightShader::SetUseTexture
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 iUseTexture
	// Description: 
	//****************************************************************
	void SetUseTexture(bool bUseTexture);

	//****************************************************************
	// Method:    SetAmbientCoef
	// FullName:  CLightShader::SetAmbientCoef
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecAmbientCoef
	// Description: 
	//****************************************************************
	void SetAmbientCoef(const Vector3f vecAmbientCoef);

	//****************************************************************
	// Method:    SetDiffuseCoef
	// FullName:  CLightShader::SetDiffuseCoef
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecDiffuseCoef
	// Description: 
	//****************************************************************
	void SetDiffuseCoef(const Vector3f vecDiffuseCoef);

	//****************************************************************
	// Method:    SetSpecularCoef
	// FullName:  CLightShader::SetSpecularCoef
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f vecSpecularCoef
	// Description: 
	//****************************************************************
	void SetSpecularCoef(const Vector3f vecSpecularCoef);

	//****************************************************************
	// Method:    SetLights
	// FullName:  CLightShader::SetLights
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 nNumLights
	// Parameter: const Light * pLights
	// Description: Set the value of the lights
	//****************************************************************
	void SetLights(i32 nNumLights, const Light *pLights);

private:
	ui32 m_nWVPLocation;
	ui32 m_nWorldLocation;
	ui32 m_nNumLightsLocation;
	ui32 m_nSamplerLocation;
	ui32 m_nEyeWorldPosLocation;
	ui32 m_nSpecularPowerLocation;
	ui32 m_nUseTextureLocation;
	ui32 m_nAmbientCoefLocation;
	ui32 m_nDiffuseCoefLocation;
	ui32 m_nSpecularCoefLocation;

	struct {
		ui32 color;
		ui32 position;
		ui32 direction;
		struct {
			ui32 constant;
			ui32 linear;
			ui32 exp;
		} atten;
		ui32 cutoff;
	} m_lightsLocation[MAX_LIGHTS];
};

#endif // _CLIGHTSHADER_H_