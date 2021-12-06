cmake_minimum_required(VERSION 3.20)
project(EpubReader C)

set(CMAKE_C_STANDARD 11)

add_executable(EpubReader Sources/main.c Headers/epub.h Sources/Core/prepareEpub.c Headers/reader.h Sources/Core/prepareStructs.c)

include_directories(${CMAKE_SOURCE_DIR}/Headers)

target_link_libraries(EpubReader ${CMAKE_SOURCE_DIR}/Libraries/liblibepub.a)
target_link_libraries(EpubReader zip)
target_link_libraries(EpubReader xml2)

add_definitions(-DLIBXML_HTML_ENABLED)