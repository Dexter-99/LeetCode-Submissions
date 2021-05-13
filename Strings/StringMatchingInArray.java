import java.util.ArrayList;
import java.util.Scanner;

/**
 * StringMatchingInArray
 */
public class StringMatchingInArray {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    int n = sn.nextInt();
    String words[] = new String[n];
    ArrayList<String> list = new ArrayList<>();
    for (int i = 0; i < n; i++)
      words[i] = sn.next();
    ;
    list = stringMatching(words);
  }

  public static ArrayList<String> stringMatching(String[] words) {
    ArrayList<String> list = new ArrayList<>();
    for (int i = 0; i < words.length; i++) {
      for (int j = 0; j < words.length; j++) {
        if (words[i].indexOf(words[j]) != -1 && i != j) {
          list.add(words[j]);
          break;
        }
      }
    }
    return list;
  }

}