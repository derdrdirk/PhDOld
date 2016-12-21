cmake_minimum_required(VERSION 3.7.0)
project(mixing CXX Fortran)

include_directories(Experiment)

add_executable(mixing 
main.cpp
teubner.f
Experiment/experiment.cpp
Experiment/experiment.h
)
