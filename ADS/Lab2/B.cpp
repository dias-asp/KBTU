#include <iostream>

using namespace std;

int timer = 0;

struct Node{
    string val;
    int id;
    Node* next;
    Node* prev;
    Node(): val(""), id(++timer), next(nullptr), prev(nullptr) {}
    Node(string x): val(x), id(++timer), next(nullptr), prev(nullptr) {}
    Node(Node* next, Node* prev): val(0), id(++timer), next(next), prev(prev) {}
    Node(string x, Node* next, Node* prev): val(x), id(++timer), next(next), prev(prev) {}
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
    Node* head = new Node();
    Node* tail = new Node();
    tail -> prev = head;
    head -> next = tail;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        head = insert(head, new Node(s), 0);
    }
    head = reverse(head);
    head = cyclic_left(head, m);
    print(head);
}