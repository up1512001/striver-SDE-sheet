#include<bits/stdc++.h>
using namespace std;

void printUniqueSubsets(vector<int> &arr,set<vector<int>> &st,int ind,vector<int> temp={}){
    if(ind == arr.size()){
        st.insert(temp);
    }
    if(ind < arr.size()){
        printUniqueSubsets(arr, st, ind + 1, temp);
        temp.push_back(arr[ind]);
        printUniqueSubsets(arr, st, ind + 1, temp);
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

    set<vector<int>> st;
    printUniqueSubsets(arr,st,0);

    cout<<"Unique subsets are :\n";
    for(auto it : st){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

}