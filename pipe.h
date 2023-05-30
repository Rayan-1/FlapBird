#ifndef PIPE_H
#define PIPE_H

#include <glm/glm.hpp>

class Pipe{
    private:
        glm::vec2 posicao; //ponto central do espaço vazio entre os obstáculos
        glm::vec2 cor;     //cor do pipe
        float largura;     //largura do pipe
        float velocidade;  //velocidade de movimentação horizontal
    public:
        Pipe(float x);          //construtor
        bool isOut();           //função que indica quando o pipe saiu a esquerda da tela
        void move(float tempo); //função que move o pipe para a esquerda
        void respawn();         //função que retorna pipe para direita e sorteia uma nova posição do espaço vazio
        void desenha();         //função que desenha o pipe
};

#endif // PIPE_H
