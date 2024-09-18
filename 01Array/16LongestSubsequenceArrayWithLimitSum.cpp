class Solution {
public:
int lower(vector<int>&arr,int targ){
    int l=0,h=arr.size()-1;
    int res=-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]<=targ){
            res=m;
            l=m+1;
        }
        else
            h=m-1;
    }
    return res+1;

}
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>pref,ans;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pref.push_back(sum);
        }
        //search
        int m=queries.size();
        for(int i=0;i<m;i++){
            int ind=lower(pref,queries[i]);
            ans.push_back(ind);
        }
return ans;
    }
};