#include "cScore.h"

cScore::cScore()
    :points(0){}

int cScore::get_points()
{return points;}

void cScore::add_points()
{points++;}

void cScore::reset_score()
{points = 0;}
