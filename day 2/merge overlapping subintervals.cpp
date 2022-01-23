#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> mergeIntervals(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    int j=0;
    vector<vector<int>> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(ans[ans.size()-1][1]<arr[i][0]){
            ans.push_back(arr[i]);
        }else{
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1],arr[i][1]);
        }
    }
    return ans;
}

void pri(vector<vector<int>> &mat){
    cout<<"Printing matrix:\n";
    for(auto x : mat){
        for(auto i : x){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    cout<<"End of matrix:\n";
}


int main(){

    cout<<"Enter number of elements:";
    int n;cin>>n;

    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }

    vector<vector<int>> ans = mergeIntervals(arr);
    pri(ans);
}