#include<bits/stdc++.h>
using namespace std;
bool ispower2(int n){
    return (n && !(n & n-1));
}
int count_bit(int n){
    int count=0;
    while(n){
        count++;
        n = n & n-1;
    }
    return count;
}
void generate_subset(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((1<<j) & i ){
                cout<<arr[j];
            }
        }cout<<endl;
    }
    return;
}
int unique_one(int arr[],int n){
    int xorsum=0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}
bool setBit(int n,int pos){
    return ((1<<pos) & n)!=0;
}
void unique_two(int arr[],int n){
    int xorsum=0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    int pos =0;int setbit =0;
    int temp = xorsum;
    while (setbit!=1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum=xorsum>>1;
    }
    cout<<pos<<endl;
    int newxorsum=0;
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxorsum =newxorsum ^ arr[i]; 
        }
    }
    temp = newxorsum^temp;
    cout<<newxorsum<<" "<< temp;
}
int fixBit(int result,int pos){
    return (result | (1<<pos));
}
int getBit(int number,int pos){
    return (number & (1<<pos))!=0;
}
//find a unique number whose triplet do'nt exist

//getting error in it 
int replica3(int arr[],int n){
    int result =0;
    for(int i=0;i<64;i++){
        int sum =0;
        for(int j=0;i<arr[j];j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            cout<<"13";
            result = fixBit(result,i);
        }
    }
    return result;
}
int main(){
    int n;
    n=8;
    int arr[n]={1,1,2,2,1,2,4,4};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    cout<<replica3(arr,n);
    return 0;
}