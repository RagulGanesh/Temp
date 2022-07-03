#include <bits/stdc++.h>
using namespace std;
int dis[6];
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < 5; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < 5; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[][5], int src)
{
	int dist[5]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[5]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < 5; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < 5 - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < 5; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}
int bellman(int graph[][3], int src, int v, int e)
{
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
    int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3},
    {0,1,0},{0,2,0},{0,3,0},{0,4,0},{0,5,0}};

    bellman(graph, 0, 6, 13);

    int a[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=0;
        }
    }
    int x,y,z;

    for(int i=0;i<13;i++){
        x=graph[i][0];
        y=graph[i][1];
        z=graph[i][2];
        a[x][y]=z+(dis[x]-dis[y]);
        a[y][x]=z+(dis[x]-dis[y]);
        
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    for(int i=0;i<5;i++){
        cout<<"Starting vertex as"<<i<<"\n";
        dijkstra(a,i);
        cout<<"\n";
    }

// dijkstra(a,1);
    return 0;
}

