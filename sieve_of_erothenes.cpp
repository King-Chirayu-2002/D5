#include<bits/stdc++.h>
using namespace std;
void find_primes(int n){
    int prime[n+1]={0};
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for (int j = i*i; j <= n; j+=i) 
            {
                prime[j]=1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
       if(prime[i]==0){
        cout<<i<<endl;
       }
    }
}
void spf(int n){
    int prime[101];
    for (int i = 0; i <= 100; i++)
    {
        prime[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(prime[j]==j){
                prime[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<<prime[n]<<" ";
        n/=prime[n];
    }
}
int main(){
    spf(100);
    return 0;
}