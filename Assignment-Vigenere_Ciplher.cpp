#include<bits/stdc++.h>
using namespace std;

class VigenereCipher{
    public:
    static string encrypt(string plaintext,string key)
    {
        transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
        transform(key.begin(), key.end(), key.begin(), ::toupper);

        string ciphertext = plaintext;

        int j = 0;
        string newKey;
        for(int i=0;i<plaintext.length();i++)
        {
            newKey += key[j];
            j++;
            j %= key.length();
        }


        for(int i=0;i<plaintext.length();i++)
        {
            int P = plaintext[i] - 'A';
            int K = newKey[i] - 'A';
            ciphertext[i] = (char)('A' +  (P + K) % 26);
        }

        return ciphertext;
    }

    static string decrypt(string ciphertext, string key)
    {
        transform(key.begin(), key.end(), key.begin(), ::toupper);

        int j = 0;
        string newKey;
        for(int i=0;i<ciphertext.length();i++)
        {
            newKey += key[j];
            j++;
            j %= key.length();
        }

        string plaintext = ciphertext;

        for(int i=0;i<ciphertext.length();i++)
        {
            int C = ciphertext[i] - 'A';
            int K = newKey[i] - 'A';
            plaintext[i] = (char)('A' +  (C - K + 26) % 26);
        }

        return plaintext;

    }
};


int main()
{

    cout << "Vigenere Cipher:\n\n"
       << "Enter your choice:\n"
       << "1. Encrypt\n"
       << "2. Decrypt\n"
       << "> ";

  int choice;
  cin >> choice;

  switch (choice) {
    case 1: {
      cout << "Enter plaintext (without spaces): ";
      string plaintext;
      getline(cin, plaintext);  // buffer reset
      getline(cin, plaintext);
      cout << "Enter key(UPPERCASE): ";
      string key;
      getline(cin, key);

      string ciphertext = VigenereCipher::encrypt(plaintext, key);

      cout << "Plaintext:  " << plaintext << "\n"
           << "Ciphertext: " << ciphertext << "\n";
    } break;

    case 2: {
      cout << "Enter ciphertext (uppercase without spaces): ";
      string ciphertext;
      cin >> ciphertext;

      cout << "Enter key: ";
      string key;
      cin >> key;

      string plaintext = VigenereCipher::decrypt(ciphertext, key);

      cout << "Ciphertext: " << ciphertext << "\n"
           << "Plaintext:  " << plaintext << "\n";
    } break;

    default:
      cout << "Invalid choice!!\n";
      break;
  }

}

// Sample Data: Wearehiring
// Key: ABSENT
// Ciphertext: WFSVRAISART
