import java.util.Scanner;

/**
 * FirstUniqueCharacter
 */
public class FirstUniqueCharacter {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(firstUniqChar(s));
  }

  private static int firstUniqChar(String s) {
    int count[] = new int[256];
    for (int i = 0; i < 256; i++)
      count[i] = -1;
    for (int i = 0; i < s.length(); i++) {
      if (count[s.charAt(i)] == -1)
        count[s.charAt(i)] = i;
      else
        count[s.charAt(i)] = -2;
    }
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < 256; i++)
      if (count[i] >= 0)
        min = Math.min(min, count[i]);
    return min == Integer.MIN_VALUE ? -1 : min;
  }
}