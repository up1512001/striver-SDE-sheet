#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

static bool cmp(job a,job b){
    return a.profit>b.profit;
}

pair<int,int> jobSequencing(job arr[],int n){
    sort(arr,arr+n,cmp);
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        maxDeadline = max(maxDeadline,arr[i].deadline);
    }
    int temp[maxDeadline+1];
    int maxProfit=0,maxProcess=0;
    memset(temp,-1,sizeof(temp));
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>0;j--){
            if(temp[j]==-1){
                temp[j]=arr[i].id;
                maxProcess++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(maxProcess,maxProfit);
}

int main(){
    cout<<"enter number of jobs available:";
    int n;cin>>n;
    job arr[n];
    cout<<"enter details:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
        cin>>arr[i].deadline;
        cin>>arr[i].profit;
    }
    pair<int,int> ans = jobSequencing(arr,n);
    cout<<"number of jobs can be done are "<<ans.first<<" and profit will be "<<ans.second<<"\n";
}

/*

4
1 4 20
2 1 10
3 2 40
4 2 30

*/