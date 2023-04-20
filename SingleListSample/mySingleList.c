//
//  mySingleList.c
//  SingleListSample
//
//  Created by 김진호 on 2023/02/26.
//

#include <stdio.h>

// 형 재선언
typedef struct NODE {
    // 관리될 데이터
    int nData;
    
    // 데이터 관리를 위한 포인터
    struct NODE* next;
} NODE;

// 구조체 배열과, 배열의 길이를 매개변수로 받음
void singleList(NODE* pList, int size){
    // 5,4,3,2
    if(size <= 1) {
        // index 4
        pList[4].next = 0;
        pList[size - 1].nData = 100;
        return;
    }
    
    pList[size - 2].next = &pList[size - 1];
    pList[size - 1].nData = size * 100;
    
    // 5
//    pList[3].next = &pList[4];
//    pList[4].nData = 500;
    // 4
//    pList[2].next = &pList[3];
//    pList[3].nData = 400;
    // 3
//    pList[1].next = &pList[2];
//    pList[2].nData = 300;
    // 2
//    pList[0].next = &pList[1];
//    pList[1].nData = 200;
    
    return singleList(pList, size - 1);
}


void singleList02(NODE* pList, int size){
    if(size <= 0) return;
    // size : 5 ~ 1
    // 3 ~ -1 = 4 ~ 0
    pList[size-2].next = &pList[size-1];
    
    singleList02(pList, size - 1);
    
    // size : 1 ~ 5
    // 0 ~ 4 = 1 ~ 5 ( 5제외 시키기 )
    pList[size-1].next = &pList[size];
    
    return;
}

void singleList03(NODE* pList, int size){
    // 5~1
    if(size <= 0) return;
    if(size == 5)
        // 처음에 마지막 요소의 next를 초기화
        pList[size-1].next = 0;
    else {
        // 이전 요소의 next를
        pList[size-1].next = pList[size].next;
    }
    
    singleList03(&pList[5-size], size-1);
}
