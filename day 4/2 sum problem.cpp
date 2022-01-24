#include<bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(vector<int> &arr,int t){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        int x = t-arr[i];
        if(mp.find(x)!=mp.end()){
            return make_pair(x,arr[i]);
        }else{
            mp[arr[i]]=i;
        }
    }
    return make_pair(-1,-1);
}

int main(){
    cout<<"Enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Enter target value:";
    int t;cin>>t;

    pair<int,int> p = twoSum(arr,t);

    cout<<"value of :"<<p.first<<" and :"<<p.second<<" gives sum :"<<t<<"\n";

}