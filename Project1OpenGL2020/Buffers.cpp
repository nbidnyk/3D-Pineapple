#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Render.h"
#include "ObjectCoords.h"
#include "Buffers.h"
#include "Shader.h"

#include <glm.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void Buffers::CreateNode(ObjectCoords* Obj, const int n)
{
	
	glGenVertexArrays(n, VAO);
	glGenBuffers(n, VBO);
	glGenBuffers(n, EBO);

	for (int i = 0; i < n; i++)
	{
		glBindVertexArray(VAO[i]);

		glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) *Obj[i].vertices.size(), Obj[i].vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) *Obj[i].indices.size(), Obj[i].indices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

	}

}
