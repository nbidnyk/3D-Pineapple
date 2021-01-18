
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "ObjectCoords.h"
#include "Shader.h"
#include <vector>


ObjectCoords :: ObjectCoords()
{

	//GLuint indices[] = {  // Note that we start from 0!
	//0, 1, 3,   // Первый треугольник
	//1, 2, 3    // Второй треугольник
	//};

	//for (int i = 0; i < 12; i++) {
	//	this->indices[i] = indices[i];
	//}
}

ObjectCoords :: ObjectCoords(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep =  0.3 * pi / stackCount;
	Radius = Rad;

}

void ObjectCoords::Greens0(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad * 2;
	GLfloat color1[3] = {0.0, 0.5, 0.0};
	GLfloat color2[3] = { 0.0, 0.9, 0.0 };
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.45 * Radius * cosf(stackAngle);			//r*cos
		z = -0.7 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			
			int stack = i % 2;
			if ((i > 0) and (stack != 0))
			{
				vertices.push_back(color1[0]);//green
				vertices.push_back(color1[1]);
				vertices.push_back(color1[2]);
			}
			else
			{
				vertices.push_back(color2[0]);//yellow
				vertices.push_back(color2[1]);
				vertices.push_back(color2[2]);
			}
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords::Greens(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad*2;
	GLfloat color[3] = {0.0, 0.7, 0.0};
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.4 * Radius * cosf(stackAngle);			//r*cos
		z = -0.7 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			vertices.push_back(color[0]);
			vertices.push_back(color[1]);
			vertices.push_back(color[2]);
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords::Greens2(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad * 2;
	GLfloat color[3] = {0.0, 0.6, 0.0};
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.3 * Radius * cosf(stackAngle);			//r*cos
		z = -0.9 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			vertices.push_back(color[0]);
			vertices.push_back(color[1]);
			vertices.push_back(color[2]);
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords::Greens3(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad * 2;
	GLfloat color[3] = {0.0, 0.9, 0.0};
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.2 * Radius * cosf(stackAngle);			//r*cos
		z = -0.7*2 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			vertices.push_back(color[0]);
			vertices.push_back(color[1]);
			vertices.push_back(color[2]);
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords::Greens4(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad * 2;
	GLfloat color[3] = {0.0, 0.5, 0.0};
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.1 * Radius * cosf(stackAngle);			//r*cos
		z = -0.7 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			vertices.push_back(color[0]);
			vertices.push_back(color[1]);
			vertices.push_back(color[2]);
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords::LowPart(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = 0.5 * pi / stackCount; //0.5*
	Radius = Rad*2;
	GLfloat color1[3] = { 255.0 / 255, 215.0 / 255, 0.0 / 255 };
	GLfloat color2[3] = { 255.0 / 255, 215.0 / 255, 0.0 / 255 };
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		xy = 0.5 * Radius * cosf(stackAngle);			//r*cos
		z = -0.2 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	


		for (int j = 0; j <= sectorCount; ++j) //*4 - (0.5)2 * Radius * sinf(stackAngle)=ellips/2
		{
			sectorAngle = j * sectorStep;		//for 0 to 360

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			y = xy * sinf(sectorAngle);// +rand() % 20 * rand() % 2 * (-1);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			int sector = j % 2;
			int stack = i % 2;
			if ((j > 0) and (sector == 0) and (i > 0) and (stack == 0))
			{
				vertices.push_back(color1[0]);//green
				vertices.push_back(color1[1]);
				vertices.push_back(color1[2]);
			}
			else
			{
				vertices.push_back(color2[0]);//yellow
				vertices.push_back(color2[1]);
				vertices.push_back(color2[2]);
			}
		}
	}



	int k1, k2;
	int n = 2;
	//int stackCount2 = stackCount * n;
	//int sectorCount2 = stackCount * n;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}
void ObjectCoords ::Hemisphere(int sectorCount, int stackCount, float Rad)
{
	sectorStep = 2 * pi / sectorCount;
	stackStep = -0.67 * pi / stackCount; 
	Radius = Rad*1.2;
	GLfloat color1[3] = { 0.0, 0.7, 0.0 };
	GLfloat color2[3] = {255.0/255, 215.0/255, 0.0/255 };
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = pi / 2  - i * stackStep;	
		xy = 1.0*Radius * cosf(stackAngle);			
		z = 1.7* Radius * sinf(stackAngle*0.9);	

		//if (i > (stackCount / 2))
		//{
		//	stackAngle = pi / 2 - i * stackStep;	//from 90 to -90
		//	xy = Radius * cosf(stackAngle);			//r*cos
		//	z = 1.0 * Radius * sinf(stackAngle);// +rand() % 20 * rand() % 2 * (-1);	//r*sin		(0.5)2 * Radius * sinf(stackAngle)=ellips	

		//}
		for (int j = 0; j <= sectorCount; ++j) 
		{
			sectorAngle = j * sectorStep;		

		//polar_coords -> decart_coords
			x = xy * cosf(sectorAngle);
			y = xy * sinf(sectorAngle);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			int sector = j % 2;
			int stack = i % 2;
			if ( (j > 0) and (sector == 0) and (i > 0) and (stack == 0) )
			{
				vertices.push_back(color1[0]);//green
				vertices.push_back(color1[1]);
				vertices.push_back(color1[2]);
			}
			else
			{
				vertices.push_back(color2[0]);//yellow
				vertices.push_back(color2[1]);
				vertices.push_back(color2[2]);
			}
	
		}
	}



	int k1, k2;
	int n = 2;

	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// k1------k1+1
			//  |	  /	|
			//  |   /	|
			//  | /		|
			// k2------k2+1

			//k1 => k2 => k1+1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			//k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
	std::cout << "Sphere\n";
	std::cout << "indices.size: " << indices.size() << std::endl;
	std::cout << "vertices.size: " << vertices.size() << std::endl;
	std::cout << "normals.size: " << vertices.size() << std::endl;
}

