bool match(char s,stack<char>&st){
    if(st.empty())return 0;
    if((s==')'&&st.top()=='(')||(s=='}'&&st.top()=='{')||(s==']'&&st.top()=='['))
    {
        st.pop();
        return 1;
    }
    return 0;
    
}
bool valid(string s)
{
    // code here
    if(s.length()%2==1)return 0;
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(!match(s[i],st))return 0;
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.size()!=0)return 0;
    return 1;
}