//
//  Ordered_list.hpp
//  Testing
//
//  Created by Dmitrii Bacherikov on 29.11.2021.
//

#ifndef Ordered_list_h
#define Ordered_list_h

#include <stdio.h>
#include "Record.h"
#include "List.h"
#include "Utility.h"


class Ordered_list:public List<Record> {
public:
    Ordered_list():List(){};
   Error_code insert(const Record &data);
   Error_code insert(int position, const Record &data);
   Error_code replace(int position, const Record &data);
};



#endif /* Ordered_list_hpp */
