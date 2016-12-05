#Assignment2 makefile
CC = g++
#	-g adds debugging information to executable
#	-Wall shows most warnings
CFLAGS = -Wall
VFLAG = -std=c++11
TARGET = finalproject.out
INCLUDES = -I libraries
SRC = src
BUILD = build
SOURCES = $(wildcard $(SRC)/*.cpp)
#Objects will just be all the sources files
OBJECTS = $(addprefix $(BUILD)/, $(notdir $(SOURCES:%.cpp=%.o)))

default: $(BUILD) $(TARGET)

debug: CFLAGS += -g
debug: default

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(VFLAG) $(INCLUDES) -o $@ -c $^

$(BUILD): |
	mkdir -p $@

phony:
	echo $(SOURCES)

clean:
	$(RM) $(TARGET) $(BUILD)/*

