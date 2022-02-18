class Solution {
public:
    string longestPalindrome(string s) {
        string s1=s;
        string s2=s;
        int n=s.length();
        vector<vector<int>>  dp(n,vector<int>(n,0));
        int I=0,J=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j])
                {
                   I=i;
                    J=j;
                }
            }
            
            // cout<<endl;
        }
        return s.substr(I,J-I+1);
    }
};