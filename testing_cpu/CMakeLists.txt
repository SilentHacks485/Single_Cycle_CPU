cmake_minimum_required(VERSION 3.25)
project(testing_cpu)

set(CMAKE_CXX_STANDARD 11)

add_executable(testing_cpu main.cpp pc.cpp pc.h instr_mem.cpp instr_mem.h control.cpp control.h alu.cpp alu.h mux.cpp mux.h reg.cpp reg.h data_mem.cpp data_mem.h signExtend.cpp signExtend.h)
