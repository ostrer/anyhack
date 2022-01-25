cmake_minimum_required(VERSION 3.9)

project(anyhack VERSION 0.2.1 DESCRIPTION "AnyConnect LAN hack")


file(GLOB SOURCES src/*.c*)
add_library(anyhack SHARED ${SOURCES})
set_target_properties(anyhack PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)

target_include_directories(anyhack PRIVATE include)
target_include_directories(anyhack PRIVATE src)

SET(CMAKE_INSTALL_PREFIX /)
INSTALL(TARGETS anyhack LIBRARY DESTINATION opt/cisco/anyconnect/lib NAMELINK_SKIP)
INSTALL(PROGRAMS scripts/anyhack scripts/anyhack.patch.vpn DESTINATION usr/local/bin)

# copy script as postinst for deb package
file(COPY   ${CMAKE_CURRENT_SOURCE_DIR}/scripts/anyhack.patch.vpn 
            DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
            FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
            NO_SOURCE_PERMISSIONS)
file(RENAME ${CMAKE_CURRENT_BINARY_DIR}/anyhack.patch.vpn ${CMAKE_CURRENT_BINARY_DIR}/postinst)

set(CPACK_GENERATOR "DEB;TGZ")
set(CPACK_INSTALL_DIRECTORY "/")
SET(CPACK_PACKAGING_INSTALL_PREFIX "/")
set(CPACK_NATIVE_INSTALL_DIRECTORY "/")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA ${CMAKE_CURRENT_BINARY_DIR}/postinst)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_DEBUGINFO_PACKAGE ON)
#set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "MarkO")
include(CPack)
