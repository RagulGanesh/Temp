#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    int *parent,*rank;
    DSU(int v){
        parent=new int[v];
        rank=new int[v];
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    int unite(int x,int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=s1;
            }
            else{
                parent[s2]=s1;
                rank[s1]+=s2;
            }
        }    
    }
};
class Graph{
    public:
    int v;
    vector<vector<int>> EdgeList;
    Graph(int v){
        this->v=v;
    }
    void addEdge(int x,int y,int w){
        EdgeList.push_back({w,x,y});
    }
    void kruskals(){
        int ans=0;
        sort(EdgeList.begin(),EdgeList.end());
        DSU s(v);
        for(auto edge:EdgeList){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                    ans+=w;
            }
        }
        cout<<ans;
    }
};
int main(){
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1,2,5);
 
    // int n, m;
    // cin >> n >> m;
 
    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x, y, w);
    // }
    
    cout<<"Minimum Cost is : ";
    g.kruskals();
    return 0;
}
