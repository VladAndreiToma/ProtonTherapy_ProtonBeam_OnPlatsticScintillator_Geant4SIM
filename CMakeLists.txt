cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Project name
project(Proton_On_Plastic_Scintillator)

# Find the GEANT4 package, assuming GEANT4 is installed
find_package(Geant4 REQUIRED)

# Set the include directories
include_directories(${PROJECT_SOURCE_DIR}/include ${Geant4_INCLUDE_DIRS})

# Set your source files (these are in the 'src' directory)
set(SOURCES 
    src/PrimaryGeneratorAction.cc
    src/DetectorConstruction.cc
    src/ActionInitialization.cc
    src/EventAction.cc
    src/SteppingAction.cc
    src/PhysicsList.cc
    main.cc
)

# Set up project with GEANT4
include(${Geant4_USE_FILE})

# Build the executable (named 'proton_simulation')
add_executable(proton_simulation ${SOURCES})

# Link it with GEANT4 libraries
target_link_libraries(proton_simulation ${Geant4_LIBRARIES})

# Optionally enable visualization (if you want visualization features)
add_definitions(-DGEANT4_USE_VIS)

# Optional: Set C++ standard (if needed)
set_target_properties(proton_simulation PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
