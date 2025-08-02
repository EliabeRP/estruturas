CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
TARGET = test_queue
OBJS = test_queue.cpp queue_s.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(TARGET)

clean:
	del /Q *.exe $(TARGET) 2>nul || exit 0

run: $(TARGET)
	$(TARGET)
