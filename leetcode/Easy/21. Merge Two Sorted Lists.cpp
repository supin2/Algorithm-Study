struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* head = list3; // dummy node
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                list3->next = list1;
                list1 = list1->next;
            } else {
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        if (list1 != nullptr) {
            list3->next = list1;
        } else if (list2 != nullptr) {
            list3->next = list2;
        }
        return head->next;
    }
};