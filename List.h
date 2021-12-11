//
//  List.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 13.11.2021.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include "Utility.h"
#include "Key.h"
//typedef Key Record;


const int max_list = 100000 ;

template <class List_entry>
class List {
public:
//  methods of the List ADT
    List():count(0){};
    
    int size() const
    {
        return count;
    };
    
    bool full() const
    {
        return (count == max_list);
    }
    
    bool empty() const
    {
        return (count == 0);
    }
    
    void clear()
    {
        count = 0;
    }
    
    void traverse(void (*visit)(List_entry &))
    {
           for (int i = 0; i < count; i++)
              (*visit)(entry[i]);
    }
    
    Error_code retrieve(int position, List_entry &x) const
    {
        if (position < 0 || position > count)
           return utility_range_error;
        
        x = entry[position];
        return success;
    }
    
    Error_code replace(int position, const List_entry &x)
    {
        if (position < 0 || position > count)
           return utility_range_error;
        
        entry[position] = x;
        return success;
    }
    
    Error_code remove(int position, List_entry &x)
    {
        if (empty())
           return underflow;

        if (position < 0 || position > count)
           return utility_range_error;

        x = entry[position];
        for (int i = position + 1; i <= count; i++)
           entry[i - 1] = entry[i];

        count--;
        return success;
    }
    
    Error_code insert(int position, const List_entry &x)
    {
           if (full())
              return overflow;

           if (position < 0 || position > count)
              return utility_range_error;

           for (int i = count - 1; i >= position; i--)
              entry[i + 1] = entry[i];

           entry[position] = x;
           count++;
           return success;
    };

    
    
    
protected:
//  data members for a contiguous list implementation
   int count;
   List_entry entry[max_list];
};





#endif /* List_hpp */
