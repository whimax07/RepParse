cmake_minimum_required(VERSION 3.22)
project(RepParseRunnable)

set(CMAKE_CXX_STANDARD 20)



# ==============================================================================
# ===== Google stuff. ==========================================================
# This grabs GTest stuff.
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
        )
FetchContent_MakeAvailable(googletest)
# I think commenting this out will disable tests.
enable_testing()
# ----- End of a Google section. -----------------------------------------------



# This should ask the CMakeList.txt in the lib dir to compile its contents.
add_subdirectory(lib)

# This builds the tests.
add_executable(RepParseRunnable
        tests/BasicTokenizerTests.cpp
        tests/TestAstEval.cpp
        tests/TokenTests.cpp
        )


# This links everything together. RepParseLib is set to static in its CMake.
target_link_libraries(
        RepParseRunnable
        GTest::gtest_main
        RepParseLib
        )

# I am not 100% sure this is correct as I don't know when PROJECT_SOURCE_DIR is
# populated... or what it would be.
target_include_directories(RepParseRunnable PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib"
        )


# A way to run code without having to go through a GTest.
add_executable(Main
        tests/NonCTestMain.cpp
        )

# Link the executable with the lib.
target_link_libraries(
        Main
        RepParseLib
)

target_include_directories(Main PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib"
        )


# ==============================================================================
# ===== Google stuff. ==========================================================
# The google has just kind of worked.
include(GoogleTest)
gtest_discover_tests(RepParseRunnable)
# ----- End of a Google section. -----------------------------------------------
