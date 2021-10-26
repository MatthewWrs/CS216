# Author: Matthew Wirasakti
# Section: 002
EXEC = Project2
HEADERS = card.h deck.h SortedLinkedList.h rank.h pokerhand.h
#(listing all header files here, separated by space)
OBJECTS = card.o deck.o SortedLinkedList.o rank.o pokerhand.o PA2.o
#(listing all of your object files here, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
clean:
	rm -i *.o $(EXEC)