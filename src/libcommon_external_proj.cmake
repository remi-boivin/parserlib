# include libcommon common settings.
include(libcommon_common.cmake)

# build CppUTest and CppUMock libraries.
include(ExternalProject)
ExternalProject_Add(libcommon
    GIT_REPOSITORY https://github.com/remi-boivin/libcommon.git
    GIT_TAG 1.0.0
    INSTALL_DIR ${EXTERNAL_INSTALL_LOCATION}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_BUILD_TOOL=gcc -DCMAKE_BUILD_TYPE=Release
)

# add the installed libcommon and cppumock include directories to those the
# compiler uses to search for include files.
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)

# adds the paths of installed libcommon and cppumock libraries in which the linker
# should search for libraries.
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

