#include <stdio.h>
#include <stdlib.h>

int main()
{

    char sa1, sa2, s;
    char sb1, sb2, sb;
    char sc1, sc2, sc;
    unsigned char ua1, ua2, u;
    unsigned char ub1, ub2, ub;
    unsigned char uc1, uc2, uc;

    sa1 = 0X15; sb1 = 0XFF; sc1 = 0X15;
    sa2 = 0X00; sb2 = 0XFF; sc2 = 0XFF;
    ua1 = 0X15; ub1 = 0XFF; uc1 = 0X15;
    ua2 = 0X00; ub2 = 0XFF; uc2 = 0XFF;

    s = sa1 & sa2;   sb = sb1 & sb2;  sc = sc1 & sc2;
    u = ua1 & ua2;   ub = ub1 & ub2;  uc = uc1 & uc2;


    printf( "00010101 & 00000000 = %X (signed) %X (unsigned)\n", s, u );
    printf( "                      %d          %d\n", s, u );

    printf( "11111111 & 11111111 = %X (signed) %X (unsigned)\n", sb, ub );
    printf( "                      %d          %d\n", sb, ub );

    printf( "00010101 & 11111111 = %X (signed) %X (unsigned)\n", sc, uc );
    printf( "                      %d          %d\n", sc, uc );


  /*
    char sa1, sa2, s;
    char sb1, sb2, sb;
    char sc1, sc2, sc;
    unsigned char ua1, ua2, u;
    unsigned char ub1, ub2, ub;
    unsigned char uc1, uc2, uc;

    sa1 = 15; sb1 = 0XFF; sc1 = 15;
    sa2 = 0;  sb2 = 0XFF; sc2 = 0XFF;
    ua1 = 15; ub1 = 0XFF; uc1 = 15;
    ua2 = 0;  ub2 = 0XFF; uc2 = 0XFF;

    s = sa1 | sa2;   sb = sb1 | sb2;  sc = sc1 | sc2;
    u = ua1 | ua2;   ub = ub1 | ub2;  uc = uc1 | uc2;


    printf( "00010101 | 00000000 = %X (signed) %X (unsigned)\n", s, u );
    printf( "                      %d          %d\n", s, u );

    printf( "11111111 | 11111111 = %X (signed) %X (unsigned)\n", sb, ub );
    printf( "                      %d          %d\n", sb, ub );

    printf( "00010101 | 11111111 = %X (signed) %X (unsigned)\n", sc, uc );
    printf( "                      %d          %d\n", sc, uc );
*/
  /*
    char sa1, sa2, s;
    char sb1, sb2, sb;
    char sc1, sc2, sc;
    unsigned char ua1, ua2, u;
    unsigned char ub1, ub2, ub;
    unsigned char uc1, uc2, uc;

    sa1 = 15; sb1 = 0XFF; sc1 = 0;
    sa2 = 0;  sb2 = 0XFF; sc2 = 0XFF;
    ua1 = 15; ub1 = 0XFF; uc1 = 0;
    ua2 = 0;  ub2 = 0XFF; uc2 = 0XFF;

    s = sa1 ^ sa2;   sb = sb1 ^ sb2;  sc = sc1 ^ sc2;
    u = ua1 ^ ua2;   ub = ub1 ^ ub2;  uc = uc1 ^ uc2;


    printf( "00010101 ^ 00000000 = %X (signed) %X (unsigned)\n", s, u );
    printf( "                      %d          %d\n", s, u );

    printf( "11111111 ^ 11111111 = %X (signed) %X (unsigned)\n", sb, ub );
    printf( "                      %d          %d\n", sb, ub );

    printf( "00000000 ^ 11111111 = %X (signed) %X (unsigned)\n", sc, uc );
    printf( "                      %d          %d\n", sc, uc );
*/

  /*
    char sa1, s;
    char sb1, sb;
    char sc1,  sc;
    unsigned char ua1, u;
    unsigned char ub1, ub;
    unsigned char uc1, uc;

    sa1 = 15; sb1 = 0XFF; sc1 = 0;
    ua1 = 15; ub1 = 0XFF; uc1 = 0;

    s = ~sa1;   sb = ~sb1;  sc = ~sc1;
    u = ~ua1;   ub = ~ub1;  uc = ~uc1;


    printf( " ~00010101 = %X (signed) %X (unsigned)\n", s, u );
    printf( "                         %d          %d\n", s, u );

    printf( " ~11111111 = %X (signed) %X (unsigned)\n", sb, ub );
    printf( "                         %d          %d\n", sb, ub );

    printf( " ~00000000 = %X (signed) %X (unsigned)\n", sc, uc );
    printf( "                         %d          %d\n", sc, uc );
*/

/*

    char sa1, sa2, sa3, s, s1, s2;
    unsigned char ua1, ua2, ua3, u, u1, u2;
    char sb1, sb2, sb3, s3, s4, s5;
    unsigned char ub1, ub2, ub3, u3, u4, u5;

    sa1 = 0XF1;                                     sb1 = 0XF4;
    sa2 = 0XF4;                                     sb2 = 0XFA;
    sa3 = 0XF5;                                     sb3 = 0XFA;
    ua1 = 0XF1;                                     ub1 = 0XF4;
    ua2 = 0XF4;                                     ub2 = 0XFA;
    ua3 = 0XF5;                                     ub3 = 0XFA;
    s = sa1 << 3;   s1 = sa2 << 1;  s2 = sa3 << 2;  s3 = sb1 >> 2;  s4 = sb2 >> 1;  s5 = sb3 >> 3;
    u = ua1 << 3;   u1 = ua2 << 1;  u2 = ua3 << 3;  u3 = ub1 >> 2;  u4 = ub2 >> 1;  u5 = ub3 >> 3;

    printf( "11110001 << 3 = %X (signed) %X (unsigned)\n", s, u );
    printf( "                %d          %d\n", s, u );

    printf( "11110100 << 1 = %X (signed) %X (unsigned)\n", s1, u1 );
    printf( "                %d          %d\n", s1, u1 );

    printf( "11110101 << 2 = %X (signed) %X (unsigned)\n", s2, u2 );
    printf( "                %d          %d\n", s2, u2);


    printf( "11110100 >> 2 = %X (signed) %X (unsigned)\n", s3, u3 );
    printf( "                %d          %d\n", s3, u3 );

    printf( "11111010 >> 1 = %X (signed) %X (unsigned)\n", s4, u4 );
    printf( "                %d          %d\n", s4, u4 );

    printf( "11111010 >> 3 = %X (signed) %X (unsigned)\n", s5, u5 );
    printf( "                %d          %d\n", s5, u5);

    */

/*    char sa, sb, s1, s2;
    unsigned char ua, ub, u1, u2;

    sa = 0XFF;    sb = 0XFF;
    ua = 0XFF;    ub = 0XFF;
    s1 = sa &~ 0; s2 = sb ^~ 0;
    u1 = ua &~ 0; u2 = ub ^~ 0;

    printf( "11111111 &~ 0 = %X (signed) %X (unsigned)\n", s1, u1 );
    printf( "               %d          %d\n", s1, u1);

    printf( "11111111 ^~ 0 = %X (signed) %X (unsigned)\n", s2, u2 );
    printf( "                %d          %d\n", s2 , u2);
*/
    return 0;
}
