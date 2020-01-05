cmake_minimum_required(VERSION 3.12)

SET(THIS BenchRex)

# -------------------------- CONFIGURATION ------------------------------------

if(WIN32)
    set(RADICAL_PATH "C:/Source/CMake/Modules")
else()
    set(RADICAL_PATH "/opt/Radicalware/CMake_Modules")
endif()

include("${RADICAL_PATH}/Radical-App-Config.cmake")

# -------------------------- BUILD --------------------------------------------

project (${THIS})

set(THESE_FILES 
    ${SRC}/${THIS}.cpp

    ${INC}/BaseRex.h
    ${SRC}/BaseRex.cpp

    ${INC}/Rex/C_Rex.h
    ${SRC}/Rex/C_Rex.cpp

    ${INC}/Rex/STL_Rex.h
    ${SRC}/Rex/STL_Rex.cpp

    ${INC}/Rex/Boost_Rex.h
    ${SRC}/Rex/Boost_Rex.cpp

    ${INC}/Rex/re2_Rex.h
    ${SRC}/Rex/re2_Rex.cpp

    ${INC}/Rex/Xpressive_Rex.h
    ${SRC}/Rex/Xpressive_Rex.cpp

    ${INC}/Rex/Pearl_Rex.h
    ${SRC}/Rex/Pearl_Rex.cpp
)

add_executable(${THIS}
    ${THESE_FILES}
)

find_package(re2)
find_package(Nexus)
find_package(xvector)
find_package(xstring)
find_package(xmap)
find_package(Timer)

find_package(pcre)

find_package(ReadyBoost)
if(WIN32)
    find_package(Boost 1.71.0 EXACT REQUIRED COMPONENTS regex)
else()
    find_package(Boost 1.65.1 EXACT REQUIRED COMPONENTS regex)
endif()

target_link_libraries( ${THIS} PRIVATE
    radical::Nexus
    radical::xvector
    radical::xstring
    radical::xmap
    radical::Timer
    radical_mod::re2

    Boost::regex
)

# -------------------------- END ----------------------------------------------

CONFIGURE_VISUAL_STUDIO(${THESE_FILES})

