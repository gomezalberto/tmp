#include "DNLFrameExchange.h"
#include <Modules/USStreamingCommon/DNLImage.h>
#include <thread>

DNLFrameExchange::DNLFrameExchange(){
     current_frame = nullptr;
}


void DNLFrameExchange::add_frame(DNLImage::Pointer frame) {
    mutex.lock();
    current_frame = frame;

    // TODO: remove
    frame->m_patientName = "Patient Name is Frank";
    mutex.unlock();
}

DNLImage::Pointer DNLFrameExchange::get_frame() {
    // Block until we have at least one frame
    while (current_frame == nullptr) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return current_frame;
}

