#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector <char>> matriz(n, vector<char>(m));
  
    int costa=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matriz[i][j];

            if((i>0 and matriz[i-1][j]=='.' and matriz[i][j]=='#') or (i==0 and matriz[i][j]=='#')){
                ++costa;
                matriz[i][j]= 'C';
                //cout<<"if 1 for 1"<<endl;
                //cout<<"i e j:"<< i <<" "<<j<<endl;
                continue;
            }
            if((j>0 and matriz[i][j-1]=='.' and matriz[i][j]=='#') or (j==0 and matriz[i][j]=='#')){
                costa++;
                matriz[i][j] = 'C';
                //cout<<"if 1 for 1"<<endl;
                //cout<<"i e j:"<< i <<" "<<j<<endl;
                continue;
            }
        }
    }

    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i<(n-1) and matriz[i+1][j]=='.' and matriz[i][j]=='#') or (i==(n-1) and matriz[i][j]=='#')){
                ++costa;
                matriz[i][j]= 'C';
                //cout << "if 1 for 2 | " << i << " " << j << endl;
                continue;
            }
            if((j<(m-1) and matriz[i][j+1]=='.' and matriz[i][j]=='#') or (j==(m-1) and matriz[i][j]=='#')){
                costa++;
                matriz[i][j] = 'C';
                //cout << "if 2 for 2 | " << i << " " << j << endl;
                continue;
            }
        }
    }

    cout << costa << endl;
    
    

}