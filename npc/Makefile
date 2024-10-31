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
	      -I/usr/include/SDL2 


#-lasan(内存检查)
GCC_LIB += $(NPC_HOME)/libnemu.so
GCC_LDFLAGS := $(addprefix -LDFLAGS ,${GCC_LIB})
GCC_CFLAGS :=  $(addprefix -CFLAGS ,${GCC_INC_PATH})
GCC_FLAGS := ${GCC_CFLAGS} ${GCC_LDFLAGS}

# run info:
OBJ_DIR := ./obj_dir
BIN := ${OBJ_DIR}/Vtop

com:${CSRC} ${VSRC}
	@verilator ${VERILATOR_FLAGS} ${CSRC} ${VSRC} ${GCC_FLAGS} 

all: default
	@echo "Write this Makefile by your self."

run: com
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
# 运行 bin文件,传入 img 参数, difftest 文件参数
	${BIN} $(NPC_HOME)/libnemu.so
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

clean:
	$(RM) ./obj_dir/*
	rm -rf $(BUILD_DIR)

include ./../Makefile
