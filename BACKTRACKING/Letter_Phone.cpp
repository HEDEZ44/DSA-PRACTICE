void letterph(vector<string>& ans,vector<string>& v,string str,int idx){
    if(idx==v.size()){
        ans.push_back(str);
        return;
    }
    for(int i=0;i<v[idx].length();i++){
        str.push_back(v[idx][i]);
        letterph(ans,v,str,idx+1);
        str.pop_back();
    }

}





vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> mp;
    mp['0']="0";
    mp['1']="1";
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    
    vector<string> v;
    for(int i=0;i<A.length();i++){

        v.push_back(mp[A[i]]);

    }
    vector<string> ans;
    letterph(ans,v,"",0);
    return ans;
    

}
