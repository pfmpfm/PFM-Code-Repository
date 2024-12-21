TOP_MODULE := top

# src
NPC_HOME := $(shell pwd)
VSRC = $(shell find $(abspath ./vsrc) -name "*.v")
CSRC = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")


# verilator flags: 
VERILATOR_INC_PATH += -I$(NPC_HOME)/vsrc -I$(NPC_HOME)/csrc
VERILATOR_FLAGS +=  -O3 -noassert --x-assign fast --x-initial fast -j 2
VERILATOR_FLAGS +=  -cc --exe  --build  --clk clk  
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += ${VERILATOR_INC_PATH}
VERILATOR_FLAGS += --top ${TOP_MODULE} --prefix Vtop -Wno-DECLFILENAME


# gcc flags 
GCC_INC_PATH =-I$(NPC_HOME)/csrc  \
	      -I/usr/include/SDL2 \


#-lasan(内存检查)
GCC_LIB += $(NPC_HOME)/libnemu.so \
			 -lSDL2 \ 
GCC_LDFLAGS := $(addprefix -LDFLAGS ,${GCC_LIB})
GCC_CFLAGS :=  $(addprefix -CFLAGS ,${GCC_INC_PATH})
GCC_FLAGS := ${GCC_CFLAGS} ${GCC_LDFLAGS}

# run info:
OBJ_DIR := ./obj_dir
BIN := ${OBJ_DIR}/Vtop
BIN_FILES := $(shell find ./win_test -type f -name "*.bin")#  批处理-遍历目录下的所有 bin 文件

com:${CSRC} ${VSRC}
	@verilator ${VERILATOR_FLAGS} ${CSRC} ${VSRC} ${GCC_FLAGS} 
 
all: default
	@echo "Write this Makefile by your self."

#run: com
#	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
#	@set -e; \
	for bin_file in $(BIN_FILES); do \
	    echo "Running with $$bin_file"; \
	    ${BIN} $(NPC_HOME)/libnemu.so $$bin_file || { \
	        echo "Error occurred with $$bin_file. Exiting."; \
	        exit 1; \
	    }; \
	done

run: com
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	${BIN} $(NPC_HOME)/libnemu.so
	
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

yosys_t:
	cat ./yosys/yosys.txt | yosys
	
clean:
	$(RM) ./obj_dir/*
	rm -rf $(BUILD_DIR)

include ./../Makefile