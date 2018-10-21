//
//  Common.h
//  CP2_WEEK6
//
//  Created by stu2017s10 on 2017. 4. 11..
//  Copyright © 2017년 stu2017s10. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <math.h>
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define SWAP(TYPE,X,Y) { TYPE temp=X; X=Y; Y=temp; }
// SWAP() 매크로는 변수 X와 Y의 값을 맞바꿔주는 일을 하는 코드를 생성시켜 줌

#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
// this._elements = NewVector(int, this_maxSize);
typedef enum {FALSE,TRUE} Boolean;  // FALSE와 TRUE 값을 갖는 Boolean 선언

#endif /* Common_h */
