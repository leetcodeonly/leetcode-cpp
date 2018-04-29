/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *m = findMiddle(head);
        ListNode* h2 = m->next;
        m->next = nullptr;
        return merge(sortList(head), sortList(h2));
    }
    
private:
    ListNode* findMiddle(ListNode* head) {
        if(!head) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode *ret;
        if(head1->val <= head2->val) {
            ret = head1;
            head1 = head1->next;
        } else {
            ret = head2;
            head2 = head2->next;
        }
        ListNode *tail = ret;
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                tail = tail->next = head1;
                head1 = head1->next;
            } else {
                tail = tail->next = head2;
                head2 = head2->next;
            }
        }
        tail->next = head1 ? head1 : head2;
        return ret;
    }
};
