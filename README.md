# 🪓 Hangman CLI Game — Built in C++

A terminal-based Hangman game made with C++, featuring real-time input, ASCII UI, a scoring system, and persistent history tracking.

![Banner](https://readme-typing-svg.herokuapp.com/?font=Fira+Code&size=24&pause=1000&color=00FF95&center=true&vCenter=true&width=600&lines=Guess+the+word...+or+get+hanged.)

---

## 🔧 Features

- 🔤 Random words pulled from `words.txt`
- 🎮 Interactive terminal UI using ASCII graphics
- 💯 **Scoring system**
  - +10 for correct guesses
  - -5 for incorrect guesses
  - +50 bonus on win
- 💾 Score history saved to `scores.txt`
- 🔁 Replay support after each game
- ⌨️ Real-time keyboard handling via `<conio.h>`
- 🧠 Lowercase input normalization

---

## 🚀 How to Run

### 🔨 Compile (Windows)
```bash
g++ Game.cpp -o hangman
.\hangman
```
## 🗂️ File Structure
```
Hangman-CLI-Game/
├── Game.cpp        ← Main C++ source file
├── words.txt       ← Word bank (one word per line)
├── scores.txt      ← (Auto-generated) score history
└── README.md       ← You're here
```
## 📝 Sample Output
```
+------------------------------------+
|            MADE BY AYUSH           |
+------------------------------------+
|                O                   |
|               /|\                  |
|               / \                  |
+------------------------------------+
REMAINING LETTERS
a b c d e f g h i j k l m 
n o p q r s t u v w x y z 
GUESS THE WORD
_ _ _ _ _ _
> 
```
## 📚 Word List Example (words.txt)
```nginx
hangman
cplusplus
variable
pointer
debug
compile
syntax
```
## 🚧 Future Ideas (PRs welcome!)
- Add difficulty levels
- Colorized console output
- Multiplayer mode
- Word hint system
- GUI version?


