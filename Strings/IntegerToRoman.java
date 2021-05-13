import java.util.Scanner;

/**
 * IntegerToRoman
 */
public class IntegerToRoman {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    System.out.println(convert(n));
  }

  private static String convert(int n) {
    String roman[] = new String[] { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int val[] = new int[] { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    String res = "";
    int i = 0;
    while (n > 0) {
      if (n - val[i] >= 0) {
        res += roman[i];
        n = n - val[i];
      } else {
        i++;
      }
    }
    return res;
  }

  // O(1) Solution
  private static String intToRoman(int n) {
    String units[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    String tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    String hundreds[] = { "", "C", "CXX", "CXXX", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    String thousands[] = { "", "M", "MM", "MMM" };
    return thousands[n / 1000] + hundreds[(n % 1000) / 100] + tens[(n % 100) / 10] + units[n % 10];
  }
}