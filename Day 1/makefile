exec = 1.exe
src = $(wildcard src/*.c)

objects = $(src: .c=.o)
flags = 

$(exec): $(objects) $(src_cs)
	gcc $(objects) $(flags) -o $(exec)
%.o: %.c src/include/%.h
	gcc -c $(flags) $< -o $@



