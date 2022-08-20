class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)   return nullptr;
        int kc = k;
        ListNode* hc = head;
        ListNode* prev = nullptr;
        ListNode* next;
        
        while(hc && k) {
            //Reverse with O(1) space 
            next = hc->next;
            hc->next = prev;
            prev = hc;
            hc = next;
            k--;
        }

        if (k > 0) {
            //Reverse again only if there were not enough nodes at the end
            hc = nullptr;
            while(prev) {
            next = prev->next;
            prev->next = hc;
            hc = prev;
            prev = next;
            }
            return hc;
        }
        head->next = reverseKGroup(hc, kc);
        return prev;
    }
};