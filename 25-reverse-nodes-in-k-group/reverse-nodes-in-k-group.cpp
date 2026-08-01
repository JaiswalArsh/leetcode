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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* findKNode(ListNode* temp, int k) {
        k -= 1;
        while (temp && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp) {
            ListNode* KNode = findKNode(temp, k);
            if (KNode == nullptr) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = KNode->next;
            KNode->next = nullptr;
            reverseLinkedList(temp);
            if (temp == head)
                head = KNode;
            else
                prevNode->next = KNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};