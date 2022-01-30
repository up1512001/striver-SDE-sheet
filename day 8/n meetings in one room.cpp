#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

static bool cmp(struct meeting m1,struct meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}


vector<int> meetingInRoom(vector<int> &start,vector<int>&end){
    int n = start.size();
    struct meeting arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }

    sort(arr, arr + n, cmp);

    vector<int> ans;
    ans.push_back(arr[0].pos);
    int limit = arr[0].end;

    for (int i = 1; i < n; i++)
    {
        if (limit < arr[i].start)
        {
            ans.push_back(arr[i].pos);
            limit = arr[i].end;
        }
    }
    return ans;
}

int main(){
    cout<<"Enter size of array:";
    int n;cin>>n;
    vector<int> start(n),end(n);
    cout<<"starting time array:\n";
    for(int i=0;i<n;i++) cin>>start[i];
    cout<<"ending time array:\n";
    for(int i=0;i<n;i++) cin>>end[i];

    vector<int> ans = meetingInRoom(start,end);
    cout<<"your answer:";
    for(auto i:ans) cout<<i<<" ";   


}