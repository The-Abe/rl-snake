.PHONY: build all run
all: build

build:
	cmake --build build

run: build
	build/snake
