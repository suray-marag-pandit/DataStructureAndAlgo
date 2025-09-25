#include <iostream>
#include <string>
using namespace std;

int main() {
    char ch;
    char word[20];
    char sentence[50];
    string modernWord, modernSentence;

    cout << "Enter a single character: ";
    cin >> ch;

    cout << "Enter a single word (char array): ";
    cin >> word;

    cin.ignore(); // clear buffer before getline

    cout << "Enter a sentence (char array): ";
    cin.getline(sentence, 50);

    cout << "Enter a single word (string): ";
    cin >> modernWord;

    cin.ignore(); // clear buffer before getline again

    cout << "Enter a sentence (string): ";
    getline(cin, modernSentence);

    cout << "\n--- OUTPUT ---\n";
    cout << "Character: " << ch << endl;
    cout << "Word (char array): " << word << endl;
    cout << "Sentence (char array): " << sentence << endl;
    cout << "Word (string): " << modernWord << endl;
    cout << "Sentence (string): " << modernSentence << endl;

    return 0;
}
