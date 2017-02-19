#version 430

in layout(location=0) vec2 position;
in layout(location=1) vec3 vertexColor;

uniform mat4 translationMatrix;

out vec3 theColor;

void main()
{
	vec4 positionVec = vec4(position, 0.0f, 1.0f);
	vec4 newPositionVec = translationMatrix * positionVec;
	gl_Position = newPositionVec;
	theColor = vertexColor;
};