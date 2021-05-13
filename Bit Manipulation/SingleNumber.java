import java.util.Scanner;

/**
 * SingleNumber
 */
public class SingleNumber {

  public static void main(String[] args) {
    int a[] = { 2, 2, 1 };
    System.out.println(singleNumber(a));
  }

  private static int singleNumber(int[] nums) {
    int res = 0;
    for (int i = 0; i < nums.length; i++)
      res ^= nums[i];
    return res;
  }
}