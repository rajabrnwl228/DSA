int count(vector<vector<int>>& img1, vector<vector<int>>& img2,int row,int col){
        int n=img1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bi=i+row;
                int bj=j+col;
                if(bi<0||bi>=n||bj<0||bj>=n)continue;
                if(img1[i][j]==1&&img2[bi][bj]==1)cnt++;

            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img2.size();
        int ans=0;
        for(int row=-n+1;row<n;row++){
            for(int col=-n+1;col<n;col++){
                int cnt=count(img1,img2,row,col);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }16