#include<bits/stdc++.h>
using namespace std;
class ColumnarCipher{
    public:
    static string encrypt(string plaintext, vector<int>& key)
    {
        transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

        int N = key.size();
        int cols = N;
        int M = (plaintext.length() / N) + (plaintext.length() % N > 0);
        // cout << plaintext.length() << ' ' << M << ' ' << N << '\n';

        vector<pair<int,int>> keyMap;
        for(int i=0;i<key.size();i++)
        {
            keyMap.push_back({key[i],i });
        }
        sort(keyMap.begin(),keyMap.end());



        vector<vector<char>> A(M,vector<char>(N,'X'));

        int i = 0;
        int j = 0;
        int k = 0;
        while(k < plaintext.length())
        {
            A[i][j] = plaintext[k++];
            j++;
            if(j == N)
            {
                i++;
                j = 0;
            }
        }

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout << A[i][j] << ' ';
            }
            cout << '\n';
        }

        string ciphertext;
        for(auto col:keyMap)
        {
            for(i=0;i<M;i++)
            {
                ciphertext += A[i][col.second];
            }
        }

        return ciphertext;
    }

    static string decrypt(string ciphertext, vector<int> & key)
    {
        int N = key.size();
        int cols = N;
        int M = (ciphertext.length() / N) + (ciphertext.length() % N > 0);

        vector<vector<char>> A(M,vector<char>(N,'X'));


        vector<pair<int,int>> keyMap;
        for(int i=0;i<key.size();i++)
        {
            keyMap.push_back({key[i],i });
        }
        sort(keyMap.begin(),keyMap.end());


        

        int r = 0;
        int c = 0;
        for(int i=0;i<ciphertext.length();i++)
        {
            A[r][keyMap[c].second] = ciphertext[i];
            r++;
            if(r == M)
            {
                r = 0;
                c++;
            }
        }

        string plaintext;

        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                plaintext += A[i][j];
                cout << A[i][j] << ' ';
            }
            cout << '\n';
        }

        return plaintext;
    }
};

int main()
{
    cout << "Columnar Cipher:\n\n"
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

      vector<int> key;
      int n;
      cout << "\nEnter Number of Elements in Key : ";
      cin >> n;
      cout << "\nEnter N values of the key(0 based indexing): ";
      for(int i=0;i<n;i++)
      {
          int k;
          cin >> k;
          key.push_back(k);
      }
      string ciphertext = ColumnarCipher::encrypt(plaintext, key);

      cout << "Plaintext:  " << plaintext << "\n"
           << "Ciphertext: " << ciphertext << "\n";
    } break;

    case 2: {
      cout << "Enter ciphertext (uppercase without spaces): ";
      string ciphertext;
      cin >> ciphertext;

      vector<int> key;
      int n;
      cout << "\nEnter Number of Elements in Key: ";
      cin >> n;
      cout << "\nEnter N values of the key: ";
      for(int i=0;i<n;i++)
      {
          int k;
          cin >> k;
          key.push_back(k);
      }

      string plaintext = ColumnarCipher::decrypt(ciphertext, key);

      cout << "Ciphertext: " << ciphertext << "\n"
           << "Plaintext:  " << plaintext << "\n";
    } break;

    default:
      cout << "Invalid choice!!\n";
      break;
  }

    
}