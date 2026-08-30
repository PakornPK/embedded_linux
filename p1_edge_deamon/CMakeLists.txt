include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG        v0.14.0
)
FetchContent_MakeAvailable(httplib)

include_directories(include)

add_executable(p1_edge_deamon src/main.cpp)

target_include_directories(p1_edge_deamon PRIVATE include)
target_link_libraries(
    p1_edge_deamon 
    PRIVATE 
    nlohmann_json::nlohmann_json 
    httplib::httplib
)

