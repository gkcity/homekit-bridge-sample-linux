CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(HomeKitBridgeSample C)

SET(PROJ_NAME "HomeKitBridgeSample")

#----------------------------------------------------------------------------
#
# for GCC
#
#----------------------------------------------------------------------------
ADD_DEFINITIONS(-Wno-multichar)
ADD_DEFINITIONS(-Wno-pointer-to-int-cast)
ADD_DEFINITIONS(-O1)
ADD_DEFINITIONS(-fPIC)
ADD_DEFINITIONS(-std=c99)
ADD_DEFINITIONS(-D_GNU_SOURCE)
ADD_DEFINITIONS(-D__LINUX__)

#----------------------------------------------------------------------------
#
# dependence Libraries
#
#----------------------------------------------------------------------------
SET(DEPENDENCE_LIB tinyhap tinycrypto tinymdns tinyfx tiny pthread)

#----------------------------------------------------------------------------
#
# DEBUG INFORMATION
#
#----------------------------------------------------------------------------
ADD_DEFINITIONS(-DTINY_DEBUG)

#---------------------------------------------------------------------------------------
#
# include dir
#
#---------------------------------------------------------------------------------------
SET(SOURCE_ROOT ${PROJECT_SOURCE_DIR}/source)
SET(TINY_ROOT ${PROJECT_SOURCE_DIR}/tiny)
SET(TINYFX_ROOT ${PROJECT_SOURCE_DIR}/tinyfx)
SET(TINYMDNS_ROOT ${PROJECT_SOURCE_DIR}/tinymdns)
SET(TINYCRYPTO_ROOT ${PROJECT_SOURCE_DIR}/tinycrypto)
SET(TINYHAP_ROOT ${PROJECT_SOURCE_DIR}/tinyhap)

INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyBase)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyPortable)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyContainer)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyLog)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyStringUtil)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyRandom)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/Netty)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/HttpClient)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TcpClient)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/Json)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/StringArray)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/ByteBuffer)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyThread)

INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyMd5)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyThread)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyUuid)
INCLUDE_DIRECTORIES(${TINY_ROOT}/source/src/TinyWorker)

INCLUDE_DIRECTORIES(${TINYFX_ROOT}/source/src/IotLauncher)
INCLUDE_DIRECTORIES(${TINYFX_ROOT}/source/src/IotTypedef)
INCLUDE_DIRECTORIES(${TINYFX_ROOT}/source/src/IotFactory)

INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/base64)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/ed25519)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/curve25519)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/secret)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/hkdf)
INCLUDE_DIRECTORIES(${TINYCRYPTO_ROOT}/source/src/chacha20poly1305)

INCLUDE_DIRECTORIES(${TINYMDNS_ROOT}/source/src/dns-common)
INCLUDE_DIRECTORIES(${TINYMDNS_ROOT}/source/src/dns-server)
INCLUDE_DIRECTORIES(${TINYMDNS_ROOT}/source/src/mdns)

INCLUDE_DIRECTORIES(${TINYHAP_ROOT}/include/hap-tcp)
INCLUDE_DIRECTORIES(${TINYHAP_ROOT}/include/hap-support)

#---------------------------------------------------------------------------------------
#
# link dir
#
#---------------------------------------------------------------------------------------
LINK_DIRECTORIES(${TINY_ROOT}/target)
LINK_DIRECTORIES(${TINYFX_ROOT}/target)
LINK_DIRECTORIES(${TINYMDNS_ROOT}/target)
LINK_DIRECTORIES(${TINYCRYPTO_ROOT}/target)
LINK_DIRECTORIES(${TINYHAP_ROOT}/libs)

#-------------------------------------------------------------------------------------
# output dir
#-------------------------------------------------------------------------------------
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)
MESSAGE(STATUS "executable output:  ${EXECUTABLE_OUTPUT_PATH}")
MESSAGE(STATUS "library output: ${LIBRARY_OUTPUT_PATH}")

#----------------------------------------------------------------------------
# sample
#----------------------------------------------------------------------------
ADD_SUBDIRECTORY(source)
