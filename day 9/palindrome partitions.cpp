/*

class Solution {
public:
    
    bool pal(vector<string> &temp){
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size()/2;j++){
                if(temp[i][j] != temp[i][temp[i].size()-1-j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void f(int ind,string &s,vector<vector<string>> &ans,vector<string> &temp){
        if(ind==s.size()){
            if(pal(temp))
                ans.push_back(temp);
            return;
        }
        if(!pal(temp)){
            return;
        }
        string t="";
        for(int i=ind;i<s.size();i++){
            t+=s[i];
            temp.push_back(t);
            f(i+1,s,ans,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0,s,ans,temp);
        return ans;
    }
};

*/