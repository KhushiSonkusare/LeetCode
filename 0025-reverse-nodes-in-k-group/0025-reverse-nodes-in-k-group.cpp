class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        ListNode* ptr = head;

        while (ptr != NULL) {
            nextNode = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nextNode;
        }

        return prev;
    }

    ListNode* kthElem(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevList = NULL;
        ListNode* newHead = NULL;

        while (temp != NULL) {
            ListNode* kth = kthElem(temp, k);
            if (kth == NULL) {
                if (prevList) {
                    prevList->next = temp;
                }
                break;
            }

            ListNode* nextnode = kth->next;
            kth->next = NULL;

            ListNode* reversedHead = reverse(temp);

            if (!newHead) newHead = reversedHead;

            if (prevList) {
                prevList->next = reversedHead;
            }

            prevList = temp;
            temp = nextnode;
        }

        return newHead ? newHead : head;
    }
};
