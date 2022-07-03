#include <bits/stdc++.h>
using namespace std;
int a[10][10], travelled[10], cost = 0, n;
void takeinput()
{
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter matrix : ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        travelled[i] = 0;
    }
}
int least(int c)
{
    int nc = INT_MAX, min = INT_MAX, kmin;
    for (int i = 0; i < n; i++)
    {
        if ((travelled[i] == 0 && a[c][i] != 0))
        {
            if (a[c][i] + a[i][c] < min)
            {
                min = a[c][i] + a[i][0];
                kmin = a[c][i];
                nc = i;
            }
        }
    }
    if (min != INT_MAX)
    {
        cost += kmin;
    }
    return nc;
}
void minimum_cost(int object)
{
    travelled[object] = 1;
    cout << object + 1 << "-->";
    int nobject = least(object);
    if (nobject == INT_MAX)
    {
        nobject = 0;
        cout << nobject + 1;
        cost += a[object][nobject];
        return;
    }
    minimum_cost(nobject);
}
int main()
{

    takeinput();
    minimum_cost(0);
    return 0;
}