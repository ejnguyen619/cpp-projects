run: test
	./test

StudentData.o: StudentData.cpp StudentData.hpp
	g++ -c -o $@ $<

StudentRoster.o: StudentRoster.cpp StudentRoster.hpp
	g++ -c -o $@ $<

options.o: options.cpp options.hpp
	g++ -c -o $@ $<

test.o: main.cpp StudentData.hpp StudentRoster.hpp options.hpp
	g++ -c -o $@ $<

test: test.o StudentData.o StudentRoster.o options.o
	g++ -std=c++14 -o test test.o StudentData.o StudentRoster.o options.o -lstdc++fs

clean:
	rm *.o test
