/*

  /*
    //Method 1
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]) return nums[i];
        }
        return -1;
    }*/
    
    /*
    //Method 2
    int findDuplicate(vector<int>& nums) {
        int arr[nums.size()];
        for(int i= 0;i<nums.size();i++){
            arr[i] = 0;
        }
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            if(arr[nums[i]] > 1) return nums[i];
        }
        return -1;
    }*/
    
    /*
    //Method 3
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        return -1;
    }
    
    
    //Method 4
    int findDuplicate(vector<int>& nums) {
        //Floyd Cycle detection.
        int fast = 0;
        int slow = 0;
        
        while (true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (nums[fast] == nums[slow])
                break;
        }
        
        fast = 0;
        while (nums[fast] != nums[slow]) {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return nums[slow];
    }
};

*/
#include<bits/stdc++.h>
using namespace std;

int duplicateElement(vector<int> &arr){
    int xor1 = arr[0];
    for(int i=1;i<arr.size();i++){
        xor1 ^= arr[i];
    }
    for(int i=1;i<arr.size();i++){
        xor1 ^= i;
    }
    return xor1;
}

int main(){
    cout<<"Enter n value:";
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"duplicate element is :->"<<duplicateElement(arr)<<"\n";
}