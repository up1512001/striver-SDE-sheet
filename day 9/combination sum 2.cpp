#include<bits/stdc++.h>
using namespace std;

void uniqueCombinationSum(vector<int> &arr,set<vector<int>> &ans,int k,int sum=0,vector<int> temp={},int ind=0){
    if(sum == k){
        // sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    if(sum>k || ind == arr.size()){
        return;
    }
    if(ind < arr.size()){
        uniqueCombinationSum(arr,ans,k,sum,temp,ind+1);
        sum += arr[ind];
        temp.emplace_back(arr[ind]);
        uniqueCombinationSum(arr,ans,k,sum,temp,ind+1);
    }
    return;
}

int main(){
    cout<<"enter size of array :";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // must do sorting
    sort(arr.begin(),arr.end());

    cout<<"enter key value:";
    int k;cin>>k;
    set<vector<int>> ans;
    uniqueCombinationSum(arr,ans,k);
    cout<<"unique combination of given key are:\n";
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }


}