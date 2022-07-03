#include<bits/stdc++.h>
using namespace std;
class obj{
    public:
    int weight;
    int profits;
};
bool compare(obj a,obj b){
    double a1=double(a.profits)/double(a.weight);
    double a2=double(b.profits)/double(b.weight);
    return a1>a2;
}
void fractional_knapsack(int max_wt,int n,obj list[]){
    sort(list,list+n,compare);
    double pweight=0,pval=0;
    int i;
    for(i=0;i<n;i++){
        if(pweight+list[i].weight<=max_wt){
            pweight+=list[i].weight;
            pval+=list[i].profits;
            cout<<list[i].weight<<"/"<<list[i].profits<<"\t"<<1<<"\n";
        }
        else{
            double frac_wt=max_wt-pweight;
            pweight=max_wt;
            pval+=(double(frac_wt)/double(list[i].weight))*(list[i].profits);
            cout<<list[i].weight<<"/"<<list[i].profits<<"\t"<<(double(frac_wt)/(double(list[i].weight)))<<"\n";
            break;
        }
    }
     for(int j=i+1;j<n;j++){
        cout<<list[j].weight<<"/"<<list[j].profits<<"\t"<<0<<"\n";
    }

    cout<<"Therefore, total profit is equal to : "<<pval;
}
int main(){
    int n;
    cout<<"Enter number of objects : "; 
    cin>>n;
    int max_wt;
    cout<<"Enter maximum weight : ";
    cin>>max_wt;
    obj list[n];
    int val,wt;
    cout<<"Value/Weights  are : ";
    for(int i=0;i<n;i++){
        val=rand()%300+1;
        wt=rand()%max_wt+1;
        list[i].weight=wt;
        list[i].profits=val;
        cout<<val<<" "<<wt<<"\t\t";
    }
    
    cout<<"\n";
    cout<<"ObjectsChosen\tFractionChosen : \n";
    fractional_knapsack(max_wt,n,list);
}