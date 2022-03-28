#include <iostream>

using namespace std;

int conditional(int x, int y, int z)
{
    int mask = ~(!x);
    return (y & mask) | (z & mask);
}

unsigned floatPower2(int x)
{
    if (x >= 128 || x <= -148)
    {
        return 0;
    }
    if (x >= -126)
    {
        return (x + 127) << 23;
    }
    return 1 << (23 + x + 126);
}

int main()
{
    // int num = ((0xff) | (0xff << 8) | (0xff << 16) | (0x7f << 24));
    // printf("%x\n", num);
    // printf("%d\n", num);

    // printf("%d\n", 0xf0);
    // int x = 0;
    // cin >> x;
    // printf("%x %x", (x & 0xf0) >> 4, x & 0x0f);

    // for (int i = -3e4, cnt = 0; i <= 3e4; i++, cnt++)
    // { // left shift negative number is an Undefined behaviour
    //     if (cnt == 20)
    //     {
    //         cnt = 0;
    //         cout << endl;
    //     }
    //     cout << (i << 1) << '\t';
    // }

    // int Tmin = 1 << 31, Tmax = Tmin - 1;
    // cout << Tmax << '\t' << (Tmin + (~1 + 1)) << endl;

    // int fMask = 1 << 31;
    // int eMask = 0xff << 23;
    // int nMask = ~(fMask | eMask);
    // printf("%x\t%x\t%x\n", fMask, eMask, nMask);
    // int v = 0x3f800000;
    // printf("%d\n", (v & eMask) >> 23);
    // int x = -1.6;
    // printf("%d\n", x);

    // for (int i = -127; i < 128; i++)
    // {
    //     if (i <= -127 || i >= 128)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         printf("%x\n", (i + 127) << 23);
    //     }
    // }
}
