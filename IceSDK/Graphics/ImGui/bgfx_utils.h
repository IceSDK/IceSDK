#pragma once

#include <bgfx/bgfx.h>

#include <cstdio>

/*
 * Copyright 2011-2020 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

/// Returns true if both internal transient index and vertex buffer have
/// enough space.
///
/// @param[in] _numVertices Number of vertices.
/// @param[in] _layout Vertex layout.
/// @param[in] _numIndices Number of indices.
///
inline bool checkAvailTransientBuffers(uint32_t _numVertices,
                                       const bgfx::VertexLayout& _layout,
                                       uint32_t _numIndices)
{
    return _numVertices
               == bgfx::getAvailTransientVertexBuffer(_numVertices, _layout)
           && (0 == _numIndices
               || _numIndices
                      == bgfx::getAvailTransientIndexBuffer(_numIndices));
}
