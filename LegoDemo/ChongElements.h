/*!
 * \file ChongElements.h
 * \date 2015/11/13
 * \author Lv Luan
 * \brief This is the file to create some elements that store the objects information
 */

#include "ChongUtils.h"
#include <string>

struct Material
{
	f32 ambient[4];
	f32 diffuse[4];
	f32 specular[4];
	f32 shininess;        // [0 = min shininess, 1 = max shininess]
	f32 alpha;            // [0 = fully transparent, 1 = fully opaque]

	std::string name;
	std::string colorMapFilename;
	std::string bumpMapFilename;
};

struct Vertex
{
	f32 position[3];
	f32 texCoord[2];
	f32 normal[3];
	f32 tangent[4];
	f32 bitangent[3];
};

struct Mesh
{
	i32 startIndex;
	i32 triangleCount;
	const Material *pMaterial;
};

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