#include <GL/glut.h>
#include <cmath>
#include <iostream>

// void drawWall(double thickness) {
// 	glPushMatrix();
// 	glTranslated(0.5, 0.5 * thickness, 0.5);
// 	glScaled(1.0, thickness, 1.0);
// 	glutSolidCube(1);
// 	glPopMatrix();
// }

int movex = 0 ; 
int movez = -20 ;


float watchx= 0;
int targetx = 0;
int targety = 0;
int targetz = 0;


double tbullet = 0;
float bulletx = 0;
float bullety = 0;
float bulletz = -8;

int mousex = 0 ;
int mousey = 0 ;

float shrukenx = 0 ;
float shrukeny = 0 ;
float shrukenz = 0 ;
float angleshruken  = 0;
float tshruken  = 0;


float grenadex = 0 ; 
float grenadey = 0  ;
float grenadez =0;
bool grenade = false ; 	
bool bullet = false ; 
bool shruken = false ; 


bool shootbullet = false ; 
bool shootgrenade = false ; 
bool shootshruken = false ; 


float  p0[3] ;
float  p1[3] ;
float  p2[3] ;
float  p3[3] ;

int anglebullet = 0 ;
void setgrenade(){
	p0[0]=0;
	p0[1]=0;

	p1[0]=0;
	p1[1]=2;

	p2[0]=0;
	p2[1]=4;

	p3[0]=0;
	p3[1]=0;



}

void setupLights() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(movex,0,movez, mousex,mousey, 0.0, 0.0, 1.0, 0.0);
} 

void drawRoom(){
	glPushMatrix();
	glColor3d(0,0,0);
	
	glBegin(GL_POLYGON);
	glVertex3d(-250,-250,250);
	glVertex3d(-250,250,250);
	glVertex3d(250,250,250);
	glVertex3d(250,0,250);
	glVertex3d(100,0,250);
	glVertex3d(100,-250,250);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3d(0,0,0);
	glVertex3d(-250, 250, 250);

	glVertex3d(-250,-250, 250);
 
	glVertex3d(-250,-250,-250); 
	  glVertex3d(-250, 250,-250);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);
	glColor3d(1,1,0);
	glVertex3d(250,250,250);
	glVertex3d(250,-250,250);
	glVertex3d(250,-250,-250);
	glVertex3d(250,250,-250);
	glEnd();

	glBegin(GL_QUADS);
	glColor3d(1,0,1);
	glVertex3d(250,-250,-250);
	glVertex3d(250,-250,250);
	glVertex3d(-250,-250,250);
    glVertex3d(-250,-250,-250);

	glEnd();

    glPushMatrix();
    glColor3d(0,0.5,1);
	glBegin(GL_QUADS);
	glColor3d(1,1,0);
	glVertex3d(250,250,-250);
	glVertex3d(250,250,250);
	glVertex3d(-250,250,250);
    glVertex3d(-250,250,-250);
    glEnd();
	glPopMatrix();

	glPopMatrix();
}




bool detect(){
	switch(movez){
	case 495:
	case -495:return true ;
		}
		return false ; 


}
 void Anim(){
 	
 	}
void Display() {
	//setupLights();
	setupCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
   glPushMatrix();
   glScaled(0.1,0.1,0.1);
   drawRoom();
    glPopMatrix();

   // drawShurken();
    glPopMatrix();
  
   
	glFlush();
}
void Passivemouse(int x , int y ){
  mousex = 500-x;
  mousey =350-y;
  glutPostRedisplay();
}
void changeMotion(int key ,int x, int y ){

switch(key){
case GLUT_KEY_LEFT :if(!(movex>=245&&movex<=250))movex+=1;break ;
case GLUT_KEY_RIGHT :if(!(movex<=-245&&movex>=-250)) movex-=1;break ;
case GLUT_KEY_UP  :if(!(movez>=245&&movez<=250))movez+=1;break;
case GLUT_KEY_DOWN :if(!(movex<=-245&&movex>=-250))movez-=1;break ;

}
std::cout<<movex<<" "<<movez;
glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Lab 5");
	glutDisplayFunc(Display);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutSpecialFunc(changeMotion);
	//glutKeyboardFunc(Keypress);
	glutPassiveMotionFunc(Passivemouse);
    glutIdleFunc(Anim);
	glShadeModel(GL_SMOOTH);

	glutMainLoop();
	return 0;
}
