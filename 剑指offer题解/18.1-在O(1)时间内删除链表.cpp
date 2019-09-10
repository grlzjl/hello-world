/*
	题目描述
	（没有对应的题目）
	大意是删除给定指针所指的结点
*/


ListNode* deleteNode(ListNode* head, ListNode* tobeDeleted)
{
	if(!head || !tobeDeleted)
		return head;
	ListNode* p;
	if(tobeDeleted->next != NULL)
	{
		p = tobeDeleted->next;
		tobeDeleted->val = p->val;
		tobeDeleted->next = p->next;
		free(p);
	}
	else
	{
		if(head == tobeDeleted)
		{
			p = tobeDeleted;
			head = NULL;
			free(p);
		}
		else
		{
			p = head;
			while(p->next!=tobeDeleted)
				p = p->next;
			p->next = NULL;
			free(tobeDeleted);
		}
	}
	return head;
}