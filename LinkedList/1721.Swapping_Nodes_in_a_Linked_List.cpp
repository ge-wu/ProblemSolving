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
    ListNode* swapNodes(ListNode* head, int k) {
      vector<int>temp;
      ListNode* pointer = head;
      while (pointer) {
        temp.push_back(pointer->val);
        pointer = pointer->next;
      }
      int n = temp.size();
      swap(temp[k-1], temp[n-k]);
      
      ListNode* res = new ListNode(0);
      pointer = res;
      for (int i: temp) {
        ListNode* cur = new ListNode(i);
        pointer->next = cur;
        pointer = pointer->next;
      }
      return res->next;
    }
};
