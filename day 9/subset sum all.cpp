#include<bits/stdc++.h>
using namespace std;


// time complexity will be O(2^N)
void subsetSum(vector<int> &arr,vector<int> &ans,int i=0,int s=0){
    if(i==arr.size()){
        ans.push_back(s);
        return;
    }
    if(i<arr.size()){
        subsetSum(arr,ans,i+1,s);
        s+=arr[i];
        subsetSum(arr, ans, i+1,s);
    }
    return;
}

int main(){
    cout<<"enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> ans;
    subsetSum(arr,ans,0,0);
    cout<<"total possible subset sum are:\n";
    for(auto i:ans) cout<<i<<" ";
}