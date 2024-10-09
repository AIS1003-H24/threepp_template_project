cmake_minimum_required(VERSION 3.19)
project(threepp_imgui_demo)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 947a7f34ff3b931d30ed777303bafaeaef84e029
)
FetchContent_MakeAvailable(threepp)

add_subdirectory(external)

add_executable(threepp_demo main.cpp)
target_link_libraries(threepp_demo PRIVATE threepp::threepp imgui::imgui)


######### Emscripten #######
if (DEFINED EMSCRIPTEN)

    set(LINK_FLAGS " --bind -sUSE_GLFW=3 -sGL_DEBUG=1 -sMIN_WEBGL_VERSION=2 -sMAX_WEBGL_VERSION=2 \
    -sFULL_ES3 -sASSERTIONS -sALLOW_MEMORY_GROWTH -sWASM=1")

    set_target_properties("demo"
            PROPERTIES SUFFIX ".html"
            LINK_FLAGS "${LINK_FLAGS}"
    )

endif ()
###########################