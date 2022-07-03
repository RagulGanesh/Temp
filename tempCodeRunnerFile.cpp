#include <bits/stdc++.h>
using namespace std;
void bellman(int graph[][3], int src, int v, int e)
{
    int dis[v];
    for (int i = 0; i < v; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (dis[graph[j][0]] != INT_MAX && (dis[graph[j][0] + graph[j][2] < dis[graph[j][1]]]))
            {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }
    for (int i = 0; i < e; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX && (dis[x] + weight < dis[y]))
        {
            dis[y] = dis[x] + weight;
        }
      
    }
      cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < v; i++)
            cout << i << "\t\t" << dis[i] << endl;
}
int main()
{
    int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    bellman(graph, 0, 5, 8);
    return 0;
}