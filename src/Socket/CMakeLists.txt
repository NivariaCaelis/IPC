###############################################################################
###                                COMPONENT                                ###
###############################################################################
## Define component-specific variables.
###############################################################################

# Set the name of the component library.
set (COMPONENT_LIB ${COMPONENT}_lib)

# Set the name of the component tests.
set (COMPONENT_TESTS ${COMPONENT}_tests)


###############################################################################
###                                 LIBRARY                                 ###
###############################################################################
## Settings and steps to build the component library.
###############################################################################

# Create an object library for the component.
add_library (
  ${COMPONENT_LIB} OBJECT
)

# Include directories for the library.
target_include_directories (
  ${COMPONENT_LIB}
    PUBLIC
      ${CMAKE_CURRENT_LIST_DIR}/include
)

# Gather source files for the component library.
file (
  GLOB SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
)

# Add the collected source files to the library.
target_sources (
  ${COMPONENT_LIB}
    PRIVATE
      ${SOURCES}
)

# Link the needed libraries.
target_link_libraries (
  ${COMPONENT_LIB}
)


###############################################################################
###                                  TESTS                                  ###
###############################################################################
## Settings and steps to build the component tests.
###############################################################################

# Create an executable for tests related to the component.
add_executable (
  ${COMPONENT_TESTS}
)

# Gather source files for the component tests.
file (
  GLOB SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_LIST_DIR}/tests/*.cpp"
)

# Add the collected source files to the tests executable.
target_sources (
  ${COMPONENT_LIB}
    PRIVATE
      ${SOURCES}
)

# Link the necessary libraries for the tests.
target_link_libraries (
  ${COMPONENT_TESTS}
    ${COMPONENT_LIB}
    gtest
    gtest_main
)

# Register the tests with CTest.
add_test (
  ${COMPONENT_TESTS}
    ${COMPONENT_TESTS}
)