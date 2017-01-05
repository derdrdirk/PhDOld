cmake_minimum_required(VERSION 3.7.0)

# Force Clang++
set(CMAKE_CXX_COMPILER "clang++")

project(mixing CXX Fortran)




# SET UP ROOT https://root.cern.ch/how/integrate-root-my-project-cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /opt/local/libexec/root6/etc/root/cmake)
find_package(ROOT REQUIRED COMPONENTS MATH MINUIT2)
# include(${ROOT_USE_FILE})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++1y -m64")

MESSAGE( STATUS "ROOT_USE_FILE" ${ROOT_USE_FILE} )
MESSAGE( STATUS "ROOT_INCLUDE_DIRS" ${ROOT_INCLUDE_DIRS} )
MESSAGE( STATUS "ROOT_LIBRARIES" ${ROOT_LIBRARIES} )
MESSAGE( STATUS "ROOT_CXX_FLAGS" ${ROOT_CXX_FLAGS} ) # -pthread -stdlib=libc++ -std=c++1y -m64

include_directories(Experiment Theory ${ROOT_INCLUDE_DIRS})
# link_directories(/opt/local/libexec/root6/lib/root)


add_executable(mixing 
main.cpp
teubner.f
Experiment/experiment.cpp
Experiment/experiment.h
Theory/theory.cpp
Theory/theory.h
)

target_link_libraries(mixing ${ROOT_LIBRARIES})
