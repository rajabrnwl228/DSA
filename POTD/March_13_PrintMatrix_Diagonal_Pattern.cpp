 vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         int c=1;
         int n=mat.size();
         vector<int>ans;
         ans.push_back(mat[0][0]);
         int l=n*n;
         int i=0,j=1;
         while(c<l){
             while(c<=l){
                 ans.push_back(mat[i][j]);
                 c++;
                 i+=1;
                 j-=1;
                 if(i>=n){
                    i--; 
                    j+=2;
                     break;
                 }
                 else if(j<0){
                     j++;
                     break;
                 }
             }
              
             while(c<l){
                ans.push_back(mat[i][j]);
                i-=1;
                j+=1;
                c++;
                 if(j>=n){
                    j--; 
                    i++;
                    if(i<n)i++;
                     break;
                 }
                 else if(i<0){
                     i++;
                     break;
                 }
             
             }


         }
         return ans;