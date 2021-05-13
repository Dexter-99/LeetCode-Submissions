import java.util.ArrayList;
import java.util.List;

/**
 * Subsets
 */
public class Subsets {

  public static void main(String[] args) {
    int nums[] = { 1, 2, 3 };
    subsets(nums);
  }

  private static List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> li = new ArrayList<>();
    int n = nums.length;
    for (int i = 0; i < Math.pow(2, n); i++) {
      List list = new ArrayList<>();
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0)
          list.add(nums[j]);
      }
      li.add(list);
    }
    return li;
  }
}