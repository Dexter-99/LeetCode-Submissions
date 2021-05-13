import java.util.Scanner;

/**
 * ReverseBits
 */
public class ReverseBits {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    reverseBits(n);
  }

  private static int reverseBits(int n) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      // System.out.println((n&1)==1?1:0);
      res += ((n & 1) == 1 ? 1 : 0) << i;
      n >>= 1;
    }
    System.out.println(n);
    return res;
  }

}