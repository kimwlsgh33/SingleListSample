//
//  main.c
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

int main(int argc, const char * argv[]) {
    NODE list[5] = {0};
    
    // 다음 구조체의 주소 저장 ( 연결됨 )
    // 순서대로 저장할 필요가 없음! ㅋㅋ
    list[0].next = &list[3];
    list[1].next = &list[2];
    list[2].next = &list[4];
    list[3].next = &list[1];
    list[4].next = 0;
    
    list[0].nData = 100;
    list[1].nData = 200;
    list[2].nData = 300;
    list[3].nData = 400;
    list[4].nData = 500;
//    singleList(list,5);
    
    for(int i = 0; i < 5; ++i)
        printf("list[%d]: %d\n", i, list[i].nData);
    
    // pTmp에 첫번째 NODE의 주소를 저장
    NODE* pTmp = &list[2];
    while(pTmp != NULL){
        // pTmp에 저장된 주소를 찾아갔더니 구조체가 존재, 구조체 멤버접근 연산자(->) 사용해서 nData 멤버를 반환
        printf("[%p]: %d\n", pTmp, pTmp->nData);
        // 다음 주소를, pTmp 포인터에 저장
        pTmp = pTmp->next;
    }
    
    return 0;
}
