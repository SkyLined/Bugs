function Memory(oReadWriteSploit) {
  // Given a oReadWriteSploit object (which implements at least one way of reading data from and one way of writing
  // data to memory), this object allows easy reading/writing of data in various common sizes and formats.
  if (!(oReadWriteSploit.readByte || oReadWriteSploit.readWord || oReadWriteSploit.readDWord)) {
    throw new Error("No way of reading memory implemented in oReadWriteSploit.");
  }
  if (!(oReadWriteSploit.writeByte || oReadWriteSploit.writeWord || oReadWriteSploit.writeDWord)) {
    throw new Error("No way of writing memory implemented in oReadWriteSploit.");
  }
  this.oReadWriteSploit = oReadWriteSploit;
}
var daiPreferedReadWriteSizes_by_iValueSize = {
  1: [1, 2, 4],
  2: [2, 1, 4],
  3: [1, 2, 4],
  4: [4, 2, 1]
};
var dRead_sMethodName_by_iSize = {
  1: "readByte",
  2: "readWord",
  4: "readDWord"
};
var dWrite_sMethodName_by_iSize = {
  1: "writeByte",
  2: "writeWord",
  4: "writeDWord"
};

// read/write values of arbitrary size
Memory.prototype.readValue = function Memory_readValue(iAddress, iValueSize) {
  var aiPreferedReadSizes = daiPreferedReadWriteSizes_by_iValueSize[iValueSize];
  if (typeof(aiPreferedReadSizes) == "undefined") {
    throw new Error("Unknown iValueSize " + iValueSize);
  }
  for (var iIndex = 0; iIndex < aiPreferedReadSizes.length; iIndex++) {
    var iReadSize = aiPreferedReadSizes[iIndex],
        sReadMethodName = dRead_sMethodName_by_iSize[iReadSize];
    if (this.oReadWriteSploit[sReadMethodName]) break;
  }
  if (iIndex == aiPreferedReadSizes.length) {
    // This should never happen because the constructor makes sure one way to read memory exists, but anyway...
    throw new Error("Cannot find a way to read memory");
  }
  var iValue = 0;
  for (var iIndex = 0; iIndex < iValueSize; iIndex += iReadSize) {
    var iReadValue = this.oReadWriteSploit[sReadMethodName](iAddress + iIndex);
    iValue += Math.pow(0x100, iIndex) * iReadValue;
  }
  iValue &= Math.pow(0x100, iValueSize) - 1;
  return iValue;
};
Memory.prototype.writeValue = function Memory_writeValue(iAddress, iValueSize, iValue) {
  var aiPreferedWriteSizes = daiPreferedReadWriteSizes_by_iValueSize[iValueSize];
  if (typeof(aiPreferedWriteSizes) == "undefined") {
    throw new Error("Unknown iValueSize " + iValueSize);
  }
  for (var iIndex = 0; iIndex < aiPreferedWriteSizes.length; iIndex++) {
    var iWriteSize = aiPreferedWriteSizes[iIndex],
        sWriteMethodName = dWrite_sMethodName_by_iSize[iWriteSize];
    if (this.oReadWriteSploit[sWriteMethodName]) break;
  }
  if (iIndex == aiPreferedWriteSizes.length) {
    // This should never happen because the constructor makes sure one way to write memory exists, but anyway...
    throw new Error("Cannot find a way to write memory");
  }
  for (var iIndex = 0; iIndex < iValueSize; iIndex += iWriteSize) {
    var iRemainingSize = iValueSize - iIndex,
        iWriteValue = iValue & (Math.pow(0x100, iWriteSize) - 1);
    if (iRemainingSize < iWriteSize) {
      // It is impossible to write as little bytes as needed, so more must be written. If the original value of those
      // bytes is read, and written, nothing changes and it's as if the addition write never took place.
      var iAdditionalValueAddress = iAddress + iIndex + iRemainingSize,
          iAdditionalValueSize = iWriteSize - iRemainingSize,
          iAdditionalValue = this.readValue(iAdditionalValueAddress, iAdditionalValueSize) * Math.pow(0x100, iRemainingSize);
      iWriteValue += iAdditionalValue;
    }
    this.oReadWriteSploit[sWriteMethodName](iAddress + iIndex, iWriteValue);
    iValue >>>= 8 * iWriteSize;
  }
};
// read/compare/write arrays of values of arbitrary size
Memory.prototype.readValueArray = function Memory_readValueArray(iAddress, iValueSize, iLength) {
  var aiValues = new Array(iLength);
  for (var iIndex = 0; iIndex < iLength; iIndex++) {
    aiValues[iIndex] = this.readValue(iAddress, iValueSize);
    iAddress += iValueSize;
  }
  return aiValues;
};
Memory.prototype.compareValueArray = function Memory_compareValueArray(iAddress, iValueSize, aiValues) {
  for (var iIndex = 0; iIndex < aiValues.length; iIndex++) {
    if (aiValues[iIndex] != this.readValue(iAddress, iValueSize)) {
      return false;
    }
    iAddress += iValueSize;
  }
  return true;
};
Memory.prototype.writeValueArray = function Memory_writeValueArray(iAddress, iValueSize, aiValues) {
  for (var iIndex = 0; iIndex < aiValues.length; iIndex++) {
    this.writeValue(iAddress, iValueSize, aiValues[iIndex]);
    iAddress += iValueSize;
  }
};
// read/compare/write (arrays of) bytes
Memory.prototype.readByte = function Memory_readByte(iAddress) {
  return this.readValue(iAddress, 1);
};
Memory.prototype.readBytes = function Memory_readBytes(iAddress, iLength) {
  return this.readValueArray(iAddress, 1, iLength);
};
Memory.prototype.compareBytes = function Memory_readBytes(iAddress, aiBytes) {
  return this.compareValueArray(iAddress, 1, aiBytes);
};
Memory.prototype.writeByte = function Memory_writeByte(iAddress, iByte) {
  return this.writeValue(iAddress, 1, iByte);
};
Memory.prototype.writeBytes = function Memory_writeBytes(iAddress, aiBytes) {
  return this.writeValueArray(iAddress, 1, aiBytes);
};
// read/compare/write (arrays of) words
Memory.prototype.readWord = function Memory_readWord(iAddress) {
  return this.readValue(iAddress, 2);
};
Memory.prototype.readWords = function Memory_readWords(iAddress, iLength) {
  return this.readValueArray(iAddress, 2, iLength);
};
Memory.prototype.compareWords = function Memory_readWords(iAddress, aiWords) {
  return this.compareValueArray(iAddress, 2, aiWords);
};
Memory.prototype.writeWord = function Memory_writeWord(iAddress, iWord) {
  return this.writeValue(iAddress, 2, iWord);
};
Memory.prototype.writeWords = function Memory_writeWords(iAddress, aiWords) {
  return this.writeValueArray(iAddress, 2, aiWords);
};
// read/compare/write (arrays of) dwords
Memory.prototype.readDWord = function Memory_readDWord(iAddress) {
  return this.readValue(iAddress, 4);
};
Memory.prototype.readDWords = function Memory_readDWords(iAddress, iLength) {
  return this.readValueArray(iAddress, 4, iLength);
};
Memory.prototype.compareDWords = function Memory_readDWords(iAddress, aiDWords) {
  return this.compareValueArray(iAddress, 4, aiDWords);
};
Memory.prototype.writeDWord = function Memory_writeDWord(iAddress, iDWord) {
  return this.writeValue(iAddress, 4, iDWord);
};
Memory.prototype.writeDWords = function Memory_writeDWords(iAddress, aiDWords) {
  return this.writeValueArray(iAddress, 4, aiDWords);
};
// read/compare/write strings
Memory.prototype.readString = function Memory_readString(iAddress, iMaxLength) {
  var aiString = [];
  for (var iIndex = 0; typeof(iMaxLength) == "undefined" || iIndex < iMaxLength; iIndex++) {
    iByte = this.readByte(iAddress + iIndex);
    if (iByte == 0) break;
    aiString[iIndex] = iByte;
  }
  return String.fromCharCode.apply(0, aiString);
};
Memory.prototype.compareString = function Memory_comapreString(iAddress, sString) {
  for (var iIndex = 0; iIndex < sString.length; iIndex++) {
    iByte = this.readByte(iAddress + iIndex);
    if (iByte != sString.charCodeAt(iIndex)) {
      return false;
    }
  }
  return this.readByte(iAddress + iIndex) == 0;
};
Memory.prototype.writeString = function Memory_readString(iAddress, sString) {
  for (var iIndex = 0; iIndex < sString.length; iIndex++) {
    this.writeByte(iAddress + iIndex, sString.charCodeAt(iIndex));
  }
  this.writeByte(iAddress + iIndex, 0);
};
// read/compare/write unicode strings
Memory.prototype.readUnicode = function Memory_readUnicode(iAddress, iMaxLength) {
  var aiUnicode = [];
  for (var iIndex = 0; typeof(iMaxLength) == "undefined" || iIndex < iMaxLength; iIndex += 2) {
    iWord = this.readWord(iAddress + iIndex);
    if (iWord == 0) break;
    aiUnicode[iIndex] = iWord;
  }
  return String.fromCharCode.apply(0, aiUnicode);
};
Memory.prototype.compareUnicode = function Memory_comapreUnicode(iAddress, sString) {
  for (var iCharIndex = 0; iCharIndex < sString.length; iCharIndex++) {
    iWord = this.readWord(iAddress + iCharIndex * 2);
    if (iWord != sString.charCodeAt(iIndex)) {
      return false;
    }
  }
  return this.readWord(iAddress + iCharIndex * 2) == 0;
};
Memory.prototype.writeUnicode = function Memory_readString(iAddress, sString) {
  for (var iIndex = 0; iIndex < sString.length; iIndex += 2) {
    this.writeWord(iAddress + iIndex, sString.charCodeAt(iIndex));
  }
  this.writeWord(iAddress + iIndex, 0);
};
