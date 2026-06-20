# ====================================================================
# COMPILER AND OPTIMIZATION CORES
# ====================================================================
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17

# ====================================================================
# EXCLUSION MATRIX
# ====================================================================
# We isolate these files so the engine doesn't build lone, broken binaries out of them.
EXCLUDE_SRCS = L.cpp static.cpp stat.cpp helloworld.cpp

# ====================================================================
# DYNAMIC WILDCARD ENGINE
# ====================================================================
ALL_SRCS = $(wildcard *.cpp)
STANDALONE_SRCS = $(filter-out $(EXCLUDE_SRCS), $(ALL_SRCS))
STANDALONE_BINS = $(STANDALONE_SRCS:.cpp=.out)

# ====================================================================
# MAIN TARGET PIPELINES
# ====================================================================
all: helloworld.out static_project.out $(STANDALONE_BINS)

# Pipeline A: Automatically links L.cpp with helloworld.cpp without modifying code
helloworld.out: helloworld.cpp L.cpp
	@echo "Linking Combined Target [helloworld.cpp + L.cpp] -> $@"
	@$(CXX) $(CXXFLAGS) helloworld.cpp L.cpp -o helloworld.out

# Pipeline B: Links your static variable multi-file assignment
static_project.out: static.cpp stat.cpp
	@echo "Linking Multi-File Assignment [static.cpp + stat.cpp] -> $@"
	@$(CXX) $(CXXFLAGS) static.cpp stat.cpp -o static_project.out

# Pipeline C: Compiles all other independent modules
%.out: %.cpp
	@echo "Compiling Standalone Module: $< -> $@"
	@$(CXX) $(CXXFLAGS) $< -o $@

# ====================================================================
# SYSTEM CLEAN SWEEP
# ====================================================================
clean:
	@rm -f *.out
	@echo "All Linux binary blocks scrubbed successfully."