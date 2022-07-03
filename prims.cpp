#include <bits/stdc++.h>
using namespace std;
#define v 5
void print(int key[])
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << key[i] << endl;
    }
}
int minKey(int key[], bool sptset[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (sptset[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void prims(int graph[][v])
{
    int parent[v], key[v];
    bool sptset[v];

    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        sptset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < v - 1; count++)
    {
        int u = minKey(key, sptset);
        sptset[u] = true;
        for (int i = 0; i < v; i++)
        {
            if (!sptset[i] && graph[u][i] && graph[u][i] < key[i])
            {
                key[i] = graph[u][i];
                parent[i] = u;
            }
        }
    }

    print(key);
}
int main()
{
    int graph[v][v] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    prims(graph);

    return 0;
}