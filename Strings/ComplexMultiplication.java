import java.util.Scanner;

public class ComplexMultiplication {
  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String a = sn.next();
    String b = sn.next();
    System.out.println(complexNumberMultiply(a, b));
  }

  private static String complexNumberMultiply(String a, String b) {
    int x1 = Integer.parseInt(a.split("[+]")[0]);
    int y1 = Integer.parseInt(a.split("[+]")[1].substring(0, a.split("[+]")[1].length() - 1));
    int x2 = Integer.parseInt(b.split("[+]")[0]);
    int y2 = Integer.parseInt(b.split("[+]")[1].substring(0, b.split("[+]")[1].length() - 1));
    String res = "";
    int re = ((x1 * x2) - (y1 * y2));
    int im = (x1 * y2) + (y1 * x2);
    res += re + "+" + im + "i";
    return res;
  }
}