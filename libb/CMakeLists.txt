cmake_minimum_required(VERSION 3.5)
include(GNUInstallDirs)

list(APPEND libb_public_headers 
  "other.hh"
)

list(APPEND libb_sources 
  "other.cc"
  ${libb_public_headers}
)

add_library(libb ${libb_sources})

target_include_directories(
  libb
 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}> # for headers when building
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for generated files in build mode
  $<INSTALL_INTERFACE:include/is/libb> # for clients in install mode
)

install(
  TARGETS libb EXPORT libbTargets
  LIBRARY  DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE  DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME  DESTINATION "${CMAKE_INSTALL_BINDIR}"
  INCLUDES  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(FILES ${libb_public_headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/is/libb)

install(
  EXPORT libbTargets
  FILE libbConfig.cmake
  NAMESPACE is::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libb
)

add_library(is::libb ALIAS libb)
