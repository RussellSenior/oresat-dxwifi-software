/**
 *  dxwifi.h
 * 
 *  DESCRIPTION: DxWiFi project includes, definitions, and types
 * 
 *  https://github.com/oresat/oresat-dxwifi-software
 * 
 */

#ifndef LIBDXWIFI_H
#define LIBDXWIFI_H

/************************
 *  Versioning
 ***********************/

#define DXWIFI_VERSION_MAJOR    0
#define DXWIFI_VERSION_MINOR    1
#define DXWIFI_VERSION_PATCH    0
#define DXWIFI_VERSION_RELEASE  "alpha"

#ifndef DXWIFI_BUILD_TYPE
#define DXWIFI_BUILD_TYPE       "debug"
#endif

#define STRINGIFY(x)  STRINGIFY_(x)
#define STRINGIFY_(x) #x

#define DXWIFI_VERSION      STRINGIFY(DXWIFI_VERSION_MAJOR) "." \
                            STRINGIFY(DXWIFI_VERSION_MINOR) "." \
                            STRINGIFY(DXWIFI_VERSION_PATCH) "-" \
                            DXWIFI_VERSION_RELEASE          "-" \
                            DXWIFI_BUILD_TYPE


/************************
 *  Constants
 ***********************/

// https://www.tcpdump.org/manpages/pcap.3pcap.html
#define DXWIFI_SNAPLEN_MAX 65535

#define DXWIFI_DFLT_PACKET_BUFFER_TIMEOUT 20

#define DXWIFI_FRAME_CONTROL_DATA_SIZE 256
#define DXWIFI_FRAME_CONTROL_CHECK_THRESHOLD 0.75

#define DXWIFI_BLOCK_SIZE_MIN (DXWIFI_FRAME_CONTROL_DATA_SIZE + 1)
#define DXWIFI_BLOCK_SIZE_MAX 2048


/************************
 *  Types
 ***********************/

/**
 * Control frames are used to signal file boundaries to the receiver during 
 * multi-file transmission
 */
typedef enum {
    DXWIFI_CONTROL_FRAME_NONE       = 0x00,
    DXWIFI_CONTROL_FRAME_PREAMBLE   = 0xff,
    DXWIFI_CONTROL_FRAME_EOT        = 0xaa
} dxwifi_control_frame_t;


#endif // LIBDXWIFI_H