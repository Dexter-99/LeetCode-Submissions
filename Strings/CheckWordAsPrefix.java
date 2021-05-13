import java.util.Scanner;

/**
 * CheckWordAsPrefix
 */
public class CheckWordAsPrefix {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    String sentence = sn.nextLine();
    String searchWord = sn.nextLine();
    System.out.println(isPrefixOfWord(sentence, searchWord));
  }

  private static int isPrefixOfWord(String sentence, String searchWord) {
    int ans = -1;
    String words[] = sentence.split(" ");
    for (int i = 0; i < words.length; i++) {
      if (words[i].indexOf(searchWord) == 0) {
        ans = i + 1;
        break;
      }
    }
    return ans;
  }
}