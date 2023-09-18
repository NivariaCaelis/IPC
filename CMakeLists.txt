###############################################################################
###                             CMAKE SETTINGS                              ###
###############################################################################
## This section includes settings related to CMake itself, ensuring necessary
## requirements are met before other processes are performed.
###############################################################################

# Set the minimum required CMake version.
cmake_minimum_required (VERSION 3.20)


###############################################################################
###                              C++ SETTINGS                               ###
###############################################################################
## This section includes C++ related settings such as the C++ standard, version,
## compile flags, and more.
###############################################################################

# Set the C++ standard to C++17.
set (CMAKE_CXX_STANDARD 17)

# Disable compiler-specific extensions.
set (CMAKE_CXX_EXTENSIONS OFF)

# Require the specified C++ standard to be used.
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Add common compile options to promote code quality.
add_compile_options (-Wall -Werror -Wextra -Wpedantic -pedantic)


###############################################################################
###                         PROJECT INITIALIZATION                          ###
###############################################################################
## This section initializes the project and sets up necessary configurations,
## including enabling testing and adding subdirectories.
###############################################################################

# Set the project name.
project (IPC)

# Enable testing for this project.
enable_testing()

# Add the 'src' subdirectory for further project structure.
add_subdirectory (src)