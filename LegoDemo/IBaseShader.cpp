/*!
 * \file ChongShaderApi.cpp
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This file is the implement of shader loading api
 */

#include "IBaseShader.h"
#include "GL/glew.h"

using std::string;

IBaseShader::IBaseShader()
:m_nFSShader(0),
m_nVSShader(0),
m_nSuccess(0),
m_nShaderProgram(0)
{
	ZERO_MEM(m_strVSFileName);
	ZERO_MEM(m_strFSFileName);
	ZERO_MEM(m_strErrorLog);
}

IBaseShader::~IBaseShader()
{

}

void IBaseShader::Init()
{
	//Create the shading program
	CreateShaderProgram();

	//Attach the shader to the program
	AttachShader(m_nVSShader, m_strVSFileName, GL_VERTEX_SHADER);
	AttachShader(m_nFSShader, m_strFSFileName, GL_FRAGMENT_SHADER);

	//Compile the shader program
	CompileShaders();

	//Enable the shader program
	UseShaderProgram();
}

void IBaseShader::AttachShader(i32 &nShader, const char* pFileName, i32 ShaderType)
{
	nShader = glCreateShader(ShaderType);
	if (nShader == 0) {
		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
		exit(1);
	}

	string strTmp;
	if (!ChongReadFile(pFileName, strTmp)) {
		exit(1);
	};

	const char *pShaderContent = strTmp.c_str();

	const char* p[1];
	p[0] = pShaderContent;
	i32 Lengths[1];
	Lengths[0] = strlen(pShaderContent);
	glShaderSource(nShader, 1, p, Lengths);
	glCompileShader(nShader);

	glGetShaderiv(nShader, GL_COMPILE_STATUS, &m_nSuccess);
	if (!m_nSuccess) {
		glGetShaderInfoLog(nShader, sizeof(m_strErrorLog), NULL, m_strErrorLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, m_strErrorLog);
		exit(1);
	}

	glAttachShader(m_nShaderProgram, nShader);
}

void IBaseShader::CompileShaders()
{
	glLinkProgram(m_nShaderProgram);
	glGetProgramiv(m_nShaderProgram, GL_LINK_STATUS, &m_nSuccess);
	if (m_nSuccess == 0) {
		glGetProgramInfoLog(m_nShaderProgram, sizeof(m_strErrorLog), NULL, m_strErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", m_strErrorLog);
		exit(1);
	}

	glValidateProgram(m_nShaderProgram);
	glGetProgramiv(m_nShaderProgram, GL_VALIDATE_STATUS, &m_nSuccess);
	if (!m_nSuccess) {
		glGetProgramInfoLog(m_nShaderProgram, sizeof(m_strErrorLog), NULL, m_strErrorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", m_strErrorLog);
		exit(1);
	}
}

void IBaseShader::DeleteShader(i32 nShader)
{
	glDeleteShader(nShader);
	glGetProgramiv(nShader, GL_DELETE_STATUS, &m_nSuccess);
	if (!m_nSuccess) {
		glGetProgramInfoLog(nShader, sizeof(m_strErrorLog), NULL, m_strErrorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", m_strErrorLog);
		exit(1);
	}
}

void IBaseShader::DeleteShaderProgram()
{

	glDeleteProgram(m_nShaderProgram);
	glGetProgramiv(m_nShaderProgram, GL_DELETE_STATUS, &m_nSuccess);
	if (!m_nSuccess) {
		glGetProgramInfoLog(m_nShaderProgram, sizeof(m_strErrorLog), NULL, m_strErrorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", m_strErrorLog);
		exit(1);
	}
}

void IBaseShader::CreateShaderProgram()
{
	m_nShaderProgram = glCreateProgram();

	if (m_nShaderProgram == 0) {
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}
}

void IBaseShader::UseShaderProgram()
{
	glUseProgram(m_nShaderProgram);
}

void IBaseShader::SetVSFilename(const char *strVSFileName)
{
	strcpy_s(m_strVSFileName, strVSFileName);
}

void IBaseShader::SetFSFileName(const char *strFSFileName)
{
	strcpy_s(m_strFSFileName, strFSFileName);
}
