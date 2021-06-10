/*
Diophantine eq >
    ax+by=c will have intergral soln if gcd(a , b) is divisible by c   .  {a,b,c,x,y} are integers

Extended gcd

if
    ax+by = gcd(a , b) then we can find x and y
    ax+by = gcd(a , b) = gcd(b , a%b) = b(x1) + (a%b)(y1)  = b(x1) + (a - b*floor(a/b))(y1)

    x = y1
    y = x1 - (floor(a/b)*y1)

    if(b==0)
        return {a , 1, 0};  // {gcd , x1, y1}

*/

vector<int>ExtendedEuclid(int a , int b)
{
    if (a < b)
        return ExtendedEuclid(b, a);

    if (b == 0)
        return {a , 1 , 0};

    vector<int> small = ExtendedEuclid(b, a % b);

    return {small[0]  , small[2] , small[1] - (a / b) *small[2]}; // gcd , x1 , y1
}
/*
vector<int> res = ExtendedEuclid(a , b);
    debug(res);
*/
