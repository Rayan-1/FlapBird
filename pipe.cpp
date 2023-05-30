#include "pipe.h"

#include "formas.h"

#include <cstdlib>
#include <GL/gl.h>

Pipe::Pipe(float x){
    posicao = glm::vec2(x, 1 + rand() % 3);
    velocidade = 1;
    largura = 0.25;
}

bool Pipe::isOut(){
    return posicao.x < 0 - largura;
}

void Pipe::move(float tempo){
    posicao.x = posicao.x - velocidade * tempo; //movimentação uniforme constante (modifica apenas posição)
}

void Pipe::respawn(){
    posicao.x = 6 + largura;
    posicao.y = 1 + rand() % 3;
}

void Pipe::desenha(){
    //O pipe é um par de obstáculo (superior e inferior)
    //obstáculo inferior
    glPushMatrix();
    glTranslatef(posicao.x, (posicao.y - 0.5)/2.0, 0);
    glScalef(largura,(posicao.y - 0.5)/2.0,1);
    Formas::quadrado();
    glPopMatrix();

    //obstaculo superior
    glPushMatrix();
    glTranslatef(posicao.x, (posicao.y + 4.5)/2.0, 0);
    glScalef(largura,(3.5 - posicao.y)/2.0,1);
    Formas::quadrado();
    glPopMatrix();
}
