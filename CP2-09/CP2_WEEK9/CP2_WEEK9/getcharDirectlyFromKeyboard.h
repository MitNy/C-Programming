//
//  getcharDirectlyFromKeyboard.h
//  CP2_WEEK9
//
//  Created by stu2017s10 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef getcharDirectlyFromKeyboard_h
#define getcharDirectlyFromKeyboard_h

#include <unistd.h>
#include <termios.h>

char getcharDirectlyFromKeyboard(void) {
    struct termios oldAttr;
    struct termios newAttr;
    char charFromKeyboard;
    
    fpurge(stdin);  // stdin buffer를 비운다
    tcgetattr( STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    charFromKeyboard = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    
    return charFromKeyboard;
    
}


#endif /* getcharDirectlyFromKeyboard_h */
