MAKEFLAGS += --silent
.PHONY: clean compile init run
run: compile
	build/snake

compile:
	cmake --build build

clean:
	rm -rf build

init:
	mkdir -p build && cmake -S . -B build
