#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void DFS(int i, vector<bool> &visitados, vector<vector<int>> grafo){
    visitados.at(i) = true;
    vector<int> ramo = grafo.at(i);
    
    for(int j=0;j<ramo.size();j++){
        if(!visitados[j])
            DFS(i,visitados,grafo);
    }
}


int numeroDeConexos(int n, vector<vector<int>> grafo){
    vector<bool> visitados(n,0);
    int cont =0;

    for(int i=0;i<n;i++){
        if(!visitados.at(i)){
            DFS(i,visitados,grafo);
            cont++;
        }
    }    

    return cont;

}



int main(){
    int m,n,c=1;
    cin >> n >> m;
    vector<vector<int>> arvore(n+1,vector<int>(n+1,0));

    unordered_map<string, int> cod;

    string nome1, lixo, nome2;

    for(int i=0;i<m;i++){

        cin >> nome1 >> lixo >> nome2;

        if(cod.find(nome1) == cod.end()){
            cod.insert(make_pair(nome1,c));
            c++;
        }

        if(cod.find(nome2) == cod.end()){
            cod.insert(make_pair(nome2,c));
            c++;
        }

        arvore[cod.at(nome1)][cod.at(nome2)] = 1;

    }

    cout << numeroDeConexos(n, arvore) << endl;

}