#pragma once
#ifndef ObjectCoords_H
#define ObjectCoords_H

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <vector>

class ObjectCoords
{
	float x, y, z, xy;		//vertices
	float nx, ny, nz;		//normal
	float s, t;             // vertex texCoord
	
	const float pi = 3.14;

	float sectorStep;		//lenght of part of horizontal
	float stackStep;		//lenght of part of vertical

	float sectorAngle;		//vertical rotation
	float stackAngle;		//horizontal rotation

public:

	std::vector <GLfloat> vertices;
	std::vector <GLuint> indices;

	float Radius;			
	float heightCyl;

	ObjectCoords();
	ObjectCoords(int sectorCount, int stackCount, float Rad);

	void Hemisphere(int sectorCount, int stackCount, float Rad);

	void Greens0(int sectorCount, int stackCount, float Rad);
	void Greens(int sectorCount, int stackCount, float Rad);
	void Greens2(int sectorCount, int stackCount, float Rad);
	void Greens3(int sectorCount, int stackCount, float Rad);
	void Greens4(int sectorCount, int stackCount, float Rad);
	void LowPart(int sectorCount, int stackCount, float Rad);
	const unsigned int* getIndices() const { return indices.data(); }
	~ObjectCoords()
	{
		std::vector<float>().swap(vertices);
		
		//std::vector<float>().swap(texCoords);
	}
};

#endif
