class Solution {
public:
    
ListNode* swapNodes(ListNode* head, int k) {
    ListNode *n1 = nullptr, *n2 = nullptr;
    for (auto p = head; p != nullptr; p = p->next) {
        n2 = n2 == nullptr ? nullptr : n2->next;
        if (--k == 0) {
            n1 = p;
            n2 = head;
        }
    }
    swap(n1->val, n2->val);
    return head;
}
