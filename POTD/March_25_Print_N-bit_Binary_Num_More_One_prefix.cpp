void generator(int &n,vector<string>&ans,int zc,int oc,string s){
    if(s.size()==n){
        ans.push_back(s);
        return ;
    }
    if(zc>oc)return ;
    if(oc>=zc)generator(n,ans,zc,oc+1,s+"1");
    if(oc>zc)
        generator(n,ans,zc+1,oc,s+"0");
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    generator(n,ans,0,0,"");
	
	    return ans;
	}