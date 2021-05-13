import java.util.Scanner;

/**
 * GoatLatin
 */
public class GoatLatin {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String s = sn.nextLine();
    System.out.println(toGoatLatin(s));
  }

  private static String toGoatLatin(String s) {
    String words[] = s.trim().split(" ");
    String vow = "aeiouAEIOU";
    StringBuilder res = new StringBuilder("");
    String a = "";
    String ma = "ma";
    for (int i = 0; i < words.length; i++) {
      if (vow.indexOf(words[i].charAt(0)) != -1) {
        res.append(words[i]);
        res.append(ma);
      } else {
        res.append(words[i].substring(1));
        res.append(words[i].charAt(0));
        res.append(ma);
      }
      res.append(a += "a");
      res.append(" ");
    }
    return res.toString().trim();
  }
}