#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *l, *r;
    Node(char x, int y): data(x), freq(y), l(NULL), r(NULL) {}
};

struct compare {
    bool operator()(Node *l, Node*r) {
        return l->freq > r->freq;
    }
};

void display(Node *p, string str) {
    if(p) {
        if(p->data != '$')
            cout << p->data << ": " << str << "\n";
        display(p->l, str + "0");
        display(p->r, str + "1");
    }
}

void huffmanCodes(char data[], int fr[], int n) {
    priority_queue<Node*, vector<Node*>, compare > pq;
    for(int i=0;i<n;i++)
        pq.push(new Node(data[i], fr[i]));
        
    while(pq.size() != 1) {
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();
        Node *t = new Node('$', l->freq + r->freq);
        t->l = l;
        t->r = r; 
        pq.push(t);
    }
    display(pq.top(), "");
}

int main() {
    
    char data[] = {'Q', 'p', 'T', 'a', 'd' };
    int freq[] = {3,23,30,12,18};
    int n = sizeof(data)/sizeof(data[0]);
    cout<<"Encoded Symbol :  ";
    for(auto &x: data) cin >> x;
    for(auto &x: freq) cin >> x;
    huffmanCodes(data, freq, n);
}