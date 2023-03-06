# load and build cpputest/cppumock library.
include(cpputest_external_proj.cmake)
# add the path to the external libraries
# link_directories(../lib/build)
# find_library(COMMON_LIB libcommon.a PATHS ../lib/build)

# # check if the library was found
# if (NOT COMMON_LIB)
#     message(FATAL_ERROR "Could not find common library")
# endif()

# build the unit test(s).
add_subdirectory(Parser)