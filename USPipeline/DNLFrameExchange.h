#ifndef DNLFRAMEEXCHANGE_H
#define DNLFRAMEEXCHANGE_H

#include <mutex>
#include <Modules/USStreamingCommon/DNLImage.h>

class DNLFrameExchange
{
public:

    DNLFrameExchange();

    void add_frame(DNLImage::Pointer frame);
    DNLImage::Pointer get_frame();

private:
    DNLImage::Pointer current_frame;
    std::mutex mutex;
};

#endif // DNLFRAMEEXCHANGE_H
