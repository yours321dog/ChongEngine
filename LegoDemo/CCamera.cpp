/*!
 * \file CCamera.cpp
 * \date 2015/11/11
 * \author Lv Luan
 * \brief This is the implement of CCamera
 */

/*

Copyright 2010 Etay Meiri

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CCamera.h"

const static f32 STEP_SCALE = 1.0f;
const static f32 EDGE_STEP = 0.5f;
const static i32 MARGIN = 10;

CCamera::CCamera()
:m_vecPos(0.0f, 0.0f, 0.0f),
m_vecTarget(0.0f, 0.0f, 1.0f),
m_vecUp(0.0f, 1.0f, 0.0f)
{
}


CCamera::CCamera(const Vector3f& vecPos, const Vector3f& vecTarget, const Vector3f& vecUp)
:m_vecPos(vecPos),
m_vecTarget(vecTarget),
m_vecUp(vecUp)
{
	m_vecTarget.Normalize();
	m_vecUp.Normalize();
}

const Vector3f& CCamera::GetPos() const
{
	return m_vecPos;
}

const Vector3f& CCamera::GetTarget() const
{
	return m_vecTarget;
}

const Vector3f& CCamera::GetUp() const
{
	return m_vecUp;
}

void CCamera::SetPosition(const Vector3f vecPosition)
{
	m_vecPos = vecPosition;
}

void CCamera::SetTarget(const Vector3f vecTarget)
{
	m_vecTarget = vecTarget;
}

void CCamera::SetUp(const Vector3f vecUp)
{
	m_vecUp = vecUp;
}

