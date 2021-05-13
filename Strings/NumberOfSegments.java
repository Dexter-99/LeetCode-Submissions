import java.util.Scanner;

/**
 * NumberOfSegments
 */
public class NumberOfSegments {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.nextLine();
    System.out.println(countSegments(s));
  }

  private static int countSegments(String s) {
    String str[] = s.trim().split(" ");
    int count = 0;
    for (int i = 0; i < str.length; i++) {

      if (!str[i].isEmpty())
        count++;
    }
    return count;
  }
}