/**********************************************\
*       character.h                                   *
*          by dovotos pcx->gba program         *
/**********************************************/
#define  character_WIDTH   56
#define  character_HEIGHT  16


const unsigned short characterData[56*16] = {
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0706, 0x0607, 0x0000, 0x0600, 0x0606,
                    0x0606, 0x0006, 0x0300, 0x0904, 0x0604, 0x0006, 0x0300, 0x0905, 0x0405, 0x0006,
                    0x0300, 0x0505, 0x0505, 0x0006, 0x0000, 0x0C03, 0x030C, 0x0006, 0x0C00, 0x0D0C,
                    0x0C0D, 0x000C, 0x0C00, 0x0E0D, 0x050E, 0x0003, 0x0C00, 0x030E, 0x0505, 0x0003,
                    0x0000, 0x0E0D, 0x0303, 0x000D, 0x0000, 0x0D0D, 0x0E0E, 0x000D, 0x0000, 0x0C00,
                    0x0C0D, 0x0000, 0x0000, 0x0C00, 0x0C0D, 0x0000, 0x0000, 0x0100, 0x0102, 0x0000,
                    0x0000, 0x0201, 0x0102, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0706,
                    0x0607, 0x0000, 0x0600, 0x0606, 0x0606, 0x0006, 0x0300, 0x0904, 0x0604, 0x0006,
                    0x0300, 0x0905, 0x0405, 0x0006, 0x0300, 0x0505, 0x0505, 0x0006, 0x0000, 0x0C03,
                    0x030C, 0x0006, 0x0C00, 0x0D0C, 0x0C0D, 0x000C, 0x0C00, 0x0E0D, 0x050E, 0x0003,
                    0x0C00, 0x0E0E, 0x0E0E, 0x0305, 0x0000, 0x0E0D, 0x0503, 0x0003, 0x0100, 0x0C0D,
                    0x030E, 0x000D, 0x0201, 0x0D01, 0x0D0D, 0x000C, 0x0201, 0x0C02, 0x0D0C, 0x000C,
                    0x0100, 0x0001, 0x0201, 0x0001, 0x0000, 0x0100, 0x0202, 0x0001, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0706, 0x0607, 0x0000, 0x0600, 0x0606, 0x0606, 0x0006,
                    0x0300, 0x0904, 0x0604, 0x0006, 0x0300, 0x0905, 0x0405, 0x0006, 0x0300, 0x0505,
                    0x0505, 0x0006, 0x0000, 0x0C03, 0x030C, 0x0006, 0x0C00, 0x0D0C, 0x0C0D, 0x000C,
                    0x0C00, 0x0503, 0x050E, 0x0003, 0x0C00, 0x030E, 0x0305, 0x000D, 0x0000, 0x0E0D,
                    0x0E03, 0x000D, 0x0100, 0x0D0D, 0x0E0E, 0x000D, 0x0201, 0x0C01, 0x0D0D, 0x000C,
                    0x0201, 0x0D02, 0x0C0C, 0x0C0D, 0x0100, 0x0C01, 0x0100, 0x0102, 0x0000, 0x0000,
                    0x0201, 0x0102, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0C00, 0x000C, 0x0000, 0x0000, 0x0D0C,
                    0x0C0D, 0x0000, 0x0C00, 0x0E0D, 0x0E0E, 0x0001, 0x0503, 0x0E05, 0x0D0E, 0x0002,
                    0x0503, 0x0E0D, 0x0E0E, 0x0002, 0x0300, 0x0D0E, 0x0E0D, 0x000D, 0x0000, 0x0E0D,
                    0x0D0E, 0x0000, 0x0000, 0x0D00, 0x000D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000C,
                    0x0000, 0x0000, 0x0C00, 0x0C0D, 0x010E, 0x0001, 0x0C00, 0x0E0D, 0x020D, 0x0D02,
                    0x0D00, 0x0E0E, 0x0E0E, 0x000D, 0x0C00, 0x0E05, 0x0D0E, 0x000E, 0x0503, 0x0D05,
                    0x0E0D, 0x000D, 0x0300, 0x0E03, 0x0E0D, 0x000D, 0x0000, 0x0000, 0x0D00, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0201, 0x0D02, 0x0000,
                    0x0C00, 0x0D0E, 0x0E0E, 0x000D, 0x0D0C, 0x0E0E, 0x0D0E, 0x0D0E, 0x0D0C, 0x0E0E,
                    0x0D0E, 0x0D0E, 0x0C00, 0x050D, 0x0E0D, 0x000D, 0x0000, 0x050C, 0x0305, 0x0000,
                    0x0000, 0x0300, 0x0003, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000D, 0x0000, 0x0000,
                    0x0100, 0x0D02, 0x0D0E, 0x000D, 0x0100, 0x0E02, 0x0E0D, 0x0D0E, 0x0E00, 0x0E0D,
                    0x0D0E, 0x000D, 0x0C00, 0x0E0E, 0x0D0E, 0x000E, 0x0D0C, 0x0E0D, 0x0505, 0x0003,
                    0x0C00, 0x0D0C, 0x050C, 0x0003, 0x0000, 0x0000, 0x0300, 0x0000,};

const unsigned short characterPalette[256] = {
                    0x7E40, 0x0004, 0x000A, 0x190C, 0x2592, 0x29D5, 0x0298, 0x02DA, 0x7FFF, 0x0000,
                    0x1801, 0x3003, 0x4C05, 0x6406, 0x7C09, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,};