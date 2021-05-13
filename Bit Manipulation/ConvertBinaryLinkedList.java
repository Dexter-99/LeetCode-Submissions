import java.util.Scanner;

/**
 * ConvertBinaryLinkedList
 */
class ListNode{
  int val;
  ListNode next;
  ListNode(int val)
  {
    this.val=val;
    this.next=null;
  }
}
public class ConvertBinaryLinkedList {

  public static void main(String[] args) {
    Scanner sn=new Scanner(System.in);

  }
  
  private static int getDecimalValue(ListNode head) {
    ListNode curr = head;
    int res = 0;
    while (curr != null) {
      res = (res << 1) + curr.val;
      curr = curr.next;
    }
    return res;
  }
}