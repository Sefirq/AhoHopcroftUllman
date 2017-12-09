project(DataStructuresAndAlgorithms)

set(HEADER_FILES ArrayList.h LinkedList.h Stack.h CursorList.h Record.h CursorSpace.h
        DoubleConnectedList.h DoubleRecord.h)

set(SOURCE_FILES ArrayList.cpp LinkedList.cpp Stack.cpp CursorList.cpp Record.cpp CursorSpace.cpp
        DoubleConnectedList.cpp DoubleRecord.cpp)

add_library(DataStructuresAndAlgorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})