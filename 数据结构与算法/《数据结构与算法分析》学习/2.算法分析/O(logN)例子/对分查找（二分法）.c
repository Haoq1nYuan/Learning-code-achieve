//数组a假设已经从小到大排好序
int search ( int *a, int target, int length )
{
    int low, mid, high;
    int NotFound = -1;
    low = 0, high = length-1;
    while ( high >= low ) {
        mid = ( high + low ) / 2;
        if ( a[mid] > target ) {
            high = mid - 1;
        } else if ( a[mid] < target ) {
            low = mid;
        } else {
            return mid;
        }
    }
    return NotFound;
}
