#include<bits/stdc++.h>
using namespace std;
void isPrime(int n){
    int factor =0;
    for(int i =2;i<=sqrt(n);i++){
        if(n%i==0)factor++;
        if(factor>1){
            cout<<"This  is not prime";
            return;
        }
    }
    if(factor==0)cout<<"This is prime";

}
int main(){
    int n ;
    cin>>n;
    isPrime(n);
}
