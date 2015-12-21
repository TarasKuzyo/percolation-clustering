#ifndef __COLOR_TOOLS_H__
#define __COLOR_TOOLS_H__


/* number of possible colors */
#define COLOR_PAD (0xffffff + 1)    


#define SITE_BLOCK_COLOR 0xffffff
#define SITE_OPEN_COLOR  0xff0000
#define SITE_FULL_COLOR  0x0000ff


typedef struct {
    float r;
    float g;
    float b;        
} rgb;


rgb hex_to_rgb(int hex_val);
int str_to_hex(char *color, int *hex_val);
int generate_color(int number);


#endif /* __COLOR_TOOLS_H__ */


