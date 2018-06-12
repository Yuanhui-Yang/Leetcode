using System;

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int x) { val = x; }
}

public class Solution {
    public static ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummy = new ListNode(-1), node = dummy;
        while (l1 != null || l2 != null || carry != 0) {
            int x = l1 == null ? 0 : l1.val;
            int y = l2 == null ? 0 : l2.val;
            int z = x + y + carry;
            carry = z / 10;
            node.next = new ListNode(z % 10);
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
            node = node.next;
        }
        return dummy.next;
    }
    public static void Main() {
        ListNode l1, l2, result;

        l1 = new ListNode(1);
        l2 = new ListNode(9);
        l2.next = new ListNode(9);
        result = AddTwoNumbers(l1, l2);
        while (result != null) {
            Console.Write(result.val);
            Console.WriteLine();
            result = result.next;
        }
        Console.WriteLine();
    }
}
