# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	doctest.h
)


set(SOURCE_FILES
	tests.cpp
)

set(LIBRARY_NAME snake-engine)

add_executable(tests ${SOURCE_FILES})
target_link_libraries(tests ${LIBRARY_NAME})
