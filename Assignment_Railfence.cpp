#include<bits/stdc++.h>
using namespace std;
class RailFenceCipher{
    public:
        static string encrypt(string plaintext,int depth)
        {
            transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

            vector<char> levels[depth];
            int curLevel = 0;
            int turn = 1;
            for(int i=0;i<plaintext.length();i++)
            {
                levels[curLevel].push_back(plaintext[i]);
                
                if(curLevel == depth - 1 && turn == 1)
                {
                    turn = -1;
                }
                else if(curLevel == 0 && turn == -1)
                {
                    turn = 1;
                }
                curLevel += turn;
            }
            string ciphertext;

            for(int i=0;i<depth;i++)
            {
                for(char c:levels[i]) ciphertext += c;
            }
            return ciphertext;
        }

        static string decrypt(string ciphertext,int depth)
        {
            int curLevel = 0;
            int turn = 1;
            vector<int> counts(depth, 0);
            
            for(int i=0;i<ciphertext.length();i++)
            {
                counts[curLevel]++;
                if(curLevel == depth - 1 && turn == 1)
                {
                    turn = -1;
                }
                else if(curLevel == 0 && turn == -1)
                {
                    turn = 1;
                }
                curLevel += turn;
            }
            


            vector<string> letters(depth);

            int start_index = 0;
            
            for(int i=0;i<depth;i++)
            {
                int c = counts[i];
                letters[i] = ciphertext.substr(start_index,c);
                start_index += c;
            }

            
            


            string plaintext;

            fill(counts.begin(),counts.end(),0);

            curLevel = 0;
            turn = 1;
            for(int i=0;i<ciphertext.length();i++)
            {
                plaintext += letters[curLevel][counts[curLevel]];
                counts[curLevel]++;

                if(curLevel == depth - 1 && turn == 1)
                {
                    turn = -1;
                }
                else if(curLevel == 0 && turn == -1)
                {
                    turn = 1;
                }
                curLevel += turn;
            }
            

            return plaintext;

        }
};


int main()
{
    cout << "Rail Fence Cipher:\n\n"
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

      int depth;
      cout << "\nEnter Depth: ";
      cin >> depth;
      string ciphertext = RailFenceCipher::encrypt(plaintext, depth);

      cout << "Plaintext:  " << plaintext << "\n"
           << "Ciphertext: " << ciphertext << "\n";
    } break;

    case 2: {
      cout << "Enter ciphertext (uppercase without spaces): ";
      string ciphertext;
      cin >> ciphertext;

      int depth;
      cout << "\nEnter Depth: ";
      cin >> depth;
      string plaintext = RailFenceCipher::decrypt(ciphertext, depth);

      cout << "Ciphertext: " << ciphertext << "\n"
           << "Plaintext:  " << plaintext << "\n";
    } break;

    default:
      cout << "Invalid choice!!\n";
      break;
  }
}