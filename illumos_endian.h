#ifndef _ILLUMOS_ENDIAN_H
#define _ILLUMOS_ENDIAN_H

/*
 * Shims to make Apple's endian headers and macros compatible
 * with <sys/endian.h> (which is awful).
 */

#include <sys/byteorder.h>

# ifdef _LITTLE_ENDIAN
#  undef _LITTLE_ENDIAN
#  define _LITTLE_ENDIAN 0x12345678
#  define _BIG_ENDIAN 0x87654321
#  define _BYTE_ORDER _LITTLE_ENDIAN

#  define htole32(x) (x)
#  define le32toh(x) (x)
#  define htobe32(x) htonl(x)
#  define be32toh(x) ntohl(x)

#elif defined (_BIG_ENDIAN)
#  undef _BIG_ENDIAN
#  define _LITTLE_ENDIAN 0x12345678
#  define _BIG_ENDIAN 0x87654321
#  define _BYTE_ORDER _BIG_ENDIAN

#  define htole32(x) BSWAP_32(x)
#  define le32toh(x) BSWAP_32(x)
#  define htobe32(x) (x)
#  define be32toh(x) (x)
# endif

#endif /* _ILLUMOS_ENDIAN_H */
