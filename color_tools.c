#include <stdio.h>
#include "color_tools.h"


/* converts hex value to rgb struct
 */
rgb hex_to_rgb(int hex_val)
{
    rgb color;
    color.r = ((hex_val >> 16) & 0xff) / 255.0;
    color.g = ((hex_val >> 8 ) & 0xff) / 255.0;
    color.b = ((hex_val      ) & 0xff) / 255.0;

    return color;
}


/* converts rgb struct to hex value 
 */
int rgb_to_hex(rgb color)
{   
    return (( (int)(color.r * 255) & 0xff ) << 16) + 
           (( (int)(color.g * 255) & 0xff ) << 8 ) + 
            ( (int)(color.b * 255) & 0xff );
}


/* converts color string of form "#rrggbb"
   to its hex value
 */
int str_to_hex(char *str, int *hex)
{
    return (str[0] == '#') ? sscanf(str + 1, "%x", hex) : 0;
}



int generate_color(int key)
{
    key = ~key + (key << 15); // key = (key << 15) - key - 1;
    key =  key ^ (key >> 12);
    key =  key + (key << 2);
    key =  key ^ (key >> 4);
    key =  key * 2057; // key = (key + (key << 3)) + (key << 11);
    key =  key ^ (key >> 16);
    
    return key % COLOR_PAD;
}


