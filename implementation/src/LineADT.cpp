//Yaminah Qureshi
//qureshiy

#include <cmath>
#include "LineADT.h"
#include "PointADT.h"
#include "MapTypes.h"
#include "Exceptions.h"


LineT::LineT(PointT st, CompassT ornt, int l) : s(st), o(ornt), L(l)
{
	if (this->L==0)
		throw invalid_argument();
}

PointT LineT::strt()
{
  PointT startPoint(this->s.x(), this->s.y());
  return startPoint;
}

PointT LineT::end()
{
	int endX;
	int endY;

	if(this->o == W) {
		endX = this->s.x() - (this->L - 1);
		endY = this->s.y();

	}
	else if(this->o == E) {
		endX = this->s.x() + (this->L - 1);
		endY = this->s.y();		
	}
	else if(this->o == N) {
		endX = this->s.x();
		endY = this->s.y() + (this->L - 1);				
	}
	else {
		endX = this->s.x();
		endY = this->s.y() - (this->L - 1);		
	}

	PointT endPoint(endX, endY);

	return endPoint;
}

CompassT LineT::orient()
{
	return this->o;

}

int LineT::len()
{
	return this->L;

}

LineT LineT::flip()
{
	CompassT flipO;

	if(this->o == W) {
		flipO = E;
	}
	else if(this->o == E) {
		flipO = W;		
	}
	else if(this->o == N) {
		flipO = S;		
	}
	else {
		flipO = N;	
	}

	LineT flipLine(this->s, flipO, this->L);

	return flipLine;
}

LineT LineT::rotate(RotateT r)
{
	CompassT rotateO;

	if(r == CW) {
		if(this->o == N){
			rotateO = E;
		}
		else if(this->o == S) {
			rotateO = W;
		}
		else if(this->o == W) {
			rotateO = N;
		}
		else {
			rotateO = S;
		}
	}
	else if(r == CCW){
		if(this->o == N){
			rotateO = W;
		}
		else if(this->o == S) {
			rotateO = E;
		}
		else if(this->o == W) {
			rotateO = S;
		}
		else {
			rotateO = N;
		}
	}

	LineT rotateLine(this->s, rotateO, this->L);

	return rotateLine;
}

LineT LineT::translate(int deltaX, int deltaY)
{
	LineT translateLine(this->s.translate(deltaX, deltaY), this->o, this->L);

	return translateLine;
}


