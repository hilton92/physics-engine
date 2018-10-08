cmake_minimum_required(VERSION 3.4)

project(Physics-engine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED 1)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

IF (NOT TARGET gtest)
    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio.
    # You don't need to modify this.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    #The following call is location of the googletest directory
    #make sure there is a "libs" directory and that the git submodule
    #call has been made for googletest
    #From the libs directory: 
    #git submodule add "Clone path to googletest on GitHub" 
    add_subdirectory(libs/googletest)
ENDIF()

add_library(${PROJECT_NAME} STATIC
	#Add your library source and header files here.
	physicsEngine.cpp
	physicsEngine.h
    	)

set(TEST_NAME ${PROJECT_NAME}_UnitTest)

add_executable(${TEST_NAME}
	#Add your unit test source file here
	unitTest.cpp
        )

target_link_libraries(${TEST_NAME} gtest gtest_main ${PROJECT_NAME})
