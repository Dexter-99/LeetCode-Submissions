class Solution
{
public:
  int numRookCaptures(vector<vector<char>> &board)
  {
    int n = board.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == 'R')
        {

          for (int k = j + 1; k < n; k++)
          {
            if (board[i][k] != '.')
            {
              if (board[i][k] == 'p')
                count++;
              break;
            }
          }
          for (int k = j - 1; k >= 0; k--)
          {
            if (board[i][k] != '.')
            {
              if (board[i][k] == 'p')
                count++;
              break;
            }
          }
          for (int k = i + 1; k < n; k++)
          {
            if (board[k][j] != '.')
            {
              if (board[k][j] == 'p')
                count++;
              break;
            }
          }
          for (int k = i - 1; k >= 0; k--)
          {
            if (board[k][j] != '.')
            {
              if (board[k][j] == 'p')
                count++;
              break;
            }
          }
          break;
        }
      }
    }
    return count;
  }
};