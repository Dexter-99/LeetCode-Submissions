import java.util.Scanner;

/**
 * MaximumScoreSplitting
 */
public class MaximumScoreSplitting {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(maxScore(s));
  }

  private static int maxScore(String s) {
    int max = 0;
    int count0[] = new int[s.length()];
    int count1[] = new int[s.length()];
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '0') {
        sum++;
      }
      count0[i] = sum;
      // System.out.print(count0[i]+" ");
    }
    int sum1 = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s.charAt(i) == '1')
        sum1++;
      count1[i] = sum1;
    }
    for (int i = 0; i < s.length() - 1; i++) {
      max = Math.max(count0[i] + count1[i + 1], max);
    }

    return max;
  }
}