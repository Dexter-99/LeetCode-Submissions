import java.util.Scanner;

/**
 * PowerOfTwo
 */
public class PowerOfTwo {

  public static void main(String[] args) {
    Scanner sn=new Scanner(System.in);
    int n=sn.nextInt();
    System.out.println(isPowerOfTwo(n));
  }
  private static  boolean isPowerOfTwo(long n) {
        
        return ((n&(n-1))==0);
        
    }
}