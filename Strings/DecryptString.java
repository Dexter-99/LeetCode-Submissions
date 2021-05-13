import java.util.Scanner;

/**
 * DecryptString
 */
public class DecryptString {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.nextLine();
    System.out.println(freqAlphabets(s));

  }

  private static String freqAlphabets(String s) {
    StringBuilder sb = new StringBuilder("");
    int i = 0;
    while (i < s.length()) {

      if (i + 2 < s.length() && s.charAt(i + 2) == '#') {
        sb.append((char) (Integer.parseInt(s.substring(i, i + 2)) + 96));
        i = i + 3;
      } else {
        // System.out.println(i);
        sb.append((char) (s.charAt(i) - 48 + 96));
        i++;
      }

    }
    return sb.toString();

  }
}