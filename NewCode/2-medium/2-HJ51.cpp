/*
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。
链表结点定义如下：
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};
正常返回倒数第k个结点指针，异常返回空指针.
要求：
(1)正序构建链表;
(2)构建后要忘记链表长度。
数据范围：链表长度满足1≤n≤1000,k≤n,0≤val≤10000 

本题有多组样例输入。

输入描述：
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述：
输出一个整数

示例1
输入：
    8
    1 2 3 4 5 6 7 8
    4
输出：
	5
*/
#include <iostream>
using namespace std;

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
    ListNode():m_nKey(0),m_pNext(nullptr) {}
    ListNode(int val):m_nKey(val), m_pNext(nullptr) {}
};

int getKNum(int k, ListNode *head) {
    int n = 0;
    ListNode *p;
    p = head;
    while(p->m_pNext) {
        p = p->m_pNext;
        n++;
    }
    k = n - k + 1;
    p = head;
    while (k--)
        p = p->m_pNext;
    return p->m_nKey;
}

int main() {
    int n;
    int k;
    int num;
    ListNode *head;
    while (cin >> n) {
        head = new ListNode;
        ListNode *p = head;
        while(n--) {
            cin >> num;
            ListNode *tmp = new ListNode(num);
            p->m_pNext = tmp;
            p = p->m_pNext;
        }
        cin >> n;
        cout << getKNum(n, head) << endl;
    }
    return 0;
}
