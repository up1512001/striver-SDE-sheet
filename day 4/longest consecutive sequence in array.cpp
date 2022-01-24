#include<bits/stdc++.h>
using namespace std;

// using sort we can get O(n Log n) time complexity
int LCSarray(vector<int> &arr){
    unordered_set<int> st;
    for(int i=0;i<arr.size();i++) st.insert(arr[i]);
    int ans=0;
    for(int i=0;i<arr.size();i++){
        int curr = arr[i];
        int streak = 1;
        while(st.find(curr + 1)!=st.end()){
            curr += 1;
            streak += 1;
        }
        ans = max(ans,streak);
    }
    return ans;
}

int main(){
    cout<<"Enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int lcsA = LCSarray(arr);
    cout<<"Longest consecutive sequence is of length :"<<lcsA<<"\n";
}