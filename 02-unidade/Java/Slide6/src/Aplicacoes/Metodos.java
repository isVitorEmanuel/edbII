package Aplicacoes;

import Entidades.*;


public class Metodos<T> {
    
    // Rotação simples à esquerda
    public No<T> rotacaoEsquerda(No<T> x) {
        No<T> y = x.getDir();         // y é o filho direito de x
        x.setDir(y.getEsq());         // o filho esquerdo de y passa a ser o filho direito de x
        y.setEsq(x);                  // x passa a ser o filho esquerdo de y
        return y;                     // y é a nova raiz da subárvore
    }

    // Rotação simples à direita
    public No<T> rotacaoDireita(No<T> x) {
        No<T> y = x.getEsq();         // y é o filho esquerdo de x
        x.setEsq(y.getDir());         // o filho direito de y passa a ser o filho esquerdo de x
        y.setDir(x);                  // x passa a ser o filho direito de y
        return y;                     // y é a nova raiz da subárvore
    }

    // Rotação dupla à esquerda (Left-Right)
    // Primeiro rotaciona o filho direito à direita, depois rotaciona x à esquerda
    public No<T> rotacaoDuplaEsquerda(No<T> x) {
        x.setDir(rotacaoDireita(x.getDir()));  // Primeiro ajusta o filho direito
        return rotacaoEsquerda(x);             // Depois rotaciona à esquerda
    }

    // Rotação dupla à direita (Right-Left)
    // Primeiro rotaciona o filho esquerdo à esquerda, depois rotaciona x à direita
    public No<T> rotacaoDuplaDireita(No<T> x) {
        x.setEsq(rotacaoEsquerda(x.getEsq()));
        return rotacaoDireita(x);
    }
}

