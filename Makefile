fname=main.cpp
c: 
	clang++ "$(fname)" -o a.out -std=c++17 -g -Wall -fsanitize=address -I/usr/local/include -L/usr/local/lib -lfmt
cg:
	g++-10 "$(fname)" -o a.out -std=c++17 -g -Wall -fsanitize=address -I/usr/local/include -L/usr/local/lib -lfmt
r:
	./a.out
