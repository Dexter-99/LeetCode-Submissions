import java.util.Scanner;

/**
 * DetectCapital
 */
public class DetectCapital {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(detectCapitalUse(s));
  }

  private static boolean detectCapitalUse(String s) {
    boolean flag = true;
    if (s.length() == 1)
      return true;
    if (s.charAt(0) >= 'a' && s.charAt(0) <= 'z') {
      for (int i = 1; i < s.length(); i++) {
        if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
          flag = false;
          break;
        }
      }
    } else {
      if (s.charAt(1) >= 'A' && s.charAt(1) <= 'Z') {
        for (int i = 2; i < s.length(); i++) {
          if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
            flag = false;
            break;
          }

        }

      } else {
        for (int i = 2; i < s.length(); i++) {
          if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
            flag = false;
            break;
          }

        }
      }
    }
    return flag;
  }

}