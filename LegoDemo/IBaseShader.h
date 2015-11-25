/*!
 * \file ChongShaderApi.h
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This file is used to load the shaders
 */

#ifndef _IBASESHADER_H_
#define _IBASESHADER_H_

#include "ChongUtils.h"

#define INVALID_UNIFORM_LOCATION 0xffffffff

class IBaseShader
{
public:
	//****************************************************************
	// Method:    CShaderManager
	// FullName:  CShaderManager::CShaderManager
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The constructor of CShaderManager
	//****************************************************************
	IBaseShader();

	//****************************************************************
	// Method:    ~CShaderManager
	// FullName:  CShaderManager::~CShaderManager
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: The destructor of CShaderManager
	//****************************************************************
	~IBaseShader();

	//****************************************************************
	// Method:    Init
	// FullName:  IBaseShader::Init
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Description: Init the shaders
	//****************************************************************
	virtual bool Init();

	//****************************************************************
	// Method:    AddShader
	// FullName:  AddShader
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 nShader
	// Parameter: const char * pFileName
	// Parameter: i32 ShaderType
	// Description: Load the shading file and add it to the shader
	//				program
	//****************************************************************
	bool AttachShader(i32 &nShader, const char *pFileName, i32 nShaderType);

	//****************************************************************
	// Method:    CompileShaders
	// FullName:  CShaderManager::CompileShaders
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 nShaderProgram
	// Parameter: const char * pVSFileName
	// Parameter: const char * pFSFileName
	// Description: 
	//****************************************************************
	bool CompileShaders();

	//****************************************************************
	// Method:    DeleteShader
	// FullName:  CShaderManager::DeleteShader
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 nShader
	// Description: 
	//****************************************************************
	bool DeleteShader(i32 nShader);

	//****************************************************************
	// Method:    DeleteShaderProgram
	// FullName:  CShaderManager::DeleteShaderProgram
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: i32 nShaderProgram
	// Description: 
	//****************************************************************
	bool DeleteShaderProgram();

	//****************************************************************
	// Method:    CreateShaderProgram
	// FullName:  IBaseShader::CreateShaderProgram
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Create shader program
	//****************************************************************
	bool CreateShaderProgram();

	//****************************************************************
	// Method:    UseShaderProgram
	// FullName:  IBaseShader::UseShaderProgram
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: Enable the shader program
	//****************************************************************
	void UseShaderProgram();

	//****************************************************************
	// Method:    SetVSFilename
	// FullName:  IBaseShader::SetVSFilename
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const char * strVSFileName
	// Description: Set the file name of vs
	//****************************************************************
	void SetVSFilename(const char *strVSFileName);

	//****************************************************************
	// Method:    SetFSFileName
	// FullName:  IBaseShader::SetFSFileName
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const char * strFSFileName
	// Description: Set the file name of fs
	//****************************************************************
	void SetFSFileName(const char *strFSFileName);

protected:
	//****************************************************************
	// Method:    GetUniformLoacation
	// FullName:  IBaseShader::GetUniformLoacation
	// Access:    protected 
	// Returns:   i32
	// Qualifier:
	// Parameter: const char * pUniformName
	// Description: Return the value of the uniform
	//****************************************************************
	ui32 GetUniformLoacation(const char *pUniformName);

private:
	char m_strVSFileName[50];
	char m_strFSFileName[50];

	i32 m_nShaderProgram;
	i32 m_nVSShader;
	i32 m_nFSShader;

	i32 m_nSuccess;
	char m_strErrorLog[1024];
};

#endif // _IBASESHADER_H_