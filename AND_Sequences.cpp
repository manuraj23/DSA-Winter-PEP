#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long factorial(int n){
    long long res=1;
    for (int i=2;i<=n;i++){
        res=(res*i)%MOD;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int totalAnd=a[0];
    for(int i=1;i<n;i++){
        totalAnd &=a[i];
    }
    int count=0;
    for (int i=0;i<n;i++){
        if (a[i]==totalAnd){
            count++;
        }
    }
    if(count<2){
        cout<<0<<endl;
        return 0;
    }
    long long result=(count*(count-1))%MOD;
    result=(result*factorial(n-2))%MOD;
    cout<<result<<endl;
    }
    return 0;
}
