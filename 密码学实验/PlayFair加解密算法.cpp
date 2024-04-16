#include <iostream>
#include <map>

using namespace std;

const int N = 1005;

char code[N];
char encode[N];
int p = 0;
pair<char, char> tem[N];
int k = 1;
int choice;

map<char, pair<int, int>> link_map = {
    {'m', {1, 1}}, {'o', {1, 2}}, {'n', {1, 3}}, {'a', {1, 4}}, {'r', {1, 5}},
    {'c', {2, 1}}, {'h', {2, 2}}, {'y', {2, 3}}, {'b', {2, 4}}, {'d', {2, 5}},
    {'e', {3, 1}}, {'f', {3, 2}}, {'g', {3, 3}}, {'i', {3, 4}}, {'k', {3, 5}},
    {'l', {4, 1}}, {'p', {4, 2}}, {'q', {4, 3}}, {'s', {4, 4}}, {'t', {4, 5}},
    {'u', {5, 1}}, {'v', {5, 2}}, {'w', {5, 3}}, {'x', {5, 4}}, {'z', {5, 5}}
};

char map_link[10][10] = {
    {'m', 'o', 'n', 'a', 'r'},
    {'c', 'h', 'y', 'b', 'd'},
    {'e', 'f', 'g', 'i', 'k'},
    {'l', 'p', 'q', 's', 't'},
    {'u', 'v', 'w', 'x', 'z'}
};

void CodingInit (char *code)
{
    int idx = 1;

    while (code[idx] != '\0')
    {
        if (code[idx] == code[idx - 1])
        {
            tem[k] = {code[idx - 1], 'x'};
            idx ++;
        }
        else
        {
            tem[k] = {code[idx - 1], code[idx]};
            idx += 2;
        }

        k ++;
    }

    if (code[idx - 1]) tem[k++] = {code[idx - 1], 'x'};  
}

void DisCodingInit (char *encode)
{
    for (int i = 0; encode[i]; i++) encode[i] = (char)(encode[i] + 32);

    CodingInit(encode);
}

void Coding (char *encode)
{
    for (int i = 1; i < k; i++) 
    {
        char a = tem[i].first, b = tem[i].second;

        if (a == 'j') a = 'i';
        if (b == 'j') b = 'i'; 

        int xa = link_map[a].first - 1, ya = link_map[a].second - 1;
        int xb = link_map[b].first - 1, yb = link_map[b].second - 1;

        if (ya == yb) 
        {
            encode[p ++] = (char)(map_link[(xa + 1) % 5][ya] - 32);
            encode[p ++] = (char)(map_link[(xb + 1) % 5][yb] - 32);
        }
        else if (xa == xb)
        {
            encode[p ++] = (char)(map_link[xa][(ya + 1) % 5] - 32);
            encode[p ++] = (char)(map_link[xb][(yb + 1) % 5] - 32);
        }
        else 
        {
            encode[p ++] = (char)(map_link[xa][yb] - 32);
            encode[p ++] = (char)(map_link[xb][ya] - 32);
        }
    }
}

void DisCoding (string code)
{
    for (int i = 1; i < k; i++)
    {
        char a = tem[i].first, b = tem[i].second;

        if (a == 'j') a = 'i';
        if (b == 'j') b = 'i';

        int xa = link_map[a].first - 1, ya = link_map[a].second - 1;
        int xb = link_map[b].first - 1, yb = link_map[b].second - 1;

        if (xa == xb) 
        {
            code[p ++] = map_link[xa - 1 != -1 ? xa - 1 : 4][ya];
            code[p ++] = map_link[xb - 1 != -1 ? xb - 1 : 4][yb];
        }
        else if (ya == yb)
        {
            code[p ++] = map_link[xa][ya - 1 != -1 ? ya - 1 : 4];
            code[p ++] = map_link[xb][yb - 1 != -1 ? yb - 1 : 4];
        }
        else 
        {
            code[p ++] = map_link[xa][yb];
            code[p ++] = map_link[xb][ya];
        }
    }
}

int main ()
{       
    cout << "Choose your need (1. Coding 2. DisCoding 3. Exit): ";
    cin >> choice;

    while (choice != 3)
    {
        p = 0;
        k = 1;

        if (choice == 1)
        {
            cout << "Show me your originalText in lowercase: ";
            cin >> code;

            CodingInit(code);

            cout << "The text after pairing is: " << endl;
            for (int i = 1; i < k; i++) cout << '{' << tem[i].first << ", " << tem[i].second << "}" << endl;

            Coding(encode);

            cout << "The codedText is: " << encode << endl;
        }
        else 
        {
            cout << "Show me your codedText in uppercase: ";
            cin >> encode;

            DisCodingInit(encode);

            cout << "The text after paring is: " << endl;
            for (int i = 1; i < k; i++) cout << '{' << (char)(tem[i].first - 32) << ", " << (char)(tem[i].second - 32) << "}" << endl;

            DisCoding(code);

            cout << "The originalText is: " << code << endl;        
        }
    
        cout << "Choose your need (1. Coding 2. DisCoding 3. Exit): ";
        cin >> choice;    
    }

    return 0;
}