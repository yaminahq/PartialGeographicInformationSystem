//Yaminah Qureshi
//qureshiy

/**
 *  \file Seq2D.h
 *  \brief Represents a map
 */

#ifndef SEQ2D_H
#define SEQ2D_H

#include <vector>
#include <set>
#include "PathADT.h"
#include "Exceptions.h"

/**
 *  \brief Class representing a 2D map
 *  \details comprised by a several points that have values
 */
template <class T>
class Seq2DT
{
  private:
    // A sequence of sequences of a type, used to represent the rows and columns of a grid
    std::vector<std::vector<T>> s;
    // the map conversion factor
    float scale;
    // the number of rows in the grid
    int nRow;
    //the number of coloumns in the grid
    int nCol;

/**
 *  \brief Returns if a row is within the grid bounds
 *  \param i the row to be checked for validity
 *  \return true if the row is within the map bounds
 */
    bool validRow(int i);

/**
 *  \brief Returns if a column is within the grid bounds
 *  \param j the column to be checked for validity
 *  \return true if the column is within the map bounds
 */
    bool validCol(int j);

/**
 *  \brief Returns if a point is within the grid bounds
 *  \param p the point to be checked for validity
 *  \return true if the point is within the map bounds
 */
    bool validPoint(PointT p);

/**
 *  \brief Returns whether a line is within the grid bounds
 *  \param l the line to be checked for validity
 *  \return true if the line is within the map bounds
 */
    bool validLine(LineT l);

/**
 *  \brief Returns if a path is within the grid bounds
 *  \param pth the path to be checked for validity
 *  \return true if the path is within the map bounds
 */
    bool validPath(PathT pth);

/**
 *  \brief Returns the set of points in a line
 *  \param l the line of which the points are found
 *  \return a set of points
 */
    std::vector<PointT> pointsInLine(LineT l);

/**
 *  \brief Returns the set of points in a path
 *  \param pth the path of which the points are found
 *  \return a set of points
 */
    std::vector<PointT> pointsInPath(PathT pth);

/**
 *  \brief Returns whether a point is contained in a set of points
 *  \param points the set of points that are searched
 *  \param p the point that is searched for
 *  \return true if the point is in the set of points
 */
    bool contains(std::vector<PointT> points, PointT p);



  public:
/**
 *  \brief Constructs a Seq2D object to represent a map
 *  \param S the sequence of sequences of elements, representing the cells of the grid
 *  \param scl the conversion factor for the map
 *  \return a Seq2D object representing a map
 */
    Seq2DT(std::vector<std::vector<T>> S, float scl);

/**
 *  \brief Modifies the value of a point in the map
 *  \param p the point to be modified
 *  \param v the value the point is modified to
 */
    void set(PointT p, T v);

/**
 *  \brief Returns the value of a point on the map
 *  \param p the point of which the value is found
 *  \return the value of the point
 */
    T get(PointT p);

/**
 *  \brief Returns the number of rows in the map
 *  \return an integer representing the number of rows in the map
 */
    int getNumRow();

/**
 *  \brief Returns the number of columns in the map
 *  \return an integer representing the number of columns in the map
 */
    int getNumCol();

/**
 *  \brief Returns the conversion factor of the map
 *  \return an integer representing the scale of the map
 */
    float getScale();

/**
 *  \brief Finds the number of occurences of a value on the map
 *  \param t the value to be found
 *  \return an integer representing the number of times a value occurs on the map
 */
    int count(T t);

/**
 *  \brief Finds the number of occurences of a value in a line
 *  \param l the line to be searched
 *  \param t the value to be found
 *  \return an integer representing the number of times a value occurs in the line
 */
    int count(LineT l, T t);

/**
 *  \brief Finds the number of occurences of a value on a path
 *  \param pth the path to be searched
 *  \param t the value to be found
 *  \return an integer representing the number of times a value occurs on the path
 */
    int count(PathT pth, T t);

/**
 *  \brief Finds the length of a path
 *  \details Finds the number of points comprising the path
 *  \param pth the path for which the length is found
 *  \return an integer representing the length of the path
 */
    float length(PathT pth);

/**
 *  \brief Determines if two points are connected on the map
 *  \details The points are connected if there is a path of a unique value connected the points
 *  \param p1 the starting point of the path
 *  \param p1 the end point of the path
 *  \return true if the two points are connected by the path
 */
    bool connected(PointT p1, PointT p2);

};

#endif