project(DataStructuresAndAlgorithms)

set(HEADER_FILES
        ArrayList.h
        )

set(SOURCE_FILES
        ArrayList.cpp
        )

add_library(DataStructuresAndAlgorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})