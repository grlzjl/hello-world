/*
	题目描述
	给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(!pHead || !pHead->next)
            return NULL;
        ListNode *fast, *slow;
		fast = slow = pHead;
		do
		{
			slow = slow->next;
			fast = fast->next->next;
		}while(fast && fast->next && fast != slow);
		if(!fast || !fast->next || fast != slow)
			return NULL;
		fast = pHead;
		while(fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
    }
};