#ifndef CONTROLLER_H
#define CONTROLLER_H

/* 
Lower 
ex  1010 1111	BUTTONA | BUTTONB
ex  1110 1111	BUTTONA
bx  1011 1111 	BUTTONB
Xc  1111 1100	LEFT | UP
Xd  1111 1101	LEFT
Xe  1111 1110  	UP


upper
xb  1111 1011   START

2x  0010 1111   SEL |DN | R
3x  0011 1111   DN  | R
6x  0110 1111   SEL | R
7x  0111 1111   R
Ax  1010 1111   SEL | DN
Ax  1011 1111   DN
Ex  1110 1111   SEL


15 14  13 12  11 10    9  8    7  6  5  4  3  2  1  0
R  D   _  SEL _  START _  _    _  B  _  A  _  _  L  U
 
 */

enum Controller_State {
  UP        = (1 << 0), 
  DOWN      = (1 << 1), 
  LEFT      = (1 << 2), 
  RIGHT     = (1 << 3), 
  SELECT    = (1 << 4), 
  START     = (1 << 5), 
  BUTTONB   = (1 << 6), 
  BUTTONA   = (1 << 7) 
};


enum Signal_Pos {
  S_UP        = (1 << 0), 
  S_LEFT      = (1 << 1), 
  S_BUTTONA   = (1 << 4), 
  S_BUTTONB   = (1 << 6),  
  S_DOWN      = (1 << 14), 
  S_RIGHT     = (1 << 15), 
  S_SELECT    = (1 << 12), 
  S_START     = (1 << 10), 
};



void controller_id(uint8_t id[6]);
int16_t controller_state_raw(void);
uint8_t controller_state(void);
void controller_disable_encryption(void);
void controller_init(void);

#endif