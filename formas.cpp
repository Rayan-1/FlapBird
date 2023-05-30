#include "formas.h"

#include <cmath>
#include <GL/gl.h>

Formas::Formas(){

}

void Formas::circulo(int divisoes){
    glBegin(GL_POLYGON);
        for(int i = 0 ; i < divisoes ; i++){
            float ang = i * (2.0*M_PI/divisoes);
            float x = cos(ang);
            float y = sin(ang);
            glVertex2f(x,y);
        }
        glEnd();
}

void Formas::quadrado(){
    glBegin(GL_QUADS);
        glVertex2f(-1, -1);
        glVertex2f( 1, -1);
        glVertex2f( 1,  1);
        glVertex2f(-1,  1);
    glEnd();
}
