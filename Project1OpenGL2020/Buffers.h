#pragma once
#ifndef BUFFERS_H
#define BUFFERS_H

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <vector>
#include "Buffers.h"

class Buffers
{
	GLuint vertexShader;
	GLuint fragmentShader;
	GLint success;
	GLchar infoLog[512];
public:
	GLFWwindow* window;
	GLuint VBO[7], VAO[7], EBO[7];
	GLuint Program;
	void CreateNode(ObjectCoords* Obj, const int n);
};
#endif