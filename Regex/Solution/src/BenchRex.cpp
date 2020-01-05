
#include "BaseRex.h"
#include "Rex/C_Rex.h"
#include "Rex/Xpressive_Rex.h"
#include "Rex/STL_Rex.h"
#include "Rex/Boost_Rex.h"
#include "Rex/re2_Rex.h"
#include "Rex/Pearl_Rex.h"

int main()
{
    xvector<BaseRex*> rexers = {
        new Xpressive_Rex,
        new STL_Rex,
        new Boost_Rex,
        new re2_Rex,
        new Pearl_Rex
    };

    #ifdef __unix__
        rexers.push_back(new C_Rex);
    #endif

    for (auto* rex : rexers) {
        rex->loop_match();
        delete rex;
    }

    return 0;
}
