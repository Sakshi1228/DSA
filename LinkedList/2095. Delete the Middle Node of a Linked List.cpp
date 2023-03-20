class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        if(head == NULL || head -> next == NULL)
        {
            head = NULL;
            return head;
        }

        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
            
        }

        prev -> next = prev -> next -> next;
        slow = NULL;


        return head;
        
    }
};
