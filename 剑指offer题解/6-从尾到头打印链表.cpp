/*
	题目描述
	输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> a;
		if(!head)
			return a;
        ListNode *p = head, *q = p->next, *t;
		p->next=NULL;
		while(q)
		{
			t=q->next;
			q->next=p;
			p=q;
			q=t;
		}

		while(p)
		{
			a.push_back(p->val);
			p=p->next;
		}
		return a;
    }
};


//头插法练习
ListNode *h=new ListNode(-1), *p=head, *t;
while(*p)
{
	t=p->next;
	p->next=h->next;
	h->next=p;
	p=t;
}

//还可以用递归和栈