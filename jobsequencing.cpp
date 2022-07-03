#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    string id;
    int dead_line;
    int profits;
};
bool cmp(Job a,Job b){
       return (a.profits>b.profits);
}
void jobScheduling(Job list[],int n){
    int result[n];
    bool slots[n];//Initially initialize all the slots to false
    for(int i=0;i<n;i++){
        slots[i]=0;
    }
    
    sort(list,list+n,cmp);

    for(int i=0;i<n;i++){
        for(int j=min(n,list[i].dead_line)-1;j>=0;j--){
            if(slots[j]==false){
                slots[j]=true;
                result[j]=i;
                break;
            }
        }
    }

    int max_profit=0;
    cout<<"Order of execution : ";
    for(int i=0;i<n;i++){
        if(slots[i]){
            cout<<list[result[i]].id<<" ";
            max_profit+=list[result[i]].profits;
        }
    }
    cout<<"\nMaximum Profit : "<<max_profit;


}
int main(){
    int n;
    cout<<"Enter  number of items : ";
    cin>>n;
    cout<<"Enter id/deadline/profits : \n";
    int limit;
    // cout<<"Enter the limit of your deadline : ";
    // cin>>limit;
    Job obj[n];
    for(int i=0;i<n;i++){
        cout<<"Job "<<i+1<<" : ";
        // obj[i].dead_line=rand()%limit+1;
        // obj[i].profits=rand()%500+1;
        // cin>>obj[i].id;
        // cout<<obj[i].dead_line<<" "<<obj[i].profits<<"\n";
        cin>>obj[i].id>>obj[i].dead_line>>obj[i].profits;
    }

    jobScheduling(obj,n);

}
