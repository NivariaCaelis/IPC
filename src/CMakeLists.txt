###############################################################################
###                             INTEGRATE GTEST                             ###
###############################################################################
## Integrate Google Test framework for unit testing.
###############################################################################

find_package(GTest REQUIRED)

include(GoogleTest)


###############################################################################
###                               COMPONENTS                                ###
###############################################################################
## Include project components and subdirectories.
###############################################################################

# Get a list of subdirectories in the current directory
set (
  COMPONENTS
    Socket          # Sockets
)

# Iterate over each subdirectory
foreach(COMPONENT ${COMPONENTS})
  message("-- Found component: ${COMPONENT}")
  add_subdirectory(${COMPONENT})
endforeach()
