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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* , int> map;

        while(headA!=NULL){
            map[headA]++;
            headA = headA->next;
        }
        while(headB != NULL){
			if(map[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;


    }
};