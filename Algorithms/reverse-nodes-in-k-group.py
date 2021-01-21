25. Reverse Nodes in k-Group
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def length(node):
            result = 0
            while node is not None:
                result += 1
                node = node.next
            return result
        def reverse(node):
            if node is None:
                return node
            if node.next is None:
                return node
            nextNode = node.next
            result = reverse(nextNode)
            node.next.next = node
            node.next = None
            return result
        sz = length(head)
        if sz < k:
            return head
        elif sz == k:
            return reverse(head)
        else:
            dummy = ListNode()
            dummy.next = head
            prevNode = dummy
            currNode = head
            for i in range(k):
                prevNode = currNode
                currNode = currNode.next
            prevNode.next = None
            a = dummy.next
            b = currNode
            a = reverse(a)
            b = self.reverseKGroup(b, k)
            dummy.next.next = b
            return a