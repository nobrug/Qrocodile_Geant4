#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Qrocodile_G4)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
#Add CRY library

#set(CRY_LIB_DIR "/home/uzh/nobrug/Qrocodile-MC-master/cry_v1.7/lib")
#include_directories(${CRY_LIB_DIR})
#link_directories(${CRY_LIB_DIR})
#set(CRY_LIBRARIES "CRY")



#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})

#Check here for DMXENV_GPS_USE
#Use GPS if the environment variable is set, and the user has *not* supplied the CMake 
#command line argument. Otherwise, the argument of the command line has the priority.
#
if("$ENV{DMXENV_GPS_USE}" AND NOT DEFINED QROCODILEENV_GPS_USE)
  set(QROCODILEENV_GPS_USE_DEFAULT ON)
else()
  set(QROCODILEENV_GPS_USE_DEFAULT ${QROCODILEENV_GPS_USE})
endif()

option(DMXENV_GPS_USE "Build Qrocodile with support for GPS" ${QROCODILEENV_GPS_USE_DEFAULT})
mark_as_advanced(QROCODILEENV_GPS_USE)

if(QROCODILEENV_GPS_USE)
  add_definitions(-DQROCODILEENV_GPS_USE)
endif()

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include 
                    ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------

file(COPY ${PROJECT_SOURCE_DIR}/Cryo2.stl DESTINATION ${CMAKE_BINARY_DIR}/)


# Add the executable, and link it to the Geant4 libraries
#
add_executable(QROCODILE Qrocodile.cc ${sources} ${headers})
target_link_libraries(QROCODILE ${Geant4_LIBRARIES})
target_link_libraries(QROCODILE /home/uzh/nobrug/Qrocodile-MC-master/cry_v1.7/lib/libCRY.a)

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build underground_physics. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(Qrocodile_SCRIPTS
    alpha_1000.mac alpha_low.mac alpha.mac ambe_spectrum.mac gamma_1000.mac gamma_2000.mac gamma_low.mac gamma.mac initInter.mac neutron.mac stt.mac stt.out stt_pmt_ref.out stt_ref.out wired.mac
  )

foreach(_script ${Qrocodile_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# Add program to the project targets
# (this avoids the need of typing the program name after make)
#
add_custom_target(Qrocodile_G4 DEPENDS QROCODILE)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS QROCODILE DESTINATION bin)

