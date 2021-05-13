class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> res(n,0);
        stack<int> st;
        st.push(n-1);
        res[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty()&&T[st.top()]<=T[i])
            {
                st.pop();
            }
            res[i]=st.empty()?0:(st.top()-i);
            st.push(i);
        }
        return res;
    }
};