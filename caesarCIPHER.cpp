#include <iostream>vaa
using namespace std;

int main() {
    string text;  // To store the text (plaintext or ciphertext)
    int shift;    // To store the shift key (number of positions to shift)
    char choice;  // To store the choice for encoding or decoding
    char repeat;  // To ask if the user wants to run the program again

    do {
        // Ask the user for input
        cout << "Enter the text: ";
        getline(cin, text);  // Read the whole line of text

        cout << "Enter the shift key (positive integer): ";
        cin >> shift;  // Get the shift value

        cout << "Choose action: (E)ncode or (D)ecode: ";
        cin >> choice;  // Get the user's choice

        // Loop through each character in the text
        for (int i = 0; i < text.length(); i++) {
            char c = text[i];  // Get the current character

            // If the character is a letter (a-z or A-Z)
            if (c >= 'a' && c <= 'z') {
                if (choice == 'E' || choice == 'e') {
                    c = ((c - 'a' + shift) % 26) + 'a';  // Encoding
                } else if (choice == 'D' || choice == 'd') {
                    c = ((c - 'a' - shift + 26) % 26) + 'a';  // Decoding
                }
            } else if (c >= 'A' && c <= 'Z') {  // If it's an uppercase letter (A-Z)
                if (choice == 'E' || choice == 'e') {
                    c = ((c - 'A' + shift) % 26) + 'A';  // Encoding
                } else if (choice == 'D' || choice == 'd') {
                    c = ((c - 'A' - shift + 26) % 26) + 'A';  // Decoding
                }
            }

            text[i] = c;  // Replace the character in the text
        }

        // Output the result
        if (choice == 'E' || choice == 'e') {
            cout << "Encoded text: " << text << endl;  // Display encoded text
        } else if (choice == 'D' || choice == 'd') {
            cout << "Decoded text: " << text << endl;  // Display decoded text
        }

        // Ask the user if they want to perform another operation
        cout << "Thanks for using this system! Do you want to continue? (Y/N): ";
        cin >> repeat;

        cin.ignore();  // To ignore the newline character left in the buffer
    } while (repeat == 'Y' || repeat == 'y');  // Continue if the user presses Y or y

    return 0;
}
