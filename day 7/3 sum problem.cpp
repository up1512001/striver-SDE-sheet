#include<bits/stdc++.h>
using namespace std;

// 3 sum is to get sum equal to zero 
// it has brute force of O(N^3) time and O(1) space 

// below is optimized
vector<vector<int>> threeSum(vector<int> &arr)
{
    if (arr.size() < 3)
        return {};
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        int l = i + 1, r = arr.size() - 1;
        int t = -arr[i];
        while (l < r)
        {
            if (arr[l] + arr[r] > t)
            {
                r--;
            }
            else if (arr[l] + arr[r] < t)
            {
                l++;
            }
            else
            {
                ans.push_back({arr[i], arr[l], arr[r]});
                while (l < arr.size() - 1 && arr[l] == arr[l + 1])
                    l++;
                while (r > i + 1 && arr[r] == arr[r - 1])
                    r--;
                r--;
                l++;
            }
        }
        while (arr[i] == arr[i + 1] && i < arr.size() - 2)
        {
            i++;
        }
    }
    return ans;
}

int main(){
    cout<<"Enter size of array:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<vector<int>> ans = threeSum(arr);
    cout<<"Your answer will be :\n";
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

}