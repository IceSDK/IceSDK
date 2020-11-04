add_library(harfbuzz STATIC
        src/harfbuzz.cc
        src/hb-icu.cc)

target_include_directories(harfbuzz PUBLIC src)

target_compile_definitions(harfbuzz PUBLIC -DHAVE_FREETYPE -DHB_NO_GETENV -DHAVE_ICU)
if(UNIX)
    target_compile_definitions(harfbuzz PUBLIC -DHAVE_PTHREAD)
    target_link_libraries(harfbuzz PUBLIC pthread)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Emscripten")
    target_compile_definitions(harfbuzz PUBLIC -DHB_NO_MT)
endif()

target_link_libraries(harfbuzz PUBLIC freetype icu)

