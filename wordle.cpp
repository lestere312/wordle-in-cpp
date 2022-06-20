#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include<stdlib.h>

using namespace std;

class Game
{
public:
    int turns = 0;

    string word;

    void setWord(string s)
    {
        word = s;
    }
    void sayWord()
    {
        cout << "\033[1;33m" << "Yellow: In the word but the wrong spot."<< "\033[0m" << endl;
        cout << "\033[1;32m" << "Green: In the word and in the correct spot."  << "\033[0m"  << endl;
        cout << "\033[1;30m" << "You get 6 tries, good luck!"  << "\033[0m"  << endl;
    }
    void turn()
    {
        int contains[5] = {};
        int dictcontains[5][5] = {};
        int win = 0;
        vector<string> dict;
        string letter = "";
        while(letter.length() != 5){
            cout << "Enter a 5 letter word:" << endl;
            cin >> letter;  
        }
        for (int i = 0; i < 5; i++){
            if(letter.at(i)==word.at(i)){
                contains[i]++;
                win++;
            }
        }

        for (int i = 0; i < 5; i++){
            if(word.find(letter.at(i))!= string::npos){
                contains[i]++;
            }         
        }
        dict.push_back(word);
        
        turns++;

        cout << endl << "word     ";

            for (int i = 0; i < 5; i++){
                if (contains[i] == 0){
                    cout << letter.at(i) << " " ;
                } else if(contains[i] == 1){
                    cout << "\033[1;33m" << letter.at(i) << " " << "\033[0m" ;
                } else if(contains[i] == 2){
                    cout << "\033[1;32m" << letter.at(i) << " " << "\033[0m" ;
                }
                
            }

        cout << endl << "\033[1;31m" << "try #    " << "\033[0m" << turns << "\n";


        if(win != 5){
            if (turns < 6){
                turn();
            }else{
                lose();
            }
            
        }else{
            end();
        }
        
    }
    void end()
    {
        cout << endl << "You've Won!" << endl << "The word was: " << word;
    }
    void lose()
    {
        cout << endl << "You've lost:(" << endl<< "The word was: " << word;;
    }
};

int main()
{
    string line;
    vector<string> lines;
    fstream newfile;
    srand(time(0));

    // input file stream
    ifstream file("mit.txt");

    // count number of total lines in the file and store the lines in the string vector
    int total_lines = 0;
    while (getline(file, line))
    {
        total_lines++;
        lines.push_back(line);
    }

    int random_number = rand() % total_lines;


    //cout << lines[random_number] << random_number << "dank" << total_lines << endl;
    while(lines[random_number].length() != 5){
        //cout << random_number << "change" << endl;
        random_number = rand() % total_lines;
    }

    Game game;
    game.setWord(lines[random_number]);
    game.sayWord();
    game.turn();
    return 0;
}