#include "bird.h"

#include "formas.h"

#include <GL/gl.h>

Bird::Bird(){
    posicao = glm::vec2(0.25,2);
    cor = glm::vec3(1,0,0);
    tamanho = 0.2;
    velocidade = 0;
}

void Bird::flap(){
    velocidade = -3; //impulso pra cima é colocar velocidade pra cima (não é fisicamente realista, mas cumpre o papel)
}

void Bird::cair(float tempo){
    float gravidade = 10;
    velocidade = velocidade + gravidade*tempo; //movimento uniformemente variado (modifica velocidade e posição)
    posicao.y = posicao.y - velocidade*tempo;
}

void Bird::desenha(){
    glPushMatrix();

    glTranslatef(posicao.x, posicao.y, 0);
    glScalef(tamanho, tamanho, 1);
    glColor3f(cor.r, cor.g, cor.b);
    Formas::circulo(36); //função da classe Formas que desenha um círculo (polígono de 36 lados)

    glPopMatrix();
}


