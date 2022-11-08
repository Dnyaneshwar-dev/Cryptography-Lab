#include<bits/stdc++.h>
using namespace std;

class CaesarCipher {
 public:
  static string encrypt(string& plaintext, int key) {
    string ciphertext;

    for (char c : plaintext) {
      if (!(('A' <= c && c <= 'Z') || (c >= 'a' && c <= 'z')))
        continue;
      if(c >= 'a' && c <= 'z') c -= 32;

      ciphertext += ('A' + (c - 'A' + key) % 26);
    }

    return ciphertext;
  }

  static string decrypt(const string& ciphertext, int key) {
    string plaintext;

    for (char c : ciphertext)
      plaintext += ('A' + (c - 'A' + 26 - key) % 26);

    return plaintext;
  }
};


class Trie{
    public:
    Trie* child[26];
    int end;
    Trie()
    {
        end = 0;
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
    }

    void insert(string s)
    {
        Trie* A = this;

        for(int i=0;i<s.length();i++)
        {
            int index = s[i] - 'A';
            if(!(index >= 0 && index < 26))continue;
            if(A -> child[index] == nullptr)
            {
                A -> child[index] = new Trie();
            }
            A = A -> child[index];
        }

        A -> end = 1;

    }

    int find(string s)
    {
        Trie* A = this;

        for(int i=0;i<s.length();i++)
        {
            int index = s[i] - 'A';
            if(A -> child[index] == nullptr)
            {
                return 0;
            }
            A = A -> child[index];
        }
        return (A -> end == 1);
    }
};



Trie generateTrie() {
  ifstream file("dictionary.txt");
  string word;
  Trie trie;

  while (getline(file, word)){
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    
    trie.insert(word);
  }

  file.close();
  return trie;
}


int dfs(int index,string text,Trie& T, string word)
{
    if(index == text.length())
    {
        if(T.find(word))
            return word.size();
        return 0;
    }

    // Move forward without adding space
    word += text[index];
    int ans = dfs(index + 1, text, T, word);
    word.pop_back();

    // Add the space
    if(T.find(word))
    {
        word = "";
        word += text[index];
        ans = max(ans,(int)word.size() + dfs(index+1,text,T,word));
    }

    return ans;
}

void findBestPrediction(string ciphertext, Trie& T)
{
    using pii = pair<int,string>;
    using sc = pair<int,pii>;

    vector<sc> decryptions;

    for(int key=1;key<=25;key++)
    {
        string text = CaesarCipher::decrypt(ciphertext, key);
        int score = dfs(0,text,T,"");

        decryptions.push_back({score,{key,text}});

        cout << score << ' ' << text << '\n';
    }
    sort(decryptions.begin(),decryptions.end(),greater<sc>());

    cout << "Most Relevant Prediction:\n";

    cout << "Text: " << decryptions[0].second.second << '\n';
    cout << "Key: " << decryptions[0].second.first << '\n';

}


int main()
{

    // Sample Input:
    // Plaintext: We reached late at college
    // Key - 10
    // Ciphertext: GOKBOVKDOPYBMBIZDYQBKZRIVOMDEBO

    // Word:
    // Plaintext: Network
    // key = 20
    // Ciphertext: HYNQILE
    string ciphertext;


    cout << "Enter The Ciphertext: (UPPERCASE) ";

    cin >> ciphertext;


    
    Trie T = generateTrie();

    findBestPrediction(ciphertext, T);

    return 0;
}