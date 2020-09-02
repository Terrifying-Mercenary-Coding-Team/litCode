#include <bits/stdc++.h>

using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int readn,copyn=0;
        do{
            readn = read4(buf+copyn);
            copyn += readn;
        }while(copyn<n && readn==4);
        return min(n,copyn);
    }
};
