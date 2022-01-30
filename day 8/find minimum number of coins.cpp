#include<bits/stdc++.h>
using namespace std;

const vector<int> arr = {1,2,5,10,20,50,100,200,500,1000};

vector<int> minCoins(int n){
    vector<int> ret;
    for(int i=arr.size()-1;i>=0;i--){
        while(n>=arr[i]){
            ret.push_back(arr[i]);
            n -= arr[i];
        }
    }
    return ret;
}

int main(){
    cout<<"enter value that you need coins:";
    int n;cin>>n;

    vector<int> ans = minCoins(n);
    cout<<"required coins are : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}