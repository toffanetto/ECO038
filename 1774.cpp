//!árvore geradora mínima
// https://www.geeksforgeeks.org/kruskals-algorithm-simple-implementation-for-adjacency-matrix/

#include <iostream>
#include<vector>
using namespace std;

int find(int i, vector<int> parent){
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j, vector<int> & parent){
    int a = find(i,parent);
    int b = find(j,parent);
    parent[a] = b;
}

int kruskal(vector<vector <int>>grafom, int rot){
    int mincost = 0;
                cout << "ALIU2" << endl;

    vector<int> parent;

    for(int i=1;i<=rot;i++){
        parent.push_back(i);
                cout << "ALIU2" << endl;
    }

    int edge_count = 0;
    for(int k=0; k<rot-1;k++){
        int min = 999999;
        int a = -1, b = -1;
        for (int i = 1; i <= rot; i++) {
            for (int j = 1; j <=rot; j++) {
                if (find(i,parent) != find(j,parent) && grafom[i][j] < min) {
                    min = grafom[i][j];
                    a = i;
                    b = j;
                }
                cout << "ALIU2" << endl;
            }
        }
        cout << "ALIU" << endl;
        union1(a, b,parent);
         edge_count++;
        mincost += min;
    }
    return mincost;
}   
 

int main(){
    int r,c,v,w,p;

    cin >> r >> c;

    vector<vector <int>> grafo(r+1, vector<int>(r+1,0));
    //cout << "OPA!" << endl;
    for(int i=0;i<c;i++){
        cin >> v >> w >> p;
        grafo[v][w] = p;
        grafo[w][v] = p;
    }
/*
    //cout << "OPA2!" << endl;
    pair<int,int> pos_menor;
    int soma=0;
   
    for(int i=1;i<=r;i++){
        pos_menor = make_pair(0, 10001);
        for(int j=1;j<=r;j++){
            if(grafo[i][j]!=0){
                if(pos_menor.second > grafo[i][j])
                   pos_menor = make_pair(j, grafo[i][j]);
                grafo[i][j] = 0;
            }
        }
        if(pos_menor.second!=10001){
        grafo[i][pos_menor.first] = pos_menor.second;
        //cout << "MENOR " << pos_menor.second << endl;
        soma+=pos_menor.second;
        }
    }
*/
    cout << kruskal(grafo,r) << endl;

}