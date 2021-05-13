import java.util.Scanner;

/**
 * StringCompression
 */
public class StringCompression {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    char ch[] = new char[n];
    for (int i = 0; i < n; i++)
      ch[i] = sn.next().charAt(0);
    System.out.println(compress(ch));
  }

  private static int compress(char[] ch) {
    int count = 1;
    ;
    int idx = 0;
    ch[idx++] = ch[0];
    for (int i = 1; i < ch.length; i++) {
      if (ch[i] == ch[i - 1]) {
        count++;
      }

      else {
        if (count != 1) {
          char c[] = String.valueOf(count).toCharArray();
          for (int j = 0; j < c.length; j++)
            ch[idx++] = c[j];
        }
        ch[idx++] = ch[i];
        count = 1;
      }
    }
    if (count > 1) {
      char c[] = String.valueOf(count).toCharArray();
      for (int j = 0; j < c.length; j++)
        ch[idx++] = c[j];
    }
    // System.out.println(idx);
    return idx;
  }
}