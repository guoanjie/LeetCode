# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        nxt = head.next
        head.next = self.swapPairs(nxt.next)
        nxt.next = head
        return nxt


if __name__ == "__main__":
    root = ListNode(1)
    root.next = ListNode(2)
    root.next.next = ListNode(3)
    root.next.next.next = ListNode(4)
    root = Solution().swapPairs(root)
    while root:
        print(root.val)
        root = root.next
