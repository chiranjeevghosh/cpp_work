#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<array>

using Byte = unsigned char;    // 1B
using Word = unsigned short;   // 2B
using u32  = unsigned int;     // 4B

using namespace std;

class Memory {
    public:
        static const u32 MAX_MEM = 1024*64; // 64 KiB memory
        Byte Data[MAX_MEM];
        // Initialize memory to 0
        void Initialize() {
            for (u32 i=0; i<MAX_MEM; i++)
                Data[i] = 0;
        }

        // Operator [] overloading to read 1 Byte from a location
        Byte operator[](u32 Address) const{
            return Data[Address];
        }

        // Operator [] overloading to write 1 Byte to a location
        Byte& operator[](u32 Address) {
            return Data[Address];
        }
        
};

class CPU {
    public:
        Word PC; // Program Counter
        Byte Ra, Rb, Rc; // Registers
        array<Byte,10> Reg;


        void Reset(Memory& Mem) {
            PC = 0xFFFA;
            Ra = Rb = Rc = 0;
            Mem.Initialize();

        }

        static const Byte   
            ADD = 0,
            SUB = 1,
            MUL = 2,
            DIV = 3,
            LD  = 4,
            ST  = 5;

        // CPU Pipeline Stages
        Byte Fetch(u32& Cycles, Memory& Mem) { // Instruction Fetch
            Byte Instr = Mem[PC];
            PC++;
            Cycles++;
            return Instr;
        }
        Byte Decode(u32& Cycles, Byte I, Byte& Ra, Byte& Rb) { // Instruction Decode + Register Fetch
            Byte OP = (Byte)((int)(I & 0b11100000)>>5);
            switch(OP) {
                case ADD:
                {
                    Ra = Reg[((int)(I & 0b00011000)>>3)];
                    Rb = Reg[((int)(I & 0b00000110)>>1)];
                } break;
                case SUB:
                {
                    Ra = Reg[((int)(I & 0b00011000)>>3)];
                    Rb = Reg[((int)(I & 0b00000110)>>1)];
                } break;
                case LD:
                {
                    Ra = (Byte)((int)(I & 0b00011000)>>3);
                    Rb = (Byte)((int)(I & 0b00000111));
                } break;
                case ST:
                {
                    Ra = Reg[((int)(I & 0b00011000)>>3)];
                    Rb = (Byte)((int)(I & 0b00000111));
                } break;
                default:
                {
                    cout << "Unrecognized Operation" << endl;
                } break;
            }
            Cycles++;
            return OP;
        }
        void Execute(u32& Cycles, Byte OP, Memory& Mem) { // ALU OR Address calculation -> MEM stage in case of LD/ST included
            switch(OP) {
                case ADD:
                {
                    cout << "Operation: ADD" << endl;
                    cout << "Val at Ra: " << hex << (int)Ra << endl;
                    cout << "Val at Rb: " << hex << (int)Rb << endl;
                    Cycles++;
                    WriteBack(Cycles, (Byte)((int)Ra + (int)Rb));

                } break;
                case SUB:
                {
                    cout << "Operation: SUB" << endl;
                    cout << "Val at Ra: " << hex << (int)Ra << endl;
                    cout << "Val at Rb: " << hex << (int)Rb << endl;
                    Cycles++;
                    WriteBack(Cycles, (Byte)((int)Rb - (int)Ra));

                } break;
                case LD:
                {
                    cout << "Operation: LOAD" << endl;
                    cout << "Val at Ra: " << hex << (int)Ra << endl;
                    cout << "Val at Rb: " << hex << (int)Rb << endl;
                    Cycles++;
                    MEM(Cycles, 0, Mem);
                } break;
                case ST:
                {
                    cout << "Operation: STORE" << endl;
                    cout << "Val at Ra: " << hex << (int)Ra << endl;
                    cout << "Val at Rb: " << hex << (int)Rb << endl;
                    Cycles++;
                    MEM(Cycles, 1, Mem);
                } break;
                default:
                {
                    cout << "Unrecognized Operation" << endl;
                } break;
                
            }
        }
        void WriteBack(u32& Cycles, Byte val) { // Write val to register
            Rc = val;
            cout << "Writing back " << hex << (int)Rc << " to reg Rc" << endl;
            Cycles++;
            
        }
        void MEM(u32& Cycles, int rw, Memory& Mem) {
            switch(rw) {
                case 0: // LOAD
                {
                    Reg[(int)Ra] = Mem[Rb];
                } break;
                case 1: // STORE
                {
                    Mem[Rb] = Ra;
                } break;
            }
            Cycles = Cycles + 100;

        }
        void Run(u32& Cycles, Memory& Mem) {
            Byte Inst = Fetch(Cycles, Mem);
            Byte OP = Decode(Cycles, Inst, Ra, Rb);
            Execute(Cycles, OP, Mem);
            
            
        }

};

int main() {
    Memory MEM;
    CPU cpu;
    cpu.Reset(MEM);
    u32 Cycles = 0;

    // TODO: Load Memory with program
    MEM[0xFFFA] = 0x02; // 0000 0010 -> Add R0 and R1
    cpu.Reg[0] = 0x49;
    cpu.Reg[1] = 0x5A;
    cpu.Run(Cycles, MEM);
    cpu.Reg[2] = cpu.Rc;
    MEM[0xFFFB] = 0xB5; // 1011 0101 -> Store R2 -> Addr 0x5


    /*for (u32 i=901; i<909; i++)
        MEM[i] = rand()%(MEM.MAX_MEM);

    for (u32 i=901; i<909; i++)
        cout << "MEM[" << i << "]: " << hex << (int)MEM[i] << endl;*/
    
    cpu.Run(Cycles, MEM);
    MEM[0xFFFC] = 0x22; // 0010 0010 -> Sub R1 - R0
    cpu.Run(Cycles, MEM);
    cpu.Reg[3] = cpu.Rc;
    MEM[0xFFFD] = 0x85; // 1000 0101 -> Load R0 <- Addr 0x5
    cpu.Run(Cycles, MEM);
    cout << "Val at reg0 " << hex << (int)cpu.Reg[0] << endl;
    cout << "Total cycles: " << dec << Cycles << endl;
    


    return 0;
}