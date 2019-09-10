/*
	题目描述	输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
			return pHead2;
		if(!pHead2)
			return pHead1;
		
		ListNode *head = new ListNode(-1), *p;
		p = head;
		while(pHead1 && pHead2)
		{
			if(pHead1->val < pHead2->val)
			{
				p->next = pHead1;
				pHead1 = pHead1->next;
				p = p->next;
			}
			else
			{
				p->next = pHead2;
				pHead2 = pHead2->next;
				p = p->next;
			}
		}
		if(pHead1)
			p->next = pHead1;
		if(pHead2)
			p->next = pHead2;
		return head->next;
    }
};