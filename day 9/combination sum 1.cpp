#include<bits/stdc++.h>
using namespace std;

void combinationSum(vector<int> &arr,vector<vector<int>> &ans,int k,int sum=0,vector<int>temp={},int ind=0){
    if(sum == k){
        ans.push_back(temp);
        return;
    }
    if(ind==arr.size() || k<sum){
        return;
    }
    if(ind<arr.size()){
        combinationSum(arr,ans,k,sum,temp,ind+1);
        sum+=arr[ind];
        temp.push_back(arr[ind]);
        combinationSum(arr,ans,k,sum,temp,ind);
    }
    return;
}

int main(){
    cout<<"enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // must do sorting
    sort(arr.begin(),arr.end());


    cout<<"enter key value:";
    int k;cin>>k;

    vector<vector<int>> ans;
    combinationSum(arr,ans,k);

    cout<<"your answers are :\n";
    for(auto it: ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

}