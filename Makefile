CXXFLAGS = -std=c++17
INCLUDES = -Iinclude

all: example_debug example_release

example_debug: example.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) example.cpp -Ofast -o example_debug

example_release: example.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -DNLOG_DEBUG example.cpp -Ofast -o example_release

check:
	./benchmark.sh

clean:
	rm -f example_debug
	rm -f example_release
