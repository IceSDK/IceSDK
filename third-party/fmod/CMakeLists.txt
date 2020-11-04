add_library(fmod STATIC dummy.c)
target_include_directories(fmod PUBLIC inc)

if (UNIX)
    get_filename_component(FMOD_LIB lib/linux/${CMAKE_SYSTEM_PROCESSOR}/libfmod.so.12 REALPATH)

    set_property(TARGET fmod PROPERTY IMPORTED_IMPLIB_RELEASE "${FMOD_LIB}")
    set_property(TARGET fmod PROPERTY IMPORTED_LOCATION_RELEASE "${FMOD_LIB}")
endif()

if (WIN32)
    get_filename_component(FMOD_LIB lib/win/${CMAKE_SYSTEM_PROCESSOR}/fmod REALPATH)
endif()

target_link_libraries(fmod PUBLIC ${FMOD_LIB})

add_custom_command (TARGET fmod POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FMOD_LIB} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
