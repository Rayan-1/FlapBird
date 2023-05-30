#ifndef BIRD_H
#define BIRD_H

#include <glm/glm.hpp>

class Bird{
    private:
        glm::vec2 posicao;
        glm::vec3 cor;
        float     tamanho;
        float     velocidade;
    public:
        Bird();
        void flap();            //função que dá impulso para cima ao bird
        void cair(float tempo); //função que abaixo o bird sob ação da gravidade
        void desenha();         //função que desenha o bird na tela
};

#endif // BIRD_H
