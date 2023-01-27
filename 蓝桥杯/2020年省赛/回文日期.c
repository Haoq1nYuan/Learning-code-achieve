#include<stdio.h>
#include<string.h>

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };
int box[9];
int Y, M, D;

int judge ( long long N ) {
    int flag = 0, i = 1;
    long BOX, result = 0, square = 10000000;
    BOX = N;
    while ( BOX ) {
        box[9-i] = BOX % 10;
        BOX /= 10;
        result += box[9-i]*square;
        square /= 10;
        i++;
    }
    if ( result == N ) {
        flag = 1;
    }
    return flag;
}

int main ( int argc, char *argv[] )
{
    int isprime = 0;
    long long N;
    scanf( "%lld", &N );
    for ( N += 1; N <= 99991231; N++ ) {
        Y = N / 10000;
        M = ( N % 10000 ) / 100;
        D = N % 100;
        if ( ( Y % 100 && Y % 4 == 0 ) || Y % 400 == 0 ) {
            month[3] = 29;
        }
        if ( M > 12 || M == 0 || D > month[M] || D == 0 ) {
            continue;
        }
        if ( isprime == 0 ) {
            if ( judge( N ) ) {
                printf( "%lld\n", N );
                isprime = 1;
            }
            if ( box[1] == box[3] && box[6] == box[8] && box[1] == box[6] && box[2] == box[4] && box[5] == box[7] && box[5] == box[2] && box[2] != box[1] ) {
                printf( "%lld\n", N );
                break;
            }
        } else if ( judge( N ) && box[1] == box[3] && box[6] == box[8] && box[1] == box[6] && box[2] == box[4] && box[5] == box[7] && box[5] == box[2] && box[2] != box[1] ) {
            printf( "%lld\n", N );
            break;
        }
    } 
    return 0;
}