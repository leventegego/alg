#include<bits/stdc++.h>
using namespace std;



int round_to_int(double x) // x > 0
{
    return (int)(x + 0.5);
}


bool is_int(double x)
{
    double epsilon = 1e-6;
    return (abs(x - round(x)) < epsilon);
}
