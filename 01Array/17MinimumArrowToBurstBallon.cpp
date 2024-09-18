int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),ans=1;
        sort(points.begin(),points.end());
        int first=points[0][0],second=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=second){
                first=max(points[i][0],first);
                second=min(points[i][1],second);
            }
            else{
                first=points[i][0];
                second=points[i][1];
                ans++;
            }
        }
        return ans;
    }