#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAX_lista 131072
#define DISTANCE(M1, M2) sqrt(pow((M1.x - M2.x), 2) + pow((M1.y - M2.y), 2))


class Position
{
public:
    int x, y;
} mestres[16];
int n;
double lista[MAX_lista], maxDouble = numeric_limits<double>::max();

double bestDist(int pos)
{
    if (lista[pos] != -1)
        return lista[pos];
    if (pos >= (1 << n) - 1)
        return lista[pos] = 0;

    double aux, best = maxDouble;
    int a, b;

    for (a = 0; a < n; a++)
        if (!((1 << a) & pos))
            break;
    
    for (b = a + 1; b < n; b++)
        if (!((1 << b) & pos))
        {
            aux = bestDist(pos + (1<<a) + (1<<b)) + DISTANCE(mestres[a], mestres[b]);
            if(aux < best) 
                best = aux;
        }

    return lista[pos] = best;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, pos;

    cin >> t;
    
    while (t--)
    {
        fill(lista, lista + MAX_lista, -1);

        cin >> n;
        for (pos = 0; pos < n; pos++)
            cin >> mestres[pos].x >> mestres[pos].y;

        cout << fixed << setprecision(2) << bestDist(0) << endl;
    }

    return 0;
}
