/*  @toffanetto
*   Gabriel Toffanetto França da Rocha
*   Universidade Federal de Itajubá - Campus Itabira
*   2294 - Duende Perdido
*/

/*
ISSUE -> change matrix alocation
1- Formar o grafo 
2- Fazer busca em profundidade
3- Pegar menor distancia do duende até uma saída
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


int main(){
    int n,m,cont=0,start;
    vector<int> exit;
    cin >> n >> m;

    pair<int,int> field[100][100];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int aux;
            cin >> aux;
            field[i][j] = make_pair(aux,cont);
            if(field[i][j].first==3)
                start=cont;
            if(field[i][j].first==0)
                exit.push_back(cont);            
            cont++;
        }
    }

    int grafo[100][100];

    memset(grafo, 0, sizeof(int)*100*100);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(field[i][j].first!=2){
                if(j<m-1 && field[i][j+1].first !=2){
                    grafo[field[i][j].second][field[i][j+1].second]=1;
                    grafo[field[i][j+1].second][field[i][j].second]=1;
                }
                if(i<n-1 && field[i+1][j].first!=2){
                    grafo[field[i][j].second][field[i+1][j].second]=1;
                    grafo[field[i+1][j].second][field[i][j].second]=1;
                }
            }
        }
    }

    vector<int> dist(100,999);

    dist.at(start)=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<n*m; i++){
            if(dist[i]==999 && grafo[u][i]){
                dist[i] = dist[u]+1;
                q.push(i);
            }
        }
    }

    int lower = 999;
    for(auto door : exit){
        lower = (dist.at(door) < lower) ? dist.at(door) : lower;
    }
    cout << lower << endl;

}