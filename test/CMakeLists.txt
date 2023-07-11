# https://github.com/OlivierLDff/cmocka-cmake-example/blob/master/cmake/FetchCMocka.cmake
include(FetchContent)

FetchContent_Declare(
  cmocka
  GIT_REPOSITORY https://git.cryptomilk.org/projects/cmocka.git
  GIT_TAG        cmocka-1.1.5
  GIT_SHALLOW    1
)

set(WITH_STATIC_LIB ON CACHE BOOL "CMocka: Build with a static library" FORCE)
set(WITH_CMOCKERY_SUPPORT OFF CACHE BOOL "CMocka: Install a cmockery header" FORCE)
set(WITH_EXAMPLES OFF CACHE BOOL "CMocka: Build examples" FORCE)
set(UNIT_TESTING OFF CACHE BOOL "CMocka: Build with unit testing" FORCE)
set(PICKY_DEVELOPER OFF CACHE BOOL "CMocka: Build with picky developer flags" FORCE)

FetchContent_MakeAvailable(cmocka)

include_directories ("${PROJECT_SOURCE_DIR}")

file(GLOB files "*.c")

foreach(file ${files})
get_filename_component(exec_name ${file} NAME_WE)
  add_executable(${exec_name} ${file})
  target_link_libraries(${exec_name} short cmocka)
  add_test (NAME ${exec_name} COMMAND $<TARGET_FILE:${exec_name}>)
endforeach()