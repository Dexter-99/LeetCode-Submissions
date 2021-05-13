import java.util.Scanner;

/**
 * IncreasingDecreasingString
 */
public class IncreasingDecreasingString {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.nextLine();
    System.out.println(sortString(s));
  }

  private static String sortString(String s) {
    StringBuilder sb = new StringBuilder("");
    int count[] = new int[26];
    for (int i = 0; i < s.length(); i++) {
      count[s.charAt(i) - 97]++;
    }
    // for(int i=0;i<26;i++)
    // System.out.println(count[i]);
    while (sb.length() < s.length()) {
      for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
          sb.append((char) (97 + i));
          count[i]--;
        }
      }
      for (int i = 25; i >= 0; i--) {
        if (count[i] != 0) {
          sb.append((char) (97 + i));
          count[i]--;
        }
      }
    }
    return sb.toString();
  }

}