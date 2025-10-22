class Solution {
public:
    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &res) {
        if (index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            string sub=s.substr(index,i-index+1);
            string rev=sub;
             reverse(rev.begin(),rev.end());
if(sub==rev){
            path.push_back(sub);
            dfs(i+1,s,path,res);
            path.pop_back();
        }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);  
        return res;
    }
};
