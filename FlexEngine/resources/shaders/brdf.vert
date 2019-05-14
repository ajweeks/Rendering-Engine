#version 400

#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

out vec2 ex_TexCoord;

void main()
{
	ex_TexCoord = vec2((gl_VertexID << 1) & 2, gl_VertexID & 2);
	gl_Position = vec4(ex_TexCoord * 2.0f - 1.0f, 0.0f, 1.0f);
}