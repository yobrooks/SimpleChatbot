#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Chatbot.h"
using namespace std;

extern Chatbot myChat;

void myToLower(string &myWord){
    string::iterator it = myWord.begin();

    while(it!=myWord.end()){
        //if the character at the iterator is not a letter or an apostrophe, set the iterator to where it points after being erased
        if(!isalpha(*it) && (*it)!='\'' && (*it)!=' '){
            it = myWord.erase(it);
        }
        else if(isalpha(*it)){
            //if the character is a letter, change it to lowercase and increment the iterator
            *it = tolower(*it);
            it++;
        }
        else{
            it++;
        }
    }
}

/* Load the key-response pairs into an unordered map */
void loadResponses(){
    ifstream in("chart.txt");
    string line;
    vector<string> responses, keys;
    if(!in){
        cout << "Unable to open file." << endl;
    }
    else{
        while(getline(in, line))
        {
            char fc = line.at(0);
            switch(fc){
                case '#':
                    keys.push_back(line.substr(1));
                    break;            
                case '$':
                    for(int i = 0; i < keys.size(); i++){
                        myChat.addDialogue(keys[i], responses);
                    }
                    keys.clear();
                    responses.clear();
                //add all the key value pairs
                //clear the vectors
                    break;
                default:
                    responses.push_back(line);
                    break;
            }
        }
    }
}

/* Have a conversation with human */
void runChat(){
    //Preliminary setup
    string response = "";
    cout << "Hello. What is your name?" << endl;
    cout << "- ";
    std::getline(std::cin, response);
    cout << "Ok " << response << ". What can I do for you?" << endl;
    response = "";
    //Loop to get answers from human
    //have to process the response each time
    bool keepChat = true;
    while(keepChat){
        cout << "- ";
        std::getline(std::cin, response);
        keepChat = myChat.searchForResponse(response);
    }
}
