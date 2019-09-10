/*
	题目描述	输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if(!pHead)
			return NULL;
        RandomListNode *cHead, *p, *c;
		p = pHead;
		while(p)
		{
			c = new RandomListNode(p->label);
			c->next = p->next;
			p->next = c;
			p = c->next;
		}
		cHead = pHead->next;
		p = pHead;
		while(p)
		{
			c = p->next;
			if(p->random != NULL)			//漏掉了，根据答案补充
				c->random = p->random->next;
			p = c->next;
		}
		p = pHead;
		while(p->next)
		{
			c = p->next;
			p->next = c->next;
			p = c;
		}
		return cHead;
    }
};