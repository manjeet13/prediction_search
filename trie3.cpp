/*
 *	Author	:	Manjeet Kumar <kumar.manjeet13@gmail.com>
 *	Date	:	6th March 2017
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//define number of symbols
#define ALPHABET_SIZE 26

using namespace std;

//vector for storing search results
vector<string> SEARCH_RESULTS;


//Creating the node structure for Trie
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isWord;
} *root = NULL;


//returns new node, initializing everything to NULLs
TrieNode *getNode()
{
    TrieNode *temp = new TrieNode();
    temp -> isWord = false;
    for(int i=0;i<ALPHABET_SIZE;i++)
        temp -> children[i] = NULL;
    return temp;
}


//Function to insert in the trie
void insert(string word)
{
    if(root == NULL)
        root = getNode();

    TrieNode *current = root;

    for(unsigned int i = 0; i < word.length(); i++)   //traverse the trie and insert each character 1 by 1
    {
        word[i] = tolower(word[i]);         //convert everything to lowercase

        if(current -> children[int(word[i]) - 97] == NULL)
        {
            TrieNode *new_node = getNode();
            current -> children[int(word[i]) - 97] = new_node;
            current = new_node;
        }
        else
            current = current -> children[int(word[i]) - 97];
    }
    current -> isWord = true;       //set isWord true if it's a word
}


/*
Function to search for the existence of prefix in the
trie and returning the node containing last word of the
prefix
*/
TrieNode* search(string pre)
{
    if(root==NULL){
        cout << endl << "No elements in the trie" << endl;
        return NULL;
    }
    TrieNode *current = root;
    unsigned int i=0;
    for(i = 0; i < pre.length(); i++)
    {
        pre[i] = tolower(pre[i]);

        if(current -> children[int(pre[i] - 'a')] == NULL)
        {
            break;
        }
        else
            current = current -> children[int(pre[i] - 'a')];
    }
    return current;
}


/*
Now implementing depth first search on the node returned
by search function to find all the words with that prefix
*/
void dfs(string current, TrieNode* node)
{
    if(node == NULL)
        return;
    else if(node -> isWord)
        SEARCH_RESULTS.push_back(current);
    for(int i=0;i<ALPHABET_SIZE;i++){
        dfs(current + char(i + 'a'), node -> children[i]);
    }
}


//Driver
int main()
{
    string prefix;
    ifstream infile;
    infile.open("word_list(1).txt");    // opening the input file
    while(!infile.eof()){
       string k;
       bool wrong_key = false;
       getline(infile,k);
        for(int index = 0; index < k.length(); index++){
            if(int(k[index])< 65 || int(k[index]) > 122){   //check if it contains anything else except alphabets
                wrong_key = true;
                break;
            }
            else if(int(k[index]) > 90 && int(k[index]) < 97){  //check if it contains anything else except alphabets
                wrong_key = true;
                break;
            }
        }
        if(k=="" || wrong_key) continue;   //skip the invalid strings
        insert(k);                    // creating trie, inserting words till end of file
    }
    cout << "Enter word or prefix to search for: " << endl;
    cin >> prefix;
    TrieNode *node = getNode();
    node = search(prefix);
    if(node == NULL)            //if prefix is not in the trie
        cout << "No such word. Sorry!" << endl;
    else
        dfs(prefix, node);           //find all the possible results for the prefix

    // Now printing the search results
    cout << endl << "Your search results are: " << endl;
    for(unsigned int count=0; count < SEARCH_RESULTS.size(); count++)
        cout << SEARCH_RESULTS[count] << endl;
    return 0;
}

/*
 *	Author	:	Manjeet Kumar <kumar.manjeet13@gmail.com>
 *	Date	:	
 */