cmake_minimum_required(VERSION 3.10)
project(Rasterizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------- OpenCV 4.6.0 ----------------
# find_package 必须知道 OpenCV 在哪：本机在 D:/opencv
#   D:/opencv/build/x64/mingw  是用 MinGW g++ 编译的（对应现在的 g++ 15.1）
#   D:/opencv/build            MSVC 会自动选 x64/vc14 | vc15
# 也可以命令行覆盖：cmake -B build -DOpenCV_DIR=<路径>
if(NOT DEFINED OpenCV_DIR)
    if(MINGW)
        set(OpenCV_DIR "D:/opencv/build/x64/mingw" CACHE PATH "OpenCV build directory")
    elseif(MSVC)
        set(OpenCV_DIR "D:/opencv/build" CACHE PATH "OpenCV build directory")
    endif()
endif()
find_package(OpenCV REQUIRED)

# ---------------- Eigen 3.4.0（header-only）----------------
# 源码里写的是 <eigen3/Eigen/Eigen>，所以 include 根目录要指向包含 eigen3/ 的
# 目录，即 D:/eigen（不是 D:/eigen/eigen3）。
if(NOT DEFINED EIGEN_ROOT)
    set(EIGEN_ROOT "D:/eigen" CACHE PATH "Directory containing eigen3/")
endif()

add_executable(Rasterizer
    main.cpp rasterizer.hpp rasterizer.cpp global.hpp
    Triangle.hpp Triangle.cpp Texture.hpp Texture.cpp Shader.hpp OBJ_Loader.h)

target_include_directories(Rasterizer PRIVATE
    ${OpenCV_INCLUDE_DIRS}   # find_package(OpenCV) 已经填好了 OpenCV 的头文件路径
    ${EIGEN_ROOT})           # Eigen 是纯头文件库，没有可链接的库

target_link_libraries(Rasterizer PRIVATE ${OpenCV_LIBS})

# 把 OpenCV 的 DLL 复制到 exe 旁边，直接运行无需手动配 PATH
if(WIN32)
    file(GLOB _opencv_dlls "${OpenCV_INSTALL_PATH}/bin/*.dll")
    if(_opencv_dlls)
        add_custom_command(TARGET Rasterizer POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${_opencv_dlls} "$<TARGET_FILE_DIR:Rasterizer>")
    endif()
endif()

#target_compile_options(Rasterizer PUBLIC -Wall -Wextra -pedantic)
