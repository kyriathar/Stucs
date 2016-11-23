OBJ_FILES = main.o StudentEntry.o StudentEntryList.o HashTable.o SkipList.o Stucs.o DoubleLinkedList.o
CC = g++
FLAGS = -c -g
OUT = exe

all : $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(OUT)

main.o : main.cpp
	$(CC) $(FLAGS) main.cpp

StudentEntry.o : StudentEntry.cpp
	$(CC) $(FLAGS) StudentEntry.cpp

StudentEntryList.o : StudentEntryList.cpp
	$(CC) $(FLAGS) StudentEntryList.cpp

HashTable.o : HashTable.cpp
	$(CC) $(FLAGS) HashTable.cpp

SkipList.o : SkipList.cpp
	$(CC) $(FLAGS) SkipList.cpp

Stucs.o : Stucs.cpp
	$(CC) $(FLAGS) Stucs.cpp

DoubleLinkedList.o : DoubleLinkedList.cpp
	$(CC) $(FLAGS) DoubleLinkedList.cpp

clean :
	rm -rf $(OBJ_FILES) $(OUT)

test :
	$(CC) test.cpp
