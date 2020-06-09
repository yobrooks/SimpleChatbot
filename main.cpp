#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include "Chatbot.h"
#include "prototypes.h"
using namespace std;

/* Global Variables*/
Chatbot myChat;

int main(){
    loadResponses(); //THIS WORKS
    runChat();
}
