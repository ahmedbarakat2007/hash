# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Target Executable
TARGET = hash

# Source and Object Files
SRCS = src/main.cpp src/exec.cpp src/colors.cpp src/dir.cpp src/shell.cpp src/ls.cpp
OBJS = $(SRCS:.cpp=.o)

# Default Target
all: $(TARGET)

# Build the Executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build Files
clean:
	rm -f $(OBJS) $(TARGET)

# Run the Program
run: $(TARGET)
	./$(TARGET)
