class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i;
        for(i=sqrt(area );i>=1;i--)
        {
            if(area%i==0)
            {
                break;
            }
        }
        
        return {area/i,i};
    }
};