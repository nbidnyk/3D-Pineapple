#pragma once
#ifndef RENDER_H
#define RENDER_H

#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "ObjectCoords.h"
#include "Buffers.h"
#include "Shader.h"

#include <glm.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
class Render 
{
	const GLuint WIDTH = 800, HEIGHT = 800;
	int width, height;
	GLint success;
	GLchar infoLog[512];
	GLuint vertexShader;
	GLuint fragmentShader;

public:
	GLFWwindow* window;
	GLuint VAO;
	Render();
	void GameLoop(Buffers Obj, const int n, ObjectCoords* ObjCoord);

};

#endif
