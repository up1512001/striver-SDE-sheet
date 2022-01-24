#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr,int t){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ret;
    for(int i=0;i<arr.size()-3;i++){
        for(int j=i+1;j<arr.size()-2;j++){
            int x = t-arr[i]-arr[j];
            int a=j+1,b=arr.size()-1;
            while(a<b){
                if(arr[a]+arr[b]==x){
                    ret.push_back({arr[i],arr[j],arr[a],arr[b]});
                    a++;
                    b--;
                }else if(arr[a]+arr[b] > x){
                    b--;
                }else{
                    a++;
                }
            }
        }
    }
    return ret;
}

int main(){
    cout<<"Enter array size:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter target value:";
    int t;cin>>t;

    vector<vector<int>> res = fourSum(arr,t);
    cout<<"our answer index are:\n";
    for(auto it:res){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

}