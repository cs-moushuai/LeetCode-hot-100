#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *l = new ListNode();
        ListNode *p = l;
        while (l1 || l2)
        {
            if (!l1)
            {
                p->next = l2;
                break;
            }
            if (!l2)
            {
                p->next = l1;
                break;
            }
            if (l1->val < l2->val)
            {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }

        }
        return l->next;

    }
};

int main(void)
{

    return 0;
}
