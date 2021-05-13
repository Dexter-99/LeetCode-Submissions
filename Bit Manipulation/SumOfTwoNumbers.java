import java.util.Scanner;

/**
 * SumOfTwoNumbers
 */
public class SumOfTwoNumbers {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int a = sn.nextInt();
    int b = sn.nextInt();
    System.out.println(sum(a, b));
  }

  private static int sum(int a, int b) {
    int carry = 0;
    while (b != 0) {
      carry = a & b;
      a ^= b;
      b = carry << 1;
    }
    return a;
  }
}