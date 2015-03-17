#include "mode0.h"
#include "DMA.h"
#include "Senary.raw.h"
#include "Senary.map.h"
#include "Senary.pal.h"
#include "button.h"

void copyColumn(unsigned short *source,int sourceStart,int sourceWidth,int sourceHeight,unsigned short *destination,int destStart,int destWidth,int destHeight);

int main(void){
    int i,buttons[10],nextRight,nextLeft,nextRightDestination,nextLeftDestination,goingRight;
    int mapWidth,mapHeight,tileWidth,tileHeight;
    int vSpeed=0;
    
    unsigned int x,y;
    x=0;
    y=0;
    i=0;
    goingRight=-1;
    
    unsigned short* bg0map = (unsigned short*)ScreenBaseBlock(31);
    unsigned short* bg1map = (unsigned short*)ScreenBaseBlock(16);
    
    
    REG_BG0CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 | (31 << SCREEN_SHIFT);
    REG_BG1CNT = BG_COLOR256 | TEXTBG_SIZE_256x256 | (16 << SCREEN_SHIFT);
    setMode(0);
    enableBG0();
    
    mapWidth=1200;
    mapHeight=256;
    tileWidth=80;
    tileHeight=72;
    
    DMAFastCopy((void*)Senary_Palette, (void*)BGPaletteMem,256, DMA_16NOW);
    
    DMAFastCopy((void*)Senary_Tiles,(void*)CharBaseBlock(0),5760/4,DMA_32NOW);
    
    for (i=0;i<30;i++){
        copyColumn(Senary_map,i,mapWidth/8,mapHeight/8,bg0map,i,256/8,256/8);
        copyColumn(Senary_Hit_map,i,mapWidth/8,mapHeight/8,bg1map,i,256/8,256/8);
    }
    
    nextLeft=mapWidth/8-1;
    nextRight=i;
    nextLeftDestination=31;
    nextRightDestination=30;
    copyColumn(Senary_map,nextLeft,mapWidth/8,mapHeight/8,bg0map,nextLeftDestination,256/8,256/8);
    
    while(1){
        pollButtons(buttons);
        
        if (checkPressed(buttons,BTN_RIGHT) /*&& !hitDetectionBackground(hitBoxes[0],bg1map,x+1,0)*/ ){
            x++;
        }
        else if (checkPressed(buttons,BTN_LEFT) /*&& (!hitDetectionBackground(hitBoxes[0],bg1map,x+1,0)*/ ){
            x--;
        }

        REG_BG0HOFS = x;
        REG_BG1HOFS = x;
        
        waitVBlank();
        if (x%8==1 && checkPressed(buttons,BTN_RIGHT)){
            copyColumn(Senary_map,nextRight,mapWidth/8,256/8,bg0map,nextRightDestination,256/8,256/8);
            copyColumn(Senary_Hit_map,nextRight,mapWidth/8,256/8,bg1map,nextRightDestination,256/8,256/8);
            nextRight++;
            nextRightDestination++;
            if (goingRight==0){
                nextRight++;
                nextRightDestination++;
            }
            
            if (nextRight>mapWidth/8-1){
                nextRight=0;
            }
            if (nextRightDestination>256/8-1){
                nextRightDestination=0;
            }
            nextLeft++;
            nextLeftDestination++;
            if (goingRight==0){
                nextLeft++;
                nextLeftDestination++;
            }
            if (nextLeft>mapWidth/8-1){
                nextLeft=0;
            }
            if (nextLeftDestination>256/8-1){
                nextLeftDestination=0;
            }

            goingRight=1;
        }
        else if (x%8==7 && checkPressed(buttons,BTN_LEFT)){
            copyColumn(Senary_map,nextLeft,mapWidth/8,mapHeight/8,bg0map,nextLeftDestination,256/8,256/8);
            copyColumn(Senary_Hit_map,nextLeft,mapWidth/8,mapHeight/8,bg1map,nextLeftDestination,256/8,256/8);
            nextLeft--;
            nextLeftDestination--;
            
            if (goingRight==1){
                nextLeft--;
                nextLeftDestination--;
            }
            
            
            if (nextLeft<0){
                nextLeft=mapWidth/8-1;
            }
            if (nextLeftDestination<0){
                nextLeftDestination=256/8-1;
            }

            nextRight--;
            nextRightDestination--;
            
            if (goingRight==1){
                nextRight--;
                nextRightDestination--;
            }
            
            if (nextRight<0){
                nextRight=mapWidth/8-1;
            }
            if (nextRightDestination<0){
                nextRightDestination=256/8-1;
            }
            
            goingRight=0;
        }
        
        for (i=0;i<4000;i++);

    }

    return 0;
}

void copyColumn(unsigned short *source,int sourceStart,int sourceWidth,int sourceHeight,unsigned short *destination,int destStart,int destWidth,int destHeight){
    int y;
    
    for(y = 0; y < sourceHeight; y++){
        destination[y*destWidth+destStart]=source[y*sourceWidth+sourceStart];
    }
}
