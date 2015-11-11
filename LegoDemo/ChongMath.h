/*!
 * \file ChongMath.h
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This is the file to store the math structure
 */

#ifndef _CHONGMATH_H_
#define _CHONGMATH_H_

#include "ChongUtils.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define ToRadian(x) (float)(((x) * M_PI / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / M_PI))


struct Vector2i
{
	int x;
	int y;
};

struct Vector2f
{
	float x;
	float y;

	//****************************************************************
	// Method:    Vector2f
	// FullName:  cho::stru::Vector2f::Vector2f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	Vector2f()
	{
	}

	//****************************************************************
	// Method:    Vector2f
	// FullName:  cho::stru::Vector2f::Vector2f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float _x
	// Parameter: float _y
	// Description: 
	//****************************************************************
	Vector2f(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};


struct Vector3f
{
	float x;
	float y;
	float z;

	//****************************************************************
	// Method:    Vector3f
	// FullName:  cho::stru::Vector3f::Vector3f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	Vector3f()
	{
	}

	//****************************************************************
	// Method:    Vector3f
	// FullName:  cho::stru::Vector3f::Vector3f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float _x
	// Parameter: float _y
	// Parameter: float _z
	// Description: 
	//****************************************************************
	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	//****************************************************************
	// Method:    Vector3f
	// FullName:  cho::stru::Vector3f::Vector3f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float f
	// Description: 
	//****************************************************************
	Vector3f(float f)
	{
		x = y = z = f;
	}

	//****************************************************************
	// Method:    operator+=
	// FullName:  cho::stru::Vector3f::operator+=
	// Access:    public 
	// Returns:   Vector3f&
	// Qualifier:
	// Parameter: const Vector3f & r
	// Description: 
	//****************************************************************
	Vector3f& operator+=(const Vector3f& r)
	{
		x += r.x;
		y += r.y;
		z += r.z;

		return *this;
	}

	//****************************************************************
	// Method:    operator-=
	// FullName:  cho::stru::Vector3f::operator-=
	// Access:    public 
	// Returns:   Vector3f&
	// Qualifier:
	// Parameter: const Vector3f & r
	// Description: 
	//****************************************************************
	Vector3f& operator-=(const Vector3f& r)
	{
		x -= r.x;
		y -= r.y;
		z -= r.z;

		return *this;
	}

	//****************************************************************
	// Method:    operator*=
	// FullName:  cho::stru::Vector3f::operator*=
	// Access:    public 
	// Returns:   Vector3f&
	// Qualifier:
	// Parameter: float f
	// Description: 
	//****************************************************************
	Vector3f& operator*=(float f)
	{
		x *= f;
		y *= f;
		z *= f;

		return *this;
	}

	//****************************************************************
	// Method:    operator const float*
	// FullName:  cho::stru::Vector3f::operator const float*
	// Access:    public 
	// Returns:   
	// Qualifier: const
	// Description: 
	//****************************************************************
	operator const float*() const
	{
		return &(x);
	}


	//****************************************************************
	// Method:    Cross
	// FullName:  cho::stru::Vector3f::Cross
	// Access:    public 
	// Returns:   cho::stru::Vector3f
	// Qualifier: const
	// Parameter: const Vector3f & v
	// Description: 
	//****************************************************************
	Vector3f Cross(const Vector3f& v) const;

	//****************************************************************
	// Method:    Normalize
	// FullName:  cho::stru::Vector3f::Normalize
	// Access:    public 
	// Returns:   Vector3f&
	// Qualifier:
	// Description: 
	//****************************************************************
	Vector3f& Normalize();

	//****************************************************************
	// Method:    Rotate
	// FullName:  cho::stru::Vector3f::Rotate
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: float Angle
	// Parameter: const Vector3f & Axis
	// Description: 
	//****************************************************************
	void Rotate(float Angle, const Vector3f& Axis);

	//****************************************************************
	// Method:    Print
	// FullName:  cho::stru::Vector3f::Print
	// Access:    public 
	// Returns:   void
	// Qualifier: const
	// Description: 
	//****************************************************************
	void Print() const
	{
		printf("(%.02f, %.02f, %.02f)", x, y, z);
	}
};


struct Vector4f
{
	float x;
	float y;
	float z;
	float w;

	//****************************************************************
	// Method:    Vector4f
	// FullName:  cho::stru::Vector4f::Vector4f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	Vector4f()
	{
	}

	//****************************************************************
	// Method:    Vector4f
	// FullName:  cho::stru::Vector4f::Vector4f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float _x
	// Parameter: float _y
	// Parameter: float _z
	// Parameter: float _w
	// Description: 
	//****************************************************************
	Vector4f(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	//****************************************************************
	// Method:    Print
	// FullName:  cho::stru::Vector4f::Print
	// Access:    public 
	// Returns:   void
	// Qualifier: const
	// Description: 
	//****************************************************************
	void Print() const
	{
		printf("(%.02f, %.02f, %.02f, %.02f)", x, y, z, w);
	}

	//****************************************************************
	// Method:    to3f
	// FullName:  cho::stru::Vector4f::to3f
	// Access:    public 
	// Returns:   cho::stru::Vector3f
	// Qualifier: const
	// Description: 
	//****************************************************************
	Vector3f to3f() const
	{
		Vector3f v(x, y, z);
		return v;
	}
};

//****************************************************************
// Method:    operator+
// FullName:  cho::stru::operator+
// Access:    public 
// Returns:   cho::stru::Vector3f
// Qualifier:
// Parameter: const Vector3f & l
// Parameter: const Vector3f & r
// Description: 
//****************************************************************
inline Vector3f operator+(const Vector3f& l, const Vector3f& r)
{
	Vector3f Ret(l.x + r.x,
		l.y + r.y,
		l.z + r.z);

	return Ret;
}

//****************************************************************
// Method:    operator-
// FullName:  cho::stru::operator-
// Access:    public 
// Returns:   cho::stru::Vector3f
// Qualifier:
// Parameter: const Vector3f & l
// Parameter: const Vector3f & r
// Description: 
//****************************************************************
inline Vector3f operator-(const Vector3f& l, const Vector3f& r)
{
	Vector3f Ret(l.x - r.x,
		l.y - r.y,
		l.z - r.z);

	return Ret;
}

//****************************************************************
// Method:    operator*
// FullName:  cho::stru::operator*
// Access:    public 
// Returns:   cho::stru::Vector3f
// Qualifier:
// Parameter: const Vector3f & l
// Parameter: float f
// Description: 
//****************************************************************
inline Vector3f operator*(const Vector3f& l, float f)
{
	Vector3f Ret(l.x * f,
		l.y * f,
		l.z * f);

	return Ret;
}


//****************************************************************
// Method:    operator/
// FullName:  cho::stru::operator/
// Access:    public 
// Returns:   cho::stru::Vector4f
// Qualifier:
// Parameter: const Vector4f & l
// Parameter: float f
// Description: 
//****************************************************************
inline Vector4f operator/(const Vector4f& l, float f)
{
	Vector4f Ret(l.x / f,
		l.y / f,
		l.z / f,
		l.w / f);

	return Ret;
}


struct PersProjInfo
{
	float FOV;
	float Width;
	float Height;
	float zNear;
	float zFar;
};

class Matrix4f
{
public:
	float m[4][4];

	//****************************************************************
	// Method:    Matrix4f
	// FullName:  cho::stru::Matrix4f::Matrix4f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Description: 
	//****************************************************************
	Matrix4f()
	{
	}

	//****************************************************************
	// Method:    Matrix4f
	// FullName:  cho::stru::Matrix4f::Matrix4f
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float a00
	// Parameter: float a01
	// Parameter: float a02
	// Parameter: float a03
	// Parameter: float a10
	// Parameter: float a11
	// Parameter: float a12
	// Parameter: float a13
	// Parameter: float a20
	// Parameter: float a21
	// Parameter: float a22
	// Parameter: float a23
	// Parameter: float a30
	// Parameter: float a31
	// Parameter: float a32
	// Parameter: float a33
	// Description: 
	//****************************************************************
	Matrix4f(float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23,
		float a30, float a31, float a32, float a33)
	{
		m[0][0] = a00; m[0][1] = a01; m[0][2] = a02; m[0][3] = a03;
		m[1][0] = a10; m[1][1] = a11; m[1][2] = a12; m[1][3] = a13;
		m[2][0] = a20; m[2][1] = a21; m[2][2] = a22; m[2][3] = a23;
		m[3][0] = a30; m[3][1] = a31; m[3][2] = a32; m[3][3] = a33;
	}

	//****************************************************************
	// Method:    SetZero
	// FullName:  cho::stru::Matrix4f::SetZero
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	void SetZero()
	{
		ZERO_MEM(m);
	}

	//****************************************************************
	// Method:    Transpose
	// FullName:  cho::stru::Matrix4f::Transpose
	// Access:    public 
	// Returns:   cho::stru::Matrix4f
	// Qualifier: const
	// Description: 
	//****************************************************************
	Matrix4f Transpose() const
	{
		Matrix4f n;

		for (unsigned int i = 0; i < 4; i++) {
			for (unsigned int j = 0; j < 4; j++) {
				n.m[i][j] = m[j][i];
			}
		}

		return n;
	}


	//****************************************************************
	// Method:    InitIdentity
	// FullName:  cho::stru::Matrix4f::InitIdentity
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	inline void InitIdentity()
	{
		m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
		m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	}

	//****************************************************************
	// Method:    operator*
	// FullName:  cho::stru::Matrix4f::operator*
	// Access:    public 
	// Returns:   cho::stru::Matrix4f
	// Qualifier: const
	// Parameter: const Matrix4f & Right
	// Description: 
	//****************************************************************
	inline Matrix4f operator*(const Matrix4f& Right) const
	{
		Matrix4f Ret;

		for (unsigned int i = 0; i < 4; i++) {
			for (unsigned int j = 0; j < 4; j++) {
				Ret.m[i][j] = m[i][0] * Right.m[0][j] +
					m[i][1] * Right.m[1][j] +
					m[i][2] * Right.m[2][j] +
					m[i][3] * Right.m[3][j];
			}
		}

		return Ret;
	}

	//****************************************************************
	// Method:    operator*
	// FullName:  cho::stru::Matrix4f::operator*
	// Access:    public 
	// Returns:   cho::stru::Vector4f
	// Qualifier: const
	// Parameter: const Vector4f & v
	// Description: 
	//****************************************************************
	Vector4f operator*(const Vector4f& v) const
	{
		Vector4f r;

		r.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
		r.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
		r.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
		r.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;

		return r;
	}

	//****************************************************************
	// Method:    operator const float*
	// FullName:  cho::stru::Matrix4f::operator const float*
	// Access:    public 
	// Returns:   
	// Qualifier: const
	// Description: 
	//****************************************************************
	operator const float*() const
	{
		return &(m[0][0]);
	}

	//****************************************************************
	// Method:    Print
	// FullName:  cho::stru::Matrix4f::Print
	// Access:    public 
	// Returns:   void
	// Qualifier: const
	// Description: 
	//****************************************************************
	void Print() const
	{
		for (int i = 0; i < 4; i++) {
			printf("%f %f %f %f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
		}
	}

	//****************************************************************
	// Method:    Determinant
	// FullName:  cho::stru::Matrix4f::Determinant
	// Access:    public 
	// Returns:   float
	// Qualifier: const
	// Description: 
	//****************************************************************
	float Determinant() const;

	Matrix4f& Inverse();

	//****************************************************************
	// Method:    InitScaleTransform
	// FullName:  cho::stru::Matrix4f::InitScaleTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: float ScaleX
	// Parameter: float ScaleY
	// Parameter: float ScaleZ
	// Description: 
	//****************************************************************
	void InitScaleTransform(float ScaleX, float ScaleY, float ScaleZ);

	//****************************************************************
	// Method:    InitRotateTransform
	// FullName:  cho::stru::Matrix4f::InitRotateTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: float RotateX
	// Parameter: float RotateY
	// Parameter: float RotateZ
	// Description: 
	//****************************************************************
	void InitRotateTransform(float RotateX, float RotateY, float RotateZ);

	//****************************************************************
	// Method:    InitTranslationTransform
	// FullName:  cho::stru::Matrix4f::InitTranslationTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: float x
	// Parameter: float y
	// Parameter: float z
	// Description: 
	//****************************************************************
	void InitTranslationTransform(float x, float y, float z);

	//****************************************************************
	// Method:    InitCameraTransform
	// FullName:  cho::stru::Matrix4f::InitCameraTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const Vector3f & Target
	// Parameter: const Vector3f & Up
	// Description: 
	//****************************************************************
	void InitCameraTransform(const Vector3f& Target, const Vector3f& Up);

	//****************************************************************
	// Method:    InitPersProjTransform
	// FullName:  cho::stru::Matrix4f::InitPersProjTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const PersProjInfo & p
	// Description: 
	//****************************************************************
	void InitPersProjTransform(const PersProjInfo& p);

	//****************************************************************
	// Method:    InitOrthoProjTransform
	// FullName:  cho::stru::Matrix4f::InitOrthoProjTransform
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: const PersProjInfo & p
	// Description: 
	//****************************************************************
	void InitOrthoProjTransform(const PersProjInfo& p);
};

struct Quaternion
{
	float x, y, z, w;

	//****************************************************************
	// Method:    Quaternion
	// FullName:  cho::stru::Quaternion::Quaternion
	// Access:    public 
	// Returns:   
	// Qualifier:
	// Parameter: float _x
	// Parameter: float _y
	// Parameter: float _z
	// Parameter: float _w
	// Description: 
	//****************************************************************
	Quaternion(float _x, float _y, float _z, float _w);

	//****************************************************************
	// Method:    Normalize
	// FullName:  cho::stru::Quaternion::Normalize
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Description: 
	//****************************************************************
	void Normalize();

	//****************************************************************
	// Method:    Conjugate
	// FullName:  cho::stru::Quaternion::Conjugate
	// Access:    public 
	// Returns:   cho::stru::Quaternion
	// Qualifier:
	// Description: 
	//****************************************************************
	Quaternion Conjugate();
};

//****************************************************************
// Method:    operator*
// FullName:  cho::stru::operator*
// Access:    public 
// Returns:   cho::stru::Quaternion
// Qualifier:
// Parameter: const Quaternion & l
// Parameter: const Quaternion & r
// Description: 
//****************************************************************
Quaternion operator*(const Quaternion& l, const Quaternion& r);

//****************************************************************
// Method:    operator*
// FullName:  cho::stru::operator*
// Access:    public 
// Returns:   cho::stru::Quaternion
// Qualifier:
// Parameter: const Quaternion & q
// Parameter: const Vector3f & v
// Description: 
//****************************************************************
Quaternion operator*(const Quaternion& q, const Vector3f& v);


#endif // _CHONGMATH_H_