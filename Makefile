OBJECTS = main.cc

run: build
	./dataframe

build:
	clang++ $(OBJECTS) -o dataframe -std=c++11 -O2
