#version 430

in layout(location=0) vec3 position;
in layout(location=1) vec3 vertexColor;

uniform mat4 translationMatrix;

out vec3 theColor;

void main()
{
	gl_Position = translationMatrix * vec4(position, 1.0f);
	theColor = vertexColor;
};