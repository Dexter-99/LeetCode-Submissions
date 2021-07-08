class Solution {
public:
    bool isValid(vector<int> & w,int days,int maxVal)
    {
        int  count=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            if(sum>maxVal)
            {
                count++;
                sum=w[i];
            }
        }
        return (count<=days);
    }
        
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.size()<days)
            return -1;
        int _max=0,sum=0;
        for(auto x:weights)
        {
            _max=max(_max,x);
            sum+=x;
        }
        int low=_max,high=sum;
        int  res=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isValid(weights,days,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};