#ifndef CSCORE_H
#define CSCORE_H


class cScore
{
    unsigned int points;
public:
    cScore();
    int  get_points();
    void add_points();
    void reset_score();
};

#endif // CSCORE_H
