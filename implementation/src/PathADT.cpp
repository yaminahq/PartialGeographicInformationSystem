//Yaminah Qureshi
//qureshiy

#include "PathADT.h"
#include "LineADT.h"
#include <vector>
#include <set>
#include "Exceptions.h"

//using namespace std;

//vector<LineT> PathT::s = vector<LineT>();

PathT::PathT(PointT st, CompassT ornt, int l)
{
	LineT startLine(st, ornt, l);
	this->s.push_back(startLine);
}

void PathT::append(CompassT ornt, int l) 
{
	std::vector<PointT> existingPoints;
	for (int i =0; i < this->s.size(); i++){
		std::vector<PointT> points = pointsInLine(s[i]);
		existingPoints.insert(existingPoints.end(), points.begin(), points.end());
	}
	LineT appendLine(adjPt(ornt), ornt, l);
	std::vector<PointT> newPoints = pointsInLine(appendLine);
	for (int i = 0; i < newPoints.size(); i++ ){
		if (contains(existingPoints, newPoints[i]))
			throw invalid_argument();
	}
	
	this->s.push_back(appendLine);

}

PointT PathT::strt() 
{
	return this->s[0].strt();

}
PointT PathT::end() 
{
	return this->s[this->s.size() - 1].end();
}
LineT PathT::line(int i) 
{
	if (i >= this->s.size())
		throw outside_bounds();
	return this->s[i];
}
int PathT::size() 
{
	return this->s.size();
}
int PathT::len() 
{
	int sum = 0;
	for(int i = 0; i < this->s.size(); i = i + 1) {
		sum = sum + this->s[i].len();
	}
	return sum;
}
PathT PathT::translate(int deltaX, int deltaY)
{
	PathT translatePath(this->s[0].strt().translate(deltaX, deltaY), this->s[0].orient(), this->s[0].len());

	for (int i=1; i < this->s.size(); i = i + 1)
        translatePath.append(this->s[i].orient(), this->s[i].len());

	return translatePath;
}

PointT PathT::adjPt(CompassT ornt)
{
	if(ornt == N) {
		return this->s[this->s.size() - 1].end().translate(0,1);
	}
	else if(ornt == S) {
		return this->s[this->s.size() - 1].end().translate(0, -1);
	}
	else if(ornt == W) {
		return this->s[this->s.size() - 1].end().translate(-1, 0);
	}
	else {
		return this->s[this->s.size() - 1].end().translate(1, 0);	
	}
}

std::vector<PointT> PathT::pointsInLine(LineT l)
{
	std::vector<PointT> setOfPoints;

	for(int i = 0; i < l.len(); i = i + 1) {
		if(l.orient() == W and not contains(setOfPoints, l.strt().translate(-i, 0))) {
			setOfPoints.push_back(l.strt().translate(-i, 0));
		}
		else if(l.orient() == E and not contains(setOfPoints, l.strt().translate(i, 0))) {
			setOfPoints.push_back(l.strt().translate(i, 0));
		}
		else if(l.orient() == N and not contains(setOfPoints, l.strt().translate(0, i))) {
			setOfPoints.push_back(l.strt().translate(0, i));			
		}
		else if (l.orient() == S and not contains(setOfPoints, l.strt().translate(0, -i))){
			setOfPoints.push_back(l.strt().translate(0, -i));
		}
	}

	return setOfPoints;
}

bool PathT::contains(std::vector<PointT> points, PointT p)
{
	for(std::vector<PointT>::iterator it = points.begin(); it != points.end(); ++it) {
    if(p.x() == (*it).x() and p.y() == (*it).y())
      return true;
    }
  return false;
}

