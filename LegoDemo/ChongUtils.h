/*!
 * \file DemoUtils.h
 * \date 2015/11/05
 * \author Lv Luan
 * \brief Define some macro for the project
 */

#ifndef _CHONGUTILS_H_
#define _CHONGUTILS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <assert.h>

//Redefine the data types
typedef unsigned char uc8;
typedef char c8;
typedef signed char i8;
typedef short i16;
typedef int i32;
typedef unsigned char ui8;
typedef unsigned short ui16;
typedef unsigned int ui32;
typedef float f32;
typedef double f64;

#define ZERO_MEM(a) memset(a, 0, sizeof(a))
#define RANDOM rand

using namespace std;

//Define common function

//****************************************************************
// Method:    ChongReadFile
// FullName:  ChongReadFile
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: const char * pFileName
// Parameter: string & outFile
// Description: This function is used to read the file and store 
//				the file into string
//****************************************************************
bool ChongReadFile(const char* pFileName, string& strOut);

#endif // _CHONGUTILS_H_