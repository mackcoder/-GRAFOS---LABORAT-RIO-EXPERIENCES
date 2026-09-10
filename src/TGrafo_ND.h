#include <iostream>
#include "TGrafo_ND.h"
#include <fstream>

/*
- Andre Doerner Duarte - 10427938
- Matheus Leonardo Cardoso Kroeff - 10426434
- Naoto Ushizaki - 10437445
*/

// Construtor do TGrafo Non-Oriented
TGrafo_ND::TGrafo_ND(int n){
    this->n = n;
    // No inicio dos tempos nao ha arestas
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

// Destructor, responsavel por
// liberar a memoria alocada para a matriz
TGrafo_ND::~TGrafo_ND(){
    for(int i = 0; i < n; i++)
		delete [] adj[i];
	
	delete [] *adj;
    n = 0;
	m = 0;
	std::cout << "espaco liberado";
}

// ⚠️EXERCICIO 7 - RELATORIO
void TGrafo_ND::readfile(const char* grafo_example){
    std::ifstream file(grafo_example);
    if(!file.is_open()){
        std::cout << "ERROR - Unable to access file" << std::endl;
        return;
    }

    int V;
    int A;
    file >> V;
    file >> A;

    int a1, a2;
    for(int y = 0; y < A; y++){
        file >> a1 >> a2;
        NDinsereA(a1, a2);
    }
    file.close();
}

// ⚠️EXERCICIO 8 (Funções ND) - RELATORIO

// Insere uma aresta no Grafo tal que
// v  adjacente a w
void TGrafo_ND::NDinsereA(int v, int w){
    // testa se nao temos a aresta
    if(adj[v][w] == 0 && adj[w][v] == 0){
        // Both ways
        adj[v][w] = 1;
        adj[w][v] = 1;
        m++; // atualiza qtd arestas
    }
}

// remove uma aresta v->w do Grafo
void TGrafo_ND::NDremoveA(int v, int w){
    // testa se temos a aresta
    if(adj[v][w] == 1 && adj[w][v] == 1){
        adj[v][w] = 0;
        adj[w][v] = 0;
        m--; // atualiza qtd arestas
    }
}

// ⚠️EXERCICIO 9 - RELATORIO
int TGrafo_ND::degree(int v){
    int ingrau_nd = 0;
    for(int b = 0; b < n; b++){
        if(adj[v][b] == 1){
            ingrau_nd++;
        }
    }
    return ingrau_nd;
}

void TGrafo_ND::NDshow(){
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;
    for( int i=0; i < n; i++){
        std::cout << "\n";
        for( int w=0; w < n; w++)
            if(adj[i][w] == 1)
                std::cout << "Adj[" << i<< "," << w << "]= 1" << " ";
            else std::cout << "Adj[" << i<< "," << w << "]= 0" << " ";
    }
    std::cout << "\nRESPOSTA 9)\n";
    for(int index = 0; index < n; index++){
        std::cout << "Grau do vertice " << index << ": " << degree(index) << std::endl;
    }
    
    std::cout << "\nfim da impressao do grafo." << std::endl;
}
