//
//  Key.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 29.11.2021.
//

#ifndef Key_h
#define Key_h

#include <stdio.h>


class Key {
   int key;
public:
    Key (int x = 0);
    static int comparisons;
    static int assignments;
    int the_key() const;
    Key &operator =(const Key &x);
};

bool operator ==(const Key &x,const Key &y);
bool operator >(const Key &x,const Key &y);
bool operator <(const Key &x,const Key &y);
bool operator >=(const Key &x,const Key &y);
bool operator <=(const Key &x,const Key &y);
bool operator !=(const Key &x,const Key &y);





#endif /* Key_hpp */
