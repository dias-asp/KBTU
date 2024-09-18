#include <iostream>

using namespace std;

int timer = 0;

struct Node{
    int val;
    int id;
    Node* next;
    Node* prev;
    Node(): val(0), id(++timer), next(nullptr), prev(nullptr) {}
    Node(int x): val(x), id(++timer), next(nullptr), prev(nullptr) {}
    Node(Node* next, Node* prev): val(0), id(++timer), next(next), prev(prev) {}
    Node(int x, Node* next, Node* prev): val(x), id(++timer), next(next), prev(prev) {}
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

void print(Node* head){
    auto cur = head -> next;
    while (cur -> next != nullptr)
    {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node();
    Node* tail = new Node();
    tail -> prev = head;
    head -> next = tail;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        head = insert(head, new Node(x), i - 1);
    }
    for (int i = n / 2 * 2; i >= 1; i -= 2)
    {
        head = remove(head, i - 1);
    }
    print(head);
}
