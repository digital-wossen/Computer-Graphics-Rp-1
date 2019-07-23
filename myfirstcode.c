#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=2;

void display(void) {
    
    // we will be working on the model view matrix stack
    // Functional equivalent of lookat()
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the drawing plane by z = -4.0
    glTranslatef(0.0,0.0,-10.0);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    
    // set lights
    float lightZeroPosition[] = {10.0, 4.0, 10.0, 1.0};
    float lightZeroColor[] = {0.8, 1.0, 0.8, 1.0}; 
    glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    float ambColor[] =  {1.0, 0.0, 0.0, 1.0};
    float difColor[] =  {1.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, difColor);
    
    // built-in (glut library) function, draws a sphere.
    glutSolidSphere(radius,20,20);
    
    // Swap and flush buffers to screen
    glutSwapBuffers();        
      
}

void reshape(int x, int y) {
    // How to react to the user changing window geometry?
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,1.0,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
} 

int main (int argc, char **argv) {
    // Initial setup and window opening
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("Display a ball in GLUT");
    xRotated = yRotated = zRotated = 30.0;
 
    // Callbacks definitions
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    // Here we go!
    glutMainLoop();
    
    return 0;
}
