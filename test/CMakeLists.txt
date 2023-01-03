include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(test_login module/api/login.cpp ${PROJECT_SOURCE_DIR}/src/module/api/login.cpp)
target_link_libraries(test_login
        PRIVATE
        GTest::GTest)
target_include_directories(test_login
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src/module)
# tests to run
add_test(test_login test_login)