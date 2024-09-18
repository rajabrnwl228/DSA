 vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)even+=nums[i];
            else odd+=nums[i];
        }
        for(int i=0;i<queries.size();i++){
            vector<int>qd=queries[i];
            if(nums[qd[1]]%2==0){
                 if(qd[0]%2==0){
                    even+=qd[0];
                    nums[qd[1]]+=qd[0];
                }
                else{
                    even-=nums[qd[1]];
                    nums[qd[1]]+=qd[0];
                    odd+=nums[qd[1]];
                }
            }
            else{
                if(qd[0]%2==0){
                    odd+=qd[0];
                    nums[qd[1]]+=qd[0];
                }else{
                    odd-=nums[qd[1]];
                    nums[qd[1]]+=qd[0];
                    even+=nums[qd[1]];

                }
               
            }
        ans.push_back(even);
        }
    return ans;
    }