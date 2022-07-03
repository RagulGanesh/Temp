#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=5;
    int tn=n+1;
    int p[tn];
    for(int i=0;i<tn;i++){
        cin>>p[i];
    }
    int m[tn][tn],s[tn][tn];
    for(int i=0;i<tn;i++){
        for(int j=0;j<tn;j++){
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    int min,q,j;
    for(int d=1;d<tn-1;d++){
        for(int i=1;i<tn-d;i++){
            j=i+d;
            min=INT_MAX;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
                if(q<min){
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}