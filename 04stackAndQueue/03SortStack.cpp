void sorthelper(stack<int> &s,int num){
    if(s.empty()){
        s.push(num);
        return ;
    }
    int x=s.top();
    if(x>num){
        s.pop();
        sorthelper(s,num);
        s.push(x);
    }
    else{
        s.push(num);
    }
}
void helper(stack<int>&s){
    if(s.empty())return ;
    int num=s.top();
    s.pop();
    helper(s);
    sorthelper(s,num);
}
void SortedStack :: sort()
{
   //Your code here
    helper(s);
        
}