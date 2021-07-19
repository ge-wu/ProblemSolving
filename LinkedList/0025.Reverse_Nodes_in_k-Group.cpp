/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = new ListNode();
        temp ->next = head;
        ListNode *pointer = temp;
        while (pointer) {
            ListNode *p2 = pointer;
            int cnt = 0;
            while (p2->next && cnt < k) {
                p2 = p2->next;
                cnt++;
            }
            cout << pointer->val << "\n";
            if (cnt < k) {
                return temp->next;
            }
            ListNode *cur = pointer->next;
            ListNode *nextNode = cur->next;
            ListNode *future = nextNode->next;
            ListNode *start = cur;
            for (int i = 0; i < k - 1; ++i) {
                nextNode->next = cur;
                cur = nextNode;
                nextNode = future;
                if (future) {
                    future = future->next;
                }
            }
            pointer->next = cur;
            start->next = nextNode;
            pointer = start;
        }
        return temp->next;
    }
};
