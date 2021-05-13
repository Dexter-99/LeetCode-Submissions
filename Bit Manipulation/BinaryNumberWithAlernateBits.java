import java.util.Scanner;

/**
 * BinaryNumberWithAlernateBits
 */
public class BinaryNumberWithAlernateBits {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    System.out.println(hasAlternatingBits(n));
  }

  private static boolean hasAlternatingBits(int n) {
    int prev = n & 1;
    n = n >> 1;
    // System.out.println(n);
    while (n > 0) {
      int curr = n & 1;
      // System.out.println(prev+" "+curr);
      if (prev == curr)
        return false;
      prev = curr;
      n = n >> 1;
    }
    return true;
  }
}