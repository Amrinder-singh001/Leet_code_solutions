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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL &&
               fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverseList(slow->next);

        ListNode* first = head;
        ListNode* temp = second;
        bool result = true;

        while (temp != NULL) {
            if (first->val != temp->val) {
                result = false;
                break;
            }

            first = first->next;
            temp = temp->next;
        }

        slow->next = reverseList(second);
        return result;
    }
};
