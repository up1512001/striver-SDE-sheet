#include<bits/stdc++.h>
using namespace std;


// below mention two approaches
class Solution
{
public:
    //     bool s(vector<string> &temp,int r,int c){
    //         for(int i=0;i<temp.size();i++){
    //             if(temp[r][i] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         for(int i=0;i<temp.size();i++){
    //             if(temp[i][c] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         for(int i=r,j=c;i<temp.size() && j<temp.size();i++,j++){
    //             if(temp[i][j] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         for(int i=r,j=c;i>=0 && j>=0;i--,j--){
    //             if(temp[i][j] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         for(int i=r,j=c;i<temp.size() && j>=0;i++,j--){
    //             if(temp[i][j] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         for(int i=r,j=c;i>=0 && j<temp.size();i--,j++){
    //             if(temp[i][j] == 'Q'){
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     void f(int col,vector<string> &temp,vector<vector<string>> &ret){
    //         if(col == temp[0].size()){
    //             ret.emplace_back(temp);
    //             return;
    //         }
    //         for(int r=0;r<temp.size();r++){
    //             if(s(temp,r,col)){
    //                 temp[r][col] = 'Q';
    //                 f(col+1,temp,ret);
    //                 temp[r][col] = '.';
    //             }
    //         }
    //         return;
    //     }

    void f(int col, vector<string> &temp, vector<vector<string>> &ret, vector<int> &v1, vector<int> &v2, vector<int> &v3, vector<int> &v4)
    {
        if (col == temp[0].size())
        {
            ret.emplace_back(temp);
            return;
        }
        for (int r = 0; r < temp.size(); r++)
        {
            if (!v1[r] && !v2[col] && !v3[r + col] && !v4[temp.size() - 1 - r + col])
            {
                temp[r][col] = 'Q';
                v1[r] = 1;
                v2[col] = 1;
                v3[r + col] = 1;
                v4[temp.size() - 1 - r + col] = 1;
                f(col + 1, temp, ret, v1, v2, v3, v4);
                temp[r][col] = '.';
                v1[r] = 0;
                v2[col] = 0;
                v3[r + col] = 0;
                v4[temp.size() - 1 - r + col] = 0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string x = "";
        for (int i = 0; i < n; i++)
            x += '.';
        vector<vector<string>> ret;
        vector<string> temp;
        vector<int> v1(n, 0), v2(n, 0), v3(2 * n - 1, 0), v4(2 * n - 1, 0);
        for (int i = 0; i < n; i++)
        {
            temp.emplace_back(x);
        }
        f(0, temp, ret, v1, v2, v3, v4);
        return ret;
    }
};