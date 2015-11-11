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

#endif // _CHONGRENDERLAGAPI_H_
