#version 330 core
//in vec3 ourColor;
//in vec2 TexCoord;
in vec3 ourColor;
out vec4 color;
//out vec3 Normal;
//uniform sampler2D ourTexture;

void main()
{
	//color = texture(ourTexture, TexCoord);
    color = vec4(ourColor, 1.0f);
	//Normal = vec3(matrixNormal);
}
