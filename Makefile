CC = g++
BUILD = build
EXECUTABLE = arrayimplementation.exe

export

clean:
	- rm $(BUILD)/$(EXECUTABLE)

all: clean
	+$(MAKE) all -C src
