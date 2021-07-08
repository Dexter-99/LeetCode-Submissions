class Solution {
public:
    vector<vector<int>> list;
    void combinationSum(vector<int> &candidates,int  target,int  idx,int n,vector<int> res)
    {
        if(target==0)
        {
              list.push_back(res);
                return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx &&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) 
                break;
            res.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],i+1,n,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<int> res;
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,target,0,candidates.size(),res);
        return list;    
    }
};