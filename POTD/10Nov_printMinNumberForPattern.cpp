 string printMinNumberForPattern(string S){
        // code here 
        int n=S.length(),count=1;
        string ans="";
        int i=0;
        while(i<n){
            int j=i,k=i;
            if(S[j]=='D'){
                int c=0;
                while(S[j]=='D'){
                    c++;
                    j++;
                }
                int t=c;
                while(c>=0){
                    ans=ans+to_string(count+c);
                    c--;
                }
                count=t+count+1;
                i=j;
            }
            else{
                int c=0;
                while(S[k]=='I'){
                    c++;
                    k++;
                }
                int t=c;
                while(c>1){
                    ans=ans+to_string(count);
                    count++;
                    c--;
                }
                if(i==0) {
                    ans=ans+to_string(count);
                    count++;
                }
                i=k;
            }
        }
        if(S[n-1]=='I'){
            ans=ans+to_string(count);
        }
        return ans;
    }
/*
Number following a pattern

Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
*/