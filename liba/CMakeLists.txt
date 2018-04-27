cmake_minimum_required(VERSION 3.5)
include(GNUInstallDirs)

find_package(OpenCV REQUIRED core)
find_package(Threads REQUIRED)

list(APPEND liba_public_headers 
  "module.hh"
)

list(APPEND liba_private_headers 
  "internal/private.hh"
)

list(APPEND liba_sources 
  "module.cc"
  ${liba_public_headers}
  ${liba_private_headers}
)

add_library(liba ${liba_sources})

target_include_directories(
  liba
 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> # for headers when building
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for generated files in build mode
  $<INSTALL_INTERFACE:include/is/liba> # for clients in install mode
 PRIVATE
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(liba 
 PRIVATE
  is::libb
  ${OpenCV_LIBRARIES} 
  Threads::Threads
)

set_property(TARGET liba PROPERTY CXX_STANDARD 11)

install(
  TARGETS liba EXPORT libaTargets
  LIBRARY  DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE  DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME  DESTINATION "${CMAKE_INSTALL_BINDIR}"
  INCLUDES  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(FILES ${liba_public_headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/is/liba)

install(
  EXPORT libaTargets
  FILE libaConfig.cmake
  NAMESPACE is::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/liba
)
