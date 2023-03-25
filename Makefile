all: clean main.exe
main.exe:
	g++ -g -o main.exe main.cc
clean:
	rm -f *.exe 