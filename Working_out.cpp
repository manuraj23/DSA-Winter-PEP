#include<bits/stdc++.h>
using namespace std;
int solver(int n,int m,vector<vector<int>>&arr){
    for(int i=0;i<n ;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    return 0;
}
int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[n][m];
        }
    }
    solver(n,m,arr);
    return 0;
}