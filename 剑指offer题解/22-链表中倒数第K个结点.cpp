/*
	题目描述
	输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *p, *q;
		p = q = pListHead;
		while(k && q)
		{
			q = q->next;
			k--;
		}
		if(k)
			return NULL;
		while(q)
		{
			p = p->next;
			q = q->next;
		}
		return p;
    }
};