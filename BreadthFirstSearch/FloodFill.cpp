class Solution
{
public:
  void solve(vector<vector<int>> &image, int i, int j, int m, int n, int newColor, int curr)
  {
    if (i == m || i < 0 || j < 0 || j == n || image[i][j] == newColor)
    {
      return;
    }
    if (image[i][j] == curr)
    {
      image[i][j] = newColor;
      solve(image, i + 1, j, m, n, newColor, curr);
      solve(image, i - 1, j, m, n, newColor, curr);
      solve(image, i, j + 1, m, n, newColor, curr);
      solve(image, i, j - 1, m, n, newColor, curr);
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int curr = image[sr][sc];
    solve(image, sr, sc, image.size(), image[0].size(), newColor, curr);
    return image;
  }
};