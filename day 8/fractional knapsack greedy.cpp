#include<bits/stdc++.h>
using namespace std;

struct frac{
    int weight,value;
    double vBw;
};

static bool cmp(frac a,frac b){
    return a.vBw>b.vBw;
}

double fractionalKnapsack(frac arr[],int n,int cap){
    sort(arr,arr+n,cmp);
    double maxProfit=0.0000;
    for(int i=0;i<n;i++){
        if(cap>=arr[i].weight){
            maxProfit += arr[i].value;
            cap-=arr[i].weight;
        }else{
            maxProfit += (cap)*arr[i].vBw;
            break;
        }
    }
    return maxProfit;
}

int main(){
    cout<<"enter size of array:";
    int n;cin>>n;
    frac arr[n];
    cout<<"enter details:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i].value;
        cin >> arr[i].weight;
        arr[i].vBw = double(arr[i].value)/arr[i].weight;
    }

    cout<<"enter capacity:";
    int cap;cin>>cap;

    double ans = fractionalKnapsack(arr,n,cap);
    cout<<"maximum profit you can get is :"<<ans<<"\n";

}

/*

3
100 20
60 10
120 30
50
*/
