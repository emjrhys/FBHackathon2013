COMPILER = g++
COMPILER_FLAGS = -c -g -O0 -Wall -Werror
LINKER = g++

runGame : main.o gamemanager.o board.o computerplayer.o
	$(LINKER) main.o gamemanager.o board.o computerplayer.o -o runGame

main.o : main.cpp gamemanager.h board.h computerplayer.h
	$(COMPILER) $(COMPILER_FLAGS) main.cpp

gamemanager.o : gamemanager.cpp gamemanager.h board.h computerplayer.h
	$(COMPILER) $(COMPILER_FLAGS) gamemanager.cpp

computerplayer.o : computerplayer.cpp computerplayer.h board.h
	$(COMPILER) $(COMPILER_FLAGS) computerplayer.cpp

board.o : board.cpp board.h
	$(COMPILER) $(COMPILER_FLAGS) board.cpp

clean :
	-rm -f *.o runGame
