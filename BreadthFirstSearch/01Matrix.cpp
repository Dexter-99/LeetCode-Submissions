class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(int k=0;k<4;k++)
            {
                int  currI=i+x[k];
                int  currJ=j+y[k];
                if(currI<0||currI==m||currJ<0||currJ==n||dist[currI][currJ]!=-1)
                    continue;
                
                q.push({currI,currJ});
                dist[currI][currJ]=dist[i][j]+1;
            }
            
        }
        return dist;
    }
};