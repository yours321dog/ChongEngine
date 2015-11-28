/*!
 * \file ICommonObject.cpp
 * \date 2015/11/14
 * \author Lv Luan
 * \brief This is the file which is used to implement the render of common objects
 */

#include "ICommonObject.h"
#include "ChongRenderLagApi.h"

ICommonObject::ICommonObject()
:m_bIsLoad(false),
m_pIndices(NULL),
m_pVertices(NULL)
{

}

bool ICommonObject::Register()
{
	m_nObjectType = OBJECT_TYPE_COMMON;
	return IBaseObject::Register();
}

void ICommonObject::Draw()
{
	if (!m_bIsRegisted || !m_bIsLoad)
	{
		return;
	}

	RenderVertexObject(m_nObjectID, m_nNumTriangles, 0);
}

