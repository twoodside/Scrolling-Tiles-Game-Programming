#define REG_DISPCNT *(unsigned long*) 0x4000000
#define REG_DISPSTAT   *(volatile unsigned short*)0x4000004
#define MODE_3 0x3
#define BG2_TOGGLE 0x400
#define setMode(mode) REG_DISPCNT = (REG_DISPCNT & !(0x7) ) | (unsigned long)((mode) & (0x7))
#define toggleBG2() REG_DISPCNT ^= BG2_TOGGLE
#define enableBG2() REG_DISPCNT |= BG2_TOGGLE
#define disableBG2() REG_DISPCNT &= ~BG2_TOGGLE
#define RGB(r,g,b) (unsigned short)((r)+((g)<<5)+((b)<<10))

typedef unsigned short u16;

u16 *videoBuffer = (u16*) 0x6000000;

inline int xBoundsCheck(int x);
inline int yBoundsCheck(int y);

inline void drawPixel3(int x,int y,u16 color){
    videoBuffer[yBoundsCheck(y)*240+xBoundsCheck(x)]=color;
}

inline int xBoundsCheck(int x){
    return (x<0)?0:((x>239)?239:x);
}

inline int yBoundsCheck(int y){
    return (y<0)?0:((y>159)?159:y);
}

inline u16 getPixelColor3(int x,int y){
    return videoBuffer[yBoundsCheck(y)*240+xBoundsCheck(x)];
}

u16 alphaColor(u16 cfront,u16 cback,int alpha){
    int rf,gf,bf,rb,gb,bb,ra,ga,ba;
    
    alpha=(alpha>256)?256:((alpha<0)?0:alpha);
    
    rf=cfront & 31;
    rb=cback & 31;
    gf=cfront & (0x3e0);
    gb=cback & (0x3e0);
    bf=cfront & (0x7c00);
    bb=cback & (0x7c00);

    gf = gf >> 5;
    gb = gb >> 5;
    bf = bf >> 10;
    bb = bb >> 10;
    
    /*
    average = front*alpha/maxalpha + back * (1-alpha/maxalpha)
    average = front*alpha/maxalpha + back - back*alpha/maxalpha
    average = (front-back)*alpha/maxalpha + back
    */
    
    ra=(rf-rb)*alpha/256+rb;
    ga=(gf-gb)*alpha/256+gb;
    ba=(bf-bb)*alpha/256+bb;
    
    return RGB(ra,ga,ba);
}


void drawLine3(int x1, int y1, int x2, int y2, unsigned short color){
	int i, deltax, deltay, numpixels;
	int d, dinc1, dinc2;
	int x, xinc1, xinc2;
	int y, yinc1, yinc2;
	//calculate deltaX and deltaY
	deltax = abs(x2 - x1);
	deltay = abs(y2 - y1);
	//initialize
	if(deltax >= deltay)
	{
		//If x is independent variable
		numpixels = deltax + 1;
		d = (2 * deltay) - deltax;
		dinc1 = deltay << 1;
		dinc2 = (deltay - deltax) << 1;
		xinc1 = 1;
		xinc2 = 1;
		yinc1 = 0;
		yinc2 = 1;
	}
	else
	{
		//if y is independant variable
		numpixels = deltay + 1;
		d = (2 * deltax) - deltay;
		dinc1 = deltax << 1;
		dinc2 = (deltax - deltay) << 1;
		xinc1 = 0;
		xinc2 = 1;
		yinc1 = 1;
		yinc2 = 1;
	}
    //move the right direction
	if(x1 > x2)
	{
		xinc1 = -xinc1;
		xinc2 = -xinc2;
	}
	if(y1 > y2)
	{
		yinc1 = -yinc1;
		yinc2 = -yinc2;
	}
	x = x1;
	y = y1;
	//draw the pixels
	for(i = 1; i < numpixels; i++)
	{
		drawPixel3(x, y, color);
		if(d < 0)
		{
		    d = d + dinc1;
		    x = x + xinc1;
		    y = y + yinc1;
		}
		else
		{
		    d = d + dinc2;
		    x = x + xinc2;
		    y = y + yinc2;
		}
	}
}

void drawCircle3(int xCenter, int yCenter, int radius, unsigned short color){
	int x = 0;
	int y = radius;
	int p = 3 - 2 * radius;
	while (x <= y)
	{
		drawPixel3(xCenter + x, yCenter + y, color);
		drawPixel3(xCenter - x, yCenter + y, color);
		drawPixel3(xCenter + x, yCenter - y, color);
		drawPixel3(xCenter - x, yCenter - y, color);
		drawPixel3(xCenter + y, yCenter + x, color);
		drawPixel3(xCenter - y, yCenter + x, color);
		drawPixel3(xCenter + y, yCenter - x, color);
		drawPixel3(xCenter - y, yCenter - x, color);
		if (p < 0)
			p += 4 * x++ + 6;
		else
			p += 4 * (x++ - y--) + 10;
	}
}


void drawBox3(int left, int top, int right, int bottom, unsigned short color){
    int x, y;
    for(y = top; y < bottom; y++)
        for(x = left; x < right; x++)
            drawPixel3(x, y, color);
}


inline void waitVBlank(void){
    while (REG_DISPSTAT & 1);
}
