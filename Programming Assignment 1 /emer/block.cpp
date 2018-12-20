#include "block.h"
#include <vector>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"



// PA1 functions
// for block


/**
 * returns current block's width
 *
 * @param none
 */

int Block::width() const{
    return data.size();
}

/**
 * returns current block's height
 *
 * @param none
 */

int Block::height() const{
    return data[0].size();
}

/**
 * From im, grabs the vertical strip of pixels whose upper left corner is at position (column,0) and
 * whose width is width.
 *
 * @param Address of PNG in heap, int column and int width of png
 */

void Block::build(PNG &im, int column, int width){
    for (unsigned int i = column; i < ((unsigned int) column + width); i++) {
        vector<HSLAPixel> row;
        for (unsigned int j = 0; j < im.height(); j++) {
            HSLAPixel* p = im.getPixel(i,j);
            row.push_back(*p);
        }
        data.push_back(row);
    }
}

/**
 * Draws the current block at position (column,0) in im.
 *
 * @param Address of PNG in heap, int column and int width of png
 */
void Block::render(PNG &im, int column) const{
    for (unsigned int i = 0; i < ((unsigned int) width()); i++) {
        for (unsigned int j = 0; j < im.height(); j++) {
            HSLAPixel* p = im.getPixel(((((unsigned int) column)) + i), j);
            *p = data[i][j]; 
        }
    }
}

/**
 * This function changes the saturation of every pixel in the block to 0, which removes the color,
 * leaving grey.
 *
 * @param none
 */

void Block::greyscale(){
    for (unsigned int i = 0; i < ((unsigned int)width()); i++) {
        for (unsigned int j = 0; j < ((unsigned int)height()); j++) {
            data[i][j].s = 0;
        }
    }
}
