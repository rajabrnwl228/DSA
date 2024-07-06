// code here
// //32*n
// //due to negative number
//         //first method
//   int singleElement(int arr[] ,int N) {
//         int ans=0;
//         for(int i=0;i<=31;i++){
//             int x=(1<<i);
//             int count=0;
//             for(int j=0;j<N;j++){
//                 if((arr[j]&x)!=0){
//                     count++;
//                 }
//             }
//             if(count%3!=0){
//                 ans=ans|(1<<i);
//             }
//         }
//         return ans;
      
//     }
//         //second method
// int maxi=INT_MIN;
// for(int i=0;i<N;i++){
//     if(abs(arr[i])>maxi)
//     maxi=abs(arr[i]);
// }
// int l=0;
// while(pow(2,l)<maxi){
//     l++;
// }
// int ans=0;
// for(int i=0;i<l;i++){
//     int x=(1<<i);
//     int count=0;
//     for(int j=0;j<N;j++){
//         if(arr[j]&x)
//         count++;
//     }
//     if(count%3!=0){
//         ans+=pow(2,i);
//     }
// }

// return ans;
////third method
int tn = (1 << 31) - 1, tnp1 = 0, tnp2 = 0;
for (int i = 0; i < N; i++)
{
    int ctnp = tn & arr[i];
    int ctnp1 = tnp1 & arr[i];
    int ctnp2 = tnp2 & arr[i];
    // reset
    tn = (tn & ~ctnp);
    // set next
    tnp1 = (tnp1 | ctnp);

    // reset
    tnp1 = (tnp1 & ~ctnp1);
    // set next
    tnp2 = (tnp1 | ctnp1);

    // reset
    tnp2 = (tnp2 & ~ctnp2);
    // set next
    tn = (tn | ctnp2);
}
return tnp1;
}