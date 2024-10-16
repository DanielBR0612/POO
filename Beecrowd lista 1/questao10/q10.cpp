#include <iostream>
using namespace std;

int main() {
    string sentence;

    while (getline(cin, sentence)) {
        if (sentence == "*") {
            break; 
        }

        char first_letter = '\0'; 
        bool is_tautogram = true; 

        
        for (int i = 0; i < sentence.length(); i++) {
            
            if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
                char current_letter = sentence[i];

               
                if (current_letter >= 'A' && current_letter <= 'Z') {
                    current_letter = current_letter + ('a' - 'A'); 
                }

                if (first_letter == '\0') {
                    first_letter = current_letter; 
                } else if (current_letter != first_letter) {
                    is_tautogram = false; 
                    break;
                }

               
                while (i < sentence.length() && ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z'))) {
                    i++;
                }
            }
        }

        if (is_tautogram) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
