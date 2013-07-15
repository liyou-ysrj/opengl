#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
double angxy=0,angz=0,angXY=0,angZ=0,lenx=0,leny=0,lenz=0,lenZ=0;
double t1=0,tmp=0;
unsigned int t2=1;
GLuint tex1;
int msta=0;
GLint d1;
int fp;
GLfloat mymatrix[16];
GLint w_width,w_height;
GLfloat mc=0,output;
GLint loc;
GLuint prog;
void myloadtex()
{
  GLuint last;
  glGetIntegerv(GL_TEXTURE_BINDING_2D,&last);
  glGenTextures(1,&tex1);
  IplImage* image=cvLoadImage("Ball.bmp",CV_LOAD_IMAGE_ANYCOLOR|CV_LOAD_IMAGE_ANYDEPTH);
  // cvShowImage("tex",image);
  GLubyte* pixels=(GLubyte*)malloc(image->widthStep*image->height);
  memcpy(pixels,image->imageData,image->widthStep*image->height);
  //  printf("width is %d , height is %d \n",image->width,image->height);
  glBindTexture(GL_TEXTURE_2D,tex1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); */
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); */
  GLfloat mrgb[]={1.0f,1.0f,1.0f,1.0f};
  glTexEnvfv(GL_TEXTURE_ENV,GL_TEXTURE_ENV_COLOR,mrgb);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB,image->width,image->height,0,GL_BGR,GL_UNSIGNED_BYTE,pixels);
  cvReleaseImage(&image);
  free(pixels);
  glBindTexture(GL_TEXTURE_2D,last);
  
}
void draw()
{

  /*
    GLfloat aad[]={.0f,1.0f,1.0f,1.0f};
    GLfloat pos[]={60.0f,.0f,.0f,1.0f};
    GLfloat spec[]={1.0f,1.0f,1.0f,1.0f};
    //  glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT_AND_DIFFUSE,aad);
    glLightfv(GL_LIGHT0,GL_POSITION,pos);
    glLightfv(GL_LIGHT0,GL_SPECULAR,spec);

    GLfloat mat_ambient[]={.0f,.0f,.0f,.0f};
    GLfloat mat_specular[] = {0.0f, 0.0f, 0.0f, 0.0f};
    GLfloat mat_emission[] = {0.0f, 0.0f, 0.0f, 0.0f};
    GLfloat mat_diffuse[] = {0.0f, 0.0f, 0.0f, 0.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,mat_emission);
    glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS,70.0f);
  */
  //  d1=glGenLists(1);
  //glNewList(d1,GL_COMPILE);

  


  // glDisable(GL_DEPTH_TEST);
  // glDepthMask(GL_DEPTH_BITS);
  //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  // glDisable(GL_DEPTH_TEST);
  //glDepthMask(GL_DEPTH_BITS);
  /* glEnable(GL_TEXTURE_GEN_S); */
  /* glEnable(GL_TEXTURE_GEN_T); */
  /* glBindTexture(GL_TEXTURE_2D,tex1); */


  /* gluSphere(q,50.0f,100,16); */
  /* glDisable(GL_TEXTURE_GEN_S); */
  /* glDisable(GL_TEXTURE_GEN_T); */


  /* glBegin(GL_TRIANGLES); */
  /* glTexCoord2d((GLdouble)4/424,(GLdouble)173/422); */
  /* glVertex3f(50.0f,-50.0f,-40.0f); */
  /* glTexCoord2d((GLdouble)4/424,(GLdouble)335/422); */
  /* glVertex3f(-50.0f,-50.0f,-40.0f); */
  /* glTexCoord2d((GLdouble)182/424,(GLdouble)355/422); */
  /* glVertex3f(-50.0f,50.0f,-40.0f); */
  /* glEnd(); */

  // glEndList();
}








void mydis()
{

  glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT |GL_STENCIL_BUFFER_BIT);
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  glClearStencil(0);
  glShadeModel(GL_SMOOTH);
  angxy=(GLint)angxy  % 360;
  angz=(GLint)angz  % 360;
  angXY=(GLint)angxy  % 360;
  angZ=(GLint)angz  % 360;


  glBindTexture(GL_TEXTURE_2D,tex1);
  /* glDisable(GL_DEPTH_TEST); */
  /* glDepthMask(GL_DEPTH_BITS); */
  
  GLUquadricObj *q;
  q=gluNewQuadric();
  gluQuadricNormals(q,GL_SMOOTH);
  gluQuadricTexture(q,GL_TRUE);

  glEnable(GL_STENCIL_TEST);
  glStencilFunc(GL_ALWAYS,0,1);
  glStencilOp(GL_KEEP,GL_KEEP,GL_REPLACE);
  /* glTexGenf(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP); */
  /* glTexGenf(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP); */
  /* glEnable(GL_TEXTURE_GEN_S); */
  /* glEnable(GL_TEXTURE_GEN_T); */
  gluSphere(q,50.0f,1000,500);
  /* glDisable(GL_TEXTURE_GEN_S); */
  /* glDisable(GL_TEXTURE_GEN_T); */
  // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  //draw();
  



  // glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_FALSE);
  glDisable(GL_TEXTURE_2D);
  //glEnable(GL_TEXTURE_2D);
  glEnable(GL_STENCIL_TEST);
  glStencilFunc(GL_ALWAYS,1,1);
  glStencilOp(GL_KEEP,GL_KEEP,GL_REPLACE);


  glEnable(GL_FOG);
  glBegin(GL_QUADS);
   /* glColor4f(.0f,1.0f,.0f,.5f); */


  glFogCoordf(1000.0f);
  glTexCoord2d((GLdouble)4/424,(GLdouble)173/422);
  glVertex3f(150.0f,-150.0f,150.0f);


  glFogCoordf(1000.0f);
  glTexCoord2d((GLdouble)4/424,(GLdouble)335/422);
  glVertex3f(150.0f,-150.0f,-150.0f);


  glFogCoordf(1000.0f);
  glTexCoord2d((GLdouble)182/424,(GLdouble)355/422);
  glVertex3f(150.0f,150.0f,-150.0f);



  glFogCoordf(1000.0f);
  glTexCoord2d((GLdouble)181/424,(GLdouble)174/422);
  glVertex3f(150.0f,150.0f,150.0f);
  

  glFogCoordf(100.0f);
  glTexCoord2d((GLdouble)4/424,(GLdouble)173/422);
  glVertex3f(550.0f,-150.0f,150.0f);

 
  glFogCoordf(100.0f);
  glTexCoord2d((GLdouble)4/424,(GLdouble)335/422);
  glVertex3f(550.0f,-150.0f,-150.0f);


  glFogCoordf(100.0f);
  glTexCoord2d((GLdouble)182/424,(GLdouble)355/422);
  glVertex3f(550.0f,150.0f,-150.0f);

 
  glFogCoordf(100.0f);
  glTexCoord2d((GLdouble)181/424,(GLdouble)174/422);
  glVertex3f(550.0f,150.0f,150.0f);

  glEnd();
  glDisable(GL_FOG);
  


  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE); 
  glCullFace(GL_BACK);
  glEnable(GL_STENCIL_TEST);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glStencilFunc(GL_EQUAL,1,1);
  glStencilOp(GL_KEEP,GL_KEEP,GL_REPLACE);
  glEnable(GL_TEXTURE_2D);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslatef(300.0f,.0f,.0f);
  glRotatef(180,.0f,1.0f,.0f);
  
  gluSphere(q,50.0f,1000,500);

  glPopMatrix();
  glDisable(GL_CULL_FACE);
  glDisable(GL_STENCIL_TEST);


 
 
  /* glEnable(GL_BLEND); */
  /* glDisable(GL_TEXTURE_2D); */
  /* glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); */
  /* glBegin(GL_TRIANGLE_FAN); */
  /* glColor4f(1.0f,1.0f,.0f,.5f); */
  /* glTexCoord2d((GLdouble)4/424,(GLdouble)173/422); */
  /* glVertex3f(150.0f,-50.0f,50.0f); */

  /* glTexCoord2d((GLdouble)4/424,(GLdouble)335/422); */
  /* glVertex3f(150.0f,-50.0f,-50.0f); */

  /* glTexCoord2d((GLdouble)182/424,(GLdouble)355/422); */
  /* glVertex3f(150.0f,50.0f,-50.0f); */

  /* glTexCoord2d((GLdouble)181/424,(GLdouble)174/422); */
  /* glVertex3f(150.0f,50.0f,50.0f); */
  
  /* /\* glTexCoord2d((GLdouble)175/424,(GLdouble)9/422); *\/ */
  /* /\* glVertex3f(-50.0f,50.0f,50.0f); *\/ */

  /* /\* glTexCoord2d((GLdouble)4/424,(GLdouble)173/422); *\/ */
  /* /\* glVertex3f(-50.0f,-50.0f,50.0f); *\/ */
  /* glEnd(); */
  /* glEnable(GL_TEXTURE_2D); */
  /* glDisable(GL_BLEND) */;
  



  
  glutSwapBuffers();

  
}

void mykb(unsigned char c,int p1,int p2)
{
  mc++;
  glUniform1f(loc,mc);
  w_width=glutGet(GLUT_WINDOW_WIDTH);
  w_height=glutGet(GLUT_WINDOW_HEIGHT);
  // printf("width is %d , height is %d\n",w_width,w_height);
  glViewport(0,0,w_width,w_height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0f,(GLfloat)w_width/(GLfloat)w_height,1.0f,1000.0f);

  switch(c)
    {
    case 'q':
      glutLeaveMainLoop();
      break;
    case 'w':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
   
      glMultMatrixf(mymatrix);
      glRotatef(1.0f,1.0f,.0f,.0f);
      mydis();
      break;
    case 's':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glMultMatrixf(mymatrix);
      glRotatef(-1.0f,1.0f,.0f,.0f);
      mydis();
      break;
    case 'a':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      glMultMatrixf(mymatrix);
      glRotatef(1.0f,.0f,1.0f,.0f);
      mydis();
      break;
    case 'd':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      glMultMatrixf(mymatrix);
      glRotatef(-1.0f,.0f,1.0f,.0f);
      mydis();
      break;
    case 'f':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(.0f,.0f,1.0f);
      glMultMatrixf(mymatrix);
      mydis();
      break;
    case 'b':
      glGetFloatv(GL_MODELVIEW_MATRIX,mymatrix);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(.0f,.0f,-1.0f);
      glMultMatrixf(mymatrix);
      mydis();
      break;

    case 'W':
      glMatrixMode(GL_MODELVIEW);
      glRotatef(1.0f,1.0f,.0f,.0f);
      mydis();
      break;
    case 'S':
      glMatrixMode(GL_MODELVIEW);
      glRotatef(-1.0f,1.0f,.0f,.0f);
      mydis();
      break;
    case 'A':
      glMatrixMode(GL_MODELVIEW);
      glRotatef(1.0f,.0f,1.0f,.0f);
      mydis();
      break;
    case 'D':
      glMatrixMode(GL_MODELVIEW);
      glRotatef(-1.0f,.0f,1.0f,.0f);
      mydis();
    case 'F':
      glMatrixMode(GL_MODELVIEW);
      glTranslatef(.0f,.0f,1.0f);
      mydis();
      break;
    case 'B':
      glMatrixMode(GL_MODELVIEW);
      glTranslatef(.0f,.0f,-1.0f);
      mydis();
      break;

     

    default:
      break;

    }

}


int main(int argc,char** argv)
{



  glutInit(&argc,argv);
 
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL);
  // glutInitWindowSize(1366,769);
  glutCreateWindow("opengl");
  int err=glewInit();
  printf("GLEW_OK is %d , err is %d\n",GLEW_OK,err);
  printf("glFogCoordf is %d\n",glFogCoordf);
  //  glutFullScreen();  



  FILE *mf=fopen("./myshader.st","r");
  char *mys=malloc(1000);
  fread(mys,1000,1,mf);
  printf("mys is %s\n",mys);
  prog=glCreateProgram();
  GLuint v_shader=glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(v_shader,1,&mys,NULL);
  glCompileShader(v_shader);
  glAttachShader(prog,v_shader);
  glLinkProgram(prog);
  glUseProgram(prog);

  loc=glGetUniformLocation(prog,"ch");
  printf("loc is %d\n",loc);
  GLint tmp;
  tmp=glGetUniformLocation(prog,"t1");
  printf("t1 is %d\n",tmp);
  glUniform1f(tmp,1.0f);
  tmp=glGetUniformLocation(prog,"ch2");
  printf("ch2 is %d\n",tmp);
  glUniform1f(tmp,2.0f);
  GLint InfoLogLength;
  glGetShaderiv(v_shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
  printf("length is %d\n",InfoLogLength);
  GLchar errormsg[InfoLogLength];
  glGetShaderInfoLog(v_shader, InfoLogLength, NULL,errormsg);
  printf("errormsg in shader is %s\n",errormsg);


  glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &InfoLogLength);
  printf("length is %d\n",InfoLogLength);
  glGetProgramInfoLog(prog, InfoLogLength, NULL,errormsg);
  printf("errormsg in program is %s\n",errormsg);





  //glEnable(GL_LIGHTING);
  //glEnable(GL_HINT_BIT);
  //  glHint(GL_LINE_BIT,GL_LINE_SMOOTH);

  w_width=glutGet(GLUT_WINDOW_WIDTH);
  w_height=glutGet(GLUT_WINDOW_HEIGHT);
 

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

  // glEnable(GL_BLEND);
  glEnable(GL_STENCIL_TEST);
   

  GLfloat fogcolor[]={.0f,.5f,.0f,.4f};
  glFogi(GL_FOG_MODE,GL_LINEAR);
  glFogfv(GL_FOG_COLOR,fogcolor);
  glFogf(GL_FOG_DENSITY,1.0f);
  glHint(GL_FOG_HINT,GL_FASTEST);
  glFogf(GL_FOG_START,20.0f);
  glFogf(GL_FOG_END,1000.0f);
  //  glFogi(GL_FOG_COORDINATE_SOURCE,GL_FOG_COORDINATE);


 

  // glLightModelf(GL_LIGHT_MODEL_AMBIENT,20.0);
  // glEnable(GL_BLEND);
  // glBlendFunc(GL_ONE_MINUS_DST_ALPHA,GL_DST_ALPHA);
  //  glutFullScreen();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(.0f,.0f,-400.0f,20.0f,.0f,.0f,.0f,1.0f,.0f);
  


  myloadtex();
  // draw();
  glutDisplayFunc(mydis);
  glutKeyboardFunc(mykb);
  //  glutIdleFunc(myid);
  //  glViewport(0,0,glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));

  //  printf("after view width is %d , height is %d\n",glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
  glutMainLoop();
  

  return 0;
}
