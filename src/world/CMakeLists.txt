cmake_minimum_required (VERSION 3.14)

aux_source_directory(. DIR_WORLD_SRCS)
aux_source_directory(./item DIR_ITEM_SRCS)
aux_source_directory(./define DIR_DEFINE_SRCS)
aux_source_directory(./space DIR_SPACE_SRCS)

add_library(world ${DIR_WORLD_SRCS} ${DIR_ITEM_SRCS} ${DIR_DEFINE_SRCS} ${DIR_SPACE_SRCS})

