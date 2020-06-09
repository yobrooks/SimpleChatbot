#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <unordered_map>
#include "prototypes.h"
#include "Chatbot.h"

using namespace std;

Chatbot::Chatbot()
{
    //is this legal???
    noMatch[0] = "What does that suggest to you?";
    noMatch[1] = "I see.";
    noMatch[2] = "I'm not sure I understand you fully.";
    noMatch[3] = "Can you elaborate?";
    noMatch[4] = "That is quite interesting.";
}

/* Private Functions */

//returns integer to index where the random reponse should come from
int Chatbot::getRandomResponse(int numResponse){
    srand((unsigned) time(0));
    int rNum = (rand() % numResponse) + 1;
    return (rNum - 1);
}

//returns the new string after replacing asterik with user input
string Chatbot::addToResponse(string userString, string response, string foundWord){
    //find if there is asterik--> if not return regular string
    
    string newResponse = response;
    string newUser = userString;
   
    if(!foundWord.empty()){
        size_t pos = userString.find(foundWord) + foundWord.length() +1;
        if(pos > userString.length()){
            newUser = userString.substr(userString.find(foundWord));
        }else{
            newUser = userString.substr(userString.find(foundWord)+ foundWord.length() + 1);
        }
    }

    if(!isalpha(newUser.at(0))){
        newUser.erase(0);
    }

    if(!isalpha(newUser.back())){
        newUser.erase(newUser.back());
    }

    size_t astPos = newResponse.find('*');

    if(astPos != string::npos){
        newResponse.replace(astPos, 1, newUser);
    }

    return newResponse;
}



/* Public Functions */

//after keyword is found, this prints out the chatbot's response
void Chatbot::getResponse(string userString, vector<string> responses, string foundWord){
    int num = responses.size();
    switch(num){
        case 0:
            {            
                int choice = getRandomResponse(5);
                cout << addToResponse(userString, noMatch[choice], foundWord) << endl;
            }
            break;
        case 1:
            cout << addToResponse(userString, responses[0], foundWord) << endl;
            break;
        default:
            {
                int choice = getRandomResponse(num);
                cout << addToResponse(userString, responses[choice], foundWord) << endl;
            }
            break;
    }
    //if there is only one possible response --> add response and print it out
    //if there are more than one --> generate random response, add response and print it out
    //if the vector is empty, then generate from private vector
}

void Chatbot::addDialogue(string key, vector<string> response){
    dialogue.insert({key, response});
}

unordered_map<string, vector<string>> Chatbot::getDialogue(){
    return dialogue;
}

bool Chatbot::searchForResponse(string userQuery){
    bool check = true; bool found = false;
    myToLower(userQuery);
    //if bye is found in the string, return false so chat can end
    if(userQuery.find("bye") != string::npos){
        check = false;
    }
    else{
        istringstream iss(userQuery);
        vector<string> str{istream_iterator<string>(iss), {}};
        for(int i = 0; i < str.size(); i++){
            string curr = str[i];
            //if the current string is an i, add the next string to it for searching
            if(curr == "i"){
                curr = curr + " " + str[i+1]; //NOT WORKING
            }
            unordered_map<string, vector<string>>::iterator it = dialogue.find(curr);
            //if the current key is found
            if(it!=dialogue.end()){
               // size_t pos = userQuery.find(curr) + curr.length() + 1; 
                getResponse(userQuery, it->second, curr);
                found = true;
                break;
            }
        }
        //if the end of the string is reached and nothing has been found
        if(!found){
            vector<string> temp; string strT="";
            getResponse(userQuery, temp, strT);
        }
    }
    return check;
}


