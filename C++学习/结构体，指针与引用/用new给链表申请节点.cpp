#include <iostream>
using namespace std;

struct Node 
{
    int val, k;
    Node* next;
    
    Node ( int _val, int _k ) : val(_val), k(_k), next(NULL) {}
};

int main ()
{
    Node* p = new Node(1, 10);  
    //开辟一块内存空间給值为1和10的结构体，并将该结构体的地址传给p
    auto q = new Node(2, 20);
    //auto相当于Node *p
    
    p->next = q;
    
    Node* head = p;
    Node* l = head;
    
    while ( l )
    {
        cout << l->val << " " << l->k << endl;
        l = l->next;
    }
    
    return 0;
}