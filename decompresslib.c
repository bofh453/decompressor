#include "decompresslib.h"

int LIBSATDECOMPRESS_API Decompress(char *input, char *output, size_t inputLength, size_t outputLength, int bitsPerPixel, int pixelsPerBlock, int pixelsPerScanline, int mask) {
  SZ_com_t params;

  mask = mask | SZ_RAW_OPTION_MASK; // By default NOAA dont as for RAW, but their images are RAW. No Compression header.

  params.options_mask = mask;
  params.bits_per_pixel = bitsPerPixel;
  params.pixels_per_block = pixelsPerBlock;
  params.pixels_per_scanline = pixelsPerScanline;

  size_t destLen = pixelsPerScanline;
  int status = SZ_BufftoBuffDecompress(output, &destLen, input, inputLength, &params);

  return status != AEC_OK ? status : destLen;
}