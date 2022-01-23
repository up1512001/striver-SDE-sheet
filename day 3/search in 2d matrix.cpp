#include<bits/stdc++.h>
using namespace std;

pair<int,int> searchin2d(vector<vector<int>> &mat,int key){
    pair<int,int> ret = make_pair(-1,-1);
    int i=0,j=mat.size()-1;
    while(i<j){
        int mid = (i+j)/2;
        if(mat[mid][0]<=key && mat[mid][mat[0].size()-1]>=key){
            int x=0,y=mat[0].size()-1;
            while(x<y){
                int m2 = (x+y)/2;
                if(mat[mid][m2]==key){
                    ret.first = mid;
                    ret.second = m2;
                    return ret;
                }else if(mat[mid][m2]<key){
                    x = m2+1;
                }else{
                    y=m2-1;
                }
            }
        }else if(mat[mid][0]<key && mat[mid][mat[0].size()-1]<key){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return ret;
}
 
int main(){
    cout<<"Enter row and column size:";
    int r,c;cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"Enter element for search:";
    int key;cin>>key;

    pair<int,int> p = searchin2d(mat,key);
    cout<<"value prsent at :"<<p.first <<" "<<p.second<<"\n";
}