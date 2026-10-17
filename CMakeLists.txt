cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OBJCXX_STANDARD 20)
set(CMAKE_OBJCXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_DEPLOYMENT_TARGET "26.0" CACHE STRING "Minimum macOS version")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#cocoon Definition
project("cocoon" LANGUAGES CXX OBJCXX VERSION 0.1.0 DESCRIPTION "A C++20 wrapper over modern AppKit.")
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

if(NOT APPLE)
    message(FATAL_ERROR "cocoon requires macOS")
endif()

option(COCOON_BUILD_EXAMPLES "Build the example applications" ON)
option(COCOON_FORMAT "Run clang-format on the hand-written sources before building" ON)
option(COCOON_REGENERATE "Add a target that regenerates the wrapper sources from the SDK headers" OFF)

#cocoon SDK
execute_process(COMMAND xcrun --sdk "${CMAKE_OSX_SYSROOT}" --show-sdk-version OUTPUT_VARIABLE COCOON_SDK_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET)
string(REGEX MATCH "^[0-9]+" COCOON_SDK_MAJOR "${COCOON_SDK_VERSION}")
message(STATUS "cocoon: building against the macOS ${COCOON_SDK_VERSION} SDK")

#cocoon Setup
file(GLOB_RECURSE COCOON_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.mm")
add_library(${PROJECT_NAME} STATIC ${COCOON_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
if(COCOON_SDK_MAJOR)
    target_compile_definitions(${PROJECT_NAME} PUBLIC COCOON_SDK_MAJOR=${COCOON_SDK_MAJOR})
endif()
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/internal.h)
target_compile_options(${PROJECT_NAME} PRIVATE -fobjc-arc -Wall -Wextra -Wno-unused-parameter -Wno-deprecated-declarations -Wno-unguarded-availability-new -Wno-auto-var-id -ferror-limit=0)

#cocoon Packages
target_link_libraries(${PROJECT_NAME} PUBLIC
    "$<LINK_LIBRARY:FRAMEWORK,AppKit>"
    "$<LINK_LIBRARY:FRAMEWORK,Foundation>"
    "$<LINK_LIBRARY:FRAMEWORK,CoreFoundation>"
    "$<LINK_LIBRARY:FRAMEWORK,UniformTypeIdentifiers>"
    "$<LINK_LIBRARY:FRAMEWORK,QuartzCore>"
    "$<LINK_LIBRARY:FRAMEWORK,CoreImage>"
    "$<LINK_LIBRARY:FRAMEWORK,CoreGraphics>")

#cocoon Install
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}.pc.in" "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}.pc" @ONLY)
configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake" INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake" VERSION "${PROJECT_VERSION}" COMPATIBILITY SameMajorVersion)
install(TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}Targets" ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}" INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}.pc" DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
install(EXPORT "${PROJECT_NAME}Targets" FILE "${PROJECT_NAME}Targets.cmake" NAMESPACE ${PROJECT_NAME}:: DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE" DESTINATION "${CMAKE_INSTALL_DATADIR}/licenses/${PROJECT_NAME}")
export(EXPORT "${PROJECT_NAME}Targets" FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Targets.cmake" NAMESPACE ${PROJECT_NAME}::)

#cocoon Format
if(COCOON_FORMAT)
    find_program(CLANG_FORMAT_EXECUTABLE clang-format)
    if(CLANG_FORMAT_EXECUTABLE)
        file(GLOB_RECURSE COCOON_FORMAT_FILES CONFIGURE_DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.mm"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
        list(FILTER COCOON_FORMAT_FILES EXCLUDE REGEX "/generated/")
        list(JOIN COCOON_FORMAT_FILES "\n" COCOON_FORMAT_LIST)
        file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/format_files.txt" "${COCOON_FORMAT_LIST}\n")
        add_custom_target(${PROJECT_NAME}_format
            COMMAND ${CLANG_FORMAT_EXECUTABLE} -i --style=file --files=${CMAKE_CURRENT_BINARY_DIR}/format_files.txt
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Formatting ${PROJECT_NAME} sources")
        add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_format)
    endif()
endif()

#cocoon Generator
if(COCOON_REGENERATE)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    add_custom_target(${PROJECT_NAME}_generate
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generator/generate.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Regenerating ${PROJECT_NAME} wrappers from the macOS SDK")
endif()

#cocoon Documentation
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "${PROJECT_NAME}")
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_FILE_PATTERNS "*.h;*.md;*.cpp")
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE ${CMAKE_CURRENT_SOURCE_DIR}/docs/mainpage.md)
    set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/examples)
    set(DOXYGEN_SEARCHENGINE NO)
    set(DOXYGEN_GENERATE_TREEVIEW NO)
    set(DOXYGEN_ALPHABETICAL_INDEX NO)
    set(DOXYGEN_HAVE_DOT NO)
    set(DOXYGEN_CLASS_GRAPH NO)
    set(DOXYGEN_COLLABORATION_GRAPH NO)
    set(DOXYGEN_GRAPHICAL_HIERARCHY NO)
    set(DOXYGEN_INCLUDE_GRAPH NO)
    set(DOXYGEN_INCLUDED_BY_GRAPH NO)
    set(DOXYGEN_SHOW_FILES NO)
    set(DOXYGEN_SHOW_USED_FILES NO)
    set(DOXYGEN_SHOW_INCLUDE_FILES NO)
    set(DOXYGEN_INLINE_SOURCES NO)
    set(DOXYGEN_VERBATIM_HEADERS NO)
    doxygen_add_docs(docs
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/docs/mainpage.md
        ${CMAKE_CURRENT_SOURCE_DIR}/examples
        COMMENT "Generating ${PROJECT_NAME} API documentation")
endif()

#cocoon Examples
if(COCOON_BUILD_EXAMPLES)
    add_subdirectory(examples/gallery)
    add_subdirectory(examples/calculator)
endif()
