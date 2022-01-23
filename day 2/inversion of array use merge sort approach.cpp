#include<bits/stdc++.h>
using namespace std;

int mergeArray(vector<int> arr,vector<int> temp,int left,int mid,int right){
    
    /*
    int i,j,k;
    int inversion=0;
    i=left;
    j=mid;
    k=left;
    // vector<int> temp(arr.size());
    while((i<=(mid-1)) && j<=right){

        // cout << "i:" << i << " j:" << j << " arr[i] :" << arr[i] << " arr[j]:" << arr[j] << " left:" << left << " mid:" << mid << " right:" << right << "\n";

        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            inversion = inversion+(mid-i);
        }
        
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int x=left;x<=right;x++){
        arr[x] = temp[x];
    }

    return inversion;

    */

    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(vector<int> arr,vector<int> temp,int left,int right){
    
    /*
    int countInversion=0;
    int mid=0;
    if(right > left){
        mid = (right+left)/2;
        countInversion += mergeSort(arr,temp,left,mid);
        countInversion += mergeSort(arr,temp,mid+1,right);
        countInversion += mergeArray(arr,temp,left,mid+1,right);
    }
    return countInversion;
    */

    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += mergeArray(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int inversion(vector<int> arr){
    vector<int> temp(arr.size());
    return mergeSort(arr,temp,0,arr.size()-1);
}


int main(){

    cout<<"Enter N Value:";
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){ cin>>arr[i];}

    cout<<"number of inversions :"<<inversion(arr)<<"\n";
    // cout << "number of inversions :" << mergeSort(arr,arr,0,n-1) << "\n";

}





