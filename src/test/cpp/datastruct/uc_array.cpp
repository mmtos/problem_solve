#include <stdio.h>
#include <string.h>

// POSIX ���̺귯���� �Ϲ�����
// �ٸ� 3rd�� ���̺귯���� �ֱ�����. (ANSI.. �ڵ��� .. )  
int main( void ){

    unsigned char src[62];
    unsigned char dest[62];
    memset(src, 0, sizeof(src));
    unsigned char *pp = src;

    *pp++ = 0x02; // �������� ó�� �ʿ��� ������ ä������ �� �ִ�. -> �Ƹ��� �������� append �޼������ �̷������� ������ �� ����.
    *pp++ = 0x0A;
    *pp++ = 0x0B;
    *pp++ = 0x0C;
    *pp++ = 0x0D;
    *pp++ = 0x03;
    *pp++ = 0x00;
    
    memcpy(dest, src, strlen( (char *) src));

    for(int i = 0; i < strlen((char *)dest); i++){
    	// X: 16���� 02 : �ڸ��� ( 0�� �־�� ���ڸ� ä����) 
    	// �ڸ��� ���� ��°� �߿��� 
        printf("%02X ", dest[i]);
    }
}

// https://github.com/t0e8r1r4y/C-CPLUS/blob/main/C_LANG/C.md
// https://linux.die.net/man/  C�� �Լ���  
