vector<int> factorial(int N){
        // code here
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++){
            vector<int>temp;
            int s=ans.size(),carry=0;
                while(s>0){
                    int t=ans[--s];
                    int m=t*i+carry;
                    carry=m/10;
                    int mt=m%10;
                    temp.push_back(mt);
                }
                while(carry){
                    int t=carry%10;
                    temp.push_back(t);
                    carry=carry/10;
                }
                ans.clear();
                // ans.insert(ans.begin(),temp.rbegin(),temp.rend() );
                ans.assign(temp.rbegin(),temp.rend());
                
            
        }
        return ans;
    }