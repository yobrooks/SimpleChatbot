CXX = g++
CFLAGS = -std=c++11
HEADERS = Chatbot.h prototypes.h
OBJS = words.o Chatbot.o

all: main

main : main.o $(OBJS)
	$(CXX) $(CFLAGS) -o main main.o $(OBJS)

main.o : main.cpp $(HEADERS)
	$(CXX) $(CFLAGS) main.cpp -c

words.o : words.cpp $(HEADERS)
	$(CXX) $(CFLAGS)  words.cpp -c

Chatbot.o : Chatbot.cpp $(HEADERS)
	$(CXX) $(CFLAGS)  Chatbot.cpp -c


pristine:
	rm *.o
	rm main
	touch *
