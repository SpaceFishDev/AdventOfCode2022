exec = d1.exe
src = $(wildcard src/*.cpp)

objects = $(src: .c=.o)
flags = -ggdb3

$(exec): $(objects) $(src_cs)
	g++ $(objects) $(flags) -o $(exec)
%.o: %.c src/include/%.h
	g++ -c $(flags) $< -o $@



