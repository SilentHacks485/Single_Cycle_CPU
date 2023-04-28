cmake_minimum_required(VERSION 3.25)
project(SingleCycleCpu)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(SingleCycle pc.cpp pc.h instr_mem.cpp instr_mem.h control.cpp control.h alu.cpp alu.h mux.cpp mux.h reg.cpp reg.h data_mem.cpp data_mem.h signExtend.cpp signExtend.h main.cpp)
