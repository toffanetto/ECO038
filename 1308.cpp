// y = n*(n+1)/2 -> inverter

#include <iostream>
#include<cmath>

using namespace std;

int main() {
    long long int c,n,delta;
    cin>>n;
    for(long long int i=0;i<n;i++){
      cin>>c;
      c*=2;
      delta=1+4*c;
      delta=(sqrt(delta)-1)/2;
      cout<<delta<<endl;
    }
}