#include<bits/stdc++.h>
using namespace std;

/*
// brout force
int ans=0;
for(int i=0;i<arr.size();i++){
    int s=0;
    for(int j=i;j<arr.size();j++){
        s += arr[j];
        if(s==0){
            ans = max(ans,j-i+1);
        }
    }
}
return ans;

// another my own approach using sliding window
// will not work
int ans=0;
int i=0,j=0;
int sum=0;
while(i<arr.size()){
    sum += arr[i];
    if(sum==0){
        ans = max(ans,i-j+1);
    }else{

    }
}


*/


int LSwithSumZero(vector<int> &arr){
    unordered_map<int,int> mp;
    int ans=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == 0){
            ans = i+1;
        }else{
            if(mp.find(sum) != mp.end()){
                ans = max(ans,i-mp[sum]);
            }else{
                mp[arr[i]] = i;
            }
        }
    }
    return ans;
}

int main(){
    cout<<"Enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int LSwithSum0 = LSwithSumZero(arr);
    cout<<"Largest subarray with sum zero length is :"<<LSwithSum0<<"\n";
}