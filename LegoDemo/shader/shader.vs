#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 gWVP;
uniform mat4 gWorld;

out vec2 texCoord0;
out vec3 normal0;
out vec3 worldPos0;

void main()
{
	gl_Position = gWVP * vec4(position, 1.0);
	texCoord0 = texCoord;
	normal0 = (gWorld * vec4(normal, 0.0)).xyz;
	worldPos0 = (gWorld * vec4(position, 1.0)).xyz;
}