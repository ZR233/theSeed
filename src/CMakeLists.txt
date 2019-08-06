# CMakeList.txt: theSeed 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.14)


# 包含子项目。
add_subdirectory ("world")
include_directories(./ ./world ./world)#添加多目录的路径

# 将源代码添加到此项目的可执行文件。
add_executable (theSeed "theSeed.cpp" "theSeed.h")
target_link_libraries(theSeed world)
# TODO: 如有需要，请添加测试并安装目标。
