#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        function<void (int, int)> rotateone = [&](int start, int end)
        {
            if (start == end)
                return;
            int val = matrix[start][start];
            for (int i = start; i < end; i++)
            {
                int tmp = matrix[start][i + 1];
                matrix[start][i + 1] = val;
                val = tmp;
            }
            for (int i = start; i < end; i++)
            {
                int tmp = matrix[i + 1][end];
                matrix[i + 1][end] = val;
                val = tmp;
            }
            for (int i = end; i > start; --i)
            {
                int tmp = matrix[end][i - 1];
                matrix[end][i - 1] = val;
                val = tmp;
            }
            for (int i = end; i - 1 >= start; --i)
            {
                int tmp = matrix[i - 1][start];
                matrix[i - 1][start] = val;
                val = tmp;
            }

        };
        int n = matrix.size();
        int start = 0, end = n - 1;
        for (; start < end; start++, end--)
        {
            for (int i = 0; i < end-start; ++i)
                rotateone(start, end);
        }

    }
};

class Solution2
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        function<void (int, int)> rotateone = [&](int start, int end)
        {
            if (start == end)
                return;
            vector<int> tmp(end - start + 1);
            int tail = matrix[start][end];
            for (int i = 0; i < end - start + 1; ++i)
            {
                tmp[i] = matrix[i + start][end];
                matrix[i + start][end] = matrix[start][start + i];

            }
            matrix[end][end] = tail;
            cout << "after rotate" << endl;
            for (auto &i : matrix)
            {
                for (auto &j : i)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << endl;
            for (auto &i : tmp)
                cout << i << " ";
            cout << endl;
            //matrix[start][end] = matrix[start][start];

            auto tmp2 = tmp;
            tail = matrix[end][end];
            for (int i = 0; i < end - start + 1; ++i)
            {
                tmp[i] = matrix[end][end - i];
                matrix[end][end - i] = tmp2[i];
            }
            matrix[end][start] = tail;
            cout << "after rotate" << endl;
            for (auto &i : matrix)
            {
                for (auto &j : i)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << endl;
            for (auto &i : tmp)
                cout << i << " ";
            cout << endl;
            //matrix[end][end] = matrix[start][end];

            tmp2 = tmp;
            tail = matrix[end][start];
            for (int i = 0; i < end - start + 1; ++i)
            {
                tmp[i] = matrix[end - i][start];
                matrix[end - i][start] = tmp2[i];
            }
            matrix[start][start] = tail;
            cout << "after rotate" << endl;
            for (auto &i : matrix)
            {
                for (auto &j : i)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << endl;
            for (auto &i : tmp)
                cout << i << " ";
            cout << endl;
            //matrix[start][end] = matrix[start][start];

        };
        int n = matrix.size();
        rotateone(0, n - 1);

    }
};

int main(void)
{
    Solution sy;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sy.rotate(matrix);
    cout << "after rotate" << endl;
    for (auto &i : matrix)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
