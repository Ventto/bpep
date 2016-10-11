#
# Try to find the wireshark library and its includes
#
# This snippet sets the following variables:
#  WIRESHARK_FOUND             True if wireshark library got found
#  WIRESHARK_INCLUDE_DIRS      Location of the wireshark headers 
#  WIRESHARK_LIBRARIES         List of libraries to use wireshark
#
#  Copyright (c) 2016 Franklin "Snaipe" Mathieu
#

find_path (WIRESHARK_INCLUDE_DIRS epan/column-info.h PATH_SUFFIXES wireshark)
find_library (WIRESHARK_LIBRARIES wireshark)

include (FindPackageHandleStandardArgs)
# handle the QUIET and REQUIRED arguments and set WIRESHARK_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(wireshark DEFAULT_MSG
                                  WIRESHARK_LIBRARIES WIRESHARK_INCLUDE_DIRS)

mark_as_advanced (WIRESHARK_INCLUDE_DIRS WIRESHARK_LIBRARIES)
