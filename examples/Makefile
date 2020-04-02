CXXFLAGS = -std=c++17 -Ofast
INCLUDES = -I../include

all: debug release

debug: example.cpp
	$(CXX) example.cpp -o debug $(CXXFLAGS) $(INCLUDES)

release: example.cpp
	$(CXX) example.cpp -o release -DNLOG_DEBUG $(CXXFLAGS) $(INCLUDES)

clean:
	rm -f debug
	rm -f release
