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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::string s1, s2;
        while (l1 != nullptr) {
            s1.append(std::to_string(l1->val));
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.append(std::to_string(l2->val));
            l2 = l2->next;
        }
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());
        int num1 = std::stoi(s1);
        int num2 = std::stoi(s2);
        int sum = num1 + num2;
        std::string str = std::to_string(sum);
        std::reverse(str.begin(), str.end());
        ListNode* newNode = new ListNode(std::stoi(str.substr(0, 1)));
        ListNode* temp = nullptr;
        ListNode* curr = newNode;
        for (int i = 1; i < str.size(); i++) {
            temp = new ListNode(std::stoi(str.substr(i, 1)));
            temp->next = nullptr;
            curr->next = temp;
            curr = temp;
        }
        return newNode;
    }
};
