import java.util.Scanner;

/**
 * AddTwoStrings
 */
public class AddTwoStrings {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s1 = sn.nextLine();
    String s2 = sn.nextLine();
    System.out.println(addStrings(s1, s2));
  }

  private static String addStrings(String num1, String num2) {
    int n = num1.length();
    int m = num2.length();
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    StringBuilder sb = new StringBuilder();
    while (i >= 0 || j >= 0) {
      if (i >= 0 && j >= 0) {
        int val = (num1.charAt(i--) - 48) + (num2.charAt(j--) - 48) + carry;
        sb.append(val % 10);
        carry = val / 10;
      } else if (i >= 0 && j < 0) {
        int val = (num1.charAt(i--) - 48) + carry;
        sb.append(val % 10);
        carry = val / 10;
      } else if (i < 0 && j >= 0) {
        int val = (num2.charAt(j--) - 48) + carry;
        sb.append(val % 10);
        carry = val / 10;
      }
    }
    if (carry != 0)
      sb.append(carry);
    return sb.reverse().toString();
  }
}