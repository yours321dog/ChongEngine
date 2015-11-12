/*!
 * \file CLightShader.cpp
 * \date 2015/11/12
 * \author Lv Luan
 * \brief This is the implement of light shader
 */

#include "CLightShader.h"

void CLightShader::Init()
{
	//Set the shaders file name
	SetVSFilename("shader/shader.vs");
	SetFSFileName("shader/shader.fs");

	//Init the shader program
	IBaseShader::Init();
}
