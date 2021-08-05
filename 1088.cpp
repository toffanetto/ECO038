#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int shellSort(int vec[], const int &n)
{
    int count = 0;
    for (int pos = n / 2; pos > 0; pos /= 2)
    {
        for (int i = pos; i < n; i += 1)
        {
            int temp = vec[i];
            int j;
            for (j = i; j >= pos && vec[j - pos] > temp; j -= pos)
            {
                vec[j] = vec[j - pos];
                count++;
            }
            vec[j] = temp;
        }
    }
    return count;
}
int main()
{
    int n, pos, vec[100000], count, temp, i, j;

    while (cin >> n && n)
    {
        for (pos = 0; pos < n; pos++)
            cin >> vec[pos];
        count = 0;
        for (pos = n / 2; pos > 0; pos /= 2)
        {
            for (i = pos; i < n; i += 1)
            {
                temp = vec[i];
                j;
                for (j = i; j >= pos && vec[j - pos] > temp; j -= pos)
                {
                    vec[j] = vec[j - pos];
                    count++;
                }
                vec[j] = temp;
            }
        }
        cout << (count % 2 ? "Marcelo\n" : "Carlos\n");
    }
}
/*
    Impar:  Marcelo
    Par:    Carlos
    (3+3)/2 = 3             impar 
    (4+1+3)/2 = 4           par 
    (0)/2 = 0               par 
    (2+3+1+3+1)/2 = 5       impar
    (4+2+2+4)/2 = 6         par
    (5+3+1+1+3+5)/2 = 9     impar


    1 4 3 2 5 6 (<3, 2>, <5, 4>, <1, 2>)
    5 4 3 2 1   (<5,1>, <4,2>) -> 4 + 2 = 6 

    3 5 2 1 4 6 1
    3 2 5 1 4 6 2
    2 3 5 1 4 6 3
    2 3 1 5 4 6 4
    2 1 3 5 4 6 5
    1 2 3 5 4 6 6
    1 2 3 4 5 6 7



    5 1 5 3 4 2     5
    5 5 1 3 4 2     6
    5 1 2 3 4 5     0
    6 3 5 2 1 4 6   11   
    5 5 4 3 2 1     
*/