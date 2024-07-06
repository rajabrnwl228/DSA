#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        long long sum=0;
        int mx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mx=max(mx,arr[i]);
            if(mx==sum-mx){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}