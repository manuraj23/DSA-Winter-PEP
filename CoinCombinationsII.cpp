    #include <bits/stdc++.h>
    using namespace std;
    int MOD=1e9+7;
    int main()
    {
        int n,target;
        cin>>n>>target;
        vector<int>coins;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            coins.push_back(temp);
        }
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1; 
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=dp[i-1][j]%MOD;
                if(j>=coins[i-1]){
                    dp[i][j]=(dp[i][j-coins[i-1]]+dp[i][j])%MOD;
                }
            }  
        }
        cout<<dp[n][target];

        return 0;
    }