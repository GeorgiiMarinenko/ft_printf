#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int    main(void)
{
    int i;

    static char	a01;
    static unsigned char a02;
    static short a03;
    static unsigned short a04;
    static int a05;
    static unsigned int a06;
    static long a07;
    static unsigned long a08;
    static long long a09;
    static unsigned long long a10;
    static char *a11;
    static void *a12;

    // setlocale(LC_ALL, "");
    // ft_printf("Hello World!\n");
    // ft_printf("%s", "This is ");
    // ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");

    // ft_printf("ft_printf: %10.5d\n", -216);
    // printf("   printf: %10.5d\n\n", -216);
    // printf("printf: %+2d\n\n", 5);

    // ft_printf("ft_printf: %8.3d\n", 8375);
    // printf("   printf: %8.3d\n\n", 8375);

    // ft_printf("ft_printf: %8.3d\n", -8473);
    // printf("   printf: %8.3d\n\n", -8473);

    // ft_printf("ft_printf %8.5d\n", 34);
    // printf("   printf %8.5d\n\n", 34);

    // ft_printf("ft_printf %8.5d\n", 0);
    // printf("   printf %8.5d\n\n", 0);

    // ft_printf("ft_printf %010.5d\n", -216);
    // printf("   printf %010.5d\n\n", -216);

    // ft_printf("ft_printf %07d\n", -54);
    // printf("   printf %07d\n\n", -54);

    // printf("d_prec_width_fit_fit_neg\n");
    // ft_printf("ft_printf %10.5d\n", -216);
    // printf("   printf %10.5d\n\n", -216);

    // printf("d_prec_width_ff_neg_zp\n");
    // ft_printf("ft_printf %010.5d\n", -216);
    // printf("   printf %010.5d\n\n", -216);

    // printf("d_prec_width_fn_neg_zp\n");
    // ft_printf("ft_printf %03.7d\n", -2375);
    // printf("   printf %03.7d\n\n", -2375);

    // printf("d_prec_width_ff_pos_zp\n");
    // ft_printf("ft_printf %08.5d\n", 34);
    // printf("   printf %08.5d\n\n", 34);

    // printf("d_prec_width_ff_zero_zp\n");
    // ft_printf("ft_printf %08.5d\n", 0);
    // printf("   printf %08.5d\n\n", 0);

    // ft_printf("\ncheking sega: %3.30d\n\n", -256);

    // printf("\n________UNSIGNED INT_________\n");

    // ft_printf("ft_printf %8.3u\n", 8375);
    // printf("   printf %8.3u\n\n", 8375);

    // printf("u_prec_width_ff_pos_zp\n");
    // ft_printf("ft_printf %08.5u\n", 34);
    // printf("   printf %08.5u\n\n", 34);

    // printf("\n________HEXICAL_________\n");

    // printf("x_prec_width_nofit_fit_pos\n");
    // ft_printf("ft_printf %8.3x\n", 8375);
    // printf("   printf %8.3x\n\n", 8375);

    // printf("x_prec_width_fit_fit_zero\n");
    // ft_printf("ft_printf %8.5x\n", 0);
    // printf("   printf %8.5x\n\n", 0);

    // printf("x_prec_width_ff_pos_zp\n");
    // ft_printf("ft_printf %08.5x\n", 34);
    // printf("   printf %08.5x\n\n", 34);

    // printf("x_prec_width_ff_zero_zp\n");
    // ft_printf("ft_printf %08.5x\n", 0);
    // printf("   printf %08.5x\n\n", 0);

    // printf("x_prec_width_nf_pos_zp\n");
    // ft_printf("ft_printf %08.3x\n", 8375);
    // printf("   printf %08.3x\n\n", 8375);

    // printf("\n________POINTER_________\n");

    // printf("\np_basic\n");
    // ft_printf("ft_printf %p%p%p%p%p%p%p%p%p%p%p%p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // printf("   printf %p%p%p%p%p%p%p%p%p%p%p%p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    // // printf("\np_width_nofit\n");
    // // ft_printf("ft_printf %70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // // printf("   printf %70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    // // printf("\np_width_nofit\n");
    // // ft_printf("ft_printf %5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // // printf("   printf %5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    // // printf("\np_width_16\n");
    // // ft_printf("ft_printf %16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // // printf("   printf %16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    // // printf("\np_width_8\n");
    // // ft_printf("ft_printf %8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // // printf("   printf %8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

    // ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
    // printf("%% *.5i 42 == |% *.5i|\n\n", 4, 42);

    // ft_printf("%15p\n", NULL);
    // printf("%15p\n\n", NULL);

    // ft_printf("%.48d", 100);

    // ft_printf("-->|%-16.p|<-- \n", NULL);
    // printf("-->|%-16.p|<-- \n\n", NULL);

    // ft_printf("-->|%-16.p|<-- \n", NULL);
    // printf("-->|%-16.p|<-- \n\n", NULL);

    // ft_printf("%20.5d\n", -1024);
    // printf("%20.5d\n\n", -1024);

    // ft_printf("%20.5i\n", -1024);
    // printf("%20.5i\n\n", -1024);

    // ft_printf("%020.5d\n", -1024);
    // printf("%020.5d\n\n", -1024);

    // ft_printf("%020.5i\n", -1024);
    // printf("%020.5i\n\n", -1024);

    // ft_printf("%+09d\n", 42);
    // ft_printf("%#b\n", 256);
    // ft_printf("%#o\n", 1039);
    // ft_printf("%#X\n", 16417188);
    // ft_printf("%p\n", &i);
    // ft_printf("%C %C %C\n", L'ä', L'ö', L'ü');
	// ft_printf("%c", 'q');
    // pause();

    // ft_printf("<<%-103.21d%*p>>\n" ,-1119242596,-94,(void*)17541392615378030860lu);
    // printf("<<%-103.21d%*p>>\n\n" ,-1119242596,-94,(void*)17541392615378030860lu);

    ft_printf("<<%0148.147d>>\n" ,-1982512519);
       printf("<<%0148.147d>>\n\n" ,-1982512519);
    return (0);
}
