/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {

    if(head==NULL)
    return false;
struct ListNode *slow = head;
struct ListNode *fast = slow->next;
while(slow!=fast)
{
    if(fast==NULL)
        return false;
    fast = fast->next;
    if(fast==NULL)
        return false;
    fast = fast->next;
    slow = slow->next;
   
}
    if(fast==NULL)
    return false;
 return true;  
}
