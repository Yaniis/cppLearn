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
    srand(time(0));
    string replay("O");
    while(replay == "O")
    {
        cout << "Welcome in the word shaker !" << endl;

        string isAlone("O");
        cout << "Play alone ? (if you choose \"O\" a word will be randomly choose in a dictionary) O/N : " << endl;
        cin >> isAlone;

        string plainWord;
        if(isAlone == "O")
        {
            ifstream dictionary("PATH");
            if(dictionary)
            {
                int randLine(0);
                randLine = rand() % 323577;
                string computerWord("");
                dictionary.seekg(randLine);
                getline(dictionary, computerWord);
                cout << computerWord << endl;
                plainWord = computerWord;

            }
        }
        else
        {
            cout << "Enter something to randomize : ";
            cin >> plainWord;
        }
        //define the variable of shacked word and applying the shaker on the word
        string randWord;
        randWord = wordRandomizer(plainWord);

        int chance(0);
        cout << "Enter a number of attempts (type 999 is you don't want that) : ";
        cin >> chance;
        string userAttempt;

        bool isWin(false);
        int gameTurn(1);
        //main loop to check answer from user
        do
        {
            if(chance == 0)
            {
                cout << "You haven't more try. The word was :  " << plainWord << endl;
                cout << "You lose, play again ? : ";
                cin >> replay;
                break;
            }

            if(chance == 999)
            {
                cout << "This is your shacked word : " << randWord <<endl;
                cin >> userAttempt;
                if(userAttempt == plainWord)
                {
                    isWin = true;
                    cout << "YOU  W I N in " << gameTurn << "attempt(s)" << endl;
                    cout << "Do you want to play again ? O/N : ";
                    cin >> replay;
                    break;
                }

                else
                {
                    //set the boolean to false, check if user have activate attempt counting and decrement the variable relative to the chances
                    isWin = false;
                    gameTurn++;

                    if(chance != 999)
                    {
                        chance--;
                    }
                }
            }
            cout << "This is your shacked word : " << randWord << " | You've " << chance << "chances" <<endl;
            cin >> userAttempt;

               if(userAttempt == plainWord)
                {
                    isWin = true;
                    cout << "YOU  W I N in " << gameTurn << "attempt(s)" << endl;
                    cout << "Do you want to play again ? O/N : ";
                    cin >> replay;
                    break;
                }

                else
                {
                    //set the boolean to false, check if user have activate attempt counting and decrement the variable relative to the chances
                    isWin = false;
                    gameTurn++;

                    if(chance != 999)
                    {
                        chance--;
                    }
                }
            }
            //condition to check if user win
            if(userAttempt == plainWord)
            {
                isWin = true;
                cout << "YOU  W I N in " << gameTurn << "attempt(s)" << endl;
                cout << "Do you want to play again ? O/N : ";
                cin >> replay;
                break;
            }
            else
            {
                //set the boolean to false, check if user have activate attempt counting and decrement the variable relative to the chances
                isWin = false;
                gameTurn++;
                if(chance != 999)
                {
                    chance--;
                }
            }

        }while(!isWin);
    }

    return 0;
}
