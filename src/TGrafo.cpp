#include <iostream>
#include "TGrafo.h"

/*
- Andre Doerner Duarte - 10427938
- Matheus Leonardo Cardoso Kroeff - 10426434
- Naoto Ushizaki - 10437445
*/

// Construtor do TGrafo
TGrafo::TGrafo( int n ){
    this->n = n;
    // No in�cio dos tempos n�o h� arestas
    this->m = 0; 
    // aloca da matriz do TGrafo
    int **adjac = new int*[n];
    for(int i = 0; i < n; i++)
    	adjac[i]= new int[n];
    adj = adjac;
    // Inicia a matriz com zeros
	for(int i = 0; i< n; i++)
		for(int j = 0; j< n; j++)
			adj[i][j]=0;	
}

// Destructor, respons�vel por
// liberar a mem�ria alocada para a matriz
TGrafo::~TGrafo(){
	n = 0;
	m = 0;
	delete [] *adj;
	std::cout << "espa�o liberado";
}

// Insere uma aresta no Grafo tal que
// v � adjacente a w
void TGrafo::insereA(int v, int w){
    // testa se nao temos a aresta
    if(adj[v][w] == 0 ){
        adj[v][w] = 1;
        m++; // atualiza qtd arestas
    }
}

// remove uma aresta v->w do Grafo
void TGrafo::removeA(int v, int w){
    // testa se temos a aresta
    if(adj[v][w] == 1 ){
        adj[v][w] = 0;
        m--; // atualiza qtd arestas
    }
}

// ⚠️EXERCICIO 1 - RELATORIO
int TGrafo::inDegree(int v){
    int ingrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[t][v] == 1)  
            ingrau++;
    }
    return ingrau;
}

// ⚠️EXERCICIO 2 - RELATORIO
int TGrafo::outDegree(int v){
    int outgrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[v][t] == 1)  
            outgrau++;
    }
    return outgrau;
}

// Apresenta o Grafo contendo
// n�mero de v�rtices, arestas
// e a matriz de adjac�ncia obtida
void TGrafo::show(){
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;
    for( int i=0; i < n; i++){
        std::cout << "\n";
        for( int w=0; w < n; w++)
            if(adj[i][w] == 1)
                std::cout << "Adj[" << i<< "," << w << "]= 1" << " ";
            else std::cout << "Adj[" << i<< "," << w << "]= 0" << " ";
    }

    // Resposta 1)

    // Resposta 2)

    // Resposta 3)

    // Resposta 4)

    // Resposta 5)

    // Resposta 6)

    // Resposta 7)

    // Resposta 8)

    // Resposta 9)

    // Resposta 10)

    // Resposta 11)

    // Resposta 12)

    // Resposta 13)

    std::cout << "\nfim da impressao do grafo." << std::endl;
}


