#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter number of vertices : ";
    int n;
    cin>>n;
    int weightMatrix[n][n];
    cout<<"Enter the weight matrix : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>weightMatrix[i][j];
        }
    }
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=weightMatrix[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((dist[i][j]>dist[i][k]+dist[k][j])&&(dist[i][k]!=999&&dist[k][j]!=999)){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 999)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}