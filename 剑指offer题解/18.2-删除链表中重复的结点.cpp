/*
	题目描述	在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(!pHead || !pHead->next)
			return pHead;
		ListNode *head = new ListNode(-1);
		head->next = pHead;
		ListNode *p = head, *q = pHead->next, *t;
		while(q)
		{
			if(p->next->val != q->val)
			{
				p = p->next;
				q = q->next;
			}
			else
			{
				while(q && p->next->val == q->val)
				{
					t = q;
					q = q->next;
					free(t);
				}
				p->next = q;
				if(q)
					q = q->next;
			}
		}
		
		return head->next;
    }
};


//递归方法
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(!pHead || !pHead->next)
			return pHead;
		ListNode *p = pHead->next;
		if(pHead->val == p->val)
		{
			while(p && pHead->val == p->val)
				p = p->next;
			return deleteDuplication(p);
		}
		else
		{
			pHead->next = deleteDuplication(pHead->next);
			return pHead;
		}
    }
};