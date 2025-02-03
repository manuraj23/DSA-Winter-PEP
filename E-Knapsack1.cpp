#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,target;
    cin>>n>>target;
    vector<long long>weight;
    vector<long long>value;
    for(long long i=0;i<n;i++){
        long long w,v;
        cin>>w>>v;
        weight.push_back(w);
        value.push_back(v);
    }
    vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=target;j++){
            if(j<weight[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][target];
}