## Android
```
.\tools\win\gn.exe gen out
cd out

python3 ..\tools\build4android.py 30 %LOCALAPPDATA%\Android\Sdk\ndk\21.3.6528147 %LOCALAPPDATA%\Android\Sdk\ndk-bundle BareBones

# Open in Android Studio && Run
```

## WebAssembly
args.gn
```gn
is_clang = true
use_lld = true

clang_base_path = "$HOME/emsdk/upstream"

target_os = "emscripten"
target_cpu = "wasm32"
```

## Supported Platforms


| ![Windows](./.assets/windows_64x64.png) | ![Linux](./.assets/linux_64x64.png) | ![osX](./.assets/osx_64x64.png) | ![android](./.assets/android_64x64.png) | ![ios](./.assets/ios_64x64.png) | ![web](./.assets/wasm_64x64.png) |
| --------------------------------------- | ----------------------------------- | ------------------------------- | --------------------------------------- | ------------------------------- | -------------------------------- |
| :heavy_check_mark:                      | :heavy_check_mark:                  | :x:                             | :heavy_check_mark:                      | :x:                             | :heavy_check_mark:               |

## Compile Status

| Platform   | Windows                                                                                                                                                         | Linux                                                                                                                        | MacOS |
| ---------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- | ----- |
| PC         | ![CircleCI](https://img.shields.io/circleci/build/github/Mempler/IceSDK?label=Win32&logo=Windows&logoColor=cyan&token=8c4dd3110757f7afa0209a688f88c407ce5783af) | [![CircleCI](https://circleci.com/gh/Mempler/IceSDK.svg?style=svg&circle-token=8c4dd3110757f7afa0209a688f88c407ce5783af)](#) | :x:   |
| Android    | :x:                                                                                                                                                             | :x:                                                                                                                          | :x:   |
| iOS        | :x:                                                                                                                                                             | :x:                                                                                                                          | :x:   |
| Emscripten | :x:                                                                                                                                                             | :x:                                                                                                                          | :x:   |
