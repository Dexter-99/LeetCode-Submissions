import java.util.Scanner;

/**
 * HammingDistance
 */
public class HammingDistance {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int x = sn.nextInt();
    int y = sn.nextInt();
    System.out.println(hammingDistance(x, y));
  }

  private static int hammingDistance(int x, int y) {
    int count = 0;
    int z = x ^ y;
    while (z > 0) {
      z = z & (z - 1);
      count++;
    }
    return count;
  }
}