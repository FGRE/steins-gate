
# this function returns the git hash of the current checkout, if the 'git'
# command is available, it is a git checkout and it is not a tagged release.
function(get_git_revision _hashvar)
    # got git?
    if(NOT GIT_FOUND)
        find_package(Git QUIET)
    endif()
    if(GIT_FOUND)
        # TODO: look for source directory (for out-of-source builds)?

        # check, if we have a tagged release
        execute_process(COMMAND ${GIT_EXECUTABLE} describe --tags --exact-match
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
            RESULT_VARIABLE EXIT_CODE
            OUTPUT_QUIET
            ERROR_QUIET
        )
        # it failed => not a tagged revision
        if(NOT ${EXIT_CODE} EQUAL 0)
            execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short=10 HEAD
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                RESULT_VARIABLE EXIT_CODE
                OUTPUT_VARIABLE GIT_REV
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE
            )
            if(${EXIT_CODE} EQUAL 0)
                # all good, set hash
                set(${_hashvar} "${GIT_REV}" PARENT_SCOPE)
                return()
            endif()
        endif()
    endif()
    # no git available or any other error above, set to empty string
    set(${_hashvar} "" PARENT_SCOPE)
endfunction()
