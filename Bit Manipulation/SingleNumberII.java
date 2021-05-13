import java.util.Scanner;

/**
 * SingleNumberII
 */
public class SingleNumberII {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    
  }

  private static int singleNumber(int[] nums) {
    int bits[] = new int[32];
    int res = 0;
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < nums.length; j++) {
        bits[i] += (nums[j] & (1 << i)) != 0 ? 1 : 0;
      }
      bits[i] = bits[i] % 3;

    }
    for (int i = 0; i < 32; i++) {
      res |= bits[i] << i;
    }

    return res;

  }
}