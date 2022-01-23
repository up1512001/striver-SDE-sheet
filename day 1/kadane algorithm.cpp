#include<bits/stdc++.h>
using namespace std;

int kadaneAlgo(vector<int> &arr){
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        ans=max(ans,sum);
        sum = max(sum,0);
    }
    return ans;
}

int main(){

    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Maximum subarray sum is :->"<<kadaneAlgo(arr)<<"\n";

}