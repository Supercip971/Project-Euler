
DIRECTORY_GUARD = mkdir -p $(@D)

CFILES := $(shell find src -type f -name \*.cpp)
HFILES := $(shell find src -type f -name \*.h)
OBJFILES := $(patsubst src/%.cpp, build/%, $(CFILES))
build/%: src/%.cpp $(CFILES) $(HFILES)
	@$(DIRECTORY_GUARD)
	@echo "[ C++] building $< "
	@clang++ -pthread -fpermissive -fsanitize=address -fsanitize=undefined -std=c++20 -m64 -Wall -g -march=x86-64 -I src/ -O3 -msse -o $@ $<

run: $(OBJFILES)
	for file in $^ ; do \
		echo [$${file}] ; \
		$${file} ; \
	done

format: 
	clang-format -i --style=file $(CFILES) $(HFILES)


clean:
	rm $(OBJFILES)

all: $(OBJFILES)
	@make run




