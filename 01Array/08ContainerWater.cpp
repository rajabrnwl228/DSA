//brute force
long long maxArea(long long arr[], int len)
{
    // Your code goes here
    long long ans=0;
    if(len==1)return 0;
    for(int i=0;i<len;i++){
        long long mini=arr[i];
        for(int j=i+1;j<len;j++){
            mini=min(arr[i],arr[j]);
            long long t=mini*(j-i);
            ans=max(ans,t);
        }
    }
    return ans;
}
//better sol
long long maxArea(long long arr[], int len)
{
    // Your code goes here
    long long ans=0;
    if(len==1)return 0;
    int i=0,j=len-1;
    
    while(i<j){
        long long h=min(arr[i],arr[j]);
        long long a=h*(j-i);
        ans=max(ans,a);
        if(arr[i]<arr[j])i++;
        else j--;
    }
    return ans;
}