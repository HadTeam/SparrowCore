cmake_minimum_required(VERSION 3.8)
project(SparrowCore)

set(CMAKE_CXX_STANDARD 17)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} $ENV{QT_DIR}/$ENV{QT_VERSION}/gcc_64/lib/cmake)

find_package(Qt5Core REQUIRED)

SET (SPARROW_SRC SparrowCore.h CommandLine.h fastDownload.h jsonParser.h Launcher.h Minecraft.h utils.h)
ADD_LIBRARY (SparrowCore SHARED ${Sparrow_SRC})
INSTALL(TARGETS SparrowCore RUNTIME DESTINATION .)
SET_TARGET_PROPERTIES(
        SparrowCore PROPERTIES LINKER_LANGUAGE CXX
        OUTPUT_NAME "SparrowCore")