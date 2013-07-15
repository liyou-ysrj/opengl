#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);
  glutCreateWindow("opengl");
  char *res;
  res=glGetString(GL_VERSION);
  printf("version is %s\n",res);
  res=glGetString(GL_VENDOR);
  printf("vendor is %s\n",res);
  res=glGetString(GL_RENDERER);
  printf("render is %s\n",res);

  return 0;
}
