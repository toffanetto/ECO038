#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int Cr, Cx, Cy, Fr, Fx, Fy;
  float distCF = 0;
  
  while(cin >> Cr >> Cx >> Cy >> Fr >> Fx >> Fy){
    
    distCF = sqrt((Fx - Cx)*(Fx - Cx) + (Fy - Cy)*(Fy - Cy));
    
    cout << ((Cr >= distCF + Fr) ? "RICO" : "MORTO") << endl;
     
    }
  }

  