class Solution
{
public:
  vector<int> distributeCandies(int candies, int num_people)
  {
    vector<int> res(num_people, 0);
    int count = 1;
    int i = 0;
    while (candies >= count)
    {

      candies -= count;
      res[(i++) % num_people] += count++;
    }
    if (candies != 0)
      res[i % num_people] += candies;
    return res;
  }
};