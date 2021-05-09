#include <bits/stdc++.h>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        head = new ListNode(0, head);
        for (ListNode *p1 = head, *p2 = head; p1 != nullptr; p1 = p1->next, p2 = p2->next)
        {
            for (; n >= 0; n--)
            {
                p2 = p2->next;
            }
            if (p2 == nullptr)
            {
                if (p1 == head)
                {
                    ListNode *res = p1->next;
                    delete p1;
                    return res;
                }
                else
                {
                    ListNode *delpointer = p1->next;
                    p1->next = delpointer->next;
                    delete delpointer;
                    return head;
                }
            }
        }
        return nullptr;
    }
};

class Solution2
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        vector<ListNode *> pointers;
        int len = 0;
        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            pointers.emplace_back(p);
            len++;
        }
        int pos = len - n;
        int former = len - n - 1;
        if (former < 0)
            return pointers[pos]->next;
        else
        {
            pointers[former]->next = pointers[pos]->next;
            delete pointers[pos];
            return head;
        }

    }
};

int main(void)
{

    return 0;
}
