project(MyLib_lib)

set(HEADER_FILES
        mylib.h
        )

set(SOURCE_FILES
        mylib.cpp)

add_library(MyLib_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})