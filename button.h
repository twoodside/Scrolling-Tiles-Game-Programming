#define REG_BUTTON (volatile unsigned short*)0x4000130
#define BTN_A 0x0
#define BTN_B 0x1
#define BTN_SELECT 0x2
#define BTN_START 0x4
#define BTN_RIGHT 0x8
#define BTN_LEFT 0x10
#define BTN_DOWN 0x20
#define BTN_UP 0x40
#define BTN_R 0x80
#define BTN_L 0x100



void pollButtons(int buttons[10]){
    int i;
    for (i=0;i<10;i++){
        int btnval=!((*REG_BUTTON) & (1 << i))*(buttons[i]+1);
        buttons[i]=btnval; //Gonna have to play around with this, but this should indicate time pressed.
    }
}

int checkPressed(int buttons[10],int button){
    switch (button){
        case BTN_A:
            return buttons[0];
        case BTN_B:
            return buttons[1];
        case BTN_SELECT:
            return buttons[2];
        case BTN_START:
            return buttons[3];
        case BTN_RIGHT:
            return buttons[4];
        case BTN_LEFT:
            return buttons[5];
        case BTN_UP:
            return buttons[6];
        case BTN_DOWN:
            return buttons[7];
        case BTN_R:
            return buttons[8];
        case BTN_L:
            return buttons[9];
        default:
            return 0;
    }
}

void setButtonState(int buttons[10],int button,int state){
    int i;
    switch (button){
        case BTN_A:
            i=0;
            break;
        case BTN_B:
            i=1;
            break;
        case BTN_SELECT:
            i=2;
            break;
        case BTN_START:
            i=3;
            break;
        case BTN_RIGHT:
            i=4;
            break;
        case BTN_LEFT:
            i=5;
            break;
        case BTN_UP:
            i=6;
            break;
        case BTN_DOWN:
            i=7;
            break;
        case BTN_R:
            i=8;
            break;
        case BTN_L:
            i=9;
            break;
        default:
            return;
    }
    buttons[i]=state;
}
