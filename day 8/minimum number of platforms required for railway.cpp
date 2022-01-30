#include<bits/stdc++.h>
using namespace std;

int minimumRequiredPlatforms(vector<int> &arr1,vector<int> &arr2){
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int ans=1,i=0,j=0,cnt=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans = max(ans,cnt);
    }
    return ans;
}

int main(){
    cout<<"enter size of array:";
    int n;cin>>n;
    vector<int> arrival(n),deparcher(n);
    cout<<"Enter arrival array:\n";
    for(int i=0;i<n;i++) cin>>arrival[i];
    cout<<"enter departcture array:\n";
    for(int i=0;i<n;i++) cin>>deparcher[i];

    int ans = minimumRequiredPlatforms(arrival,deparcher);
    cout<<"minimum required plateforms are :"<<ans<<"\n";

}