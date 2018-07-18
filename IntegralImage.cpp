#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

using namespace std;

/* Write a program to compute the integral image (in place)
 * and compute the sum of a region
*/

/* Integral Image :
 * S(x,y) = I(x,y) + S(x-1,y) + S(x,y-1) - S(x-1,y-1)
 *
 * Area of a location
 * i(x,y) = S(x,y) - S(x-1,y) - S(x,y-1) + S(x-1,y-1)
*/

vector<vector<float>> integralImage(vector<vector<float>> img){
    int M = img.size();
    int N = img[0].size();

    if(M == 0 || N ==0)
        return vector<vector<float>>();

    vector<vector<float>> iImage(M,vector<float>(N,0.0f));
    // integral image
    for(int i = 0; i < M; i++)
        for(int j = 0 ; j < N; j++){
            iImage[i][j] = img[i][j];
            if(i-1 >= 0)
                iImage[i][j] += iImage[i-1][j];
            if(j-1 >= 0)
                iImage[i][j] += iImage[i][j-1];
            if(i-1 >=0 && j-1 >=0)
                iImage[i][j] -= iImage[i-1][j-1];
        }
    return iImage;
}

TEST_CASE("Test case - 1","[integralImage]"){
    vector<vector<float>> img = {{5,2},
                                 {3,6}};
    vector<vector<float>> result = {{5,7},
                                    {8,16}};
    REQUIRE(integralImage(img) == result);
}

/*
int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
*/
