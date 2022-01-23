#include<bits/stdc++.h>
using namespace std;

vector<int> majority3(vector<int> &arr){
    if(arr.size()==1) return arr;
    else if(arr.size()==2){
        if(arr[0]==arr[1]) return {arr[0]};
        return arr;
    }
    int n1=-1,n2=-1,cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==n1){
            cnt1++;
        }else if(arr[i]==n2){
            cnt2++;
        }else if(cnt1==0){
            n1=arr[i];
            cnt1=1;
        }else if(cnt2==0){
            n2=arr[i];
            cnt2=1;
        }else{
            cnt1--;
            cnt2--;
        }
        // below will not work need some extra cases
        // if(cnt1==0){
        //     n1=arr[i];
        //     cnt1++;
        // }else if(cnt2==0){
        //     n2=arr[i];
        //     cnt2++;
        // }else if(n1==arr[i]){
        //     cnt1++;
        // }else if(n2==arr[i]){
        //     cnt2++;
        // }else{
        //     cnt1--;
        //     cnt2--;
        // }
    }
    cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(n1==arr[i]) cnt1++;
        else if(n2==arr[i]) cnt2++;
    }
    // cout << (arr.size() / 3)<<" "<<n1<<" "<<n2<<" "<<cnt1<<" "<<cnt2<<"\n";
    if (cnt1 > (arr.size() / 3) && cnt2 > (arr.size() / 3)) return {n1, n2};
    else if(cnt1 > (arr.size()/3)) return {n1};
    else if (cnt2 > (arr.size() / 3)) return {n2};
    return {-1};
}

int main(){
    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> ans = majority3(arr);
    cout<<"majority element by n//3 is : ";
    for(auto i:ans) cout<<i<<" ";
}