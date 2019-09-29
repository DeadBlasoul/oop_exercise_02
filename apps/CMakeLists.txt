project(oop-exercise-02)

set(App_TARGET_NAME oop_exercise_02)

add_executable(${App_TARGET_NAME} main.cpp)

include_directories(${Lab_INCLUDE_DIRS})
target_link_libraries(${App_TARGET_NAME} Lab)

install(TARGETS ${App_TARGET_NAME} DESTINATION ${PROJECT_SOURCE_DIR}/bin)

set_target_properties(${App_TARGET_NAME} PROPERTIES
    FOLDER apps
)