#include<bits/stdc++.h>
using namespace std;
void printSolution(int slots[],int n){
    set<int> c;
    for(int i=0;i<n;i++){
        c.insert(slots[i]);
    }
    cout<<c.size();
}
bool isSafe(vector<vector<int>> &clash,int slots[],int c,int v,int n){
    for(int i=0;i<n;i++){
        if(clash[v][i]&&slots[i]==c){
            return false;
        }
    }
    return true;
}
bool graphUtil(vector<vector<int>> &clash,int slots[],int v,int n){
    if(v==n){
        return true;
    }
    for(int c=1;c<=n;c++){
        if(isSafe(clash,slots,c,v,n)){
            slots[v]=c;
            if(graphUtil(clash,slots,v+1,n)==true){
                return true;
            }
            slots[v]=0;
        }
    }
    return false;
}
bool graphColoring(vector<vector<int>> &clash,int n){
    int slots[n];
    for(int i=0;i<n;i++){
        slots[i]=0;
    }
    if(graphUtil(clash,slots,0,n)==false){
        cout<<"Solution doesn't exist";
        return false;
    }
    printSolution(slots,n);
    return true;

}
int main(){
    cout << "Enter number of subjects: ";
    int n;
    cin >> n;
    // string names[n],codes[n];
    // cout << "Enter subject names and codes:";
    // for(int i=0;i<n;i++){
    //     cin >> names[i] >> codes[i];
    // }
    vector <vector <int>> coll;
    cout << "Enter the graph collision values:"<< endl;
    for(int i=0;i<n;i++){
        vector <int> row;
        for(int j=0;j<n;j++){
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        coll.push_back(row);
    }
    // int m=10;
    graphColoring(coll,n);

    return 0;
}