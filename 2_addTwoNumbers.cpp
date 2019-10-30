#include <iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0,res = 0;
        ListNode *head,*tail ;
        head = new ListNode(0);
        tail = head;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL)
                l1 = new ListNode(0);
            else if(l2 == NULL)
                l2 = new ListNode(0);
            res = l1->val + l2->val + flag;
            if(res > 9){
                res -= 10;
                flag = 1;
            }
            else
                flag = 0;
            tail->next = new ListNode(res);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(flag == 1)
            tail->next = new ListNode(1);
        return head->next;
    }
};

//进位符偏暴力求解