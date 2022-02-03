// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++


// main code starts below 

class Solution{
    public:
    
    void f(int i,int j,vector<vector<int>> &m,vector<string>&ret,string t,vector<vector<int>>&check){
        if(i==m.size()-1 && j==m.size()-1){
            ret.push_back(t);
            return;
        }
        // i>=0 && i<m.size() && 
        // left
        if(j>0 && j<m.size() && check[i][j-1] == 0 && m[i][j-1]){
            check[i][j] = 1;
            t+='L';
            f(i,j-1,m,ret,t,check);
            t.pop_back();
            check[i][j] = 0;
        }
        // right
        if(j+1<m.size() && j>=0 && check[i][j+1]==0 && m[i][j+1]){
            check[i][j] = 1;
            t+='R';
            f(i,j+1,m,ret,t,check);
            t.pop_back();
            check[i][j] = 0;
        }
        // down
        //  j>=0 && j<m.size() &&
        if(i>=0 && i+1<m.size() && check[i+1][j]==0 && m[i+1][j]){
            check[i][j] = 1;
            t+='D';
            f(i+1,j,m,ret,t,check);
            t.pop_back();
            check[i][j] = 0;
        }
        // up
        if(i>0 && i<m.size() && check[i-1][j]==0 && m[i-1][j]){
            check[i][j] = 1;
            t+='U';
            f(i-1,j,m,ret,t,check);
            t.pop_back();
            check[i][j] = 0;
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ret;
        string t="";
        vector<vector<int>> check(n,vector<int>(n,0));
        if(m[0][0]==1) f(0,0,m,ret,t,check);
        return ret;
    }
};

// main code portion end above    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends