#include<bits/stdc++.h>
using namespace std;
class obj{
    public:
    int weight;
    int profits;
};
void zero_one(int max_wt,int n,obj list[]){
    int B[n+1][max_wt+1];
    int i,w;
    for(i=0;i<=n;i++){
        for(w=0;w<=max_wt;w++){
            if(i==0||w==0){
                B[i][w]=0;
            }
            else if(list[i-1].weight<=w){
                B[i][w]=max(B[i-1][w],B[i-1][w-list[i-1].weight]+list[i-1].profits);
            }
            else{
                B[i][w]=B[i-1][w];
            }
        }
    }
    i=n;
    cout<<"Maximum profit : "<<B[n][max_wt]<<endl;
    int k=max_wt,p=B[n][max_wt];
    while(i>0&&k>0){
        if(B[i][k]!=B[i-1][k]){
            cout<<i<<" ";
            i-=1;
            k-=list[i].weight;
            p-=list[i].profits;
        }
        else{
            i-=1;
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of objects : ";
    cin >> n;
    int max_wt;
    cout << "Enter maximum weight : ";
    cin >> max_wt;
    obj list[n];
    int val, wt;
    cout << "Value/Weights  are : ";
    for (int i = 0; i < n; i++)
    {
        val = rand() % 300 + 1;
        wt = rand() % max_wt + 1;
        list[i].weight = wt;
        list[i].profits = val;
        cout << val << " " << wt << "\t";
    }
    
    cout<<"\n";
    zero_one(max_wt,n,list);

}