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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode *list: lists) {
            ListNode *pointer = list;
            while (pointer) {
                pq.push(pointer->val);
                pointer = pointer->next;
            }
        }        
        ListNode *ans = new ListNode(0);
        ListNode *pointer = ans;
        while (!pq.empty()) {
            int cur = pq.top(); pq.pop();
            ListNode *new_node = new ListNode(cur);
            pointer->next = new_node;
            pointer = pointer->next;
        }
        return ans->next;
    }
};
