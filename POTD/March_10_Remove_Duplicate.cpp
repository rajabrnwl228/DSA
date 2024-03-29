	string removeDuplicates(string s) {
	    // code here
	    string ans="";
	    unordered_map<char,int>mp;
	    for(int i=0;i<s.size();i++){
	        if(mp.find(s[i])==mp.end()){
	            ans+=s[i];
	            mp[s[i]]++;
	        }
	    }
	    return ans;
	}