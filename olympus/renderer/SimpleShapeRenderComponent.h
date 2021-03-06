#pragma once

#include <vector>

#include <glad/glad.h>

#include <utils/macros.h>
#include <utils/forward.h>
#include <containers/DoubleBuffer.h>

#include <Point.h>
#include <ShaderProgram.h>

BeginNamespaceOlympus

class Texture;

class SimpleShapeRenderComponent
{
    OlyNonCopyableMovable(SimpleShapeRenderComponent)
public:
    SimpleShapeRenderComponent();
    ~SimpleShapeRenderComponent();

    OlyPerfectForwardInContainer(render2DPoints, m_2Dpoints.frontBuffer())

    void render();
    size_t getMaxPoints() const;

    void swapBuffers() { m_2Dpoints.swapBuffersSafe(); }
    void clearBackBuffers() { m_2Dpoints.clearBackBuffer(); }

private:
    DoubleBuffer<std::vector<Point2D>> m_2Dpoints;

    GLuint m_vertexArrayID{ 0 };

    ShaderProgram m_2DpointsShader;
};

EndNamespaceOlympus
