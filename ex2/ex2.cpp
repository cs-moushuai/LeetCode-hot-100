#include <bits/stdc++.h>
#include <memory>
#include <stack>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */
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
private:
    queue<int> toQueue(ListNode *l)
    {
        queue<int> que;
        for (ListNode *p = l; p != nullptr; p = p->next)
        {
            que.emplace(p->val);
        }
        return que;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        queue<int> que1 = toQueue(l1);
        queue<int> que2 = toQueue(l2);
        ListNode *head = nullptr, *p = nullptr;
        bool carry = false;
        int sum = 0;
        while (!que1.empty() || !que2.empty())
        {
            sum = 0;
            int val1 = 0, val2 = 0;
            if (!que1.empty())
            {
                val1 = que1.front();
                que1.pop();
            }
            else
            {
                val1 = 0;
            }
            if (!que2.empty())
            {
                val2 = que2.front();
                que2.pop();
            }
            else
            {
                val2 = 0;
            }
            if (head == nullptr)
            {
                int tmp = val1 + val2;
                if (tmp >= 10)
                {
                    sum = tmp % 10;
                    carry = true;
                }
                else
                {
                    sum = tmp;
                    carry = false;
                }
                head = new ListNode(sum);
                p = head;
            }
            else
            {
                if (carry)
                    ++sum;
                int tmp = val1 + val2;
                sum += tmp;
                if (sum >= 10)
                {
                    sum %= 10;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
                p->next = new ListNode(sum);
                p = p->next;
            }
        }
        if (carry)
        {
            p->next = new ListNode(1);
        }
        return head;
    }
};

int main(void)
{

    return 0;
}
