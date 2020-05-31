#include "marker_detector.h"

#include <array>

#include <easy/profiler.h>

#include <aruco.h>

#include <logging/logging.h>
#include <utils/olyerror.h>

BeginNamespaceOlympus

namespace markers
{
    std::optional<DetectResult> detectMarker(MarkerRecognitionOptions& options, cv::Mat frame)
    {
        EASY_FUNCTION(profiler::colors::DarkGreen);

        std::vector<aruco::Marker> markers;
        try
        {
            options.getDetector().detect(frame, markers, options.getParameters(), 0.178f);
        }
        catch (std::exception& e)
        {
            olyError("[marker_detector] Exception on detect: {}", e.what());
            return std::nullopt;
        }
        
        if (markers.empty())
        {
            return std::nullopt;
        }

        if (markers.size() > 1)
        {
            logging::warning("[marker_detector] Found 2 markers. Only first will be used.");
        }

        auto& marker = markers.front();

        if (!marker.isPoseValid())
        {
            logging::info("[marker_detector] Pose not valid.");
            return std::nullopt;
        }

        cv::Mat glModelView(4, 4, CV_64F);
        marker.glGetModelViewMatrix(&glModelView.at<double>(0));
        glModelView.convertTo(glModelView, CV_32F);

        cv::Mat glProjection(4, 4, CV_64F);
        options.getParameters().glGetProjectionMatrix(frame.size(), frame.size(), &glProjection.at<double>(0), 0.1, 100);
        glProjection.convertTo(glProjection, CV_32F);

        return DetectResult{ glModelView, glProjection };
    }
}

EndNamespaceOlympus