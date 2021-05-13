import java.util.Scanner;

/**
 * StudentAttendanceRecord
 */
public class StudentAttendanceRecord {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(checkRecord(s));
  }

  private static boolean checkRecord(String s) {
    int l = 1;
    int a = 0;
    if (s.charAt(0) == 'A')
      a++;
    for (int i = 1; i < s.length(); i++) {
      if (l > 2 || a > 1)
        return false;
      if (s.charAt(i) == 'A')
        a++;
      if (s.charAt(i - 1) == 'L' && s.charAt(i) == 'L') {
        l++;
      } else {
        l = 1;
      }

    }
    // System.out.println(l);
    if (l > 2 || a > 1)
      return false;
    return true;
  }
}