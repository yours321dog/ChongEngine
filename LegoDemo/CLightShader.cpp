/*!
 * \file CLightShader.cpp
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the implement of light shader
 */

#include "CLightShader.h"
#include "ChongElements.h"
#include "GL/glew.h"

bool CLightShader::Init()
{
	//Set the shader file name
	SetVSFilename("shader/shader.vs");
	SetFSFileName("shader/shader.fs");

	//Init the shader program
	if (!IBaseShader::Init())
	{
		return false;
	}

	//get the locations of uniform from shader
	m_nWVPLocation = GetUniformLoacation("gWVP");
	m_nWorldLocation = GetUniformLoacation("gWorld");
	m_nNumLightsLocation = GetUniformLoacation("gNumLights");
	m_nSamplerLocation = GetUniformLoacation("gSampler");
	m_nEyeWorldPosLocation = GetUniformLoacation("gEyeWorldPos");
	m_nSpecularPowerLocation = GetUniformLoacation("gSpecularPower");
	m_nUseTextureLocation = GetUniformLoacation("gUseTexture");
	m_nAmbientCoefLocation = GetUniformLoacation("gAmbientCoef");
	m_nDiffuseCoefLocation = GetUniformLoacation("gDiffuseCoef");
	m_nSpecularCoefLocation = GetUniformLoacation("gSpecularCoef");

	if (m_nWVPLocation == INVALID_UNIFORM_LOCATION ||
		m_nWorldLocation == INVALID_UNIFORM_LOCATION ||
		m_nNumLightsLocation == INVALID_UNIFORM_LOCATION ||
		m_nSamplerLocation == INVALID_UNIFORM_LOCATION ||
		m_nEyeWorldPosLocation == INVALID_UNIFORM_LOCATION ||
		m_nUseTextureLocation == INVALID_UNIFORM_LOCATION ||
		m_nSpecularPowerLocation == INVALID_UNIFORM_LOCATION ||
		m_nAmbientCoefLocation == INVALID_UNIFORM_LOCATION ||
		m_nDiffuseCoefLocation == INVALID_UNIFORM_LOCATION ||
		m_nSpecularCoefLocation == INVALID_UNIFORM_LOCATION)
	{
		return false;
	}

	for (i32 i = 0; i < ARRAY_SIZE_IN_ELEMENTS(m_lightsLocation); i++)
	{
		char name[128];
		ZERO_MEM(name);
		SNPRINTF(name, sizeof(name), "gLights[%d].color", i);
		m_lightsLocation[i].color = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].position", i);
		m_lightsLocation[i].position = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].direction", i);
		m_lightsLocation[i].direction = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].atten.constant", i);
		m_lightsLocation[i].atten.constant = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].atten.linear", i);
		m_lightsLocation[i].atten.linear = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].atten.exp", i);
		m_lightsLocation[i].atten.exp = GetUniformLoacation(name);

		SNPRINTF(name, sizeof(name), "gLights[%d].cutoff", i);
		m_lightsLocation[i].cutoff = GetUniformLoacation(name);

		if (m_lightsLocation[i].color == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].position == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].direction == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].atten.constant == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].atten.linear == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].atten.exp == INVALID_UNIFORM_LOCATION ||
			m_lightsLocation[i].cutoff == INVALID_UNIFORM_LOCATION)
		{
			return false;
		}
	}

	return true;
}

void CLightShader::SetWVP(const Matrix4f &matWVP)
{
	glUniformMatrix4fv(m_nWVPLocation, 1, GL_TRUE, (const GLfloat *)matWVP.m);
}

void CLightShader::SetWorldMatrix(const Matrix4f *matWorld)
{
	glUniformMatrix4fv(m_nWorldLocation, 1, GL_TRUE, (const GLfloat *)matWorld);
}

void CLightShader::SetTextureUnit(ui32 nTextureUnit)
{
	glUniform1i(m_nSamplerLocation, nTextureUnit);
}

void CLightShader::SetEyeWorldPosition(const Vector3f vecEyePos)
{
	glUniform3f(m_nEyeWorldPosLocation, vecEyePos.x, vecEyePos.y, vecEyePos.z);
}

void CLightShader::SetSpecularPower(f32 fSpecularPower)
{
	glUniform1f(m_nSpecularPowerLocation, fSpecularPower);
}

void CLightShader::SetUseTexture(bool bUseTexture)
{
	glUniform1i(m_nUseTextureLocation, bUseTexture);
}

void CLightShader::SetAmbientCoef(const Vector3f vecAmbientCoef)
{
	glUniform3f(m_nAmbientCoefLocation, vecAmbientCoef.x, vecAmbientCoef.y, vecAmbientCoef.z);
}

void CLightShader::SetDiffuseCoef(const Vector3f vecDiffuseCoef)
{
	glUniform3f(m_nDiffuseCoefLocation, vecDiffuseCoef.x, vecDiffuseCoef.y, vecDiffuseCoef.z);
}

void CLightShader::SetSpecularCoef(const Vector3f vecSpecularCoef)
{
	glUniform3f(m_nSpecularCoefLocation, vecSpecularCoef.x, vecSpecularCoef.y, vecSpecularCoef.z);
}

void CLightShader::SetLights(i32 nNumLights, const Light *pLights)
{
	glUniform1i(m_nNumLightsLocation, nNumLights);

	for (i32 i = 0; i < nNumLights; i++)
	{
		glUniform3f(m_lightsLocation[i].color, pLights[i].color.x, pLights[i].color.y, pLights[i].color.z);
		glUniform3f(m_lightsLocation[i].position, pLights[i].position.x, pLights[i].position.y, pLights[i].position.z);
		Vector3f direction = pLights[i].direction;
		direction.Normalize();
		glUniform3f(m_lightsLocation[i].direction, direction.x, direction.y, direction.z);
		glUniform1f(m_lightsLocation[i].atten.constant, pLights[i].atten.constant);
		glUniform1f(m_lightsLocation[i].atten.linear, pLights[i].atten.linear);
		glUniform1f(m_lightsLocation[i].atten.exp, pLights[i].atten.exp);
		glUniform1f(m_lightsLocation[i].cutoff, cosf(ToRadian(pLights[i].cutoff)));
	}
}

