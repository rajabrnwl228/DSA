#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        // vector<vector<char>>arr(n,vector<char>(m));
        char arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cin>>arr[i][j];
            }
        }
        int fr=-1,fc=-1,lr=-1,lc=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='#'){
                    if(fr==-1)fr=i;
                    lr=i;
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(arr[i][j]=='#'){
                    if(fc==-1)fc=j;
                    lc=j;
                }
            }
        }
        fr++,lr++,fc++,lc++;
        int a=fr+(lr-fr)/2;
        int b=fc+(lc-fc)/2;
        cout<<a<<" "<<b<<endl;
    }
}