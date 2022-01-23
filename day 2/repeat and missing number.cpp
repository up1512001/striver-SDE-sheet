#include<bits/stdc++.h>
using namespace std;

pair<int,int> RandM(vector<int> &arr){
    int xor1=arr[0];
    for(int i=1;i<arr.size();i++){
        xor1 ^= arr[i];
    }
    for(int i=1;i<=arr.size();i++){
        xor1 ^= i; 
    }
    int setbit = xor1 & ~(xor1-1);
    int x=0,y=0;
    for(int i=0;i<arr.size();i++){
        if(setbit & arr[i]) x ^= arr[i];
        else y ^= arr[i];
    }
    for(int i=1;i<=arr.size();i++){
        if (setbit & i)
            x ^= i;
        else
            y ^= i;
    }
    for(int i=0;i<arr.size();i++){
        if(x==arr[i]){
            return make_pair(x,y);
        }
    }
    return make_pair(y,x);
}

int main(){

    cout<<"Enter n value:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    pair<int,int> p = RandM(arr);
    cout << "repeating:" << p.first << " missing :" << p.second << "\n";
}