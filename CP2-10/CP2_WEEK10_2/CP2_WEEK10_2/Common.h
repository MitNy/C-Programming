//
//  Common.h
//  CP2_WEEK10_2
//
//  Created by stu2017s10 on 2017. 5. 17..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <stdlib.h>
#include "MessageKOR_PostfixError.h"

#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
typedef enum {FALSE,TRUE} Boolean;  // FALSE와 TRUE 값을 갖는 Boolean 선언

typedef
enum {
    PostfixError_None,
    PostfixError_ExpressionTooLong,
    PostfixError_OperandsTooMany,
    PostfixError_OperandsTooFew,
    PostfixError_UnknownOperator,
    PostfixError_DivideByZero
}
PostfixError ;



#endif /* Common_h */
