#include <bits/stdc++.h>
using namespace std;
vector < long long > a;

void heapify_up(int id)
{
    while (id > 1 && a[id] < a[id / 2])
    {
        swap(a[id], a[id / 2]);
        id /= 2;
    }

}
void heapify_down(int id)
{
    while (true)
    {
        int next = id;
        if (id + id < a.size() && a[id + id] < a[next]) next = id + id;
        if (id + id + 1 < a.size() && a[id + id + 1] < a[next]) next = id + id + 1;
        if (id == next) break;
        swap(a[id], a[next]);
        id = next;
    }
}
void add(long long x)
{
    a.push_back(x);
    heapify_up(a.size() - 1);
}
void pop()
{
    swap(a[1], a[a.size() - 1]);
    a.pop_back();
    heapify_down(1);
}

int main()
{
    int n, w;
    cin >> n >> w;

    a.push_back(0);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s == "print") cout << sum << endl;
        if (s == "insert")
        {
            int x;
            cin >> x;
            sum += x;
            add(x);
            if (a.size() > w + 1)
            {
                sum -= a[1];
                pop();
            }
        }
    }

}
