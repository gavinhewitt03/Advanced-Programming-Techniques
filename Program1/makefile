program1 : program1.cc
	g++ -Wall -std=c++17 program1.cc -o program1

checkit : checkit.cc
	g++ -Wall -std=c++17 checkit.cc -o checkit

test1 : program1 checkit test1-input.txt correct-test1.txt
	./program1 < test1-input.txt > student-test1.txt
	./checkit 0

test2 : program1 checkit test2-input.txt correct-test2.txt
	./program1 < test2-input.txt > student-test2.txt
	./checkit 1

test3 : program1 checkit test3-input.txt correct-test3.txt
	./program1 < test3-input.txt > student-test3.txt
	./checkit 2

clean :
	rm student* checkit program1
