include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests testTest.cpp listTests.cpp linkedListTests.cpp cursorListTests.cpp
        bidirectionalListTests.cpp)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests DataStructuresAndAlgorithms)