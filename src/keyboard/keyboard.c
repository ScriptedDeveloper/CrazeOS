#define KBD_DATA_PORT 0x60
#define true 1
#define false 0
#define PIC1 0x20
#define PIC2 0xA200
#define ICW1 0x11
#define ICW4 0x01
#include "keyboard.h"
char* cInput;
const char upper_ascii_codes[255] = {
   0x00,  0x00,  '!',  '@', 
   '#',  '$',  '%',  '^',   
   '&',  '*',  '(',  ')',   
   '_',  '+',   0x00, '\t', 
   'Q',  'W',  'E',  'R',   
   'T',  'Y',  'U',  'I',   
   'O',  'P',  '{',  '}',   
   '\n', 0x00,  'A',  'S',  
   'D',  'F',  'G',  'H',   
   'J',  'K',  'L',  ':',   
   '"',  '~', 0x00,  '|',   
   'Z',  'X',  'C',  'V',   
   'B',  'N',  'M',  '<',   
   '>',  '?', 0x00,  '*',   
   0x00,  ' ', 0x00, 0x00,  
   0x00, 0x00, 0x00, 0x00,  
   0x00, 0x00, 0x00, 0x00,  
   0x00, 0x00, 0x00,  '7',  
   '8',  '9',  '-',  '4',   
   '5',  '6',  '+',  '1',   
   '2',  '3',  '0',  '.',   
   0x00, 0x00, 0x00, 0x00,  
   0x00, 0x00, 0x00, 0x00   
};

unsigned char inportb(unsigned int port){
   unsigned char ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}

void outportb(unsigned int port,unsigned char value){
   asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}

void init_pics(int pic1, int pic2){
   outportb(PIC1, ICW1);
   outportb(PIC2, ICW1);
   outportb(PIC1 + 1, pic1);   
   outportb(PIC2 + 1, pic2);   
   outportb(PIC1 + 1, 4);   
   outportb(PIC2 + 1, 2);
   outportb(PIC1 + 1, ICW4);
   outportb(PIC2 + 1, ICW4);
   outportb(PIC1 + 1, 0xFF);
}

char* keyboard_handler(bool input) {
	int c, i = 0;
   do{
      init_pics(0x20, 0x28);
		if(inportb(KBD_DATA_PORT) != c){
			c = inportb(KBD_DATA_PORT);
			if(c>0){
            if(c & 0x80){} else{
            if(input == true){
               if(upper_ascii_codes[c] == '\n'){
                  return cInput;
               }
               cInput[i] = upper_ascii_codes[c];
            }
            char *character = upper_ascii_codes[c]; // works!!!
            print(&character);
            i++;
         }
         }
      }
   }while(c != 1);
	return cInput;
}
