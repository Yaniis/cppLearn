#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;
//function to randomize the inputed word
string wordRandomizer(string word)
{
    srand(time(0));
    int sizeM = word.size();
    for(int i(0); i<sizeM; ++i)
    {
        int randN;
        randN = rand() % sizeM;
        char currentLetter = word[randN]; //get current letter to put it back on the word
        word.erase(randN, 1);
        word.push_back(currentLetter);
    }
    return word;
}



int main()
{
    cout << "Welcome in the word shaker !" << endl;
    cout << "Enter something to randomize : ";
    string userWord;
    cin >> userWord;
    string randWord;
    randWord = wordRandomizer(userWord);

    string attemp;
    bool isWin(false);
    int gameTurn(1);
    //main loop to check answer from user
    do
    {
        string attemp;
        cout << "This is your shaked word : " << randWord << endl;
        cin >> attemp;
        //condition to check if user win
        if(attemp == userWord)
        {
            isWin = true;
        }
        else
        {
            isWin = false;
            gameTurn++;
        }

    }while(!isWin);

    cout << "YOU  W I N in " << gameTurn << "attemp(s)";

    return 0;
}
