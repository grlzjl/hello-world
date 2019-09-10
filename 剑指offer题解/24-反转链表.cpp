/*
	题目描述
	输入一个链表，反转链表后，输出新链表的表头。
*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(!pHead || !pHead->next)
			return pHead;
		ListNode *head = new ListNode(-1), *p;
		while(pHead)
		{
			p = pHead->next;
			pHead->next = head->next;
			head->next = pHead;
			pHead = p;
		}
		return head->next;
    }
};


//递归方法，理解略困难
public ListNode ReverseList(ListNode head) {
	if (head == null || head.next == null)
		return head;
	ListNode next = head.next;
	head.next = null;
	ListNode newHead = ReverseList(next);
	next.next = head;
	return newHead;
}