/**
 * SingleNumberIII
 */
public class SingleNumberIII {

  public static void main(String[] args) {

  }

  private static int[] singleNumber(int[] nums) {
    int xor = 0;
    for (int i = 0; i < nums.length; i++) {
      xor ^= nums[i];
    }
    int setBit = xor & ~(xor - 1);
    int res1 = 0, res2 = 0;
    for (int i = 0; i < nums.length; i++) {
      if ((nums[i] & setBit) != 0)
        res1 = res1 ^ nums[i];
      else
        res2 = res2 ^ nums[i];
    }
    return new int[] { res1, res2 };
  }
}