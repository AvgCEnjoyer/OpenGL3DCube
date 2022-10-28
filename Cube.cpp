#include "Cube.h"
#include <GLFW/glfw3.h>
#include <GLFW/glut.h>
#include <Windows.h>

Cube::Cube(float w, float h, float centerX, float centerY, float centerZ) {

	width = w;
	height = h;
	a = 0.0;
	center[0] = centerX;
	center[1] = centerY;
	center[2] = centerZ;

	coord[0][0] = centerX - w / 2;
	coord[0][1] = centerY - h / 2;
	coord[0][2] = centerZ + w / 2;

	coord[1][0] = centerX + w / 2;
	coord[1][1] = centerY - h / 2;
	coord[1][2] = centerZ + w / 2;

	coord[2][0] = centerX + w / 2;
	coord[2][1] = centerY + h / 2;
	coord[2][2] = centerZ + w / 2;

	coord[3][0] = centerX - w / 2;
	coord[3][1] = centerY + h / 2;
	coord[3][2] = centerZ + w / 2;

	coord[4][0] = centerX - w / 2;
	coord[4][1] = centerY - h / 2;
	coord[4][2] = centerZ - w / 2;

	coord[5][0] = centerX + w / 2;
	coord[5][1] = centerY - h / 2;
	coord[5][2] = centerZ - w / 2;

	coord[6][0] = centerX + w / 2;
	coord[6][1] = centerY + h / 2;
	coord[6][2] = centerZ - w / 2;

	coord[7][0] = centerX - w / 2;
	coord[7][1] = centerY + h / 2;
	coord[7][2] = centerZ - w / 2;
}


void Cube::draw() {


	glPushMatrix();
	glRotatef(a, 1, 0, 0); //rotate alpha around the x axis
	glRotatef(a, 0, 1, 0); //rotate beta around the y axis
	glRotatef(a, 0, 0, 1); //rotate gamma around the z axis


	glBegin(GL_QUADS);

	//Up
	glNormal3d(0.0f, 1.0f, 0.0f);
	glVertex3d(coord[2][0], coord[2][1], coord[2][2]); //RUF
	glVertex3d(coord[3][0], coord[3][1], coord[3][2]); //LUF
	glVertex3d(coord[7][0], coord[7][1], coord[7][2]); //LUB
	glVertex3d(coord[6][0], coord[6][1], coord[6][2]); //RUB

	//Down
	glNormal3d(0.0f, -1.0f, 0.0f);
	glVertex3d(coord[1][0], coord[1][1], coord[1][2]); //RDF
	glVertex3d(coord[0][0], coord[0][1], coord[0][2]); //LDF
	glVertex3d(coord[4][0], coord[4][1], coord[4][2]); //LDB
	glVertex3d(coord[5][0], coord[5][1], coord[5][2]); //RDB

	//Front
	glNormal3d(0.0f, 0.0f, 1.0f);
	glVertex3d(coord[1][0], coord[1][1], coord[1][2]); //RDF
	glVertex3d(coord[0][0], coord[0][1], coord[0][2]); //LDF
	glVertex3d(coord[3][0], coord[3][1], coord[3][2]); //LUF
	glVertex3d(coord[2][0], coord[2][1], coord[2][2]); //RUF

	//Left
	glNormal3d(-1.0f, 0.0f, 0.0f);
	glVertex3d(coord[0][0], coord[0][1], coord[0][2]); //LDF
	glVertex3d(coord[3][0], coord[3][1], coord[3][2]); //LUF
	glVertex3d(coord[7][0], coord[7][1], coord[7][2]); //LUB
	glVertex3d(coord[4][0], coord[4][1], coord[4][2]); //LDB

	//Back
	glNormal3d(0.0f, 0.0f, -1.0f);
	glVertex3d(coord[5][0], coord[5][1], coord[5][2]); //RDB
	glVertex3d(coord[4][0], coord[4][1], coord[4][2]); //LDB
	glVertex3d(coord[7][0], coord[7][1], coord[7][2]); //LUB
	glVertex3d(coord[6][0], coord[6][1], coord[6][2]); //RUB

	//Right
	glNormal3d(1.0f, 0.0f, 0.0f);
	glVertex3d(coord[1][0], coord[1][1], coord[1][2]); //RDF
	glVertex3d(coord[2][0], coord[2][1], coord[2][2]); //RUF
	glVertex3d(coord[6][0], coord[6][1], coord[6][2]); //RUB
	glVertex3d(coord[5][0], coord[5][1], coord[5][2]); //RDB

	glEnd();

	glPopMatrix();

	a += 22.5f * 0.01;
}