#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    // int ans=-1;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i][0] = 0;
            }
            else
            {
                if (i == 0)
                {
                    if (j % coins[i] == 0)
                    {
                        dp[0][j] = j / coins[i];
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if (coins[i] > j)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        if (dp[i][j - coins[i]] != INT_MAX)
                        {
                            dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
                        }
                        else
                        {
                            dp[i][j] = dp[i - 1][j];
                        }
                    }
                }
            }
        }
    }
    if (dp[n - 1][amount] == INT_MAX)
        return -1;
    else
        return dp[n - 1][amount];
}
int main(){
    int n, target;
    cin>>n>>target;
    vector<int>coins;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        coins.push_back(temp);
    }
    int ans=coinChange(coins,target);
    cout<<ans;
    return 0;
}