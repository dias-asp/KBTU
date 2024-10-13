#include <bits/stdc++.h>
using namespace std;
vector < long long > a;

void heapify_up(int id)
{
    while (id > 1 && a[id] > a[id / 2])
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
        if (id + id < a.size() && a[id + id] > a[next]) next = id + id;
        if (id + id + 1 < a.size() && a[id + id + 1] > a[next]) next = id + id + 1;
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
    int n;
    cin >> n;
    a.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x);
    }

    while (a.size() > 2)
    {
        int y = a[1];
        pop();
        int x = a[1];
        pop();
        if (y > x) add(y - x);
    }

    if (a.size() == 1) cout << 0;
    else cout << a[1];
}
