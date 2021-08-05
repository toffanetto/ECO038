#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, k, pos, atual, anterior, total;
    int vet[1000000];

    while (cin >> n >> k)
    {
        vet[0] = total = atual = 0;

        for (pos = 1; pos < n; pos++)
        {
            anterior = atual;
            cin >> atual;
            vet[pos] = atual - anterior;
        }
        sort(vet, vet + n, [](const int &p1, const int &p2)
             { return p1 > p2; });

        for (pos = k - 1; pos < n; pos++)
            total += vet[pos];
        cout << total << endl;
    }
}