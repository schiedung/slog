CXXFLAGS = -std=c++17

all: example_debug example_release

example_debug: example.cpp slog.h
	$(CXX) $(CXXFLAGS) example.cpp -Ofast -o example_debug

example_release: example.cpp slog.h
	$(CXX) $(CXXFLAGS) -DNLOG_DEBUG example.cpp -Ofast -o example_release

check:
	./benchmark.sh

clean:
	rm -f example_debug
	rm -f example_release
