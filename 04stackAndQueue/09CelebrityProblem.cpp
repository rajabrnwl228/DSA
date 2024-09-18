int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i=0;i<n;i++){
            bool r=1,c=1;
                // doesNotKnow
            for(int row=0;row<n;row++){
                if(i!=row&&M[row][i]==0)r=0;
            }
            for(int col=0;col<n;col++){
                if(i!=col&&M[i][col]==1)c=0;
            }
            if(r&&c) return i;
        }
        return -1;
    }