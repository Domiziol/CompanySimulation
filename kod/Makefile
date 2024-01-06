CXX = g++ 
CXXFLAGS = -Wall -I. -g
OBJS = pracownik.o firma.o gra.o kredyt.o main.o 
DEPS = pracownik.hpp firma.hpp gra.hpp kredyt.hpp

%.o: %.cpp $(DEPS)
	$(CXX) -c $^ $(CXXFLAGS)

all: $(OBJS)
	$(CXX) -o $@ $(OBJS)

.PHONY: clean

clean: 
	rm -f $(OBJS) *.o