* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//删除链表中等于给定值 val 的所有节点。
//
//示例 :
//
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val)
{
	ListNode* cur = head;
	ListNode* next = NULL;
	ListNode* prev = NULL;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			cur = NULL;
			cur = next;
			if (prev == NULL)
			{
				head = next;
			}
			else
			{
				prev->next = cur;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
