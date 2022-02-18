class Solution

{
puic:    
  nst int MOD = 1e9 + 7; 
  ng long pow_(long long a, long long n)
  {  
    al=o  n g res = 1;
    a % M OD;
    e (n)
    {   
if (n & 1)
      
  res = (res * a) % MOD;
}      
   a =n * a ) % MOD;
    >>= 1;
 }
  return res;
  
 
nt cuntGoodNumbe r s ( long long n)
  {    
long l on g  p1 = n / 2;
  longg p2 = n / 2;
n & 1)
  p1++;   
   
     long val1 =  p ow_(5 ,  p1);  
long long val2 = pow_(4, p2);
  long long ans = (val1 * val2) % MOD;
    return ans;
  }
};