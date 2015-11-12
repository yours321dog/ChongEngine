/*!
 * \file CLightShader.h
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the header of CLightShader, which is used to define the shader of light
 */

#ifndef _CLIGHTSHADER_H_
#define _CLIGHTSHADER_H_

#include "IBaseShader.h"

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
	virtual void Init();

private:
};

#endif // _CLIGHTSHADER_H_