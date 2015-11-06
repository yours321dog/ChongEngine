/*!
 * \file Tank.cpp
 * \date 2015/10/27
 * \author Lv Luan
 * \brief This is the implement of tank model
*/

#include "Tank.h"
#include "GL/glew.h"
#include "GL/glut.h"

//The vertexs of axis 1
static const GLfloat g_fgAxisOneVertexs[] = {
	-4.0f, -1.5f, -2.0f,
	4.0f, -1.5f, -2.0f,
	-4.0f, 0, -2.0f,
	3.0f, 0, -2.0f,
	-4.0f, -1.5f, 2.0f,
	4.0f, -1.5f, 2.0f,
	-4.0f, 0, 2.0f,
	3.0f, 0, 2.0f,
};

static const GLfloat g_fgAxisOneNormals[] = {
	-4.0f, -1.5f, -2.0f,
	4.0f, -1.5f, -2.0f,
	-4.0f, 0, -2.0f,
	3.0f, 0, -2.0f,
	-4.0f, -1.5f, 2.0f,
	4.0f, -1.5f, 2.0f,
	-4.0f, 0, 2.0f,
	3.0f, 0, 2.0f,
};


//The vertexs of axis 2
static const GLfloat g_fgAxisTwoVertexs[] = {
	-2.0f, -1.0f, -2.0f,
	2.0f, -1.0f, -2.0f,
	-1.0f,  1.0f, -1.0f,
	2.0f,  1.0f, -1.0f,
	-2.0f, -1.0f, 2.0f,
	2.0f, -1.0f, 2.0f,
	-1.0f,  1.0f, 1.0f,
	2.0f,  1.0f, 1.0f,
};

static const GLfloat g_fgAxisTwoNormals[] = {
	-2.0f, -1.0f, -2.0f,
	2.0f, -1.0f, -2.0f,
	-1.0f,  1.0f, -1.0f,
	2.0f,  1.0f, -1.0f,
	-2.0f, -1.0f, 2.0f,
	2.0f, -1.0f, 2.0f,
	-1.0f,  1.0f, 1.0f,
	2.0f,  1.0f, 1.0f,
};

static const GLint g_fgAxisIndex[] = {
	0, 2, 3,
	0, 3, 1,
	0, 4, 6,
	0, 6, 2,
	0, 1, 5,
	0, 5, 4,
	4, 5, 7,
	4, 7, 6,
	1, 3, 7,
	1, 7, 5,
	2, 6, 7,
	2, 7, 3,
};

static const float g_fAmbient[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
static const float g_fDiffuse[4] = { 0.8f, 0.8f, 0.0f, 1.0f};
static const float g_fSpecular[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

Tank::Tank()
	:m_fTankTranslateFactor(0.0f),
	m_fAxisTwoRotateFactor(0.0f),
	m_fAxisThreeRotateFactor(0.0f),
	m_nPolygonMode(GL_FILL)
{
	m_iCylinder = gluNewQuadric();
	gluQuadricDrawStyle(m_iCylinder, m_nPolygonMode);
}

Tank::~Tank()
{
}

void Tank::RunForward()
{
	//The tank can translate forward for 7 units at most
	m_fTankTranslateFactor = m_fTankTranslateFactor >= 6 ? m_fTankTranslateFactor : m_fTankTranslateFactor + 1;
}

void Tank::RunBackward()
{
	//The tank can translate backward for 7 units at most
	m_fTankTranslateFactor = m_fTankTranslateFactor <= -6 ? m_fTankTranslateFactor : m_fTankTranslateFactor - 1;
}

void Tank::UpliftAxisThree()
{
	//The axis 3 can be uplifted for 10 units at most
	m_fAxisThreeRotateFactor = m_fAxisThreeRotateFactor >= 10 ? m_fAxisThreeRotateFactor : m_fAxisThreeRotateFactor + 1;
}

void Tank::LowerAxisThree()
{
	//The axis 3 can be lower for 3 units at most
	m_fAxisThreeRotateFactor = m_fAxisThreeRotateFactor <= -3 ? m_fAxisThreeRotateFactor : m_fAxisThreeRotateFactor - 1;
}

void Tank::RotateAxisTwo()
{
	m_fAxisTwoRotateFactor = ((int)m_fAxisTwoRotateFactor + 1) % 36;
}

void Tank::ResetPosition()
{
	m_fAxisThreeRotateFactor = 0.0f;
	m_fAxisTwoRotateFactor = 0.0f;
	m_fTankTranslateFactor = 0.0f;
}

void Tank::ChangeMode()
{
	//Change the draw mode of the tank to GL_FILL or GL_LINE
	m_nPolygonMode = m_nPolygonMode == GL_FILL ? GL_LINE : GL_FILL;
	gluQuadricDrawStyle(m_iCylinder, m_nPolygonMode);
}

void Tank::Draw()
{
	//Store the old mode so that it can be reset after draw the tank
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glPolygonMode(GL_FRONT_AND_BACK, m_nPolygonMode);

	if (m_nPolygonMode == GL_LINE)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);

		glColor3f(1.0, 1.0, 0.0);
	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, g_fAmbient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, g_fDiffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, g_fSpecular);
	}

	glPushMatrix();
	{
		glTranslatef(m_fTankTranslateFactor * 1.0f, 0.0f, 0.0f);
		DrawAxisOne();

		glPushMatrix();
		{
			glTranslatef(-2.0f, 1.0f, 0.0);
			glRotatef(m_fAxisTwoRotateFactor * 10, 0.0f, 1.0f, 0.0f);
			DrawAxisTwo();

			glPushMatrix();
			{
				glTranslatef(1.0f, 0.0f, 0.0f);
				glRotatef(m_fAxisThreeRotateFactor * 2, 0.0f, 0.0f, 1.0f);
				DrawAxisThree();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPopAttrib();
}

void Tank::DrawAxisOne()
{
	glVertexPointer(3, GL_FLOAT, 0, g_fgAxisOneVertexs);
	glNormalPointer(GL_FLOAT, 0, g_fgAxisOneNormals);

	glEnableClientState(GL_VERTEX_ARRAY);
	if (m_nPolygonMode == GL_FILL)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
	}

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, g_fgAxisIndex);

	if (m_nPolygonMode == GL_FILL)
	{
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Tank::DrawAxisTwo()
{
	glVertexPointer(3, GL_FLOAT, 0, g_fgAxisTwoVertexs);
	glNormalPointer(GL_FLOAT, 0, g_fgAxisOneNormals);

	glEnableClientState(GL_VERTEX_ARRAY);
	if (m_nPolygonMode == GL_FILL)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
	}

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, g_fgAxisIndex);

	if (m_nPolygonMode == GL_FILL)
	{
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Tank::DrawAxisThree()
{
	glPushMatrix();
	glRotatef(90.0, 0, 1.0, 0);
	gluCylinder(m_iCylinder, 0.5, 0.5, 6.0, 32, 6);
	glPopMatrix();
}