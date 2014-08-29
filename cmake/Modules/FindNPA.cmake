# find our libnpa
# when successful, defines:
# - NPA_LIBRARY
# - NPA_FOUND
# - NPA_INCLUDE_DIR
# - NPA_LIBRARY_DIR

# define the list of search paths for headers and libraries
set(FIND_NPA_PATHS
    ${NPA_ROOT}
    $ENV{NPA_ROOT}
    /usr/local
    /usr
    /opt/local
    /opt
    ${CMAKE_SOURCE_DIR}/../libnpa # for krofna's build setup
)

# find include directory
find_path(NPA_INCLUDE_DIR npaversion.hpp
    PATH_SUFFIXES include include/libnpa
    PATHS ${FIND_NPA_PATHS}
)

# TODO: check version number

# find library
find_library(NPA_LIBRARY
    NAMES npa
    PATH_SUFFIXES lib64 lib
    PATHS ${FIND_NPA_PATHS}
)

# set result
if (NPA_LIBRARY)
    set(NPA_FOUND TRUE)
    # directory
    get_filename_component(_dir "${NPA_LIBRARY}" PATH)
    set(NPA_LIBRARY_DIR "${_dir}" CACHE PATH "NPA library directory" FORCE)
else()
    set(NPA_FOUND FALSE)
endif()

# errors
if(NOT NPA_FOUND)
    set(FIND_NPA_ERROR "Could NOT find NPA")
endif()
if (NOT NPA_FOUND)
    if(NPA_FIND_REQUIRED)
        message(FATAL_ERROR ${FIND_NPA_ERROR})
    elseif(NOT NPA_FIND_QUIETLY)
        message("${FIND_NPA_ERROR}")
    endif()
endif()

# success
if(NPA_FOUND)
    message(STATUS "Found NPA in ${NPA_INCLUDE_DIR}")
endif()
