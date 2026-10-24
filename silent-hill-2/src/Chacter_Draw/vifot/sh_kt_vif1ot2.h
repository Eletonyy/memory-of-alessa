#ifndef SH_KT_VIF1OT2_H
#define SH_KT_VIF1OT2_H

typedef struct _sceDmaTag {
    u_short qwc;             // transfer count
    u_char mark;             // mark
    u_char id;               // tag
    struct _sceDmaTag* next; // next tag
    u_int p[2];              // padding
} sceDmaTag __attribute__((aligned(16)));

typedef struct {
    sceDmaTag* top_1; // offset 0x0, size 0x4
    sceDmaTag* top_2; // offset 0x4, size 0x4
    u_int n_bits_1; // offset 0x8, size 0x4
    u_int n_bits_2; // offset 0xC, size 0x4
    u_int length_1; // offset 0x10, size 0x4
    u_int length_2; // offset 0x14, size 0x4
    u_int mask_1; // offset 0x18, size 0x4
    u_int mask_2; // offset 0x1C, size 0x4
} ktVif1Ot2;


void ktVif1Ot2Init(ktVif1Ot2* ot, u_int n_bits_1, sceDmaTag* top_1, u_int n_bits_2, sceDmaTag* top_2);
void ktVif1Ot2Reset(ktVif1Ot2* ot);
void ktVif1Ot2Append(ktVif1Ot2* ot, u_int depth, u_long128* packet_);
void ktVif1Ot2AppendFake(ktVif1Ot2* ot, u_int depth, u_long128* packet_, void* entity_);

static void Init2ndOT(ktVif1Ot2* ot);
static void Make2ndOT(ktVif1Ot2* ot);
static void Sort2(sceDmaTag* top_2, sceDmaTag* p);
static void SetNext(sceDmaTag* tag, sceDmaTag* p);
static sceDmaTag* Next(sceDmaTag* tag);
static u_int Depth2(sceDmaTag* tag);
static sceDmaTag* Link(sceDmaTag* tag);

void ktVif1Ot2KickPre(ktVif1Ot2* ot);

UNMIGRATED (/* static */ sceDmaTag term); // size: 0x10, address: 0x2A94A0
#endif // SH_KT_VIF1OT2_H
