/**
 * NumberComplement
 */
public class NumberComplement {

  public static void main(String[] args) {
    int n = 5;
    System.out.println(naive(n));
    System.out.println(hammingWeight(n));
  }

  private static int hammingWeight(int n) {

    int count = 0;
    while (n != 0) {
      count += n & 1;
      n >>>= 1;
    }
    return count;
  }

  private static int naive(int num) {
    String res = "";
    while (num > 0) {
      res = ((num & 1) == 1 ? 0 : 1) + res;
      num >>= 1;
    }
    return Integer.parseInt(res, 2);
  }
}