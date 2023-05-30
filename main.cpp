#include <GL/glut.h>
#include <glm/glm.hpp>
#include <cmath>
#include <vector>

#include "bird.h"
#include "pipe.h"

using namespace std;

/*
 * Programa que simula uma parte do jogo Flappy Bird
 * O personagem (círculo) sofre influência da gravidade e se mantem no ar ao pressionar espaço ou a tecla 'a'
 */

//Variáveis globais
float frameRate = 30;

//Um personagem (bird) e três obstáculos em ciclo (pipes)
Bird bird;
Pipe pipe1(7);
Pipe pipe2(9);
Pipe pipe3(11);
std::vector<Pipe> pipes;

//Função com configurações iniciais da aplicação
void inicio(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    pipes.push_back(pipe1);
    pipes.push_back(pipe2);
    pipes.push_back(pipe3);
}

void teclado(unsigned char tecla, int x, int y){
    if(tecla == ' ' || tecla == 'a' || tecla == 'A')
        bird.flap(); //a cada pressionar da tecla, o bird recebe velocidade pra cima
}

//Função indicada pra GLUT que será executada após uma certa quantidade de tempo
void timer(int v){
    glutTimerFunc(1000.0/frameRate, timer, 0); //Controlando o desenho a cada 1000/30 significa que a tela será redesenhada 30 frames por segundo

    bird.cair(1.0/frameRate); //a cada frame, o bird cai sob ação da gravidade

    for(unsigned int i = 0 ; i < pipes.size() ; i++){
        pipes[i].move(1.0/frameRate); //a cada frame, um pipe se move pra esquerda
        if(pipes[i].isOut()) pipes[i].respawn(); //quando sai da tela, ele retorna para a direita
    }

    glutPostRedisplay();
}

//Função indicada na 'main' que será usada para redesenhar o conteúdo do frame buffer
void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);

    //definição da área do sistema de coordenadas do mundo que será usado no jogo
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,6,0,4,-1,1);

    glMatrixMode(GL_MODELVIEW); //habilita o uso de matrizes de transformações geométricas
    glLoadIdentity();           //inicializa a matriz de trasnformação com a matriz identidade (não altera as coordenadas dos pontos)

    //desenha personagem e obstáculos
    bird.desenha();
    for(unsigned int i = 0 ; i < pipes.size() ; i++) pipes[i].desenha();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,360);
    glutCreateWindow("Transformacoes Geometricas 2D - OpenGL Classico");

    inicio();

    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutTimerFunc(1000.0/30, timer, 0);

    glutMainLoop();

    return 0;
}
