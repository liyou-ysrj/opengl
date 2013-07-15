#version 430 compatibility
uniform float ch;

void main()
{
 vec4 mp=vec4(gl_Vertex.x,gl_Vertex.y*sin(ch/100),gl_Vertex.z,gl_Vertex.w);
 gl_Position=gl_ModelViewProjectionMatrix*mp;
}