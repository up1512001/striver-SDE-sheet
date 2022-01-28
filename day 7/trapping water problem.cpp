#include<bits/stdc++.h>
using namespace std;


int trappingRainWater(vector<int> &arr){
    vector<int> maxL(arr.size()),maxR(arr.size()),water(arr.size());
    maxL[0] = arr[0];
    for(int i=1;i<arr.size();i++){
        maxL[i] = max(maxL[i-1],maxL[i]);
    }
    maxR[arr.size()-1] = arr[arr.size()-1];
    for(int i=arr.size()-2;i>=0;i--){
        maxR[i] = max(maxR[i],maxR[i+1]);
    }
    for(int i=0;i<arr.size();i++){
        water[i] = min(maxL[i],maxR[i]) - arr[i];
    }
    int ans = 0;
    for(auto i : water){
        ans+=i;
    }
    return ans;
}

// optimized

int trapintwater(vector<int> arr){
    int l=0,r=arr.size()-1,level=0,ans=0;
    while(l<r){
        int t = arr[l] < arr[r] ? l++:r--;
        int lower = arr[t];
        level = max(level,lower);
        ans += (level - lower);
    }
    return ans;
}


int main(){
    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"maximum trapping water that can be stored is :"<<trappingRainWater(arr)<<"\n";

}