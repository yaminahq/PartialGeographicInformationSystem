//Yaminah Qureshi
//qureshiy

/**
 *  \file LineADT.h
 *  \brief Generates an abstract data type for representing lines
 */


#ifndef LINEADT_H
#define LINEADT_H

#include "PointADT.h"
#include "MapTypes.h"
#include "Exceptions.h"

/**
 *  \brief Class representing a line in a 2D plane
 */
class LineT
{
  private:
    // the first point of the line
    PointT s;
    // the orientatoin of the line
    CompassT o;
    // the length of the line
    int L;

  public:
/**
 *  \brief Constructs a new line object
 *  \param st The starting point of the line
 *  \param ornt The orientation of the line
 *  \param l The lengthof the line
 *  \return The line object
 */
    LineT(PointT st, CompassT ornt, int l);

/**
 *  \brief Returns the first point of the line
 *  \return The starting point of the line
 */
    PointT strt();

/**
 *  \brief Returns the last point of the line
 *  \return The ending point of the line
 */
    PointT end();

/**
 *  \brief Returns the orientation of the line
 *  \return The direction the line is in
 */    
    CompassT orient();

/**
 *  \brief Returns the length of the line
 *  \return an integer representing the number of points comprising the line
 */
    int len();

/**
 *  \brief Flips a line
 *  \return a new line with its orientation changed by 180 degrees
 */
    LineT flip();

/**
 *  \brief Rotates a line
 *  \return a new line with its orientation changed by 90 degrees
 */
    LineT rotate(RotateT r);

/**
 *  \brief Shifts a line
 *  \param deltaX the shift in the x-direction
 *  \param deltaY the shift in the y-direction
 *  \return a new line shifted in some direction
 */
    LineT translate(int deltaX, int deltaY);
};

#endif