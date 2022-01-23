#include<bits/stdc++.h>
using namespace std;

int stockBuySell(vector<int> &arr){
    int ans=INT_MIN;
    int mn = INT_MAX;
    for(int i=0;i<arr.size();i++){
        mn = min(mn,arr[i]);
        ans = max(ans,arr[i]-mn);
    }
    return ans;
}

int main(){

    cout<<"Enter n size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Maximum profit after buy and sell stock is :->"<<stockBuySell(arr)<<"\n";

}