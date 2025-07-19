#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

class Hangman {
private:
    int guessCount;
    int score;
    bool gameOver;
    string guessedWord;
    string wordToGuess;

public:
    Hangman() {
        guessCount = 0;
        score = 0;
        gameOver = false;
        guessedWord = "";
        wordToGuess = "";
    }

    void PrintMessage(string message, bool printTop = true, bool printBottom = true) {
        if (printTop) {
            cout << "+------------------------------------+" << endl;
            cout << "|";
        } else cout << "|";

        bool flag = true;
        for (int i = message.length(); i < 36; i++) {
            if (flag)
                message += " ";
            else
                message = " " + message;
            flag = !flag;
        }

        cout << message;

        if (printBottom) {
            cout << "|" << endl;
            cout << "+------------------------------------+" << endl;
        } else {
            cout << "|" << endl;
        }
    }

    void DrawHangman() {
        if (guessCount >= 1)
            PrintMessage("!", 0, 0);
        else
            PrintMessage("", 0, 0);

        if (guessCount >= 2)
            PrintMessage("!", 0, 0);
        else
            PrintMessage("", 0, 0);

        if (guessCount == 10)
            PrintMessage("@", 0, 0);
        else if (guessCount >= 3)
            PrintMessage("O", 0, 0);
        else
            PrintMessage("", 0, 0);

        if (guessCount == 4)
            PrintMessage("|", 0, 0);
        else if (guessCount == 5)
            PrintMessage("\\| ", 0, 0);

        if (guessCount >= 6)
            PrintMessage("\\|/", 0, 0);
        else
            PrintMessage("", 0, 0);

        if (guessCount >= 7)
            PrintMessage("|", 0, 0);
        else
            PrintMessage("", 0, 0);

        if (guessCount == 8)
            PrintMessage("/  ", 0, 0);

        if (guessCount >= 9)
            PrintMessage("/ \\", 0, 0);
        else
            PrintMessage("", 0, 0);
    }

    void RandomWord(string path = "words.txt") {
        srand(time(0));
        vector<string> v;
        ifstream file(path);

        if (file.is_open())
            while (getline(file, wordToGuess))
                v.push_back(wordToGuess);
        file.close();

        if (v.size() > 0)
            wordToGuess = v.at(rand() % v.size());
        else {
            cout << "words.txt not found or empty!" << endl;
            exit(1);
        }
    }

    void PrintLetters(char from, char to) {
        string S;
        for (char i = from; i <= to; i++) {
            if (guessedWord.find(i) == string::npos) {
                S += i;
                S += " ";
            } else {
                S += "  ";
            }
        }
        PrintMessage(S, 0, 0);
    }

    void RemainingLetters() {
        PrintMessage("REMAINING LETTERS");
        PrintLetters('a', 'm');
        PrintLetters('n', 'z');
    }

    void PrintWord() {
        PrintMessage("GUESS THE WORD");
        string S;
        gameOver = true;
        for (int i = 0; i < wordToGuess.length(); i++) {
            if (guessedWord.find(wordToGuess[i]) == string::npos) {
                gameOver = false;
                S += "_ ";
            } else {
                S += wordToGuess[i];
                S += " ";
            }
        }
        PrintMessage(S, 0);
    }

    void CountGuess(string newGuess) {
        for (char c : newGuess) {
            if (wordToGuess.find(c) == string::npos) {
                guessCount++;
                score -= 5; // Wrong guess
            } else {
                score += 10; // Correct guess
            }
        }
    }

    void Setup() {
        guessCount = 0;
        score = 0;
        guessedWord = "";
        gameOver = false;
        RandomWord();

        do {
            system("cls");
            PrintMessage("MADE BY AYUSH");
            DrawHangman();
            RemainingLetters();
            PrintWord();

            string ch;
            cout << "> ";
            cin >> ch;

            // Normalize to lowercase
            for (char& c : ch)
                c = tolower(c);

            if (guessedWord.find(ch) == string::npos) {
                guessedWord += ch;
                CountGuess(ch);
            }

            if (gameOver)
                break;

            if (_kbhit()) {
                char key = _getch();
                if (key == '0')
                    break;
            }

        } while (guessCount < 10);

        system("cls");
        PrintMessage("RESULT");
        DrawHangman();
        cout << "WORD: " << wordToGuess << endl;

        if (gameOver) {
            cout << "🎉 You Win!" << endl;
            score += 50; // Bonus for winning
        } else {
            cout << "💀 You Lose!" << endl;
        }

        cout << "Your Score: " << score << endl;

        // Save to scores.txt
        ofstream scoreFile("scores.txt", ios::app);
        if (scoreFile.is_open()) {
            scoreFile << "Score: " << score << " | Word: " << wordToGuess << " | Result: "
                      << (gameOver ? "Win" : "Lose") << endl;
            scoreFile.close();
        }
    }
};

int main() {
    char playAgain;
    do {
        Hangman h;
        h.Setup();
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    system("pause");
    return 0;
}
