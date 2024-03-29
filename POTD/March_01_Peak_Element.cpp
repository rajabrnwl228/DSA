 int peakElement(int arr[], int n)
    {
       // Your code here
       int max=0;
       for(int i=1;i<n;i++){
           if(arr[i]>=arr[i-1])
           max=i;
           
       }
       return max;
       
    }