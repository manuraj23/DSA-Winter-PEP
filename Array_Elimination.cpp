#include <bits/stdc++.h>
using namespace std;
void solve(){
    int t;
    cin>>t;
    for(int i=0;i<t;t++){
        int n;
        cin>>n;
        vector<int>a(n);
        int total_and=(1 << 30) - 1;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            total_and &= a[i]; 
        }
        if (total_and != 0){
            cout << endl; 
            continue;
        }
        int group_count = 0;
        int current_and = (1 << 30) - 1; 
        for (int i = 0; i < n; ++i)
        {
            current_and &= a[i];
            if (current_and == 0)
            {
                group_count++; 
                current_and = (1 << 30) - 1;
            }
        }
        vector<int> valid_k;
        for (int k = 1; k * k <= group_count; ++k)
        {
            if (group_count % k == 0)
            {
                valid_k.push_back(k);
                if (k != group_count / k)
                {
                    valid_k.push_back(group_count / k);
                }
            }
        }
        sort(valid_k.begin(), valid_k.end());

        for (int k : valid_k)
        {
            cout << k << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
