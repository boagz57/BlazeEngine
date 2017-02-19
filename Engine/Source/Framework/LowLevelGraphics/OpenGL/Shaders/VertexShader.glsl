#version 430

in layout(location=0) vec2 position;
in layout(location=1) vec3 vertexColor;

uniform mat4 translationMatrix;
uniform vec2 newPosition;

out vec3 theColor;

void main()
{
	gl_Position = translationMatrix * vec4(position, 0.0f, 1.0f);
	theColor = vertexColor;
};