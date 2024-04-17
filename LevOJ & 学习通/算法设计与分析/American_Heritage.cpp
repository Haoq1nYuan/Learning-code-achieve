#include <iostream>
#include <map>

using namespace std;

string preorder, inorder;
map<char, int> g;

void build (int pl, int pr, int il, int ir)
{
    char root = preorder[pl];
    int rg = g[root];

    if (rg > il) build(pl + 1, pl + rg - il, il, rg - 1);
    if (rg < ir) build(pl + rg - il + 1, pr, rg + 1, ir);
    
    cout << root;
}

int main ()
{
    while (cin >> inorder >> preorder)
    {
        int idx = 1;
        for (auto ch: inorder) g[ch] = idx++;
        idx --;

        inorder = ' ' + inorder;
        preorder = ' ' + preorder;

        build (1, idx, 1, idx);

        cout << endl;
    }

    return 0;
}