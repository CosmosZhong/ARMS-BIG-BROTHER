#ifndef ASM_REFERENCE_SIMULATOR_HPP
#define ASM_REFERENCE_SIMULATOR_HPP

#include <tuple>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// Read a binary (hex format) from the given stream
// This always returns the full 2^32 values, even if there are fewer in the input binary
unordered_map<uint32_t, uint32_t> readMemoryBinary(istream &src, const uint32_t memInstructionStartIdx);

// Simulates the execution of a program on a MIPS processors.
// Input: Receives a vector that represents the initial memory.
// Output: Returns the final value inside register $v0 (register_v0).
uint32_t simulateMIPS(unordered_map<uint32_t, uint32_t> &memory, const uint32_t memInstructionStartIdx);

// Out[0] = d register address
// Out[1] = s register address
// Out[2] = t register address
// Out[3] = 5 bit constant (a)
tuple<uint32_t, uint32_t, uint32_t, uint32_t> decodeArithmeticType(uint32_t instruction);

// Out[0] = t register address
// Out[1] = s register address
// Out[2] = immediate value (i)
tuple<uint32_t, uint32_t, uint32_t> decodeImmediateType(uint32_t instruction);

// Extract byte from 4 byte word (unsigned)
// byteNr <= 3
uint32_t getByteFromWord(uint32_t word, uint32_t byteNr);

// Signed version of getByteFromWord
uint32_t getByteFromWordSigned(uint32_t word, uint32_t byteNr);

// Replace one byte inside a word and return the modified word
// byteNr <= 3
uint32_t replaceByteInWord(uint32_t word, uint32_t byte, uint32_t byteNr);

#endif
