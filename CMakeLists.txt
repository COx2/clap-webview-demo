cmake_minimum_required(VERSION 3.21)

project(clap-webview-demo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

if (APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11 CACHE STRING "Build for 10.11")
endif()

add_subdirectory(libs/clap EXCLUDE_FROM_ALL)
add_subdirectory(libs/clap-helpers EXCLUDE_FROM_ALL)

add_library(${PROJECT_NAME} MODULE
        src/clap-webview-demo-pluginentry.cpp
        src/clap-webview-demo-processor.cpp
        src/clap-webview-demo-processor.h
        src/clap-webview-demo-editor.cpp
        src/clap-webview-demo-editor.h
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        libs/choc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        clap-core
        clap-helpers
)

if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE CLAP_MAC=1)
    set_target_properties(${PROJECT_NAME} PROPERTIES
            BUNDLE True
            BUNDLE_EXTENSION clap
            MACOSX_BUNDLE_GUI_IDENTIFIER com.cox2.${PROJECT_NAME}
            MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
            MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
            # MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/${PROJECT_NAME}.plist.in
            )
    target_link_libraries(${PROJECT_NAME} "-framework CoreFoundation" "-framework AppKit" "-framework CoreGraphics")
elseif(UNIX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE CLAP_LINUX=1)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".clap" PREFIX "")
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE CLAP_WINDOWS=1)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".clap" PREFIX "")
endif()