#include <stdio.h>
#include <string.h>

// POSIX 라이브러리가 일반적임
// 다른 3rd의 라이브러리도 있긴있음. (ANSI.. 자동차 .. )  
int main( void ){

    unsigned char src[62];
    unsigned char dest[62];
    memset(src, 0, sizeof(src));
    unsigned char *pp = src;

    *pp++ = 0x02; // 가변인자 처럼 필요한 값들을 채워넣을 수 있다. -> 아마도 추측컨데 append 메서드들이 이런식으로 동작할 것 같다.
    *pp++ = 0x0A;
    *pp++ = 0x0B;
    *pp++ = 0x0C;
    *pp++ = 0x0D;
    *pp++ = 0x03;
    *pp++ = 0x00;
    
    memcpy(dest, src, strlen( (char *) src));

    for(int i = 0; i < strlen((char *)dest); i++){
    	// X: 16진수 02 : 자릿수 ( 0이 있어야 앞자리 채워줌) 
    	// 자리수 맞춰 찍는게 중요함 
        printf("%02X ", dest[i]);
    }
}

// https://github.com/t0e8r1r4y/C-CPLUS/blob/main/C_LANG/C.md
// https://linux.die.net/man/  C의 함수들  
