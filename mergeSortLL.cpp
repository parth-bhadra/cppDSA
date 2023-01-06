#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* sortList(ListNode* A);
};

ListNode* mergeTwoSortedLists (ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(-1);
    ListNode* head = ans;
    while(A!=NULL && B!=NULL) {
        if(A->val < B->val) {
            ans->next = new ListNode(A->val);
            ans = ans->next;
            A = A->next;
        } else {
            ans->next = new ListNode(B->val);
            ans = ans->next;
            B = B->next;
        }
    }
    while(A!=NULL) {
        ans->next = A;
        ans = ans->next;
        break;
    }
    while(B!=NULL) {
        ans->next = B;
        ans = ans->next;
        break;
    }

    return head->next;
}

ListNode* getMiddleElement(ListNode* A) {
    
    ListNode* slow = A;
    ListNode* fast = A;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* Solution::sortList(ListNode* A) {
    if(A->next == NULL) return A;
    ListNode* H1 = A;
    
    ListNode* middle = NULL; // get middle of sorted list
    if(H1->next->next != NULL) {
        middle = getMiddleElement(H1);
    } else {
        middle = H1;
    }

    ListNode* H2 = middle->next;
    middle->next = NULL;
    ListNode* sortedLL1 = sortList(H1);
    ListNode* sortedLL2 = sortList(H2);
    return mergeTwoSortedLists(sortedLL1, sortedLL2);

}


int main() {

    ListNode* head = new ListNode(3);
    ListNode* two = new ListNode(4);
    ListNode* three = new ListNode(2);
    ListNode* four = new ListNode(8);
    head->next = two;
    two->next = three;
    three->next = four;

    Solution myObj;
    ListNode* ans = myObj.sortList(head);
    
    return 0;
}
