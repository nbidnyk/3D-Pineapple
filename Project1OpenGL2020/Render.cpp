#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "windows.h"
#include "soil.h"
#include "Render.h"
#include "ObjectCoords.h"
#include "Shader.h"
#include "Buffers.h"

#include <glm.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#pragma comment(lib, "soil.lib")
Render::Render()
{

	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glEnable(GL_DEPTH_TEST);

}

void Render::GameLoop(Buffers Obj, const int n, ObjectCoords *ObjCoord)
{


	float stepY1 = 1.5;
	std::cout << stepY1;
	float stepY2 = stepY1 + 1.0*ObjCoord[3].Radius + ObjCoord[2].Radius*0.2;
		
	glm::vec3 Positions[] = {
	glm::vec3(0.0f,  0.18f,  0.0f),
	glm::vec3(0.0f,  -0.05f,  0.0f),
	glm::vec3(0.0f, stepY2 + 0.3,  0.0f),
	glm::vec3(0.0f, stepY2 + 0.4,  0.0f),
	glm::vec3(0.0f, stepY2 + 0.5,  0.0f),
	glm::vec3(0.0f, stepY2 + 0.6,  0.0f)
	};
	
	Shader MyShader("C:\\Users\\User\\source\\Project1OpenGL2020_2\\Shaders\\VertexShader.cpp",
					"C:\\Users\\User\\source\\Project1OpenGL2020_2\\Shaders\\FragmentShader.cpp");
	

	while (!glfwWindowShouldClose(window))
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		glfwPollEvents();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL
		);

		glClearColor(135.0/255, 206.0/255, 235.0/255, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		MyShader.Use();
		
		glm::mat4 view;
		GLfloat radius = 4.5f;
		GLfloat camX = sin(glfwGetTime()) * radius;
		GLfloat camY = 2.0f;
		GLfloat camZ = cos(glfwGetTime()) * radius;

		view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glm::mat4 projection;
		
		
		projection = glm::perspective(glm :: radians(60.0f),/*60*/ (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
			
		GLint modelLoc = glGetUniformLocation(MyShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(MyShader.Program, "view");
		GLint projLoc = glGetUniformLocation(MyShader.Program, "projection");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		for (int i = 0; i < n; i++)
		{
			glBindVertexArray(Obj.VAO[i]);
			
			glm::mat4 model;
			model = glm::translate(model, Positions[i]);
			GLfloat angle = -3.0f * 1;
			model = glm::rotate(model, angle, glm::vec3(0.1f, 1.0f, 1.0f));


			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			glDrawElements(GL_TRIANGLES, ObjCoord[i].indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
			
		}

		glfwSwapBuffers(window);

	}

	//for (int i = 0; i < n; i++)
	//{
	//	std::cout << ObjCoord[i].indices.size() << std::endl;
	//	glDeleteVertexArrays(1, VAO[i]);
	//	glDeleteBuffers(1, VBO[i]);
	//	glDeleteBuffers(1, EBO[i]);
	//}

	glfwTerminate();
}
 
