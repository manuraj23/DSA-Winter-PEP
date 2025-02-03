#include <bits/stdc++.h>
using namespace std;
int main()
{
    const long long MAX_VAL=1e5;
    long long n, target;
    cin >> n >> target;
    vector<long long> weight;
    vector<long long> value;
    for (long long i = 0; i < n; i++)
    {
        long long w, v;
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    vector<vector<long long>> dp(n+2,vector<long long>(target+1,1e17));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int index=n;index<=n+1;index++){
        for(int valueLeft=0;valueLeft<=target;valueLeft++){
            dp[index][valueLeft]=dp[index+1][valueLeft];
            if(valueLeft-value[index]>=0){
                dp[index][valueLeft]=min(dp[index][valueLeft],weight[index]+dp[index+1][valueLeft-valueLeft-value[index]]);
            }
        }
    }
    long long ans=0;
    for(long long valueLeft=MAX_VAL;valueLeft>=0;valueLeft--){
        if(dp[1][valueLeft]<=target){
            if(dp[1][valueLeft]<=target){
                ans=valueLeft;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}