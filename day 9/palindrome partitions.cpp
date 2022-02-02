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



// another approach striver

/*

class Solution {
public:
    
    bool pal(string &s,int st,int e){
        while(st<=e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
    
    void f(int ind,string s,vector<vector<string>> &ret,vector<string> &temp){
        if(ind == s.size()){
            ret.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(pal(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,ret,temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> temp;
        f(0,s,ret,temp);
        return ret;
    }
};

*/
