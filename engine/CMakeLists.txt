set(SOURCE_FILES
    run.cpp
    utils.h
    utils.cpp
    component/Asset.h
    component/Asset.cpp
    system/Physics.h
    system/Physics.cpp
    entity/snake.h
    entity/snake.cpp
    entity/apple.h
    entity/apple.cpp
    component/cBoundingBox.h
    component/cBoundingBox.cpp
    component/cDirection.h
    component/WindowGrid.h

)
add_library(snake-engine ${SOURCE_FILES})
