#include <iostream>
using namespace std;

int main() {
    string sentence;

    while (getline(cin, sentence)) {
        if (sentence == "*") {
            break; // Condição de parada
        }

        char first_letter = '\0'; // Para armazenar a primeira letra da frase
        bool is_tautogram = true; // Suponha que a frase é um tautograma

        // Percorre a frase e checa as primeiras letras das palavras
        for (int i = 0; i < sentence.length(); i++) {
            // Encontrar a primeira letra de uma palavra
            if ((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) {
                char current_letter = sentence[i];

                // Converter maiúsculas para minúsculas manualmente (se necessário)
                if (current_letter >= 'A' && current_letter <= 'Z') {
                    current_letter = current_letter + ('a' - 'A'); // Converte para minúsculo
                }

                if (first_letter == '\0') {
                    first_letter = current_letter; // Define a primeira letra
                } else if (current_letter != first_letter) {
                    is_tautogram = false; // Se a letra for diferente, não é tautograma
                    break;
                }

                // Avançar para o final da palavra
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
