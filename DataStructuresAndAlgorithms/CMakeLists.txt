project(DataStructuresAndAlgorithms)

set(HEADER_FILES ArrayList.h LinkedList.h)

set(SOURCE_FILES ArrayList.cpp LinkedList.cpp)

add_library(DataStructuresAndAlgorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})