void insertAtBottom(stack<int> &St,int num){
    if(St.empty()){
        St.push(num);
        return ;
    }
    int x=St.top();
    St.pop();
    insertAtBottom(St,num);
    St.push(x);
}
    void Reverse(stack<int> &St){
        if(St.empty())return ;
        int num=St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St,num);
    }