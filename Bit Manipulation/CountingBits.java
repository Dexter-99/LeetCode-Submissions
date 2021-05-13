import java.util.Scanner;

/**
 * CountingBits
 */
public class CountingBits {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    countBits(n);
  }

  static int table[];

  private static int[] countBits(int num) {
    initialize(num);
    return table;
  }

  private static void initialize(int num) {
    table = new int[num + 1];
    table[0] = 0;
    for (int i = 1; i <= num; i++)
      table[i] = (i & 1) + table[i / 2];
  }
}