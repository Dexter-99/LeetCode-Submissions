import java.util.Scanner;

/**
 * ReduceNumberToZero
 */
public class ReduceNumberToZero {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    System.out.println(numberOfSteps(n));
  }

  private static int numberOfSteps(int num) {
    int count = 0;
    while (num > 0) {
      if ((num & 1) != 0)
        num--;
      else
        num = num >> 1;
      count++;
    }
    return count;
  }
}