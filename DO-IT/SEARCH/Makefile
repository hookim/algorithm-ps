final: main
	./a.out < test.txt
main: file_test
	g++ --std=c++20 break_wall.cpp
file_test: file
	./a.out test.txt
file: 
	g++ test_case.cpp