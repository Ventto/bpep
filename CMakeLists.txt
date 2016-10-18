cmake_minimum_required (VERSION 2.8)

project (Bpep C)

set (MODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.cmake/Modules")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${MODULE_DIR})

set (GLIB2_MIN_VERSION 2.4.0)

find_package (Wireshark REQUIRED)
find_package (GLIB2 REQUIRED)

include (WiresharkPlugin)
include (UseMakeDissectorReg)

if (NOT WIRESHARK_PLUGIN_PATH)
  set (WIRESHARK_PLUGIN_PATH "$ENV{HOME}/.config/wireshark/plugins")
endif ()

# Plugin name and version info (major minor micro extra)
set_module_info(bpep 0 0 1 0)

include_directories (${GLIB2_INCLUDE_DIRS})
include_directories (${WIRESHARK_INCLUDE_DIRS})

set (LINK_MODE_MODULE MODULE)

set(DISSECTOR_SRC
  packet-bpep.c
)

set(PLUGIN_FILES
  plugin.c
  ${DISSECTOR_SRC}
)

set(CLEAN_FILES
  ${PLUGIN_FILES}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

register_dissector_files(plugin.c
  plugin
  ${DISSECTOR_SRC}
)

add_plugin_library(bpep)

set_property(TARGET bpep PROPERTY C_STANDARD 99)

if (CMAKE_COMPILER_IS_GNUCC)
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
endif ()

target_link_libraries(bpep ${WIRESHARK_LIBRARIES} ${GLIB2_LIBRARIES})

install(TARGETS bpep DESTINATION ${WIRESHARK_PLUGIN_PATH})
