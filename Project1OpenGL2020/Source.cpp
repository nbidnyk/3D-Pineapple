// GLEW нужно подключать до GLFW.
// GLEW
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

#include <iostream>
#include "ObjectCoords.h"
#include "Render.h"
#include "Buffers.h"
//#include "ObjectCoords2.h"

#include <glm.hpp>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


int main()
{
	const int n = 7;
	Render Renderer;
	   
	ObjectCoords PineappleCoords[n];
	PineappleCoords[0].Hemisphere(28, 29, 0.4);
	PineappleCoords[1].LowPart(20, 10, 0.4*1.06);
	PineappleCoords[2].Greens0(10, 2, 0.4);
	
	PineappleCoords[2].Greens(10, 2, 0.4);
	PineappleCoords[3].Greens2(15, 2, 0.4);
	PineappleCoords[4].Greens3(20, 2, 0.4);
	PineappleCoords[5].Greens4(10, 2, 0.4);
	
	Buffers BufObj;
	BufObj.CreateNode(PineappleCoords, n);
	
	Renderer.GameLoop(BufObj, n, PineappleCoords);

	return 0;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{ 
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
//bool firstMouse = true;
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	GLfloat xoffset = xpos - lastX;	//смещение мыши, произошедшее между последним и текущим кадром :
//	GLfloat yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
//	lastX = xpos;
//	lastY = ypos;
//
//	GLfloat sensitivity = 0.05;	// Change this value to your liking
//	xoffset *= sensitivity;
//	yoffset *= sensitivity;
//
//	yaw += xoffset;
//	pitch += yoffset;
//
//	// Make sure that when pitch is out of bounds, screen doesn't get flipped
//	if (pitch > 89.0f)
//		pitch = 89.0f;
//	if (pitch < -89.0f)
//		pitch = -89.0f;
//
//	glm::vec3 front;
//	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//	front.y = sin(glm::radians(pitch));
//	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//	cameraFront = glm::normalize(front);
//}



