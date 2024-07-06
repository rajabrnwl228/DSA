#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        long long k;
        cin>>x>>y>>z>>k;
        int ans=0;
        for(int a=1;a<=x;a++){
            for(int b=1;b<=y;b++){
                int c=k/(a*b);           
                if(k%(a*b)==0&&c<=z ){
                    int sub=(x-a+1)*(y-b+1)*(z-c+1);
                    ans=max(ans,sub);
                }
            }
        
        }
        cout<<ans<<endl;
    }
}