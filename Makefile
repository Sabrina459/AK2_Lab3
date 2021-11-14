CXX = g++

RM = del /Q /F

CXXFLAGS = -Wall -Wextra  -c 

lab3: main.o
	$(CXX) $? -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $? -o $@

clean:
	$(RM) *.o lab3.exe