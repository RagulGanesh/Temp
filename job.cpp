#include<bits/stdc++.h>
using namespace std;
class obj{
    public:
    int profits;
    int deadlines;
};
void job_schduling(obj list[],int n){
    int slots[n],results[n];
    for(int i=0;i<n;i++){
        slots[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(list[i].deadlines,n)-1;j>=0;j--){
            if(slots[j]){
                slots[j]=i;
                results[j]=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slots[i]){
            cout<<list[results[i]].deadlines;
        }
    }
}