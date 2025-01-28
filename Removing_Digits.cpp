// From CSES

#include<bits/stdc++.h>
using namespace std;
int finder(int a){
    int max1=INT_MIN;
    while(a>0){
        int temp=a%10;
        max1=max(max1,temp);
        a=a/10;
    }
    return max1;
}
int main(){
    int n;
    cin>>n;
    int count=0;
    while(n>0){
        int max1=finder(n);
        n=n-max1;
        count++;
    }
    cout<<count;
    return 0;
}