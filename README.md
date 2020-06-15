# Simple Chatbot Project

## Introduction
This project simulates a text-based chatbot utilizing natural language processing pulling from a "database" of keywords and appropriate responses. This particular chatbot behaves similarly to a psychtherapist. The program asks a question, the user enters an answer to that question and then the process will repeat until the user says "bye". 

## Guidelines
The "-" character displays as a prompt whenever the user is entering dialogue to remind the user to enter that input. Each time the program reads a line of input from the user, it will search the input from certain keywords and if a match is found, it will display that particular response. If there are multiple responses, one will be chosen randomly. The bot always responds to the first matching keyword even if there are multiple in the user's input. The keywords and response pairs that the program pulls from are read in from a separate input file at the start of the program. 

Example Conversation:

What's on your mind?
- I'm depressed.

I'm sorry to hear you are depressed.
-My boyfriend is mad at me.
...
That is quite interesting.
- I've got to run. Bye.

To find a response for a user's input, the input is first parsed for cleaning like removing uneccessary punctuation and making all letters lowercase. 
