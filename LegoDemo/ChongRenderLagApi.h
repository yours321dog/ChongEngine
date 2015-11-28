/*!
 * \file ChongRenderLagApi.h
 * \date 2015/11/05
 * \author Lv Luan
 * \brief This is the header of ChongRenderLagApi, which provides interface for 
 *		  the engine
 */

#ifndef _CHONGRENDERLAGAPI_H_
#define _CHONGRENDERLAGAPI_H_

#include "ChongUtils.h"
#include "ChongMath.h"
#include "ChongElements.h"
#include "ChongConstant.h"
#include "CLightShader.h"

//Initial API

//****************************************************************
// Method:    InitialDevice
// FullName:  cho::core::InitialDevice
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: i32 argc
// Parameter: char * * argv
// Description: Initial the device
//****************************************************************
void InitialDevice(i32 argc, char **argv);

//****************************************************************
// Method:    CreateViewWindow
// FullName:  cho::CreateViewWindow
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: i32 nWindowWidth
// Parameter: i32 nWindowLength
// Parameter: i32 nWindowPosX
// Parameter: i32 nWindowPosY
// Parameter: char * sWindowName
// Description: This function is used to create a window
//****************************************************************
void CreateViewWindow(i32 nWindowWidth = 1024, i32 nWindowLength = 768, i32 nWindowPosX = 100,
	i32 nWindowPosY = 100, char *sWindowName = "ProjectTest");

//****************************************************************
// Method:    InitalRenderEnvironment
// FullName:  InitalRenderEnvironment
// Access:    public 
// Returns:   void
// Qualifier:
// Description: Initial the render environment
//****************************************************************
void InitalRenderEnvironment();

//****************************************************************
// Method:    InitialView
// FullName:  cho::core::InitialView
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: f32 fEyeAngle
// Parameter: f32 fZNear
// Parameter: f32 fZFar
// Description: Initial the viewport and projection
//****************************************************************
void InitialView(f32 fEyeAngle, f32 fZNear, f32 fZFar);

//****************************************************************
// Method:    WindowReshape
// FullName:  cho::core::WindowReshape
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: This function is used to redraw the content when 
//				window changes
//****************************************************************
void WindowReshape(i32 nWindowWidth, i32 nWindowHeight);

//****************************************************************
// Method:    SetWindowReshapeFunc
// FullName:  cho::core::SetWindowReshapeFunc
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: Set the window reshape function
//****************************************************************
void EnableWindowReshapeFunc();

//****************************************************************
// Method:    SetCamera
// FullName:  cho::core::SetCamera
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: f32 fPositionX
// Parameter: f32 fPositionY
// Parameter: f32 fPositionZ
// Parameter: f32 fViewpointX
// Parameter: f32 fViewpointY
// Parameter: f32 fViewpointZ
// Parameter: f32 fTopX
// Parameter: f32 fTopY
// Parameter: f32 fTopZ
// Description: Set the properties of viewing camera
//****************************************************************
void SetCamera(f32 fPositionX, f32 fPositionY, f32 fPositionZ, f32 fViewpointX,
	f32 fViewpointY, f32 fViewpointZ, f32 fTopX = 0.0f, f32 fTopY = 1.0f, f32 fTopZ = 0.0f);

//****************************************************************
// Method:    SetDisplayFunc
// FullName:  cho::core::SetDisplayFunc
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: void
// Parameter: * func
// Parameter: 
// Description: Set the display function
//****************************************************************
void SetDisplayFunc(void(*func)());

//****************************************************************
// Method:    SetKeyBoardFunc
// FullName:  cho::core::SetKeyBoardFunc
// Access:    public static 
// Returns:   void
// Qualifier:
// Parameter: void
// Parameter: * func
// Parameter: unsigned char key
// Parameter: i32 x
// Parameter: i32 y
// Description: Set the key board function
//****************************************************************
void SetKeyBoardFunc(void(*func)(unsigned char key, i32 x, i32 y));

//****************************************************************
// Method:    EnableSimpleLight
// FullName:  cho::core::EnableSimpleLight
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: Enable a simple light
//****************************************************************
void EnableSimpleLight();

//****************************************************************
// Method:    EnableSimpleDepth
// FullName:  cho::core::EnableSimpleDepth
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: Enable simple depth
//****************************************************************
void EnableSimpleDepth();

//****************************************************************
// Method:    RedisplayWindow
// FullName:  cho::core::RedisplayWindow
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: Redisplay the window
//****************************************************************
void RedisplayWindow();

//****************************************************************
// Method:    DoMainLoop
// FullName:  cho::core::DoMainLoop
// Access:    public static 
// Returns:   void
// Qualifier:
// Description: Looping for the external events
//****************************************************************
void DoMainLoop();

//****************************************************************
// Method:    BeforeDrawAllInScene
// FullName:  BeforeDrawAllInScene
// Access:    public 
// Returns:   void
// Qualifier:
// Description: Do something before render all the things
//****************************************************************
void BeforeDrawAllInScene();

//****************************************************************
// Method:    RenderAll
// FullName:  RenderAll
// Access:    public 
// Returns:   void
// Qualifier:
// Description: Render all the things in the scene
//****************************************************************
void DrawALLInScene();

//****************************************************************
// Method:    SetCurrentObjectTran
// FullName:  SetCurrentObjectTran
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: const Matrix4f &
// Description: Set the matrix value of rendering object transform
//****************************************************************
void SetCurrentObjectTran(const Matrix4f &matObjectTransform);

//****************************************************************
// Method:    GetUniqueObjectID
// FullName:  GetUniqueObjectID
// Access:    public 
// Returns:   i32
// Qualifier:
// Parameter: const i32 & nObjectType
// Description: Get an unique ID from system
//****************************************************************
void GetUniqueObjectID(const i32 &nObjectType, ui32 *pObjectID);

//****************************************************************
// Method:    AddLights
// FullName:  AddLights
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: i32 nLight
// Parameter: const Light * pLight
// Description: Add light to the render system
//****************************************************************
void RenderLights(i32 nLight, const Light *pLight);

//****************************************************************
// Method:    StoreOjectVertex
// FullName:  StoreOjectVertex
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: ui32 nObjectID
// Parameter: const Vertex * pVertex
// Description: 
//****************************************************************
void StoreOjectVertex(ui32 *nObjectID, const i32 nVerticesCount, const Vertex *pVertices, 
	const i32 nIndicesCount, const ui32 *pIndices);

//****************************************************************
// Method:    RenderVertexObject
// FullName:  RenderVertexObject
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: ui32 nObjectID
// Description: 
//****************************************************************
void RenderVertexObject(ui32 *pObjectID, const i32 nTrianglesCount, const ui32 nStartIndex);

#endif // _CHONGRENDERLAGAPI_H_
