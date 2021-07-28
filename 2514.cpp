#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
    int m,l1,l2,l3;

    while(cin>>m){
        cin >> l1 >> l2 >> l3;

        int lcm1 = lcm(l1,l2);
        int lcm2 = lcm(lcm1,l3);
        cout << lcm2-m << endl;
            
    }
}