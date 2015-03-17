#include <stdlib.h>

#define REG_BG0HOFS *(volatile unsigned short*) 0x4000010
#define REG_BG0VOFS *(volatile unsigned short*) 0x4000012
#define REG_BG1HOFS *(volatile unsigned short*) 0x4000014
#define REG_BG1VOFS *(volatile unsigned short*) 0x4000016
#define REG_BG2HOFS *(volatile unsigned short*) 0x4000018
#define REG_BG2VOFS *(volatile unsigned short*) 0x400001A
#define REG_BG3HOFS *(volatile unsigned short*) 0x400001C
#define REG_BG3VOFS *(volatile unsigned short*) 0x400001E

#define REG_BG0CNT *(volatile unsigned short*) 0x4000008
#define REG_BG1CNT *(volatile unsigned short*) 0x400000A
#define REG_BG2CNT *(volatile unsigned short*) 0x400000C
#define REG_BG3CNT *(volatile unsigned short*) 0x400000E
#define BG_COLOR256 0x80
#define CHAR_SHIFT 2
#define SCREEN_SHIFT 8
#define WRAPAROUND 0x1

#define BGPaletteMem ((unsigned short*)0x5000000)

#define TEXTBG_SIZE_256x256 0x0
#define TEXTBG_SIZE_256x512 0x8000
#define TEXTBG_SIZE_512x256 0x4000
#define TEXTBG_SIZE_512x512 0xC000

#define CharBaseBlock(n) (((n)*0x4000)+0x6000000)
#define ScreenBaseBlock(n) (((n)*0x800)+0x6000000)

#define REG_DISPCNT *(unsigned long*) 0x4000000
#define REG_DISPSTAT   *(volatile unsigned short*)0x4000004
#define MODE_0 0x0
#define BG2_TOGGLE 0x400
#define toggleBG2() REG_DISPCNT ^= BG2_TOGGLE
#define enableBG2() REG_DISPCNT |= BG2_TOGGLE
#define disableBG2() REG_DISPCNT &= ~BG2_TOGGLE

#define BG0_TOGGLE 0x100
#define toggleBG0() REG_DISPCNT ^= BG0_TOGGLE
#define enableBG0() REG_DISPCNT |= BG0_TOGGLE
#define disableBG0() REG_DISPCNT &= ~BG0_TOGGLE

#define BG1_TOGGLE 0x200
#define toggleBG1() REG_DISPCNT ^= BG1_TOGGLE
#define enableBG1() REG_DISPCNT |= BG1_TOGGLE
#define disableBG1() REG_DISPCNT &= ~BG1_TOGGLE

#define setMode(mode) REG_DISPCNT = (REG_DISPCNT & !(0x7) ) | (unsigned long)((mode) & (0x7))

#define frontBuffer ( (unsigned short*)0x6000000 )
#define backBuffer ( (unsigned short*)0x600A000 )
#define BACKBUFFER 0x10


typedef unsigned short u16;

u16 *videoBuffer = (u16*) 0x6000000;
u16 *paletteMem = (u16*)0x5000000;

volatile unsigned short *scanlineCounter = (volatile unsigned short*)0x4000006;


inline int xBoundsCheck(int x);
inline int yBoundsCheck(int y);

void waitVBlank(void){
    while (*scanlineCounter < 160){}
}

void drawPixel4(int x,int y,unsigned char color){
    u16 offset = (y*240 + x) >>1;
    u16 pixel = videoBuffer[offset];
    
    if (x & 1){
        videoBuffer[offset]=(color<<8) + (pixel & 0x00FF);
    }
    else{
        videoBuffer[offset] = (pixel & 0xFF00) + color;
    }
}

void pageFlip(void){
    if (REG_DISPCNT & BACKBUFFER){
        REG_DISPCNT &= ~BACKBUFFER;
        videoBuffer=backBuffer;
    }
    else{
        REG_DISPCNT |= BACKBUFFER;
        videoBuffer=frontBuffer;
    }
}

inline int xBoundsCheck(int x){
    return (x<0)?0:((x>239)?239:x);
}

inline int yBoundsCheck(int y){
    return (y<0)?0:((y>159)?159:y);
}
void drawImage4WithShorts(int x,int y,const unsigned short image[],int width,int height){
    int xi,yi;

    for (yi=y;yi<y+height;yi++){
        for (xi=x;xi<x+width;xi+=2){
            if (xi<240 && yi<160){
                //int xdiff=xi-x;
                //videoBuffer[(yi*240+x+xdiff*2)>>1]=image[(yi-y)*width+(xdiff)];
                unsigned char leftHalf,rightHalf;
                leftHalf= (unsigned char) image[(yi-y)*width+xi]>>8;
                rightHalf= (unsigned char) image[(yi-y)*width+xi]&0x00FF;
                drawPixel4(xi,yi,leftHalf);
                drawPixel4(xi+1,yi,rightHalf);
            }
        }
    }
}

void drawImage4(int x,int y,const unsigned char image[],int width,int height){
    int xi,yi;

    for (yi=y;yi<y+height;yi++){
        for (xi=x;xi<x+width;xi++){
            if (xi<240 && yi<160){
                drawPixel4(xi,yi,image[(yi-y)*width+(xi-x)]);
            }
        }
    }

}

void addToPalette(const u16 palette[256],int start,int end){
    end=(end<=256)?end:256;
    for (;start<end;start++){
        paletteMem[start]=palette[start];
    }
}


