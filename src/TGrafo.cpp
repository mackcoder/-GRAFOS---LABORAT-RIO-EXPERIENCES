#include <iostream>
#include "TGrafo.h"
#include <fstream>

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

// ⚠️EXERCICIO 3 - RELATORIO
int TGrafo::degree(int v){
    int grau_total = 0;
    for(int t = 0; t < n; t++){
        if(adj[v][t] == 1)  
            grau_total++;

        if(adj[t][v] == 1)
            grau_total++;
    }
    return grau_total;
}

// ⚠️EXERCICIO 4 - RELATORIO
bool TGrafo::Fonte_check(int v){
    int outgrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[v][t] == 1)  
            outgrau++;
    }

    int ingrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[t][v] == 1)  
            ingrau++;
    }
    if (outgrau > 0 && ingrau == 0)
        return 1;
    else
        return 0;

}

// ⚠️EXERCICIO 5 - RELATORIO
bool TGrafo::Sorvedouro(int v){
    int outgrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[v][t] == 1)  
            outgrau++;
    }

    int ingrau = 0;
    for(int t = 0; t < n; t++){
        if(adj[t][v] == 1)  
            ingrau++;
    }
    if (outgrau == 0 && ingrau > 0)
        return 1;
    else
        return 0;
}

// ⚠️EXERCICIO 6 - RELATORIO
bool TGrafo::isSymetric(){
    for(int a = 0; a < n; a++){
        for(int b == 0; b < n; b++){
            // Checando se todo o grafo é simétrico:
            if(adj[a][b] =! adj[b][a])
                return 0;
        }
    }
    return 0;
}

// ⚠️EXERCICIO 7 - RELATORIO
void TGrafo::readfile(const char* grafo_example){
    std::ifstream file(grafo_example);

    if(!file.is_open()){
        std::cout << "ERROR - Unable to access file" << std::endl;
        return;
    }
    int V;
    int A;
    file >> V;
    file >> A;
    

    int v, t;
    for(int k = 0; k < A; k++){
        file >> v >> t;
        insereA(v, t);
    }

    file.close();
}

// ⚠️EXERCICIO 8 - RELATORIO



// ⚠️EXERCICIO 9 - RELATORIO


// ⚠️EXERCICIO 10 - RELATORIO


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

    std::cout << "\n";
    // Funções sobre Grau:
    // Resposta 1)
    std::cout << "Grau de Entrada do vertice " << v << ": "<< inDegree(v) << std::endl; 

    // Resposta 2)
    std::cout << "\nGrau de Saida do vertice " << v << ": "<< outDegree(v) << std::endl; 

    // Resposta 3)
    std::cout << "Grau total do vertice: " << v << ": " << degree(v) << std::endl;
    //-----------------------------------------------------------------------------------//
    // Função Checa Fonte e Sorvedouro:
    // Resposta 4) && 5)
    for(int v = 0; v < n; v++){
        std::cout << "Vertice " << v << " -> Fonte: " << Fonte_check(v) << "|| Sorvedouro: " << Sorvedouro(v) << std::endl;
    }
    // Função Checa Simétrico:
    // Resposta 6)
        if(isSymetric())
            std::cout << "Grafo é Simétrico" << std::endl; 

    // Resposta 7)


    // Resposta 8)


    // Resposta 9)


    // Resposta 10)

    // Resposta 11)

    // Resposta 12)

    // Resposta 13)
    
    std::cout << "\nfim da impressao do grafo." << std::endl;
}


