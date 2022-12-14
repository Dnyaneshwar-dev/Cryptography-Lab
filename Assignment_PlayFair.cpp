#include<bits/stdc++.h>
using namespace std;

class PlayFair{
public:
    static string encrypt(string plaintext, string key)
    {
        transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
        transform(key.begin(), key.end(), key.begin(), ::toupper); 

        for(char &c:key)
        {
            if(c == 'J')c = 'I';
        }

        for(char &c:plaintext)
        {
            if(c == 'J')c = 'I';
        }

        vector<string> word_pairs;

        for(int i=0;i<plaintext.length();i++)
        {
            string p;
            p += plaintext[i];

            if(i + 1 >= plaintext.length() || plaintext[i] == plaintext[i+1])
            {
                p += "X";
            }
            else
            {
                p += plaintext[i+1];
                i++;
            }

            word_pairs.push_back(p);
        }

        
        // Play Fair table

        vector<vector<char>> table(5,vector<char>(5,'A'));

        map<char,int> taken;
        map<char,pair<int,int>> indexOf;

        int row = 0;
        int col = 0;

        for(char c: key)
        {
            if(taken.find(c) != taken.end())continue;
            table[row][col] = c;
            taken[c] = 1;
            indexOf[c] = {row,col};
            col++;
            if(col == 5)
            {
                col = 0;
                row++;
            }
        }
        for(char c='A';c<='Z';c++)
        {
            if(taken.find(c) != taken.end() || c == 'J')continue;
            table[row][col] = c;
            taken[c] = 1;
            indexOf[c] = {row,col};
            col++;
            if(col == 5)
            {
                col = 0;
                row++;
            }
        }


        cout << "Play Fair Table: \n\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout << table[i][j] << '\t';
            }
            cout << '\n';
        }
        
        cout << "\n\n";


        string ciphertext;

        for(string s:word_pairs)
        {
            char F = s[0];
            char S = s[1];

            int x1 = indexOf[F].first;
            int y1 = indexOf[F].second;

            int x2 = indexOf[S].first;
            int y2 = indexOf[S].second;

            if(x1 == x2)
            {
                y1++;
                y2++;
                y1 %= 5;
                y2 %= 5;
                ciphertext += table[x1][y1];
                ciphertext += table[x2][y2];
            }
            else if(y1 == y2)
            {
                x1++;
                x2++;
                x1 %= 5;
                x2 %= 5;
                ciphertext += table[x1][y1];
                ciphertext += table[x2][y2];
            }
            else{
                ciphertext += table[x1][y2];
                ciphertext += table[x2][y1];
            }
        }


        return ciphertext;
    }

    static string decrypt(string ciphertext, string key)
    {
        transform(key.begin(), key.end(), key.begin(), ::toupper); 

        for(char &c:key)
        {
            if(c == 'J')c = 'I';
        }

        vector<string> word_pairs;

        for(int i=0;i<ciphertext.length();i+=2)
        {
            word_pairs.push_back(ciphertext.substr(i,2));
        }

        
        // Play Fair table

        vector<vector<char>> table(5,vector<char>(5,'A'));

        map<char,int> taken;
        map<char,pair<int,int>> indexOf;

        int row = 0;
        int col = 0;

        for(char c: key)
        {
            if(taken.find(c) != taken.end())continue;
            table[row][col] = c;
            taken[c] = 1;
            indexOf[c] = {row,col};
            col++;
            if(col == 5)
            {
                col = 0;
                row++;
            }
        }

        for(char c='A';c<='Z';c++)
        {
            if(taken.find(c) != taken.end() || c == 'J')continue;
            table[row][col] = c;
            taken[c] = 1;
            indexOf[c] = {row,col};
            col++;
            if(col == 5)
            {
                col = 0;
                row++;
            }
        }


        cout << "Play Fair Table: \n\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout << table[i][j] << '\t';
            }
            cout << '\n';
        }

        cout << "\n\n";




        string plaintext;

        for(string s:word_pairs)
        {
            char F = s[0];
            char S = s[1];

            int x1 = indexOf[F].first;
            int y1 = indexOf[F].second;

            int x2 = indexOf[S].first;
            int y2 = indexOf[S].second;

            if(x1 == x2)
            {
                y1--;
                y2--;
                y1 = (y1 + 5) % 5;
                y2 = (y2 + 5) % 5;
                plaintext += table[x1][y1];
                plaintext += table[x2][y2];
            }
            else if(y1 == y2)
            {
                x1--;
                x2--;
                x1 = (x1 + 5) % 5;
                x2 = (x2 + 5) % 5;
                plaintext += table[x1][y1];
                plaintext += table[x2][y2];
            }
            else{
                plaintext += table[x1][y2];
                plaintext += table[x2][y1];
            }
        }


        return plaintext;
    }

    



};

int main()
{

    cout << "Caeser Cipher:\n\n"
       << "Enter your choice:\n"
       << "1. Encrypt\n"
       << "2. Decrypt\n"
       << "> ";

  int choice;
  cin >> choice;

  switch (choice) {
    case 1: {
      cout << "Enter plaintext (lowercase): ";
      string plaintext;
      getline(cin, plaintext);  // buffer reset
      getline(cin, plaintext);
      cout << "Enter key(UPPERCASE): ";
      string key;
      getline(cin, key);

      string ciphertext = PlayFair::encrypt(plaintext, key);

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

      string plaintext = PlayFair::decrypt(ciphertext, key);

      cout << "Ciphertext: " << ciphertext << "\n"
           << "Plaintext:  " << plaintext << "\n";
    } break;

    default:
      cout << "Invalid choice!!\n";
      break;
  }


}