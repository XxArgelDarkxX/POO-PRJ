COMPILER=g++
FLAGS=-Wall -std=c++17
INCLUDES=-I include
MAIN=main.cpp
SRC=src/**/*.cpp
BUILD=build

setup:
	mkdir -p build

compile:
	$(COMPILER) $(FLAGS) $(INCLUDES) $(MAIN) $(SRC) -o $(BUILD)/main

.PHONY: setup compile 
run:
	$(BUILD)/main


all: setup compile run

