macro (create_test target)
  add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro (create_test)

include_directories ("${PROJECT_SOURCE_DIR}")

file(GLOB files "*.c")

set(i 0)
foreach(file ${files})
  add_executable(test_${i} ${file})
  add_dependencies(test_${i} test_${i})
  target_link_libraries(test_${i} slist state hashlist cmocka)
  create_test(test_${i})
  math(EXPR i "${i} + 1")
endforeach()