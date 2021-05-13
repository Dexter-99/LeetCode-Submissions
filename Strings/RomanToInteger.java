import java.util.HashMap;
import java.util.Scanner;

/**
 * RomanToInteger
 */
public class RomanToInteger {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.next();
    HashMap<Character, Integer> m = new HashMap<>();
    m.put('I', 1);
    m.put('V', 5);
    m.put('X', 10);
    m.put('L', 50);
    m.put('C', 100);
    m.put('D', 500);
    m.put('M', 1000);
    int val = 0;
    int prev = 0;
    int curr = 0;
    for (int i = 0; i < s.length(); i++) {
      curr = m.get(s.charAt(i));
      if (curr > prev)
        val += curr - 2 * prev;
      else
        val += curr;
      prev = curr;
    }
    System.out.println(val);
  }
}