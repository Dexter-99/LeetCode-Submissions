import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

/**
 * DestinationCity
 */
public class DestinationCity {

  public static void main(String[] args) {
    Scanner sn = new Scanner(System.in);
    List<List<String>> list = new ArrayList<>();
    for (int i = 0; i < 4; i++) {
      ArrayList<String> city = new ArrayList<>(2);
      for (int j = 0; j < 2; j++)
        city.add(sn.nextLine());
      list.add(city);
    }
    System.out.println(destCity(list));
  }

  private static String destCity(List<List<String>> paths) {
    HashSet<String> h = new HashSet<>();
    for (int i = 0; i < paths.size(); i++) {
      h.add(paths.get(i).get(0));
    }
    for (int i = 0; i < paths.size(); i++) {
      if (!h.contains(paths.get(i).get(1)))
        return paths.get(i).get(1);
    }
    return "";
  }
}