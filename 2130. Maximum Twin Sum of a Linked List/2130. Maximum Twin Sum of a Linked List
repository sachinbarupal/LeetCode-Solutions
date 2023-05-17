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
    int pairSum(ListNode* head) {
        stack<int> st;
        int len = 0,maxi=0;
        ListNode* tmp = head;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        tmp= head;len = len/2;
        while(tmp){
            if((len--)>0){
                st.push(tmp->val);
            }

            else{
                int sum = tmp->val + st.top(); st.pop();
                maxi = max(maxi,sum);
            }
            tmp = tmp->next;
        }
        return maxi;
    }
};
