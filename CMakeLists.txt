cmake_minimum_required(VERSION 3.7.0)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

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

include_directories(Experiment Theory Numeric ${ROOT_INCLUDE_DIRS})
# link_directories(/opt/local/libexec/root6/lib/root )


add_executable(mixing 
main.cpp
teubner.f
Experiment/aleph14_vpa.f90
Experiment/num_const.f90
Experiment/Experiment.cpp
Experiment/Experiment.h
Experiment/Aleph.cpp
Experiment/Aleph.h
Numeric/Numeric.h
Numeric/Numeric.cpp
Theory/theory.cpp
Theory/theory.h
Theory/OPE.h
Theory/OPE.cpp
Theory/FCN.h
Theory/FCN.cpp
Theory/Constants.h
)


target_link_libraries(mixing ${ROOT_LIBRARIES})


##############
# Testing
##############
if (test)
   # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/googletest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests
		Test/Test.cpp
		Numeric/Numeric.cpp
		Test/Numeric.cpp
  )		

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  #  target_link_libraries(runUnitTests project1_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(NAME that-test-I-made COMMAND runUnitTests)
  
endif()
