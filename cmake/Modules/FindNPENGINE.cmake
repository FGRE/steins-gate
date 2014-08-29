# find our libnpengine
# when successful, defines:
# - NPENGINE_LIBRARY
# - NPENGINE_FOUND
# - NPENGINE_INCLUDE_DIR
# - NPENGINE_LIBRARY_DIR

# define the list of search paths for headers and libraries
set(FIND_NPENGINE_PATHS
    ${NPENGINE_ROOT}
    $ENV{NPENGINE_ROOT}
    /usr/local
    /usr
    /opt/local
    /opt
    ${CMAKE_SOURCE_DIR}/../libnpengine # for krofna's build setup
)

# find include directory
find_path(NPENGINE_INCLUDE_DIR npengineversion.hpp
    PATH_SUFFIXES include include/libnpengine
    PATHS ${FIND_NPENGINE_PATHS}
)

# TODO: check version number

# find library
find_library(NPENGINE_LIBRARY
    NAMES npengine
    PATH_SUFFIXES lib64 lib
    PATHS ${FIND_NPENGINE_PATHS}
)

# set result
if (NPENGINE_LIBRARY)
    set(NPENGINE_FOUND TRUE)
    # directory
    get_filename_component(_dir "${NPENGINE_LIBRARY}" PATH)
    set(NPENGINE_LIBRARY_DIR "${_dir}" CACHE PATH "NPENGINE library directory" FORCE)
else()
    set(NPENGINE_FOUND FALSE)
endif()

# errors
if(NOT NPENGINE_FOUND)
    set(FIND_NPENGINE_ERROR "Could NOT find NPENGINE")
endif()
if (NOT NPENGINE_FOUND)
    if(NPENGINE_FIND_REQUIRED)
        message(FATAL_ERROR ${FIND_NPENGINE_ERROR})
    elseif(NOT NPENGINE_FIND_QUIETLY)
        message("${FIND_NPENGINE_ERROR}")
    endif()
endif()

# success
if(NPENGINE_FOUND)
    message(STATUS "Found NPENGINE in ${NPENGINE_INCLUDE_DIR}")
endif()
