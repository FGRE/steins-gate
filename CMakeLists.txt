cmake_minimum_required(VERSION 2.8)

# add modules
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

# set version
set(VERSION_MAJOR "0")
set(VERSION_MINOR "5")
set(VERSION_PATCH "3")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# append git revision if available
include(get-git-revision)
get_git_revision(VERSION_GIT)
if(NOT "${VERSION_GIT}" STREQUAL "")
    set(VERSION "${VERSION}-${VERSION_GIT}")
endif()

message(STATUS "Configuring steins-gate version " ${VERSION})

# project name and language
project (steins-gate CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -ljpeg")

# include version number in header
configure_file(${PROJECT_SOURCE_DIR}/src/version.hpp.in
    ${PROJECT_SOURCE_DIR}/src/version.hpp)

find_package(NPA REQUIRED)
find_package(NPENGINE REQUIRED)
find_package(GLEW REQUIRED)
find_package(GStreamer REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)
include(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(libpng REQUIRED libpng)
PKG_SEARCH_MODULE(PANGOCAIRO REQUIRED pangocairo)

# add libraries
include_directories(
    ${NPA_INCLUDE_DIR}
    ${NPENGINE_INCLUDE_DIR}
)
link_directories(
    ${PANGOCAIRO_LIBRARY_DIR}
    ${NPENGINE_LIBRARY_DIR}
    ${NPA_LIBRARY_DIR}
    ${GLEW_INCLUDE_DIR}
)

add_executable(steins-gate
    src/Main.cpp
    src/SGExe.cpp
    src/SGWindow.cpp
    src/SGInterpreter.cpp
    src/SGResourceMgr.cpp
    src/Phone.cpp
    src/PhoneModeAddressBook.cpp
    src/PhoneModeDefaultOperatable.cpp
    src/PhoneModeMailMenu.cpp
    src/PhoneModeSendMailEdit.cpp
    src/PhoneModeReceivingMail.cpp
    src/PhoneSD.cpp
)
target_link_libraries(steins-gate
    ${Boost_LIBRARIES}
    ${PANGOCAIRO_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${libpng_LIBRARIES}
    ${GLEW_LIBRARY}
    ${GSTREAMER_LIBRARIES} ${GSTREAMER_APP_LIBRARIES} ${GSTREAMER_VIDEO_LIBRARIES}
    npengine npa
)

# install target
install(TARGETS steins-gate DESTINATION bin)

# create packages
set(CPACK_GENERATOR "TBZ2")
set(CPACK_PACKAGE_VERSION ${VERSION})
include(CPack)
