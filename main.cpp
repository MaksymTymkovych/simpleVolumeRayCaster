#include "include/mv.h"
using namespace std;

int main() {

    mvImage3_t volume;
    mvImageLoadFromRaw(volume,"aneurism.raw",mvSize3(256,256,256));

    mvRayCastState_t* pState;
    mvRayCasterCreate(&pState,&volume,mvSize2(800,600),MV_RAY_CASTER_OPTIONS_USE_SHADING);
    mvImage1_t lt = mvCreateLookUpTable({
                                        std::make_pair(0,mvColor4(0,0,0,0)),
                                        std::make_pair(0,mvColor4(0,0,0,0)),
                                        std::make_pair(100,mvColor4(0,0,0,20)),
                                        std::make_pair(120,mvColor4(100,100,100,50)),
                                        std::make_pair(160,mvColor4(10,10,10,20)),
                                        std::make_pair(180,mvColor4(200,10,40,100)),
                                        std::make_pair(200,mvColor4(200,20,20,100)),
                                        std::make_pair(225,mvColor4(20,20,200,100)),
                                        std::make_pair(255,mvColor4(200,20,20,200))
                                        });

    mvRayCasterSetLookUpTable(&pState,&lt);
    mvRayCasterRender(&pState);
    mvImageSaveToBitmap(pState->colorBuffer,"screen.bmp");
    mvRayCasterDelete(&pState);
    mvDelete(volume);


    return 0;
}
