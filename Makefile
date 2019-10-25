EXE = sort
OBJ = main.o SortAlgo.o

all : main clean 
main : ${OBJ}
	@g++ -o ${EXE} ${OBJ}
%.o : %.cpp
	@g++ -c $<
.PHONY: clean
clean:
	@rm -rf ${OBJ}
