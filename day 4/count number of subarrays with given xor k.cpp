#include<bits/stdc++.h>
using namespace std;

int countXORk(vector<int> &arr,int k){
    unordered_map<int,int> mp;
    int ans=0,cx=0;
    for(int i=0;i<arr.size();i++){
        cx ^= arr[i];
        // cout<<cx<<" ";
        // cout<<ans<<" ";
        if(cx == k) ans++;
        int temp = k^cx;
        if(mp.find(temp)!=mp.end()){
            ans += mp[temp];
        }
        mp[cx]++;
    }
    return ans;
}

int main(){
    cout<<"enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;cout<<"Enter k value :";cin>>k;
    int ans=countXORk(arr,k);
    cout<<"number of subarrays with given xor are :"<<ans<<"\n";
}