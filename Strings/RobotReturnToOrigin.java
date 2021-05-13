import java.util.Scanner;

/**
 * RobotReturnToOrigin
 */
public class RobotReturnToOrigin {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    System.out.println(judgeCircle(s));
  }

  private static boolean judgeCircle(String moves) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < moves.length(); i++) {
      char ch = moves.charAt(i);
      if (ch == 'U')
        y++;
      else if (ch == 'D')
        y--;
      else if (ch == 'L')
        x--;
      else if (ch == 'R')
        x++;
    }
    return (x == 0 && y == 0);
  }
}