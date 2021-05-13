import java.util.Scanner;

/**
 * ConsecutiveCharacters
 */
public class ConsecutiveCharacters {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.nextLine();
    System.out.println(maxPower(s));
  }

  private static int maxPower(String s) {
    int len = 1;
    int count = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s.charAt(i) == s.charAt(i - 1))
        count++;
      else {
        len = Math.max(len, count);
        count = 1;
      }
    }
    len = Math.max(len, count);
    return len;

  }

}