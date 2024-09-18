// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;


    //better solution
    //Time complexity n^3
int longestPalindrome(string s) {
     int mp[256];
    for(int i=0;i<256;i++){
        mp[i]=0;
    }
    for(int i=0;i<s.size();i++){
        int k=s[i];
        mp[k]++;
    }
    int len=0,flag=0;
    for(int i=0;i<256;i++){
        if(mp[i]%2==0)len+=mp[i];
        else {
            len+=(mp[i]-1);
            flag=1;
        }
    }
    return len+flag;

}
        
int main(){
    string s="abcbabcbdabadb";
    int ans=longestPalindrome(s);
    cout<<ans<<endl;
    return 0;
}
