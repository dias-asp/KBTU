#include <iostream>

using namespace std;

int timer = 0;

struct Node{
    char val;
    Node* next;
    Node* prev;
    Node(): val(' '), next(nullptr), prev(nullptr) {}
    Node(char x): val(x), next(nullptr), prev(nullptr) {}
    Node(Node* next, Node* prev): val(' '), next(next), prev(prev) {}
    Node(char x, Node* next, Node* prev): val(x), next(next), prev(prev) {}
};

Node* insert(Node* head, Node* node, int p){
    auto cur = head;
    for (int i = 1; i <= p; i++)
    {
        cur = cur -> next;
    }
    (cur -> next) -> prev = node;
    node -> next = cur -> next;
    cur -> next = node;
    node -> prev = cur;
    return head;
}

Node* remove(Node* head, int p){
    auto cur = head;
    for (int i = 0; i <= p; i++)
    {
        cur = cur -> next;
    }
    (cur -> prev) -> next = cur -> next;
    (cur -> next) -> prev = cur -> prev;
    return head;
}

int find(Node* head, char val)
{
    auto cur = head -> next;
    int p = 0;
    while (cur -> next != nullptr)
    {
        if (cur -> val == val) return p;
        p++;
        cur = cur -> next;
    }
    return -1;
}

Node* get(Node* head, int p)
{
    auto cur = head;
    for (int i = 0; i <= p; i++)
    {
        cur = cur -> next;
    }
    return cur;
}

Node* replace(Node* head, int p1, int p2){
    Node* node = get(head, p1);
    head = remove(head, p1);
    head = insert(head, node, p2);
    return head;
}

Node* reverse(Node* head){
    Node* head1 = new Node ();
    Node* tail1 = new Node ();
    tail1 -> prev = head1;
    head1 -> next = tail1;
    auto cur = head -> next;
    while (cur -> next != nullptr)
    {
        head1 = insert(head1, new Node(cur -> val), 0);
        cur = cur -> next;
    }
    return head1;
}

void print(Node* head){
    auto cur = head -> next;
    while (cur -> next != nullptr)
    {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
    auto tail = head;
    while (tail -> next != nullptr)
    {
        tail = tail -> next;
    }
    for (int i = 1; i <= x; i++)
    {
        Node* node = get(head, 0);
        head = remove(head, 0);
        node -> next = tail;
        node -> prev = tail -> prev;
        tail -> prev -> next = node;
        tail -> prev = node;
    }
    return head;
}
Node* cyclic_right(Node* head, int x){
    head = reverse(head);
    head = cyclic_left(head, x);
    head = reverse(head);
    return head;
}

int main(){

    int ts;
    cin >> ts;
    for (int t = 1; t <= ts; t++)
    {
        Node* head = new Node();
        Node* tail = new Node();
        tail -> prev = head;
        head -> next = tail;

        Node* head1 = new Node();
        Node* tail1 = new Node();
        tail1 -> prev = head1;
        head1 -> next = tail1;

        int n;
        cin >> n;
        int cnt_good = 0;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;

            if (find(head1, c) != -1)
            {
                head1 = remove(head1, find(head1, c));
                head = insert(head, new Node(c), 0);
                cnt_good--;
            }
            else if (find(head, c) == -1)
            {
                head1 = insert(head1, new Node(c), cnt_good);
                cnt_good++;
            }

            if (head1 -> next == tail1) cout << -1 << " ";
            else cout << get(head1, 0) -> val << " ";
        }
        cout << endl;
    }
}
