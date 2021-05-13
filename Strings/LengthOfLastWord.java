import java.util.Scanner;

/**
 * LengthOfLastWord
 */
public class LengthOfLastWord {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(lengthOfLastWord(s));
  }

  private static int lengthOfLastWord(String s) {
    String str[] = s.trim().split(" ");
    return str[str.length - 1].length();
  }
}
