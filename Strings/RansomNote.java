import java.util.Scanner;

/**
 * RansomNote
 */
public class RansomNote {

  public static void main(String[] args) {
    Scanner sn=new Scanner(System.in);
    String s1=sn.next();
    String s2=sn.next();
    canConstruct(s1,s2);
  }

  private static boolean canConstruct(String ransomNote, String magazine) {
    int count[] = new int[256];
    for (int i = 0; i < ransomNote.length(); i++) {
      count[ransomNote.charAt(i)]++;
    }
    for (int i = 0; i < magazine.length(); i++) {
      count[magazine.charAt(i)]--;
    }
    for (int i = 0; i < 256; i++) {
      if (count[i] > 0)
        return false;

    }
    return true;
  }
}