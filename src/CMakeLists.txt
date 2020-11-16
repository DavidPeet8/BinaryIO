
add_subdirectory(transforms)

# add an executable target, tells cmake to make a make file that will product this
add_executable(
  "${PROJECT_NAME}"
  main.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC "include")

target_link_libraries(${PROJECT_NAME} PRIVATE transforms)
