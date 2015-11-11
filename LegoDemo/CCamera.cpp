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

CCamera::CCamera(i32 WindowWidth, i32 WindowHeight)
{
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	m_vecPos = Vector3f(0.0f, 0.0f, 0.0f);
	m_vecTarget = Vector3f(0.0f, 0.0f, 1.0f);
	m_vecTarget.Normalize();
	m_vecUp = Vector3f(0.0f, 1.0f, 0.0f);

	Init();
}


CCamera::CCamera(i32 WindowWidth, i32 WindowHeight, const Vector3f& Pos, const Vector3f& Target, const Vector3f& Up)
{
	m_nWindowWidth = WindowWidth;
	m_nWindowHeight = WindowHeight;
	m_vecPos = Pos;

	m_vecTarget = Target;
	m_vecTarget.Normalize();

	m_vecUp = Up;
	m_vecUp.Normalize();

	Init();
}


void CCamera::Init()
{
	Vector3f HTarget(m_vecTarget.x, 0.0, m_vecTarget.z);
	HTarget.Normalize();

	if (HTarget.z >= 0.0f)
	{
		if (HTarget.x >= 0.0f)
		{
			m_fAngleH = 360.0f - ToDegree(asin(HTarget.z));
		}
		else
		{
			m_fAngleH = 180.0f + ToDegree(asin(HTarget.z));
		}
	}
	else
	{
		if (HTarget.x >= 0.0f)
		{
			m_fAngleH = ToDegree(asin(-HTarget.z));
		}
		else
		{
			m_fAngleH = 90.0f + ToDegree(asin(-HTarget.z));
		}
	}

	m_fAngleV = -ToDegree(asin(m_vecTarget.y));

	m_bOnUpperEdge = false;
	m_bOnLowerEdge = false;
	m_bOnLeftEdge = false;
	m_bOnRightEdge = false;
	m_vecMousePos.x = m_nWindowWidth / 2;
	m_vecMousePos.y = m_nWindowHeight / 2;

	// glutWarpPointer(m_mousePos.x, m_mousePos.y);
}


//bool CCamera::OnKeyboard(OGLDEV_KEY Key)
//{
//	bool Ret = false;
//
//	switch (Key) {
//
//	case OGLDEV_KEY_UP:
//	{
//						  m_pos += (m_target * STEP_SCALE);
//						  Ret = true;
//	}
//		break;
//
//	case OGLDEV_KEY_DOWN:
//	{
//							m_pos -= (m_target * STEP_SCALE);
//							Ret = true;
//	}
//		break;
//
//	case OGLDEV_KEY_LEFT:
//	{
//							Vector3f Left = m_target.Cross(m_up);
//							Left.Normalize();
//							Left *= STEP_SCALE;
//							m_pos += Left;
//							Ret = true;
//	}
//		break;
//
//	case OGLDEV_KEY_RIGHT:
//	{
//							 Vector3f Right = m_up.Cross(m_target);
//							 Right.Normalize();
//							 Right *= STEP_SCALE;
//							 m_pos += Right;
//							 Ret = true;
//	}
//		break;
//
//	case OGLDEV_KEY_PAGE_UP:
//		m_pos.y += STEP_SCALE;
//		break;
//
//	case OGLDEV_KEY_PAGE_DOWN:
//		m_pos.y -= STEP_SCALE;
//		break;
//
//	default:
//		break;
//	}
//
//	return Ret;
//}
//
//
//void CCamera::OnMouse(i32 x, i32 y)
//{
//	const i32 DeltaX = x - m_mousePos.x;
//	const i32 DeltaY = y - m_mousePos.y;
//
//	m_mousePos.x = x;
//	m_mousePos.y = y;
//
//	m_AngleH += (f32)DeltaX / 20.0f;
//	m_AngleV += (f32)DeltaY / 20.0f;
//
//	if (DeltaX == 0) {
//		if (x <= MARGIN) {
//			//    m_AngleH -= 1.0f;
//			m_OnLeftEdge = true;
//		}
//		else if (x >= (m_windowWidth - MARGIN)) {
//			//    m_AngleH += 1.0f;
//			m_OnRightEdge = true;
//		}
//	}
//	else {
//		m_OnLeftEdge = false;
//		m_OnRightEdge = false;
//	}
//
//	if (DeltaY == 0) {
//		if (y <= MARGIN) {
//			m_OnUpperEdge = true;
//		}
//		else if (y >= (m_windowHeight - MARGIN)) {
//			m_OnLowerEdge = true;
//		}
//	}
//	else {
//		m_OnUpperEdge = false;
//		m_OnLowerEdge = false;
//	}
//
//	Update();
//}


void CCamera::OnRender()
{
	bool ShouldUpdate = false;

	if (m_bOnLeftEdge) {
		m_fAngleH -= EDGE_STEP;
		ShouldUpdate = true;
	}
	else if (m_bOnRightEdge) {
		m_fAngleH += EDGE_STEP;
		ShouldUpdate = true;
	}

	if (m_bOnUpperEdge) {
		if (m_fAngleV > -90.0f) {
			m_fAngleV -= EDGE_STEP;
			ShouldUpdate = true;
		}
	}
	else if (m_bOnLowerEdge) {
		if (m_fAngleV < 90.0f) {
			m_fAngleV += EDGE_STEP;
			ShouldUpdate = true;
		}
	}

	if (ShouldUpdate) {
		Update();
	}
}

void CCamera::Update()
{
	const Vector3f Vaxis(0.0f, 1.0f, 0.0f);

	// Rotate the view vector by the horizontal angle around the vertical axis
	Vector3f View(1.0f, 0.0f, 0.0f);
	View.Rotate(m_fAngleH, Vaxis);
	View.Normalize();

	// Rotate the view vector by the vertical angle around the horizontal axis
	Vector3f Haxis = Vaxis.Cross(View);
	Haxis.Normalize();
	View.Rotate(m_fAngleV, Haxis);

	m_vecTarget = View;
	m_vecTarget.Normalize();

	m_vecUp = m_vecTarget.Cross(Haxis);
	m_vecUp.Normalize();
}
