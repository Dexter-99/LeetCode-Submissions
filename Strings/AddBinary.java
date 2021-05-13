import java.util.Scanner;

/**
 * AddBinary
 */
public class AddBinary {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s1 = sn.next();
    String s2 = sn.next();
    System.out.println(addBinary(s1, s2));
  }

  private static String addBinary(String a, String b) {
    int carry = 0;
    int n = a.length();
    int m = b.length();
    int i = n - 1, j = m - 1;
    StringBuilder sb = new StringBuilder("");
    while (i >= 0 || j >= 0) {
      if (i >= 0 && j < 0) {
        int sum = a.charAt(i--) - 48 + carry;
        if (sum == 0 || sum == 1) {
          sb.append(sum);
          carry = 0;
        } else if (sum == 2) {
          sb.append('0');
          carry = 1;
        } else {
          sb.append('1');
          carry = 1;
        }

      }
      if (j >= 0 && i < 0) {
        int sum = b.charAt(j--) - 48 + carry;
        if (sum == 0 || sum == 1) {
          sb.append(sum);
          carry = 0;
        } else if (sum == 2) {
          sb.append('0');
          carry = 1;
        } else {
          sb.append('1');
          carry = 1;
        }

      }
      if (i >= 0 && j >= 0) {
        int sum = (a.charAt(i--) - 48) + (b.charAt(j--) - 48) + carry;

        if (sum == 0 || sum == 1) {
          sb.append(sum);
          carry = 0;
        }

        else if (sum == 2) {
          sb.append('0');
          carry = 1;
        } else {
          sb.append('1');
          carry = 1;
        }

      }
    }
    if (carry != 0)
      sb.append('1');
    return sb.reverse().toString();

  }
}