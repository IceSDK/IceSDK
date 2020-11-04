add_executable(Test-IceSDK
        Test.cc

        IceSDK/Utils/Buffer.cc
        IceSDK/Utils/FileSystem.cc
        IceSDK/Utils/String.cc)

target_link_libraries(Test-IceSDK IceSDK gtest gtest_main gmock)
target_include_directories(Test-IceSDK PUBLIC
        ../third-party/googletest/googletest/include
        ../third-party/googletest/googlemock/include)
