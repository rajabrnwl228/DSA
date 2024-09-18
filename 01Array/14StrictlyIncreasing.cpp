bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX;
        int num2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num3=nums[i];
            if(num3<=num1){
                num1=num3;
            }
            else if(num3<=num2){
                num2=num3;
            }
            else if(num1<num2&&num2<num3){
                return true;
            }
        }return false;
    }
    