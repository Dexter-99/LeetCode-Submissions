class Solution
{
public:
  int _gcd(int a, int b)
  {
    return (b == 0 ? a : _gcd(b, a % b));
  }
  string fractionAddition(string expression)
  {
    bool negative = false;
    int i = 0;
    if (expression[i] == '-')
    {
      negative = true;
      i++;
    }
    int n = expression.size();
    int currNum = 0, currDen = 1;
    for (; i < n; i++)
    {

      if (expression[i] == '+')
      {
        negative = false;
        continue;
      }
      if (expression[i] == '-')
      {
        negative = true;
        continue;
      }
      if (expression[i] == '/')
      {
        int nrt = 0;
        int mul = 1;
        int idx1 = i - 1;
        while (idx1 >= 0 && (expression[idx1] != '+' && expression[idx1] != '-'))
        {
          int dig = expression[idx1] - '0';
          nrt = dig * mul + nrt;
          mul *= 10;
          idx1--;
        }
        int dnt = 0, idx2 = i + 1;
        mul = 1;
        while (idx2 < n && (expression[idx2] != '+' && expression[idx2] != '-'))
        {
          int dig = expression[idx2] - '0';
          dnt = dnt * mul + dig;
          mul *= 10;
          idx2++;
        }
        i = idx2 - 1;
        int _lcm = (currDen * dnt) / _gcd(dnt, currDen);
        if (negative)
          nrt *= -1;
        // cout<<negative<<<<endl;
        // cout<<currNum*(_lcm/currDen)<<" "<<nrt*(_lcm/dnt)<<endl;
        currNum = currNum * (_lcm / currDen) + nrt * (_lcm / dnt);
        currDen = _lcm;
        int currGcd = _gcd(abs(currNum), abs(currDen));
        // cout<<currNum<<"/"<<currDen<<endl;
        currNum /= currGcd;
        currDen /= currGcd;
        // cout<<currNum<<"/"<<currDen<<endl;
      }
    }
    string s = to_string(currNum) + "/" + to_string(currDen);
    return s;
  }
};