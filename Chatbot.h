#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class Chatbot{
    private:
        string noMatch[5];
        unordered_map<string, vector<string>> dialogue;
        string addToResponse(string userString, string response, string foundWord);
        int getRandomResponse(int numResponse);
        
    public:
        Chatbot();
        void getResponse(string userString, vector<string> responses, string foundWord);
        void addDialogue(string key, vector<string> response);
        unordered_map<string, vector<string>> getDialogue();
        bool searchForResponse(string userQuery);
};