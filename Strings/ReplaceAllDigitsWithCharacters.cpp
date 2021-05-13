class Solution {
public:
    string replaceDigits(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(i&1)
            {
                s[i]=(s[i-1]+(s[i]-48));
            }
        }
        return s;
    }
};