cmake_minimum_required(VERSION 3.7.0)
project(mixing CXX Fortran)

include_directories(Experiment Theory)
link_directories(/opt/local/libexec/root6/lib/root)

add_executable(mixing 
main.cpp
teubner.f
Experiment/experiment.cpp
Experiment/experiment.h
Theory/theory.cpp
Theory/theory.h
)

target_link_libraries(mixing Minuit2)
