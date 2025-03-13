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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* current = slow->next;
        ListNode* next = slow->next;

        while (current != nullptr) {
            next = current->next;   
            current->next = prev;
            prev = current;
            current = next;
        }

        while(prev != nullptr){
            if(prev->val != head->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};