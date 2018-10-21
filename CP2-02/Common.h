//
//  Common.h
//  
//
//  Created by stu2017s10 on 2017. 3. 14..
//
//

#ifndef Common_h
#define Common_h

#include <math.h>

#define EPSILON 0.000001  // 상수에 이름을 부여하기 위한 매크로 선언
#define FloatValueIsZero(NUMBER)    fabsf(NUMBER) < EPSILON  // 반복 사용되는 코드를 위한 매크로 선언

typedef enum {FALSE,TRUE} Boolean;  // Boolean 타입을 define 해주고  FALSE, TRUE 값을 가짐. FALSE와 TRUE의 순서는 바뀌면 안됨.

#endif /* Common_h */
