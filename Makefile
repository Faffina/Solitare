OUT_NAME=solitare
SOURCE_FILE := $(shell find ./source -name "*.c")
OBJ_FILE := $(patsubst ./source/%.c, build/%.o, $(SOURCE_FILE))
DEP_FILE := $(patsubst build/%.o, build/%.d, $(OBJ_FILE))
BUILD_FOLDER := $(sort $(dir $(OBJ_FILE)))

all: make_dir $(OUT_NAME)

$(OUT_NAME): $(OBJ_FILE)
	@printf "linking %-42s" $@
	@clang -lncursesw $^ -o $@
	@printf "done \n"

build/%.o: source/%.c
	@printf "compiling %-40s" $<
	@clang -O3 -march=native -I include -MMD -c $< -o $@
	@printf "done \n"

make_dir:
	mkdir -p $(BUILD_FOLDER)
clear_build:
	rm -rf build/*

-include $(DEP_FILE)

.PHONY: all make_dir clear_build
