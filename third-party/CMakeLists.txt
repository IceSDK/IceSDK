#######################################################
#                      Audio                          #
#######################################################
if (ICESDK_USE_FMOD)
    add_subdirectory(fmod)
endif()

#######################################################
#                     Graphics                        #
#######################################################

# Windowing

if (ICESDK_USE_SDL2)
    add_subdirectory(sdl2)
endif()

# Graphics Wrapper
add_subdirectory(bgfx)
add_subdirectory(bimg)
add_subdirectory(bx)

# Font rendering
add_subdirectory(freetype)
add_subdirectory(harfbuzz)
add_subdirectory(icu)

#######################################################
#                       Math                          #
#######################################################
add_subdirectory(glm)

#######################################################
#                      Utils                          #
#######################################################
add_subdirectory(entt)
add_subdirectory(imgui)
add_subdirectory(spdlog)

#######################################################
#                Tests/Benchmarks                     #
#######################################################
#add_subdirectory(gbenchmark)
#add_subdirectory(googletest)
