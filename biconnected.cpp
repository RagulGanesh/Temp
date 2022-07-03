#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};
class Graph
{
public:
    int v, e;
    list<int> *adjList;
    Graph(int v)
    {
        this->v = v;
        this->e = 0;
        adjList = new list<int>[v];
    }
    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        e++;
    }

    void BccUtil(int u, int parent[], int disc[], int low[], list<Edge> *st)
    {
        static int time = 0;
        low[u] = disc[u] = ++time;
        int children = 0;
        list<int>::iterator i;
        for (i = adjList[u].begin(); i != adjList[u].end(); i++)
        {
            int v = *i;
            if (disc[v] == -1)
            {
                children++;
                parent[v] = u;
                st->push_back(Edge(u, v));
                BccUtil(v, parent, disc, low, st);
                low[u] = min(low[u], low[v]);
                if ((disc[u] == -1 && children > 1) || (disc[u] > 1 && low[v] > disc[u]))
                {
                    while (st->back().u != u || st->back().v != v)
                    {
                        cout << st->back().u << "--" << st->back().v << " ";
                        st->pop_back();
                    }
                    cout << st->back().u << "--" << st->back().v << " ";
                    st->pop_back();
                }
            }
            else if(v!=parent[u]){
                low[u]=min(low[u],disc[v]);
                if(disc[u]>disc[v]){
                    st->push_back(Edge(u,v));
                }
            }
        }
    }

    void Bcc(){
        int* parent=new int[v];
        int* disc=new int[v];
        int* low=new int[v];
        list<Edge>* st=new list<Edge>[e];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            low[i]=-1;
            disc[i]=-1;
        }
        for(int i=0;i<v;i++){
            if(disc[i]==-1){
                BccUtil(i,parent,disc,low,st);
            }
            while(st->size()>0){
                cout<<st->back().u<<"--"<<st->back().v<<" ";
                st->pop_back();
            }
        }
    }
};
int main()
{
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.Bcc();
	return 0;
}