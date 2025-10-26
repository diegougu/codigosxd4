#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct CBinNode {
    int value;
    CBinNode* nodes[2];

    CBinNode(int v) {
        value = v;
        nodes[0] = nullptr;
        nodes[1] = nullptr;
    }                                                                                     
};

class CBinTree {
private:
    CBinNode* m_root = nullptr;
    bool m_b = 0;
    bool find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void recvc(int ini, int fin, vector<int> vc);
public:
    bool Insert(int x);
    bool Remove(int x);
    void print();
    void sortedArrayToBTS(vector<int> vc);
};

bool CBinTree::find(int x, CBinNode**& p) {
    for (p = &m_root; *p && (*p)->value != x; p = &((*p)->nodes[(*p)->value < x]));
    return *p && (*p)->value == x;
}

bool CBinTree::Insert(int x) {
    CBinNode** p;
    if (find(x, p)) {
        return false;
    }
    *p = new CBinNode(x);
    return true;
}

CBinNode** CBinTree::Rep(CBinNode** p) {
    m_b = !m_b;
    p = &((*p)->nodes[!m_b]);
    while ((*p)->nodes[m_b]) {
        p = &((*p)->nodes[m_b]);
    }
    return p;
}

bool CBinTree::Remove(int x) {
    CBinNode** p;
    if (!find(x, p)) {
        return false;
    }


    if ((*p)->nodes[0] && (*p)->nodes[1]) {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }

    CBinNode* temp = *p;
    *p = (*p)->nodes[(*p)->nodes[0] == 0];
    delete temp;
    return true;
}




void CBinTree::print() {
    queue<CBinNode*> q;
    q.push(m_root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            CBinNode* p = q.front();
            q.pop();
            cout << p->value << " ";
            if (p->nodes[0] != nullptr) {
                q.push(p->nodes[0]);
            }

            if (p->nodes[1] != nullptr) {
                q.push(p->nodes[1]);
            }
        }
        cout << endl;
    }

    cout << endl;
}


void CBinTree::recvc(int ini, int fin, vector<int> vc) {
    if (ini >= fin) {
        return;
    }
    int mid = ini + ((fin - ini) / 2);
    this->Insert(vc[mid]);
    recvc(ini, mid, vc);
    recvc(mid + 1, fin, vc);
}

void CBinTree::sortedArrayToBTS(vector<int> vc) {
    recvc(0, vc.size(), vc);
}


int main() {
    CBinTree t;
    vector<int> vc = { -10,-3,0,5,9 };
    t.sortedArrayToBTS(vc);
    t.print();
}
