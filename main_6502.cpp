#include<iostream>
#include<stdio.h>
#include<stdlib.h>


using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

using namespace std;

struct Mem {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise() {
        for (u32 i=0; i<MAX_MEM; i++) {
            Data[i] = 0;
        }
    }
    // Read 1 byte
    Byte operator[](u32 Address) const {
        return Data[Address];
    }
    // Write 1 byte
    Byte& operator[](u32 Address) {
        return Data[Address];
    }
};

struct CPU {
   
    Word PC; // Program Counter
    Word SP; // Stack Pointer

    Byte A, X, Y; // Registers

    // Status Flags
    Byte C: 1;
    Byte Z: 1;
    Byte I: 1;
    Byte D: 1;
    Byte B: 1;
    Byte V: 1;
    Byte N: 1;

    void Reset(Mem& memory) {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialise();

    }

    Byte FetchByte(u32& Cycles, Mem& memory) {
        Byte Data = memory[PC];
        PC++;
        Cycles--;
        return Data;
    }

    Byte ReadByte(u32& Cycles, Byte Address, Mem& memory) {
        Byte Data = memory[Address];
        Cycles--;
        return Data;
    }

    static constexpr Byte
        INS_LDA_IM = 0xA9,
        INS_LDA_ZP = 0xA5;

    void LDASetStatus() {
        Z = (A==0);
        N = (A & 0b10000000) > 0;
    }

    void Execute(u32 Cycles, Mem& memory) {
        while(Cycles>0) {
            Byte Ins = FetchByte(Cycles, memory);
            switch (Ins) {
                case INS_LDA_IM:
                {
                    Byte Value = FetchByte(Cycles, memory);
                    A = Value;
                    LDASetStatus();
                } break;
                case INS_LDA_ZP:
                {
                    Byte ZeroPageAddress = 
                        FetchByte(Cycles,memory);
                    A = ReadByte(Cycles,ZeroPageAddress,memory);
                    LDASetStatus();
                }break;
                default:
                {
                    cout << "Instruction " << Ins << " not handled" << endl;
                }break;
            }
        }
    }

};

int main() {

    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    mem[0xFFFC] = CPU::INS_LDA_ZP;
    mem[0xFFFD] = 0x42;
    mem[0x0042] = 0x84;
    cpu.Execute(3, mem);
    return 0;

}