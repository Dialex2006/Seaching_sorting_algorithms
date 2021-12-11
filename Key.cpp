//
//  Key.cpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 29.11.2021.
//

#include "Key.h"




Key::Key(int x) {
    key = x;
};


int Key::the_key() const {
    return key;
};


Key &Key::operator =(const Key &x)
{
    Key::assignments++;
    key = x.key;
    return *this;
}

bool operator == (const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() == y.the_key();
};

bool operator >(const Key &x,const Key &y)
{
    Key::comparisons++;
    return x.the_key() > y.the_key();
};

bool operator <(const Key &x,const Key &y)
{
    Key::comparisons++;
    return x.the_key() < y.the_key();
};

bool operator >=(const Key &x,const Key &y)
{
    Key::comparisons++;
    return x.the_key() >= y.the_key();
};

bool operator <=(const Key &x,const Key &y)
{
    Key::comparisons++;
    return x.the_key() <= y.the_key();
};

bool operator !=(const Key &x,const Key &y)
{
    Key::comparisons++;
    return x.the_key() != y.the_key();
};




int Key::comparisons = 0;
int Key::assignments = 0;
