long int Pow ( long X, unsigned int N ) 
{
    if ( N == 0 ) {
        return 1;
    } 
    if ( N == 1 ) {
        return X;
    }
    if ( N%2 ) {
        return Pow( X, N-1 ) * X; //»òÕßÐ´ÎªPow( X*X, N/2 ) * X
    } else {
        return Pow( X*X, N/2 );
    }
} 