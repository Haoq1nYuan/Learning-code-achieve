#include <iostream>
#include <ctime>

using namespace std;

string originalText;
string codedText;

int PforOriginalText[26];
int PforCodedText[26];

int Turn[25];
bool st[25];

void InitTurn ()
{
    srand(static_cast<unsigned>(time(nullptr))); 

    for (char k = 0; k <= 25; k++)
    {
        int random_number = rand() % 26;  // 得到0-25之间的数

        while (st[(k + random_number) % 26]) random_number = rand() % 26;

        Turn[k] = (k + random_number) % 26;
        st[(k + random_number) % 26] = true;
    }
}

void GetProbabilities (string str, int mode)
{
    for (auto k : str)
    {
        if (k >= 'a' && k <= 'z')
        {
            if (!mode) PforOriginalText[int(k - 'a')]++;
            else PforCodedText[int(k - 'a')]++;
        }
        else if (k >= 'A' && k <= 'Z')
        {
            if (!mode) PforOriginalText[int(k - 'A')]++;
            else PforCodedText[int(k - 'A')]++;
        }
    }
}

void Coded (string str)
{
    int idx = 0;

    for (char k : str)
    {
        if (k >= 'a' && k <= 'z') codedText[idx] = char('a' + Turn[int(k - 'a')]);
        else if (k >= 'A' && k <= 'Z') codedText[idx] = char('A' + Turn[int(k - 'A')]);
        else codedText[idx] = k;

        idx ++;
    }
}

int main ()
{
    InitTurn();

    cout << endl << "The letter substitution rules are: " << endl;
    for (int i = 0; i <= 25; i++) cout << char('a' + i) << " -> " << char('a' + Turn[i]) << endl;

    cout << endl << "Please send me the original text: " << endl;
    getline(cin, originalText);
    codedText = originalText;

    cout << endl << "The originalText is: " << endl << originalText << endl;

    GetProbabilities(originalText, 0);

    cout << endl << "The Probabilities of each letter in originalText are: " << endl;
    for (int i = 0; i <= 25; i++) cout << char('a' + i) << ": " << PforOriginalText[i] << endl;
    cout << endl;

    Coded(originalText);

    cout << endl << "The codedText is: " << endl << codedText << endl;

    GetProbabilities(codedText, 1);

    cout << endl << "The Probabilities of each letter in codedText are: " << endl;
    for (int i = 0; i <= 25; i++) cout << char('a' + i) << ": " << PforCodedText[i] << endl;
    cout << endl;

    return 0;
}

/*
originalText:
The sun was setting, casting long shadows across the park. Children's laughter echoed as they played on the swings and slides, their parents watching from nearby benches. Joggers ran along the path, their breaths rhythmic and steady. The scent of blooming flowers filled the air, a sweet reminder of the approaching spring. A group of friends gathered around a picnic table, their conversation filled with joy and laughter. Nearby, a couple sat quietly on a bench, their hands entwined as they watched the sun dip below the horizon. The park was alive with activity, a snapshot of everyday life. As the last rays of sunlight disappeared, the park began to quiet down. The children were called home for dinner, the joggers finished their runs, and the friends packed up their picnic. The couple on the bench shared a final, lingering look at the sunset before heading home. In the quiet of the evening, the park took on a different kind of beauty. The moon cast a soft glow on the empty playground, the flowers closed up for the night, and the world seemed to hold its breath. It was a moment of peace, a perfect end to the day.
*/