am x1 the x coordinate of the start point
 * \param y1 the y coordinate of the start point
 * \param x2 the x coordinate of the end point
 * \param y2 the y coordinate of the end point
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderFillRects
 * \sa SDL_RenderPresent
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawLine(SDL_Renderer * renderer,
                                               int x1, int y1, int x2, int y2);

/**
 * Draw a series of connected lines on the current rendering target.
 *
 * \param renderer the rendering context
 * \param points an array of SDL_Point structures representing points along
 *               the lines
 * \param count the number of points, drawing count-1 lines
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderFillRects
 * \sa SDL_RenderPresent
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawLines(SDL_Renderer * renderer,
                                                const SDL_Point * points,
                                                int count);

/**
 * Draw a rectangle on the current rendering target.
 *
 * \param renderer the rendering context
 * \param rect an SDL_Rect structure representing the rectangle to draw, or
 *             NULL to outline the entire rendering target
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderFillRects
 * \sa SDL_RenderPresent
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawRect(SDL_Renderer * renderer,
                                               const SDL_Rect * rect);

/**
 * Draw some number of rectangles on the current rendering target.
 *
 * \param renderer the rendering context
 * \param rects an array of SDL_Rect structures representing the rectangles to
 *              be drawn
 * \param count the number of rectangles
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderFillRects
 * \sa SDL_RenderPresent
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawRects(SDL_Renderer * renderer,
                                                const SDL_Rect * rects,
                                                int count);

/**
 * Fill a rectangle on the current rendering target with the drawing color.
 *
 * The current drawing color is set by SDL_SetRenderDrawColor(), and the
 * color's alpha value is ignored unless blending is enabled with the
 * appropriate call to SDL_SetRenderDrawBlendMode().
 *
 * \param renderer the rendering context
 * \param rect the SDL_Rect structure representing the rectangle to fill, or
 *             NULL for the entire rendering target
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRects
 * \sa SDL_RenderPresent
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC int SDLCALL SDL_RenderFillRect(SDL_Renderer * renderer,
                                               const SDL_Rect * rect);

/**
 * Fill some number of rectangles on the current rendering target with the
 * drawing color.
 *
 * \param renderer the rendering context
 * \param rects an array of SDL_Rect structures representing the rectangles to
 *              be filled
 * \param count the number of rectangles
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderPresent
 */
extern DECLSPEC int SDLCALL SDL_RenderFillRects(SDL_Renderer * renderer,
                                                const SDL_Rect * rects,
                                                int count);

/**
 * Copy a portion of the texture to the current rendering target.
 *
 * The texture is blended with the destination based on its blend mode set
 * with SDL_SetTextureBlendMode().
 *
 * The texture color is affected based on its color modulation set by
 * SDL_SetTextureColorMod().
 *
 * The texture alpha is affected based on its alpha modulation set by
 * SDL_SetTextureAlphaMod().
 *
 * \param renderer the rendering context
 * \param texture the source texture
 * \param srcrect the source SDL_Rect structure or NULL for the entire texture
 * \param dstrect the destination SDL_Rect structure or NULL for the entire
 *                rendering target; the texture will be stretched to fill the
 *                given rectangle
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderCopyEx
 * \sa SDL_SetTextureAlphaMod
 * \sa SDL_SetTextureBlendMode
 * \sa SDL_SetTextureColorMod
 */
extern DECLSPEC int SDLCALL SDL_RenderCopy(SDL_Renderer * renderer,
                                           SDL_Texture * texture,
                                           const SDL_Rect * srcrect,
                                           const SDL_Rect * dstrect);

/**
 * Copy a portion of the texture to the current rendering, with optional
 * rotation and flipping.
 *
 * Copy a portion of the texture to the current rendering target, optionally
 * rotating it by angle around the given center and also flipping it
 * top-bottom and/or left-right.
 *
 * The texture is blended with the destination based on its blend mode set
 * with SDL_SetTextureBlendMode().
 *
 * The texture color is affected based on its color modulation set by
 * SDL_SetTextureColorMod().
 *
 * The texture alpha is affected based on its alpha modulation set by
 * SDL_SetTextureAlphaMod().
 *
 * \param renderer the rendering context
 * \param texture the source texture
 * \param srcrect the source SDL_Rect structure or NULL for the entire texture
 * \param dstrect the destination SDL_Rect structure or NULL for the entire
 *                rendering target
 * \param angle an angle in degrees that indicates the rotation that will be
 *              applied to dstrect, rotating it in a clockwise direction
 * \param center a pointer to a point indicating the point around which
 *               dstrect will be rotated (if NULL, rotation will be done
 *               around `dstrect.w / 2`, `dstrect.h / 2`)
 * \param flip a SDL_RendererFlip value stating which flipping actions should
 *             be performed on the texture
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderCopy
 * \sa SDL_SetTextureAlphaMod
 * \sa SDL_SetTextureBlendMode
 * \sa SDL_SetTextureColorMod
 */
extern DECLSPEC int SDLCALL SDL_RenderCopyEx(SDL_Renderer * renderer,
                                           SDL_Texture * texture,
                                           const SDL_Rect * srcrect,
                                           const SDL_Rect * dstrect,
                                           const double angle,
                                           const SDL_Point *center,
                                           const SDL_RendererFlip flip);


/**
 * Draw a point on the current rendering target at subpixel precision.
 *
 * \param renderer The renderer which should draw a point.
 * \param x The x coordinate of the point.
 * \param y The y coordinate of the point.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawPointF(SDL_Renderer * renderer,
                                                 float x, float y);

/**
 * Draw multiple points on the current rendering target at subpixel precision.
 *
 * \param renderer The renderer which should draw multiple points.
 * \param points The points to draw
 * \param count The number of points to draw
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawPointsF(SDL_Renderer * renderer,
                                                  const SDL_FPoint * points,
                                                  int count);

/**
 * Draw a line on the current rendering target at subpixel precision.
 *
 * \param renderer The renderer which should draw a line.
 * \param x1 The x coordinate of the start point.
 * \param y1 The y coordinate of the start point.
 * \param x2 The x coordinate of the end point.
 * \param y2 The y coordinate of the end point.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawLineF(SDL_Renderer * renderer,
                                                float x1, float y1, float x2, float y2);

/**
 * Draw a series of connected lines on the current rendering target at
 * subpixel precision.
 *
 * \param renderer The renderer which should draw multiple lines.
 * \param points The points along the lines
 * \param count The number of points, drawing count-1 lines
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawLinesF(SDL_Renderer * renderer,
                                                 const SDL_FPoint * points,
                                                 int count);

/**
 * Draw a rectangle on the current rendering target at subpixel precision.
 *
 * \param renderer The renderer which should draw a rectangle.
 * \param rect A pointer to the destination rectangle, or NULL to outline the
 *             entire rendering target.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawRectF(SDL_Renderer * renderer,
                                                const SDL_FRect * rect);

/**
 * Draw some number of rectangles on the current rendering target at subpixel
 * precision.
 *
 * \param renderer The renderer which should draw multiple rectangles.
 * \param rects A pointer to an array of destination rectangles.
 * \param count The number of rectangles.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderDrawRectsF(SDL_Renderer * renderer,
                                                 const SDL_FRect * rects,
                                                 int count);

/**
 * Fill a rectangle on the current rendering target with the drawing color at
 * subpixel precision.
 *
 * \param renderer The renderer which should fill a rectangle.
 * \param rect A pointer to the destination rectangle, or NULL for the entire
 *             rendering target.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderFillRectF(SDL_Renderer * renderer,
                                                const SDL_FRect * rect);

/**
 * Fill some number of rectangles on the current rendering target with the
 * drawing color at subpixel precision.
 *
 * \param renderer The renderer which should fill multiple rectangles.
 * \param rects A pointer to an array of destination rectangles.
 * \param count The number of rectangles.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderFillRectsF(SDL_Renderer * renderer,
                                                 const SDL_FRect * rects,
                                                 int count);

/**
 * Copy a portion of the texture to the current rendering target at subpixel
 * precision.
 *
 * \param renderer The renderer which should copy parts of a texture.
 * \param texture The source texture.
 * \param srcrect A pointer to the source rectangle, or NULL for the entire
 *                texture.
 * \param dstrect A pointer to the destination rectangle, or NULL for the
 *                entire rendering target.
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderCopyF(SDL_Renderer * renderer,
                                            SDL_Texture * texture,
                                            const SDL_Rect * srcrect,
                                            const SDL_FRect * dstrect);

/**
 * Copy a portion of the source texture to the current rendering target, with
 * rotation and flipping, at subpixel precision.
 *
 * \param renderer The renderer which should copy parts of a texture.
 * \param texture The source texture.
 * \param srcrect A pointer to the source rectangle, or NULL for the entire
 *                texture.
 * \param dstrect A pointer to the destination rectangle, or NULL for the
 *                entire rendering target.
 * \param angle An angle in degrees that indicates the rotation that will be
 *              applied to dstrect, rotating it in a clockwise direction
 * \param center A pointer to a point indicating the point around which
 *               dstrect will be rotated (if NULL, rotation will be done
 *               around dstrect.w/2, dstrect.h/2).
 * \param flip An SDL_RendererFlip value stating which flipping actions should
 *             be performed on the texture
 * \return 0 on success, or -1 on error
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderCopyExF(SDL_Renderer * renderer,
                                            SDL_Texture * texture,
                                            const SDL_Rect * srcrect,
                                            const SDL_FRect * dstrect,
                                            const double angle,
                                            const SDL_FPoint *center,
                                            const SDL_RendererFlip flip);

/**
 * Render a list of triangles, optionally using a texture and indices into the
 * vertex array Color and alpha modulation is done per vertex
 * (SDL_SetTextureColorMod and SDL_SetTextureAlphaMod are ignored).
 *
 * \param texture (optional) The SDL texture to use.
 * \param vertices Vertices.
 * \param num_vertices Number of vertices.
 * \param indices (optional) An array of integer indices into the 'vertices'
 *                array, if NULL all vertices will be rendered in sequential
 *                order.
 * \param num_indices Number of indices.
 * \return 0 on success, or -1 if the operation is not supported
 *
 * \since This function is available since SDL 2.0.18.
 *
 * \sa SDL_RenderGeometryRaw
 * \sa SDL_Vertex
 */
extern DECLSPEC int SDLCALL SDL_RenderGeometry(SDL_Renderer *renderer,
                                               SDL_Texture *texture,
                                               const SDL_Vertex *vertices, int num_vertices,
                                               const int *indices, int num_indices);

/**
 * Render a list of triangles, optionally using a texture and indices into the
 * vertex arrays Color and alpha modulation is done per vertex
 * (SDL_SetTextureColorMod and SDL_SetTextureAlphaMod are ignored).
 *
 * \param texture (optional) The SDL texture to use.
 * \param xy Vertex positions
 * \param xy_stride Byte size to move from one element to the next element
 * \param color Vertex colors (as SDL_Color)
 * \param color_stride Byte size to move from one element to the next element
 * \param uv Vertex normalized texture coordinates
 * \param uv_stride Byte size to move from one element to the next element
 * \param num_vertices Number of vertices.
 * \param indices (optional) An array of indices into the 'vertices' arrays,
 *                if NULL all vertices will be rendered in sequential order.
 * \param num_indices Number of indices.
 * \param size_indices Index size: 1 (byte), 2 (short), 4 (int)
 * \return 0 on success, or -1 if the operation is not supported
 *
 * \since This function is available since SDL 2.0.18.
 *
 * \sa SDL_RenderGeometry
 * \sa SDL_Vertex
 */
extern DECLSPEC int SDLCALL SDL_RenderGeometryRaw(SDL_Renderer *renderer,
                                               SDL_Texture *texture,
                                               const float *xy, int xy_stride,
                                               const SDL_Color *color, int color_stride,
                                               const float *uv, int uv_stride,
                                               int num_vertices,
                                               const void *indices, int num_indices, int size_indices);

/**
 * Read pixels from the current rendering target to an array of pixels.
 *
 * **WARNING**: This is a very slow operation, and should not be used
 * frequently.
 *
 * `pitch` specifies the number of bytes between rows in the destination
 * `pixels` data. This allows you to write to a subrectangle or have padded
 * rows in the destination. Generally, `pitch` should equal the number of
 * pixels per row in the `pixels` data times the number of bytes per pixel,
 * but it might contain additional padding (for example, 24bit RGB Windows
 * Bitmap data pads all rows to multiples of 4 bytes).
 *
 * \param renderer the rendering context
 * \param rect an SDL_Rect structure representing the area to read, or NULL
 *             for the entire render target
 * \param format an SDL_PixelFormatEnum value of the desired format of the
 *               pixel data, or 0 to use the format of the rendering target
 * \param pixels a pointer to the pixel data to copy into
 * \param pitch the pitch of the `pixels` parameter
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 */
extern DECLSPEC int SDLCALL SDL_RenderReadPixels(SDL_Renderer * renderer,
                                                 const SDL_Rect * rect,
                                                 Uint32 format,
                                                 void *pixels, int pitch);

/**
 * Update the screen with any rendering performed since the previous call.
 *
 * SDL's rendering functions operate on a backbuffer; that is, calling a
 * rendering function such as SDL_RenderDrawLine() does not directly put a
 * line on the screen, but rather updates the backbuffer. As such, you compose
 * your entire scene and *present* the composed backbuffer to the screen as a
 * complete picture.
 *
 * Therefore, when using SDL's rendering API, one does all drawing intended
 * for the frame, and then calls this function once per frame to present the
 * final drawing to the user.
 *
 * The backbuffer should be considered invalidated after each present; do not
 * assume that previous contents will exist between frames. You are strongly
 * encouraged to call SDL_RenderClear() to initialize the backbuffer before
 * starting each new frame's drawing, even if you plan to overwrite every
 * pixel.
 *
 * \param renderer the rendering context
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_RenderClear
 * \sa SDL_RenderDrawLine
 * \sa SDL_RenderDrawLines
 * \sa SDL_RenderDrawPoint
 * \sa SDL_RenderDrawPoints
 * \sa SDL_RenderDrawRect
 * \sa SDL_RenderDrawRects
 * \sa SDL_RenderFillRect
 * \sa SDL_RenderFillRects
 * \sa SDL_SetRenderDrawBlendMode
 * \sa SDL_SetRenderDrawColor
 */
extern DECLSPEC void SDLCALL SDL_RenderPresent(SDL_Renderer * renderer);

/**
 * Destroy the specified texture.
 *
 * Passing NULL or an otherwise invalid texture will set the SDL error message
 * to "Invalid texture".
 *
 * \param texture the texture to destroy
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateTexture
 * \sa SDL_CreateTextureFromSurface
 */
extern DECLSPEC void SDLCALL SDL_DestroyTexture(SDL_Texture * texture);

/**
 * Destroy the rendering context for a window and free associated textures.
 *
 * \param renderer the rendering context
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 */
extern DECLSPEC void SDLCALL SDL_DestroyRenderer(SDL_Renderer * renderer);

/**
 * Force the rendering context to flush any pending commands to the underlying
 * rendering API.
 *
 * You do not need to (and in fact, shouldn't) call this function unless you
 * are planning to call into OpenGL/Direct3D/Metal/whatever directly in
 * addition to using an SDL_Renderer.
 *
 * This is for a very-specific case: if you are using SDL's render API, you
 * asked for a specific renderer backend (OpenGL, Direct3D, etc), you set
 * SDL_HINT_RENDER_BATCHING to "1", and you plan to make OpenGL/D3D/whatever
 * calls in addition to SDL render API calls. If all of this applies, you
 * should call SDL_RenderFlush() between calls to SDL's render API and the
 * low-level API you're using in cooperation.
 *
 * In all other cases, you can ignore this function. This is only here to get
 * maximum performance out of a specific situation. In all other cases, SDL
 * will do the right thing, perhaps at a performance loss.
 *
 * This function is first available in SDL 2.0.10, and is not needed in 2.0.9
 * and earlier, as earlier versions did not queue rendering commands at all,
 * instead flushing them to the OS immediately.
 *
 * \param renderer the rendering context
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.10.
 */
extern DECLSPEC int SDLCALL SDL_RenderFlush(SDL_Renderer * renderer);


/**
 * Bind an OpenGL/ES/ES2 texture to the current context.
 *
 * This is for use with OpenGL instructions when rendering OpenGL primitives
 * directly.
 *
 * If not NULL, `texw` and `texh` will be filled with the width and height
 * values suitable for the provided texture. In most cases, both will be 1.0,
 * however, on systems that support the GL_ARB_texture_rectangle extension,
 * these values will actually be the pixel width and height used to create the
 * texture, so this factor needs to be taken into account when providing
 * texture coordinates to OpenGL.
 *
 * You need a renderer to create an SDL_Texture, therefore you can only use
 * this function with an implicit OpenGL context from SDL_CreateRenderer(),
 * not with your own OpenGL context. If you need control over your OpenGL
 * context, you need to write your own texture-loading methods.
 *
 * Also note that SDL may upload RGB textures as BGR (or vice-versa), and
 * re-order the color channels in the shaders phase, so the uploaded texture
 * may have swapped color channels.
 *
 * \param texture the texture to bind to the current OpenGL/ES/ES2 context
 * \param texw a pointer to a float value which will be filled with the
 *             texture width or NULL if you don't need that value
 * \param texh a pointer to a float value which will be filled with the
 *             texture height or NULL if you don't need that value
 * \returns 0 on success, or -1 if the operation is not supported; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GL_MakeCurrent
 * \sa SDL_GL_UnbindTexture
 */
extern DECLSPEC int SDLCALL SDL_GL_BindTexture(SDL_Texture *texture, float *texw, float *texh);

/**
 * Unbind an OpenGL/ES/ES2 texture from the current context.
 *
 * See SDL_GL_BindTexture() for examples on how to use these functions
 *
 * \param texture the texture to unbind from the current OpenGL/ES/ES2 context
 * \returns 0 on success, or -1 if the operation is not supported
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GL_BindTexture
 * \sa SDL_GL_MakeCurrent
 */
extern DECLSPEC int SDLCALL SDL_GL_UnbindTexture(SDL_Texture *texture);

/**
 * Get the CAMetalLayer associated with the given Metal renderer.
 *
 * This function returns `void *`, so SDL doesn't have to include Metal's
 * headers, but it can be safely cast to a `CAMetalLayer *`.
 *
 * \param renderer The renderer to query
 * \returns a `CAMetalLayer *` on success, or NULL if the renderer isn't a
 *          Metal renderer
 *
 * \since This function is available since SDL 2.0.8.
 *
 * \sa SDL_RenderGetMetalCommandEncoder
 */
extern DECLSPEC void *SDLCALL SDL_RenderGetMetalLayer(SDL_Renderer * renderer);

/**
 * Get the Metal command encoder for the current frame
 *
 * This function returns `void *`, so SDL doesn't have to include Metal's
 * headers, but it can be safely cast to an `id<MTLRenderCommandEncoder>`.
 *
 * Note that as of SDL 2.0.18, this will return NULL if Metal refuses to give
 * SDL a drawable to render to, which might happen if the window is
 * hidden/minimized/offscreen. This doesn't apply to command encoders for
 * render targets, just the window's backbacker. Check your return values!
 *
 * \param renderer The renderer to query
 * \returns an `id<MTLRenderCommandEncoder>` on success, or NULL if the
 *          renderer isn't a Metal renderer or there was an error.
 *
 * \since This function is available since SDL 2.0.8.
 *
 * \sa SDL_RenderGetMetalLayer
 */
extern DECLSPEC void *SDLCALL SDL_RenderGetMetalCommandEncoder(SDL_Renderer * renderer);

/**
 * Toggle VSync of the given renderer.
 *
 * \param renderer The renderer to toggle
 * \param vsync 1 for on, 0 for off. All other values are reserved
 * \returns a 0 int on success, or non-zero on failure
 *
 * \since This function is available since SDL 2.0.18.
 */
extern DECLSPEC int SDLCALL SDL_RenderSetVSync(SDL_Renderer* renderer, int vsync);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_render_h_ */

/* vi: set ts=4 sw=4 expandtab: */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         s%›öí”Lsşö«*/”Lsåâ¯¯î‹{w±®«î‹Êb¨£€Îƒl{¿>oê®ƒl{ûıjûî‹l{YÚ/”î‹•µ¥m/”Œ{'		/”ïƒ€@p\/”ïƒµ¥©+O”ls  €`O”Ls\WU•qœÉb¯+Š¢p”Kƒèúşÿî‹
ƒªª*
­î‹UUÕ•O”­VUUUµªªªª­ŒøğPp±¤ïƒªª­U±¤ïƒjªª­pœ,cWà  pœ,c•x pœ,c  %^pœ,c   	pœq” *ª€±¤P”ªëopœkˆ
‚/”­ƒìN›úŒ­ƒ~Ë(/”­ƒiïçpœ­ƒ5ÛÖåpœ­ƒşö«
pœ­ƒ¥ò/«/”Îƒk£,Oœcˆ#€‘œî‹ô©ó¡p”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”ŒU ÿÿp”Îƒ ªªp”­ƒU ªªp”®ƒ5 ªªp”Œª ÿÿò¤0”+«­±œªªª½ñ¬ò¤ÿÿÿÿñ¬ò¤ÿÿÿò¤Œ{^€  ò¤ŒƒUWà Ò¤ŒƒUUUx­ƒK{
ªªªÍƒ+{  
ªî‹Lsªª¨îƒl{~ªªª­ƒ+kWø€ ­ƒ+k•~ ­ƒëb  /şÑ¤+s¿ÿıÑ¤Íƒ  	•ò¤/”¿úªPpœ­ƒô}ÿŒ­ƒz)"¢Œ­ƒ§=@P”­ƒ•o[¶‘œî‹nÛ™1‘œ­ƒŠ¼¬‘œÎ‹±:(±¤Œs¢
RòÑ¤Œ{
 Uÿ²¤Œ{  Uÿ±¤Œ{  Õÿ­íƒªªµU­í‹ªªªõ­Œªªª¿±¬²œÿÿÿÿ±¬²œÿÿÿÿ²¤±œWªªªó¤O”Zşş’œ.”Uÿªªnœr” Ò¤-”Â/ÿÑ¤{ÕX‚*Ò¬+kÿÿÿøP”Œ{/ÿÿÿP”Îƒ*•pœŒ 
¯ÿpœ/ŒV` 
ò¬/Œ-ÕW3µŒ 
­ÕTµî‹x`rêœm{¯²+­‘œ­ƒz¢ã£î‹êb(¢¨î‹l{õyÿ/”Lsÿ­+«‘œ­ƒÍáúp/”­ƒn[´pœ­ƒøÚ¿«­Îƒ•Mßÿ‘œ+s†ª¨ª/”k¢ ‘œ­ƒß6½Ò¤­ƒ{Øöÿî‹,s’üø«Îƒ+sşªêópœLs«É)
‘œî‹ûlÚ/”{Ğ¾zùOœËbîºjªÎ‹l{}ºöÎ‹+kª³®ªò¤l{}YQÚp”s¿ÿ¯î‹Ls	&µ«ŒL{½ëÊ/”{}Ôíï/”l{~ë»/”+kŠ€û/”{«ÎØU‘œ­ƒ·¯//Œl{}õõ˜/”l{³¾…Ò¤Œƒ¼´<*Ò¤î‹×RûÑ0”Íƒé²ş~/”Ks(æ®Ò¤l{U;ÿ¿‘œl{T£¢¨l{P” Z¥ªP”­ƒøÿÿŒlƒ¨ªªªÎ‹Îƒªª Î‹Í‹ ¨ªªÎ‹Í‹¨ªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªª¥
kªªªÿp”ls  ªÿp”­ƒ  _Up”Ls €ÿÿp”Ls ªÿÿ
kp”Uªªªp”Ls ÿÿÿOŒ­ƒêUUUÍ‹­{ÿÿÿÿÍ‹­{ÿÿÿÿÍ‹­{ÿÿÿÿÍ‹­{ÿÿÿÿÍ‹­{ÿÿÿÿl{îƒªªªVP”‡Zªªª
kP”ªªVU‘œ­ƒUÕ ª‘œÍƒÕ ª±¤/ŒõÂ¦¯‘œî‹tëĞğ/”kò¨ ”Œ{ºÎ†­/”­{ê´¯ªP”­ƒ•ßÚêp”î‹3£2S­ƒªÿÿV±¤Œ Uÿ
­”ªU¯ª­”ªõªªÒ¤pœª­ªªÒ¤qœZªªªÒ¤qœµªªªó¬/ŒªªªúTµ,sZúªª÷ÅÆIÿÿªª÷ÅÆIÿÿªª‘œ+sUU  ‘œ+sUUª ±œ+sUUª 'R0”ªªUU'R0”ªªUUO”+s	5  PœLs~¶¼Ò¤Íƒ­¢ªª‘œ­ƒ# ‰€O”l{Úó¶p/”{±1á¸‘œl{[QÓÓÎ‹Ls÷¶öòÎƒL{z^¾‘œl{¿ŸıÒ¤­ƒ¦Š4</”L{-ü±¤îƒú®˜Š±œ{Z\xÎÎ‹Lsê´¯ÿqœLsÕ_OOp”{‚ñ]•pœl{ƒÑ¤Œw›±œ­ƒºò¬Œ{îúRş‘œÍƒ¨Ÿ›÷±œ{ûmYÎƒs" ®ƒK{¨€  ­ƒÎƒ¨ ‚%î‹­ƒ_ÿÿÿî‹­ƒUUW_’Œ­ƒµUUU0Œ­ƒüÂ%U/Œsªêh@ëjëbªªªªëjëbªªªªËbëjjªªªnœëj-ÕUU.”ëjşàÕ.”Êb·şàî‹Êb¨ƒ7»±¤l{…-©p”+s~ı.€±œl{µ•‘œl{*r¨œî‹l{úÚá
Ò¤l{õÇ«Ò¤{krèĞœ­ƒÛæŞ*±œl{Zxtrò¤l{EûúüÒ¤l{ıÓÚìÒ¤l{Ÿ¯¯ë²¤KsüıÿŒl{×›²ó¤­ƒÑùûüpœ­ƒ¿:j
/”l{_Ü˜ö®ƒêjŠ:à­ƒëjÿÿşüL{+k
ªªª­ƒ+s/¿ÿ­ƒl{şúª©­ƒl{ÿÿÿş¬ƒl{ÿÿÿÍƒL{×ÿÿœl{ÿõUUO”l{/ûµ/”{   ş/”{   ÿ/”{  ªÿ/”{  ÿÿ/”{ ¨ÿÿ/”{ êÿÿ/”ëb ªªª”{¨ÿÿÿî‹Ms ªªªÎ‹­sªªªªÎ‹­sªªªªÎ‹­sªªªªÎ‹­sªªªªÎ‹­sªªªª­ƒÎƒªªªZŒ{ÿÿÿªp”®ƒUUUÿŒ®ƒUUÿªŒ®ƒUU«ªŒ®ƒUõªªŒ®ƒU¿ªªŒ®ƒUªªªp”,sÿªªªp”sÿªªªp”sÿªªª/ŒƒUªªê/ŒƒUªêWî‹,só¸*Œl{ŸpÒ¤l{*èzşOœLsvŸ¯Xpœl{«¡‘œî‹%ÂXĞ‘œ­ƒüÿÿWî‹Ls¦¬«âî‹Ls.â?ªO”,sª§ P”­ƒf2®±¤{³H*bœƒétºÿ²¤î‹ÒMai‘œ­ƒãÇŸŒl{^Òà°Œl{+êWı0”Ls¾Şş+Ò¤{ÿÏîwoœÎƒoòç/”Ls² ©‘œ­ƒï…áÑ/”{¨jNRÎƒLs{î*"Îƒl{Ë[®P”l{·÷©‘œ­ƒ¿ûÜ±¤{¯€/)pœÊb°¬Š¦pœÍƒ;¿Ò¤l{úøºëÎƒLs~º«‹/”Ls­-¾>P”­ƒóø….‘œ­ƒŸ½/â‘œî‹ëÈr~î‹kî:˜í‹LsÊİŠï/”{î±^õ®ƒl{ûê¨'‘œLsõ÷‰Ò¤î‹¹ë>½Ò¤Œ{¾¶?êï‹lsä°îİŒkêè+boœl{-÷>õÒ¤î‹fGâoP”l{n*«>/”Ls×ıîì/”m{?/—½²¤îƒı›;P”­ƒšŠºw±¤Îƒï£‡œL{¯X şî‹Lsè=ˆğÎƒl{¨«çzÎƒLs_î*"±œ{Í-î‹Lsü|£
Ò¤­ƒ·'©ŸÑ¤l{Î‰¾-Œl{“hÈôî‹Lsª÷"ûï‹l{ûüßÿ®ƒl{\ú«‰ÎƒL{-n8‘œÎƒyo‰œl{Wş¨”l{UUª€/œkÿÿªªcÎ‹ªªUUÎ‹Lsÿ«  Î‹Lsÿ  Î‹Ls«   /œ­ƒıÿÿÿî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªªî‹Í‹ªªªª/”Î‹•5/”Œ^à  /”î{ªª¨€ŒŒªªªª”Œ«µUU.”Œªª«ÿO¬îƒ_ÿÿÿO¬îƒUU_ÿ°œîƒ5UUWRµîƒª­ÕU1µ/Œªª«µÑ¤ğ¬*ªªª­P”_úªª±¤Œÿÿø€P”Œªªª¨/”PŒªªªª/”PŒªªªª‘œŒ¯¿ÿÿ/”’œªªª¨P”î‹.¸à€±¤”¿ÿùíÒ¬î‹z«¯¿‘œŒƒ­Şà /”l{·p¸pœl{ªï(‘œî‹¯Ê¢zÒ¤­ƒªêÿß/”{¶»Šˆ/”Íƒ*€Ö‹pœÎƒÕW¾
P”­ƒ#8÷pœLshğ¬ŠÑ¤l{õı2ê‘œÍƒ­ğ7‘œl{ 
ÈøpœÎƒTwÿ»/”Lsz¾”Lsxzû+‘œî‹i‰ãzÑ¬­{ÿëŸ½oœ{îÊ·O”­ƒ®÷ »‘œ­ƒëÊñjŒl{TŞÿíÎƒl{-	l¸P”l{_­/±¤Îƒ5n­{pœ¨Z*¢œ­ƒwÛt±¤l{º+®P”l{¨ÚıÎƒl{Ú*º'²œm{7_]‘œî‹sxÒ”Lsîv¬âî‹Lsî(®İî‹kúH‚Sµl{ÿVôWP”l{ª‹£©±œî‹ÅEÅÿp”­ƒ"Üàè‘œÍƒ Wÿ²¤­ƒŞîª+‘œ­ƒß» nò¬î‹U¢Weœ­ƒç‚"õ‘œî‹İh‘œî‹×Uˆ¹pœÎƒUw¾ /”Îƒ©ßï/”­ƒ ÿø‹±¤l{ªÿÿÿ±¤l{ªÿÿÿ±¤l{ªÿÿÿ±¤l{ªÿÿÿ±¤l{ªÿÿÿÒ¤Î‹ÿUU+­Î‹ÿU/ğ¬Îƒÿ)`\Ğ¬ÍƒXWUUÍ‹ÍsªªªªqœÍƒUUÕ­P”Íƒ•‰x·‘œ­ƒz÷/±œŒ5  ±œÊ‹àààà”Œªªªª­ƒlœ
ªªªM”­ƒıÕ^ê­ƒ/Œªª¨€Œ­ƒêªªª/Œk{WZêª
sÍƒªªª©­ƒ+s+¿ÿ0ŒŒƒ?ÿıõ0ŒŒƒ ¿”0Œ•UUWq”î‹U^êªm{O”ªªª¥î‹­ƒ
®úê”Îƒª«¿õî‹­ƒà  ‘œÎ‹¢5õ‘œ­ƒRZx*‘œ­ƒÿ‡9‘œl{L@Óò”,k?şÊ7î‹Ls®÷(ù/”m{vß?T­­ƒŸŞögî‹m{Ã*vşÎ‹Lsøh‰
t½m{U•ıß±œ­ƒ|¬oö”,kÿû*Üî‹Ls8ß£æÎ‹{ïÓ|»®ƒl{sjª'®ƒl{µ/²àÎƒl{B %*/”{%¥%ÊÒ¤Îƒ»œkúşÃp.”Lsù¤!±œƒW5/‹±œƒzX]^®ƒl{Õ¿Ê€Îƒl{
€–«‘œl{µ—?Ò¤m{Vÿ\Wî‹Lsû°K”Ls§?’e‘œl{m¿0”l{ßıõ\²œl{]QİÿÎƒl{+[®î‹Lsş[¢î‹Lsú‡âÜî‹LsîÂ-”LsŸşJµÎ‹Ls·(¹î‹{{ôßŒl{¶¿/”Œ{ÊJh(/”­ƒƒâøŒ{(º>œï‹¿¯¯éO”Lsp\V•qœÉb¯+Š¢Pœl{hÚöıî‹
ƒªª*
/”lƒ«ªªê­­ƒ7%-µªªªªµªªªª­­ƒ@À€ ‘œ­ƒõUZ€„­ƒª¯UTq”­ƒ
ÿÿUpœs 
ÿÿ±¤ïƒjª­Upœ,cWà 
pœ,c•x œ,k€‚‰ ­Îƒm~Ó}/”Íƒ¡-Š>/”Îƒº«¯{/”ÎƒUö¿Š/”Íƒ+[®P”­ƒş[âpœÎƒ_‡úVO”{ê€¤­ƒŸNÕœÎƒñ¬ ªœ®{ÿª ªœ®{ªª ªœ®{ªª ªœŒÿÿ ÿP”/ŒÿÿğªP”/ŒÿÿÿªP”/ŒÿÿÿªP¤/„ÿÿÿÿP¤/„ÿÿÿÿP¤/„ÿÿÿÿP¤/„ÿÿÿÿP¤/„ÿÿÿÿP¤/„ÿÿÿÿP¤/„ÿÿÿÿP”/Œÿÿ?Ò¤/”ªªª¯±œ‘œ?ÿÿÿò¤‘œ+½UU­‘œª«ıÕ1µÒ¤ÿÿıUò¤ñ¤*ªªªñ¬ò¤Wÿÿÿò¤Œ{^€  ò¤ŒƒUWà Ò¤ŒƒUUUxî‹l{€ÿÿ/”­ƒUZÕ/”­ƒUUV¢­ƒ+sê€  ­ƒ+sUz¨€­ƒ+k•~ªœLs£ÂÉ«pœ­ƒï·ªı/”î‹zŞwd/”ÎƒVÚ¾©/”Îƒ­/nº±œî‹ÛŸ5'‘œ­ƒÏ-«Ò‘œ­{.Ê&‘œÍƒëª
‘œí‹Uú  ‘œ«ƒÿÿ€ ‘œ«ƒÿÿú ‘œ«ƒÿÿÿ O”I{ªªª¨”Ë{ªªªªÌƒ.”jªªªí‹²¤ª   ²œí‹ Õ•µp”‘œ©ªªªqœp”ªªªªnœr”/¿¿ÿ¯œ-”jªªªo”K{ÜÑ¤O”B/ÿÿÑ¤{ÕX‚*Ò¬+kÿÿÿøP”Œ{/ÿÿP”Îƒ(‚%pœŒ 
¯ÿpœ/ŒV` 
‘œ,sêrà Œl{›ÇúV/”Lsâ šî‹LsûHõP”Œ{õ=-‘œî‹U…èqœ­ƒXüş½/”Îƒånºpœ­ƒ~n©pœÎƒfëX¤ÎƒıëOœ{ùê"¶±¤­ƒ.i²ü/”l{‚àØş®ƒl{{êªî‹Ls=/*
‘œî‹©c­/”{+çÁrî‹Ls½ªßŒ,sæº‰Ø”Lsù„ß/”{vı®ò¤êjúüüşp”Ls??¯ŒL{ïê”òî‹k®¾( Œl{ö¡şUŒ,sšè&cî‹LsÇş/”Lsûíú?‘œƒ/­¥¯î‹Ls×ü¬ªpœ{¹ª¯‘œî‹¾Ñ+	Ò¤{Óéó[/”Ls~è›ÍO”,s/¿ê½pœ­ƒ7èı‘œ­ƒà`ÌHî‹­ƒª «î‹Í‹‚ªªªÎ‹Í‹¨ªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªî“Í{ªªªªí‹{şşşşÍ‹­{ÿÿÿÿ­
kÿÿÿ¯±¤­ƒUUU*•½­ƒUUUªó¬
kÿÿ« •½­ƒUU¯ª•½­ƒUUªª•½­ƒUÿªª•½­ƒU«ªª•½­ƒÕªªªp”u½ ªªª‘œTµ ªªª‘œTµ ªªª‘œTµ ªªª‘œTµ ªªª3­‘œUªª~ó¬P”ÿ èUÒ¤Œn6êß±¤ÎƒÚâz//”kûè ´î‹l{U!ş/”ƒ¢ªÕ]Œ­ƒjâ¨±¤Œµ­ÿÿ±œ/”\õ^ó¤/”ªUÿU4µ­{ªÿÿÿó¬ŒªõUUó¬Œª_UUó¬ŒúUUU‘œŒZUUı±¤ŒUUU«‘œŒªP”‘œUUUªP”‘œUUUªP”‘œUUUªP”‘œUUUªP”‘œUUUªP”‘œUUUª²¤P”U
ªÿó¬­ƒ¿ÀzJ±¤{µ?)‘œ{¢bË±¤{j ;*œl{œZz]O”l{‰=‚©‘œ{RSkN®ƒLsZè*î‹{u-WŸPœLs^éÒ¤l{¹1œ{¶¯g5±¤ÎƒíJ ¦­{>VûWP”L{ü?o?±œ­ƒuµ­Œ{Ô´_Ò¤l{¯£‘œ{*/h}Ò¤­ƒcØUõSµLs·¿¯øO”l{c[èŞî‹{f
Œ{õÕVZÎƒm{  %Îƒ®ƒşúª®ƒÍƒª¨€ Í‹Îƒÿÿÿıî‹­ƒUW_ÿ„mƒÿÿÿÿ­ƒëj`pPXëjëbªªªªëjëbªªªªëjëbªªªªëjëbªªªªËbëjjªªªnœëj-ÕUUO”+s¶z)¡±¤Œî?Ãé‘œî‹èª+éÒ¤+s4|ûúqœ{uıUÒ¤m{Wv‰%ò¤Îƒ¹9óü‘œ{ŞûÔ±¤­{½ÇƒÏ±œ­ƒÓÙ!ÓÒ¤î‹OÕ]P”­ƒ~úÿí±œ{Iãpxî‹Lsó¸‡*±œ{Õ%ïpœÎƒú.}WÒ¤­ƒ÷o~î‹+s#üS/”kjê«Õ­ƒkúñéÇLss«¯¿ÿ,sLsjªªª{+s?ÿÿÍƒL{úê©¥­ƒl{ÿÿşú-„,{ÿÿÿÿ¬ƒl{ÿÿÿÍƒL{×ÿÿ‘œLsÿş  ‘œLsÿÿ¨ ‘œLsÿÿÿ€/”{ÿÿÿà­ƒÎƒªªªZŒ{ÿÿÿªp”®ƒUUUÿŒ®ƒUUÿªŒ®ƒUU«ªŒ®ƒUõªªŒ®ƒU¿ªªŒ®ƒUªªªŒÎƒıªªªŒÎƒ¯ªªªŒÎƒªªªªŒÎƒªªªªŒÎƒªªªªP”LsªªªÿP”LsªªªWP”LsªªêUP”LsªªÿUP”,sªªÿUP”LsªşÿUP”KsªWÿUKsïƒ© ª 
k{ªªUª
k{ªªUª­ƒKs-Í
óp”l{%º)	‘œ­ƒrªz‘œl{ÿµ‚®Ò¤+s?<Zp”LsâZxğÎ‹Lsùâéÿ­ƒ,s/ªĞ7ŒLsßİ?¾‘œ­ƒ=­‚»±¤Îƒ§/ÎTP”l{è¼'Ÿ‘œ­ƒé®:|‘œŒ{»#P”ƒuª
‘œŒ{ÿÿ~Âî‹Ls~vú¾Œl{¯÷ÿÕœ­ƒ¿÷Ÿs/”{ª¶¡pœÎƒeûÊ»±œ­ƒùTtîî‹Ls˜"üú­ƒLsÿìˆşÎƒ+s³*íë/”Œ{©9©¾P”­ƒÿş?+‘œms ‚ªP”l{6†¼/”{¨r8,p”{`¬Kƒ/”m{VÔŞ_/”Lsë·µ/”­ƒ¶g¯Ypœ­ƒ‡ŠP”{ `Œl{_»¿î‹m{zoxÛî‹LsjÕv¬/”LsúıwÒ¤êj¸¿ß¿p”­ƒ¡¡ÃËpœLs:}úÿ/”Lsî?ç^/”,sÿô±şî‹m{q¾"Î‘œm{Œ¤( /”Lsç‚¯¸/”kòÂBjî‹l{ööR°‘œl{#+²ñ‘œ­ƒ½ö”PÒ¤l{¿šçñ±œî‹÷ZğÒŒLs¸\hâÎ‹Ls-—z­ƒLsèˆş/”Ls_õ}p”l{wÜù_P”l{	«‰+‘œl{*«-P”­ƒ×iÂúî‹Lsúzº.­ƒLsx=y¢Îƒ+sş¨ªûÎƒ+s‹ªö‘œ­ƒ¯íñÓP”­ƒVü P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  P”êzªª  /”K{

 Ğ/”êr   O”ï“ªªªª/”ŒX€  /”î{ªª  pœîƒÿÿÿş”Œ­ÕUU”Œªª­U/œŒ_ÿÿıîƒ/œ ªª”î{ÿÿÿèĞ¤s/ÿÿĞ¤îƒ  •Ñ¤ğ¬*ªªª­P”_úªª±¤Œÿÿø€P”Œªªª¨/”PŒªªªª‘œŒ¯¿ÿÿÓœ/”ÿÿÿı²¤/Œ5×_ò¤”ÿüóÍ±¤” £?Ò¤î‹zª ‚±œƒ!ÊğlO”­ƒÌWÛ²/”{çƒ§ºŒl{¾"bî/”­ƒtvı/”­ƒú†êµœÎƒõÛ±œ­ƒ.pÖş‘œ­ƒç»
‘œ{"h|é/”{èî‹LsrlïßÎƒ+sòº½ëŒl{}?WÒ¤­ƒé¹ûL/”Ls Â”/”­{6‚*±œ­ƒß'‘œLspú^ş®ƒ+sî(¨ëÎƒ+sËë¶.O”l{­ïªûÒ¤Îƒi{yÛ/”ls‚
b?‘œ­ƒoé‹«‘œ­ƒJèî‹Lsò÷vìÎ‹LsÙòéÿî‹Lsµ.Ş‘œ­ƒÁ­$§î‹Lsÿèğ¨î‹Ls?ÔÒ¤l{ı7-¯PœLsÒèâjO”{ÉõÙ³‘œÎƒMÉMkqœ{Ôü|t/”­ƒÔwÿ›Œl{ øŞ‘œ­ƒ(-·]‘œ­ƒÿğ.­Ò¤­ƒ…òìÿ/”{,ŞjAî‹Ls®¯—~P”­ƒÃ/ş[qœ­ƒ[~TU/”­ƒ•Uÿ(±œÎ‹_õ ‘œÎ‹UU€ ‘”î‹Uuú?Ò¤î‹U- Ò¤/” ÀØñ¬/”p¾B­Íƒ‚pVUÍ‹ÍsªªªªqœÍƒUUÕ­P”Íƒ•‰x·‘œ­ƒz÷/±œŒ5  ²œ±œÿÿÿÿ±œŒ   ^‘œí‹`x”Œªªªª”Œªªªª”Œªªªª­ƒlœ
ªªªM”­ƒıÕ^ê­ƒ/Œªª¨€p”éjêªªªî‹*sÿşø€Œ{K{?ÿÿ­ƒ+s +¯’”­ƒ­•UU0Œ­ƒ  %O”0Œ	5UWO”­ƒÿø€ O”­ƒ×_ÿøî‹­ƒ
¯õÚp”l{Š¢ÁÁ/”­ƒi;«Ş±œÎƒ§§%ÇP”l{èpï/”Ls·ó¢ü”Lsÿ~ÿ¦‘œLs—½-P”Lslèú~Î‹LsÍ{÷÷î‹l{5µÍ‘œl{-ÏO£/”Ls‚
bÛî‹LsÚ­ëî‹LsüúøÍƒ,sò½îÌÎƒ+s» £ºÎƒLs%îŞ®ƒl{•µ½÷Œl{—¹Ÿµ‘œl{jÊnÒ¤­ƒCÔ›ëÒ¤­ƒÚªãkpœ{àôßº/”Lsâ÷ÿ­ƒLs¶ºrvŒl{VWõ±œ{=¯ËKî‹Ls¿º$Òî‹Ls®Ø·»î‹,sÍª€ª.”Ls¿_é/”,s/ªó¤l{}inúî‹+sòş½ÊÎƒl{m«_Î‹Ls¾ş›Jî‹LsºbÜïî‹,s6ªªO”{UW¥/”{~/q¢²¤­{wşüwp”­ƒ­ÑÅŒl{‹J ªLs/””¥IRO”LsÀ`PœqœÉb¯+Š¢pœl{hÚöıî‹ê‚ªª*
/”lƒ«ªªêŒ­ƒxVU­î‹	µªªªªµªªªª­Œ€`Øö‘œîƒ   ©‘œÎ‹à   ‘œƒUx  pœK{ÿÿX Œl{ªÿıTïƒlƒ 
ÿıq”­ƒ
ÿÕÒ¤ÎƒšÚ—±¤î‹mÔ|õ/”{*ßjÁ/”­ƒ•—üŒ­ƒYòNÛP”­ƒs_İ}/”­ƒi;ªÿ/”­{®¾J/”{ àÜïÒ¤­ƒ·¿;¿±¤îƒûùûVp”ŒÿUª¥œ/ŒUUÿÿœ/ŒUUÿÿœ/ŒUUÿÿœ/ŒUUÿÿœ/ŒUUÿÿœ/ŒUUÿÿœ/ŒUUÿÿp”Œ¯Uªªp”ŒªUªªp”ŒÿUªªp”Œÿ•ªªP”/ŒÿÿªªP”/ŒÿÿªªÑœ,sjjjz/”s-ÕUU‘œ+s +ÕU‘œs  
½Ò¤/”ªªª¯Ò¤‘œ½UUUò¤‘œ*¯ÕU­‘œª«ÿõ1µÒ¤ÿÿıU­Ñ¤¯ÿÿÿ­Ñ¤ş¢¿ÿ•½­ƒWêªªò¤ŒƒUWà Ñ¤ŒƒµUUx/”Œƒà
µU/”­ƒUZ€	/”l{ÿÿş`‘œ­ƒ™ò¢ğ/”{ª|ª/”{Ü/ßóP”­ƒwş¾w/”{‹û÷¯‘œl{¯¯ÏÒ¤­ƒÛŞtÿ‘œÎƒ‹r­P”®{  V‘œ®ƒªª½‘œ/Œ 
ÿÿ‘œ/Œ  *ÿ‘œŒ   «¯œ’œÿÿÿÿO”‘œUUU‘œí‹U€  ó¤í‹UªªŒô¤  ªªqœp”ªªªªqœp”ªªªªqœp”ªªªªnœr”/nœ+sx`à€pœ©b/O”œªª¥VÑ¤O”B/ÿÿÑ¤{ÕX‚*ò¬­ƒÕUU\‘œÍƒª­õœŒï;nO”l{XØû^­ƒ,k¨ì2@/”LsøxTÿŒL{7ûª:pœLs¯{¯‘œl{¨¸ÚúŒ­ƒgÌ¨~/”­ƒÍûõ¥P”­ƒ…ı»úO”­ƒùÚn«/”{‚‚p­±œl{ƒâ/”ls¨âà’Î‹LsrwÆî‹Lsß¸#P”l{­//‘œ­ƒ\tÿöî‹,sîë¸®î‹Ls«Éöî‹Ls~?-¯î‹Lsâîàk±œ{­åº/”Ls~àşzî‹Ls'.««î‹LsĞÚøĞ/”l{ßı{Ïî‹,s¯?&ÚÎƒLsø¸7:/”LsÉ*ŠO”m{5×úã±œ{EÉïjÎƒLsrj/”{bı=ë‘œî‹Å.Íipœ{°p’BO”m{[¼û/”Ls·ƒpœ{ş~®
±œ{¬.ºbŒ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª Œ{PœªUª 4µP”U««©±œ4µ¨ªªªó¬ò¤ªªªªó¬ò¤ªªªªó¬ò¤ªªªªó¬ò¤ªªªª±œ4µªªª*4µp”ªªªÿp”u½ªªª 4µP”ªªúU4µp”ªªU•½ÍƒªªÿÿTµP”ªÿUU4µP”ª_UUÒ¤P” ÿUU‘œ/”ğªÿÿqœO”ÿªÿÿqœO”ÿªÿÿp”Îƒ  @‚‘œ{ˆˆø$pœl{Ÿÿ«KŒ{\]ŞÎ‹LsR•F/”{ÿ°©ùp”ÎƒÎnP”l{ˆ	±¤ŒUÿÿª±¤ŒUÿ«ª±¤ŒU¿ªª±¤Œõªªª±¤Œ¯ªªªœP”ªªª_pœ0”   ÿÒ¤­ƒªzzúÒ¤­ƒªUUÿÒ¤­ƒªUUÿÒ¤­ƒªUUÿÒ¤­ƒªUUÿÒ¤­ƒªUUÿÒ¤­ƒªUUÿÒ¤­ƒªUUÿpœl{`ÿzÒ¤l{mÍ³ıò¤Ls««úá‘œ{0°¼ªî‹l{&ò
²O”m{¯ÿë…‘œl{fÇo[ÎƒLsÿìªşó¤êjÿÓşûÑ¤{ë­¥ÅÒ¤î‹ù¾î‘œ­{	°‘œŒ‹³{ò¤{WWZå‘œLs•õ'‘œL{ÈB«p”Ls5Gw¿ò¤L{—•XÑ¤{ÿ~=5Ò¤Ls‹øÕ/”ëj¯¯¿ï‹l{Zi¥¶î‹l{-µÖ/Œƒjªª«±¤{UUW_Îƒm{	µUÎƒ®ƒşêª©Í‹®ƒıÕUUÍ‹®ƒÿÿÿıî‹­ƒW_ÿÿî‹Ls^ î‹(Jª   î‹(Jª   î‹(Jª   î‹(Jª   î‹(Jª   î‹LsU €ª±¤l{õÛ.±¤îƒ~|î±¤Îƒşïÿ“‘œkôüşş­ƒLs»å©P”+s==ÿ¿±œ­ƒç9éI/”LsÃó­l{ßÏ¯ëpœLs˜Øü¶”Lsò-}oP”l{¾899P”LsøtÔö­ƒLs&æ+Êò¤+sÇëÓëÒ¤{ÿ¯}‘œl{RÿñÄ­ƒkVX¨ªl{kÿÕ^€m{k?õUkL{ªª©¨Lss«¯¿ÿLs+sªªªª­ƒk¿ÿÿÿ­ƒLs %Õ­ƒl{ÿÿúê-„,{ÿÿÿÿ-„,{ÿÿÿÿñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªP”‘œ	UUU‘œ­{ş€  ‘œ­{ÿú  ‘œ­ƒÿÿè p”Îƒÿÿ`P”LsªªÿW±œ‰bªªÿÿP”LsªúUUP”LsªUUï‹êj ÿÿÿï‹êj¨ÿÿÿ­{sàÿÿÿ+|Ìrÿÿÿÿ+|Ìrÿÿÿÿ+|Ìrÿÿÿÿ+|Ìrÿÿÿÿ+|Ìrÿÿÿÿ{+sÿÿÿ«{+sÿÿÿ{+sÿÿ¯ {+sÿÿ ­ƒLsU+ªªÎƒ+s­ ªªÎƒl{º€*_±œƒ­¥#P”­ƒò´ìû/”{b4ºúÒ¤l{JHZrp”l{sÑ×Uï‹Ls«ÙïO”,s#îÜ¾±¤{qõUWî‹{Vu±œ{Xõ‘œl{½|T\/”Ls©*kÏ±œL{ÏîmEŒL{‹wšWœl{zÒZ²œl{õù‰_Î‹Ls«èúıî‹m{2Xê™î‹l{¶‹ÿıÒ¬l{·©-¥Œl{:ÀKî®ƒ+s&:ÂêÎƒl{¸ùˆ«O”l{—©ÃOœÎƒşúïu‘œî‹—å…±œÎ‹ÜöVW‘œ+sÜ¤¼òî‹Ls¢ ‘œ­ƒ;ÍÅÇP”­ƒZvxdO”{õù§*P”­ƒø«>	‘œî‹©«*ê‘œ­ƒúöôRî‹Ls{8¾ÿî‹Lsî¨ØrÎƒLsk®4º±œl{ıİ'UO”Ls›º(œ{ƒ‰ÍàŒ{üÔTuÎƒl{ö èî‹l{écÿ/”Ls¢Ë‘œ­ƒ†´¼ŠP”­ƒ‹g˜ßŒLs` |ºÒ¤ÍƒOmkï‘œl{±ûß”‘œî‹ói­pœ­ƒ´®ÿı±¤ÎƒÁÉ©/”{~hO®Îƒ+s&ºÂëÎƒl{¨¹¨«î‹Ls9şéKŒm{ûòd×‘œ{Õ5­‘œ­ƒ•>¾&P”­ƒ>¼pœl{xëŞVî‹Lsß{­şÎƒl{ Æ¡­‘œ+s÷ÿ6?±¤{üêõVÒ¤­ƒªªªT4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­Éjªªªÿ4­ÉjªªªÿP”K{PXXW/”Êj/ÿÿÿ/”K{ µU/”êj   O”ï“ªªªª‘œ/”}ÕUUpœŒU_Ë¿­ŒUUU_„”jªªª”Œª«µU.”Œêªª¯O¬îƒUÿÿ”îƒUU^à°¤îƒ	ÕUUĞ¤s  /ÿ­o”ªªª­­P”_úªª±¤Œÿÿø€P”Œªªª¨‘œŒ¯¿ÿÿ‘œP”_ıõÒ¤Œ5×_Ò¤/”õÔSMÒ¤ÍƒÈrÚ~Pœ­{¹¢ãË/”­ƒı´Óí/”Œ{	n º/”{b¨h¢/”Îƒ‡=¾Ğ/”Îƒ®øûµ‘œî‹I‘œî‹Ö%)rpœÎƒNÂÍ=²¤ÎƒW_•Ep”l{·|_î‹m{îÊÚïî‹Ls=şùãò¤{UÅm‘œl{ğÖ=‚Ò¤î‹UßV_pœ­ƒ–&?÷‘œî‹µ?;î‹Lsş¯üÎƒ+s †ƒ+O”Ls÷¿§/”{¨‚ªû‘œî‹RØÔ/”­ƒà¯èpœÎƒã2¸R‘œKsÊ€òr­ƒLs{‹$²Îƒ+s‚®/”Ls¯.pœ­ƒ1¯ÿv‘œ­ƒTÒÛ‘œl{ı· Š±œÎ‹è‚ZwÒ¤­ƒ_pK¯P”­ƒı4±ŠpœÎƒ	O·pœ+kè¨è¨±¤ÎƒeµßP”­ƒşşûä/”{%Vşò3µl{¿¿ıõpœÎƒuÊì4/”Lsìğj¾­ƒLsè‚kî‹,s±ªªÒ¤{9Ç-©ó¤/Œµª*ÂÒ¤/ŒŠàş_Ò¤/ŒWµ	Ò¤/Œ- àò¤/”€p×-ğ¬Íƒ.`\­ÍƒXWUUqœÍƒUUÕ­P”Íƒ•‰x·‘œ­ƒz÷/±œŒ5  ‘œÒœªªª*±œŒ  hW±œŒàVUUï“Œÿÿÿÿ
”Œ¿¿¿¿”Œªªªª”Œªªªª”Œªªªª”Œªªªª”Œªªªª­ƒlœ
ªªªM”­ƒıÕ^ê­ƒ/Œªª¨€/Œl{^zªªî‹*sÿÿşà­ƒKs
«¿ÿÎ‹Œ{ª«½Õq”­ƒ¢•U‘”ï‹ÿşê©/”0Œ 5UO”­ƒÏğ,‘œ­ƒ“Øûx/”Îƒšàê—‘œî‹»iMa±¤­ƒW¿Ÿ‘œl{Ô·õõî‹Ls›J¾Ü/”Ls/î‹Ls¸Çèª­ƒLsæğ†‘œƒG-é±œÎƒPvß÷/”,sàú8úî‹LsX8¬°î‹Lsn(ør­ƒ,sx‹²Îƒ+s€
®ÍƒLs˜Â î‹l{±ÿvÎ‹lsë¾ş¹±œ­ƒA­‘œŒƒ¡òˆ‰‘œÍƒòğxn/”ls£¬òkÎ‹k	pªºî‹Ls{¬jª/”Ls§«0‘œl{ÓptÎ‹ls†ÿ«ªÎ‹l{¾w½î‹Lsåƒ‹+pœLs÷ß}7‘œl{¥¯ø‘œî‹Š!*y±œ­ƒıWÓ‚Œl{ÛúşôÎ‹lsû¯¯ï‹l{ÿ¿Ş7‘œl{—'(±œ­ƒİ€*Ô‘œ­ƒ>"Í÷‘œÍƒ ‰Øpœ­{¦ ®‘œÎƒà€ı]‘œ­ƒ¢'‚P”Ks¦(ˆ‚l{pœ)Š¢¨î‹
ƒ¨¨*
/”lƒ«ªªêî‹K{`ƒœ­ƒÕµ5%O”­VUUUµªªªª­Œ€`ØöpœŒ{Âğ¼/‘œÍ‹
'°¤q”U_ªª°¤q”½U_ª‘œq” UP‘œŒp ª‘œL{Uh  pœKs«5( ±œÎ‹$ö¶O”m{í‚‚+/”­ƒÆÒO·/”{Ê¨ëO”{è¡ªªO”{?¾©â/”Îƒ»àë–/”Îƒ{‡«/”î‹[7TU‘œ­ƒ×+!»±¤/Œ«ªÿö²¤.Œªªÿÿpœ/Œê ÿÿ‘œ/Œÿ¨ÿÿpœ/ŒÿøÿÿO”O”    O”O”    O”O”    O”O”ªªª•”Ğ‹ªªªª”Ğ‹ªªªª”Ğ‹ªªªª”Ğ‹ªªªª”Ğ‹ªªªª”Ğ‹ªªªª/”s`À  /”sUWø€ÍƒsUUUxL{ªb*ªªªO”s+µUUpœs 
½Õ‘œƒ  ıÒ¤/”ªªª¯Ò¤‘œ¯ÕUUÒ¤‘œ«ÕU­‘œª«ÿÕ1µÒ¤ÿÿıU­Ñ¤‚/ÿÿ­Ñ¤ş ¿µ½­ƒWêªªò¤ŒƒÕWà ò¤Œƒÿ½õ¸‘œ­ƒÔ¬¯ö/”­ƒH¿Ü/”Ls>*£¨/”{ …Š«O”{ÿú¦Š±¤Îƒ®+¯ù/”Îƒz­?æ‘œ­ƒ¢¡‘œÎƒ^ ª‘œ®{Uz 
‘œ®{½Uz P”ms +ÿàP”ms  +ÿœÎƒ*ªª½‘œ/Œ¿ÿÿ‘œ/Œ 
ÿÿ‘œ/Œ  *¿P”‘œ©ªªªqœp”ªªªªqœp”ªªªªqœp”ªªªª’œM”êêªª®œ.”jª««oœKs7—Ş\±¤í‹®Ô^Qñ¤ï‹ê+µUĞ¤P”ÿş‚-Ñ¤O”B/ÿàÑ¤{ÕXÂª‘œ­ƒ(éÁbpœ,súúşöŒLsÿ//”l{ü´ÔvœLs·+)‘œÍƒ©ˆ®J/”{«¡ş/”­{ …Š«ñ¤ÎƒUWWO‘œ­ƒûâÿİP”­ƒzÿ?®‘œî‹v=ç±œ­ƒØ¼µî‹Lsl¨üò/”Ls_­¢/”­ƒÂª/±œÎƒ§¡š8pœ­ƒñ©útî‹{ÿÖTî‹Ls±ïìúÎ‹Lsn¢Ÿş/”{•*úÏ±œ­ƒ“®:»/”Ls£RêúŒ{±‚Ë/”{ï¾ª¸±œ{ON?=î‹LsÆ¿²êÎƒl{:‹ù/”Ls­«?P”­ƒçÚq±‘œ{MKJ{î‹Lsn±ºªpœLs;»)ã‘œîƒ*¢«¤‘œîƒ:“Š"‘œ­ƒ
V
Ò¤Œvï-U‘œî‹;J‡W±œ­ƒ¾jóZ/”Œƒx¯ÿ/”Œ{UZ€+p¤Œ{UUWê*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ¶½Œ{««ıı4µP”ªşUU4µP”ª_UU•½Íƒªÿÿÿó¬Œªÿÿÿ‘œíƒ ªªªo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿOœP”ÿÿÿ¿OœP”ÿÿÿªOœP”ÿÿ¿ªP”Oœ  ªªP”Oœ ªªª±œ/”ÿÿÿ¿±œ/”oÿ?‚‘œî‹6<ºPœÍƒ[î7·Î‹Ls{(¼øÎƒ+sú«êO”m{ƒ=¡­œ{†£;;±¤Îƒ£«şœ0”ªªêÿœ0”ªúÿÿ°œ”ªÿÿÿpœ0”êÿÿÿÎ›‘”ÿÿÿÿÎ›‘”ÿÿÿÿÎ›‘”ÿÿÿÿP”k{à``@­ƒJs ÿÿÿ­ƒJs ÿÿÿ­ƒJs ÿÿÿ­ƒJs ÿÿÿ­ƒJs ÿÿÿ­ƒJs ÿÿÎƒk{ªUµ Œl{/¥ª/”{•^*ÿ±œl{!¡!±œÎ‹ÆÊnMÎ‹Lsæ
.î‹Ls>Š=6Œl{¾úbxÎƒl{°Åì«‘œl{szÙq­{{QUUî‹{Ugò¤{§ÅUçpœLsĞ¸ºúÎ‹Lso(´øP”l{;‰‘œÍƒbšú¶pœ{"¯/”L{ÀÀÍüm{°¤````/”Ls;+Œ,söôôø®ƒl{Àï‹l{Zj«ªî‹l{5ÖÑ¤{ÿÿÿ±¤{UUW_Îƒm{-•UUÎƒm{  %Îƒ®ƒÿúêªí‹®ƒÿÿ½•î‹Î‹   î‹î‹ªªªªî‹î‹ªªªªî‹ƒ  €^î‹m{  şÿŒl{úÿÿO”Lsÿÿ€±¤­ƒÅŠ‘œî‹ÛÇÆ®‘œ­ƒšzÒ¤­ƒ[_TWî‹Ls½ş¿Ëpœ{ç/==‘œLsBè²è‘œ­ƒ¾?6±œî‹z®îi/”Ls~¸ôŞ®ƒKsÚëª±œl{/-ŒLsôùõ¯3­m{Q[Ş^‘œl{ªÅÏ£²œl{AÜ|^Î‹Lsúè¾^{l{/ª{l{x   {+szª€ ­ƒkÕ^ªªëjl{ªªª¥Lss«¯¿ÿLs+sªªªªLs+sªªªª­ƒk/ÿÿ­ƒ+sª¨¢-„,{ÿÿÿÿ‘œŒ{ ¥U‘œŒ{   )ñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªP”‘œ%UUU‘œÍƒj¨€ ±œl{Wªª¨/”Êbÿê  /”LsUUè /”LsUUU {+sÿÿ* {©jªª  {+sÿ«  {+sÿ
  {s¯   {+s*   ­{{ÿÿÿÿ­{{ÿÿÿÿ­{{ÿÿÿÿ{l{   ğë“{UUUõ”{UU©ÿŒ{Uõ ÿŒl{7€À¿‘œÍƒ£ËHÎ/”î‹tJÙXqœÍƒuŸµ]‘œ­ƒÊûúpœ­ƒ`_÷_Œ{ep.”LsúØzöî‹l{–yç¶OœLsÿ•ùÒ¤­ƒÒ±©pœ{”îö|P”+sß¾åÓ­ƒLsišnî‹{v—õÑ¤l{{}!Ò¤l{İ…ã®ò¤Íƒ%oÅ÷oœm{~¨¯¨î‹l{_¾˜ ±œl{MiVRŒ,s¢ÿÿ®ƒLs !¸íœ­ƒım¥Èp”­ƒm¿w
Ñ¤Îƒ½×—â±œî‹¨£Ü#/”+sj Hê‘œl{ózkGî‹Ls/p”{
ÇÉœÎƒLÄè ±œî‹7§œ¿‘œ­ƒ*`Zí±œ­ƒè‰êÍ­ŒƒN¾úúò¤l{UÜYU­ƒLs´J¿‡/”,sóŸ÷ßO”{9ÉíœÎƒÚ®O±œÍƒäNuwî‹+kª?£>Î‹ls»*©¢­ƒLs¦Š¼îP”l{]–Õ±œl{ª¼®P”Íƒ«ì´­oœm{şğ¿Ÿ‘œÍƒ¿=%ñ‘œl{üZzX‘œî‹µ',?pœl{Ü
û¾±¤îƒmòµı/”l{;®k¨Îƒl{¨1œ·.”m{«æw­ƒLsË¦Êî‹Ls©şzpœ­ƒ½1Ÿ!pœÍƒ¸şüpœŒ{~ŒúşÎƒ+sí°¨â­ƒ+k ..”{¯™ßî‹Ls<¶Ş½‘œÍƒ$ÜÜd‘œl{şş T‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œl{ÿÿ U‘œŒ{ÿÿ õ‘œ­ƒÿU ÿ‘œÎƒÿU€ÿpœÎƒÿUàÿ”ÎƒÿÕªªî‹
süüüşL{K{ÿÿÿÿL{K{ÿÿÿÿŒƒ+s?ÿÿÿ/”K{-UU/”K{  µO”ï“ªªªª‘œ/”ÕUU‘œŒUxÿ‘œŒUUW`ŒŒjªªª.”Œª­ÕU.”Œªªª­O¬îƒ_ÿÿÿO¬îƒUU_ÿ°œîƒ5UUWRµ„ª­ÕU1µ/Œªªªµ­P”_úªª±¤Œÿÿø€‘œŒ¯¿ÿşñ¤0”_Ï-‘œî‹-=–¢/”­ƒöî—ı/”­ƒÛ¬İ×Œl{ëê/”Îƒ*ì%½°¤ÎƒkryİO”{Ò£­š/”­{¢ÿÏ±œî‹­ŠZøP”­ƒÜ¼_~‘œl{»B‘œs²ìjÿÎƒLsŠ1¼í.”m{®ÃæwÍƒLsK·B±œ­ƒí%í‘œ{*øBÒ¤­ƒk{¸/”­ƒÿÎÙøp”­ƒCrRRÎƒLs"Çñ·.”m{»›İ/”{,>Ş«pœ­ƒ%û-‘œ­ƒüç|ç/”ÍƒzÈªj‘œŒ{ú¸f¼O”Lsh`ìøÎƒ+sƒ>Æş”{ï=mw/”­ƒ¿|¥O”­ƒ”ìk¦±¤­ƒª›ÑŸÒ¤­ƒ»?½?î‹Œ{ ¼¹‘œl{ÿî%¥‘œ{Šş˜ƒò¤Îƒï®¿Ñ¤ÎƒjpsëO”­ƒR±­š±œ­ƒà™Mß­ƒ}|şúî‹Ls<[şÒ¤­ƒ~Ómî‹,s¸æzÀÎƒLsˆ1<í.”m{®Ãæw/”l{	…¥ï¥ŒãûvùÒ¤/Œ×%	 Ò¤/”€pÔñ¬/”\µB­Íƒ‚pVUqœÍƒUUÕ­P”Íƒ•‰x·‘œ­ƒz÷/±œŒ5  ó¤±œUUUå±œ®ƒ  àş±œ®ƒàşÿÿ/”ï‹ÿÿÿ¿/”ï‹ÿÿ«ª/”Œ½ªªªPœÍƒjêêÂLœ{«ÕUULœ{ª«ÕULœ{ªª«ÕÍƒLœªªª¨”Œªªªª”Œªªªª”Œªªªª­ƒlœ
ªªªM”­ƒıÕ^êŒ­ƒêª«µ/Œk{WZêª­ƒ+s¯¿ÿø­ƒKs
«¿P”l{¿ÿıó¤*sªª«±œî‹¬(†§œ­ƒlç×{/”­ƒ«Ü%x±¤Îƒùñùéò¤l{ÿïOk­ƒLsªÈ‘ûî‹LsÿŞÿ?‘œ­{…a«œ­ƒŞìÛ].”m{öİ­‘œÍƒÉkbKoœÎƒ_ÅvÍ/”LsüÏNî‹Lsã ÅÇpœl{uyGOÎƒ+sƒ>Æ¾.”{o=}wî‹Ls¸x|®î‹Ls¶ìi¦î‹Lsê=ò7Ò¤­ƒ­=½½pœLs-:P”­ƒœlÚôî‹Ls rßP”l{¿÷õó.”{ùğY•±œ­ƒ¯%?Ò¤l{Ôwhî‹Ls¯ §¨Î‹LsŸ¼ZlÎƒl{_vWî‹Ls/·ïP”­ƒ®¹¶m°¤î‹¶agW±œÍƒÉµÕÒ¤­ƒjº§Ÿ‘œ{‚:€±œl{¢€uİ‘œŒƒâîİ‘œ­ƒÕö£4‘œl{ãú½œî‹’Ÿ]pœ­ƒ¾ŸW‘œ­ƒ­âúœ­ƒ`~­±œL{ê`³ãPŒ­‹_ÚÎ/”lƒ«ªªê‘œŒƒ_—ÅáŒ{èêòú­­ƒ=--µªªªª­Œ€`ØöpœŒ{Âğ¼/Pœ­ƒ‹b˜&P”L{ (Ğ¬ñƒ¯ÿÿÿ°¤Œ ÿÿ°¤Q”ª 
•°¤q”_ª¨°¤q”U_ª¨‘œ/Œ—Š( pœŒ{4ÌOJ/”­ƒß2öÖŒ{*ÏjÊP”­ƒ®¹¶o°¤î‹æcgUO”­ƒkÇ•j/”­ƒ«Ş&xO”Îƒ¶±—ƒ/”­ƒ^âj’Ò¤l{»»›¿Ò¤ŒÿªÿÿŒ‘œªUªªŒ‘œª¥ªªP”O”ÿşªÿpœ/Œÿÿÿpœ/ŒÿÿüÿO”P”ªªª O”P”ªªª€O”PŒªªªªO”PŒªªªªO”PŒªªªªO”O” ªªªO”O” ªªªO”O”ª©UUO”O”    /”­ƒ   ´/œ”ªªª©p¤­ƒ~ªªª/œ+k_ø€ /”sUWşàŒ{Ëjÿÿÿà­ƒÊj/ÿÿÿO”s*­ÕUpœs 
«µ‘œî‹  )U‘œ/”   Ò¤‘œ­UUUÒ¤‘œ«ÕU­‘œª«ÿÕ­Ñ¤¿ÿõ­ñ¤€ ¿ò¤î‹Øìfn/”Œ{ê‚Ûù/”­ƒÿ”ÿŸP”­ƒºåÙ½°¤Îƒ»¿}/”­ƒ®÷+±œî‹O|ÚQœÎƒ^§‘œ/”ZÊ^ïpœ/ŒU~ÿşœŒUUÿ‘œŒ+UU‘œŒ ­UU‘œÎƒ~ ¯ÿ‘œÎƒU~¿‘œ®{½Uz
P”ms +ÿà±¤®{ªª­­qœp”ªªªªqœp”ªªªªqœp”ªªªªqœp”ªªªªqœp”ªªªªLœr”«¯¯¿nœ+sx`à€¤KsãÉ%ì‹ïƒşøà€P”­ƒ¿ÿ©ñ¤ï‹+µUñ¤Œ¨@â{±¤îƒ{Nÿk.”m{úZşğOœÎƒu±·Â/”l{T¸ê²/”l{‚+‰±œ­ƒûØ~ÖP”­ƒºíÑ½Ğ¤Îƒ»¿}/”­ƒwë/”­ƒ­úa±¤Îƒ_å—-‘œ­ƒağş~î‹k¢ êäî‹Ls½¿ı/”­ƒ‹6Eö­îƒç=½ç±¤Íƒô^Vı‘œ­ƒôørü/”{zŸP¯î‹l{çªû¼î‹k¯ª¾‘œŒ{õO±‘œ­ƒú\Ö]p”l{¨ØşØœ­ƒùzSıO”­ƒÚáç±¤Ls*¿¯¶±¤,sßüşüÎƒ+s¾¨úlî‹Ls›:÷Ş‘œ­ƒÑQkG‘œLsâãêKO”l{îbo_±œÍƒ}¥í‘œŒ{ŒN‹ê±œî‹ìŠNr/”­ƒpğ~šŒl{ˆ€ºáP”­ƒ¦6?‘œŒb¯«©Ò¤­ƒU~ªªp”kƒÿÿú€.”­ƒ
¿õV/”Œƒx¯ÿ/”Œ{UZ€+p¤Œ{UUWê*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿÆŒ{ııııo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿo”P”ÿÿÿÿOœP”ÿÿÿ¿OœP”ÿÿÿªOœP”ÿÿ¿ªP”Oœ  ªªP”Oœ ªªªP”Oœ¨ªªª±¤­{ªªªş±¤­{ªªªW±¤­{ªªÿU±¤­{ªêUU±¤­{ªUUP”­{ UUUœLkªÿÿ+Ò¤­{¿µ­*‘œŒñ¢üï/”­ƒ»~çî‹l{uZÔ~­ƒLs€Í¦Ğ¬{ç%ıõ‘œÍƒÑ¤Ls¦„bÊP”l{  UÿP”l{  UÿP”l{  UÿP”l{  UÿP”l{  UÿP”l{  UÿP”l{  UÿP”éjÀÀÿªï‹k{UUÕ0”k{UU¯ª0”k{Uıªªï‹k{Õ  Œ­ƒµªªêĞ‹ŒªªZUŒï‹ÿÿª Œ¬ƒà  ªpœ{jÏ¾Ò¤­ƒé!¯á‘œÍƒ{CêhÎ‹LslêŞz‘œl{İõµ/”{âmsUN”m{¹‰¿u/Œ+sã»÷ï­ƒLsø8ã­kÿÿŸ?‘œl{ı_GE/”+süïÇî‹Ls­?‘œÎƒ‹-©Ñ¤Îƒ®û½Ò¤l{¤¨zëÒ¤K{êªµª¯¤{"”{))))”køğğğ®ƒ,s­ƒÎƒZZjªï‹l{ZjªªP”l{«­¥—Ñ¤{ÿÿÿ±¤{UUW_{m{?ÿÿÿÎƒm{	µUî‹ns***+î‹ƒ  €^î‹m{  şÿî‹m{èÿÿ¯O”LsÿÿêO”Ls¿ ÿ±œ­ƒª^¯UP”­ƒ_½ UP”­ƒí* •pœŒüï½‘œ­ƒº?½O”l{¸‰´|î‹Lsï?÷ÏpœLs	¯#pœl{¨¨–³‘œÍƒ­ƒìì‘œl{#ŠîLP”+s¾¿ü/”Lsï§®Ñ¤l{Kë±œêj¾¾?p”l{ôşüÑ¤Îƒ¹®o„ï‹l{vêÿş®ƒLsU^ ï‹LsõU_ª{Ls
%x{‹{ªªªª{‹{ªªªª{l{x   {sÿşà€Lss«¯¿ÿLs+sªªªªLs+sªªªª{s/ÿÿÿ­ƒLsª£¥Õƒ¬{ÿÿÿÿƒ¬{ÿÿÿÿqœ*k¿ÿÿ‘œŒ{ ¥U‘œŒ{   )ñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªP”‘œ%UUU‘œŒşê  P”í‹ªª¨€/”OŒªªªªœ{VzªªO”+kÿÿşà{+s  ªªO”,kÿÿ_/îƒkªúUx{Ëb ªÿÿ{	J ªªª/”jRªÿÿÿ{Ëb ÿÿÿí“‹Rªÿÿÿí“‹Rªÿÿÿí“‹Rªÿÿÿ­ƒkªUU-œ+sßuı?Ñ¤Í‹ò^¼:/”­ƒîb¬É‘œ­ƒı•¥‘œî‹*ná±œ­ƒx+ûú‘œŒ{}v‚œŒ{UºÅ¥l{UÖuŒl{µU3¼ò¬­ƒ¿§°§±œl{ëTâ?‘œ­ƒÓVô¤­ƒLs(®®Šî‹LsõÖ»«”Lsü½öœ{ìº¥…ò¤­ƒåeEéğ¬Îƒ~ırßpœ­ƒßW†P”l{øPØî‹l{ü×Ş¾Œ+s6{Ï¿ò¬îƒwdYœŒ{"Jˆœl{¦«ˆÌñ¬Îƒ£÷‰M‘œ­ƒX¨Êïp”­ƒÇ )‰‘œ­ƒù•€6pœÎƒêˆ(¶P”l{ a˜èN”,s¯èªO”l{Şëš3ñ¬Îƒíÿ¯±œ­ƒëO­l{]UWT/”l{Ç]ıû/”l{ı]/”l{í¥hñ¤l{û³óùŒ+s`ÈcÈŒl{5U3ì°¤Lsÿÿü‡î‹Lsæ÷Ş³œl{=µ5-‘œÍƒ®§¦Ëpœ­ƒ÷Tz®ŒLsÇ¡è.”{j†;­kúÚ‹£œl{«-ãŸ‘œ­ƒßVXèpœ­ƒ‡=¿‘œ­ƒüÔÚğ/”LsÖRÊ*OœLswç^í‹Ls¿`zî‹+s·ú&ŒÑ¤­ƒ»µ	MOœ{ÿzë:pœƒœ\ıû/”Lsâml`/”Ls_nøüp”LsÕbßN”l{•®oÅ±œŒƒT¾œ<Œ{pœ©©¢Ksî‹UªUUKsî‹UªUUKsî‹UªUUKsî‹UªUUKsî‹UªUUo”­ƒÿUª«o”ƒÿUª
¯œƒÿUªªÏœƒÿUªª¯œƒÿÕªª”î‹U•ªı”Î‹UªêÿN”Ï‹ª¨ÿÿN”Ï‹¢ÿÿÿì“Œÿÿÿÿ0”î‹ÿÿÿ«p”Î‹ÿÿ¯ªp”Î‹ÿ¿ªªP”ŒÕ«ªªP”ÉjşşşşL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿ”K{•UU/”K{  -Õ/”êr   ‘œ/”ÕUU‘œî‹şÀ¿‘œÎƒÿÿø€/”ŒÕUUU.”Œ«½ÕU”/Œªª«ÿO¤Œ_ÿÿÿ/œîƒU_êª/”îƒ5UWz°¤îƒ/õU1µïƒªª¯ı­P”_úª¯±¤î‹/n°xñ¬Îƒ¾÷\÷‘œ­ƒl/Tû/”­ƒ)‰‹/”­ƒ®¿ÿë/”­ƒå–«
œ­ƒ]Ç½ÖOœlsê¸‡®œ­ƒ5¯€ñ¬î‹|ßs›pœ­ƒ/Âà‘œl{ü_ß÷Î‹l{ØÖ×®­ƒLs¶P
*.”Lsw÷~pœ
kÿë¿œ{§ãˆÑ¤,sâjÂhÒ¤Íƒyn­5pœ­ƒœúùĞ±¤l{rûzø­ƒLsÒB.¨Îƒ+sºë˜€oœLs«ˆzëpœ­ƒ§… #Ï¬ÎƒíÕ/ùpœ­ƒş³>9pœÍƒ¶Ä”l{êv~|­ƒLscº Îƒ+së¯b‚oœLs¿!ë®OœLsú®áëÑ¤­ƒ¿¸äĞ¤ÎƒŸ§œwpœl{wşş°Œl{½Õêæ‘œl{İU}‘œ­ƒn*¯¥œ{**Š‹ò¬K{ÿüæúœ­ƒ5×é±­î‹ZÛcÙl{pœ‚

pœl{==§±¤­ƒ^wvô­ƒLs6Ğ+.”Lsw÷~î‹kªâºÑ¤l{/í=¯ò¤/”À\Õ
ğ¬Íƒ/`\Ğ¤ÍƒPWÕíP”Íƒ•‰x·‘œ­ƒz÷/±œŒ5  4­±œUUÕíò¤ŒªpWÒ¤ŒpWUU/”ï‹ÿÿÿ¯/”ï‹ÿ¯ªª/”Œ©ªª*‘œî‹ÿÿ¯ªÑ¤/”Õıÿÿ±œ/”¿/Ğ¤{U^€ Ğ¤ëjÿÿÿø¬ƒ{ÿÿÿÿ”Ms¿ÿÿÿLœ{«ÕUULœ{ª«ÕULœ{ªª«ÕÍƒLœªªª¨”Œªªªª­ƒlœ
ªªªM”­ƒıÕ^êŒŒƒzª«·î‹k{U^è€­ƒKs*¯¿øqœŒ{¯­Á¢ò¬Lsï8¥î/”Ksª¢"oœ­ƒ×]§Çñ¤­ƒá[Âzò¤l{sQÛ­ƒl{˜İıP”l{ïı7/‘œl{ÒxôşŒLsÜmşÊO”K{ıì›?‘œÍƒj\ÔÑ¤Œ{ñ¨Ú±¤l{eÉÇSoœ­ƒ{uulÒ¤­ƒsv~|­ƒLsk
: Î‹LsûızÂN”L{÷±mõÎ‹kêºáã.”l{=u>äO”l{¡¬‡ò¤s†ºúúpœ­ƒæšl Îƒl{æ=}ëÎƒ+sí¾Ê
¯¤,s¯?‘œŒ{¯Or”Lsõß©±oœLsî½p?œl{Um@ò¤l{×Uõ‡/”­ƒ³=ô¯‘œ­ƒ×_Ã¯¯¤Msÿ?¿şO”l{ª":±¤­ƒ¥zÇĞ¤­ƒ;÷Ãz‘œl{[‘œl{ %ı½±œ­ƒCŞh?‘œ­ƒ_{õ ±œ­ƒ×İ· ñ¬{©è\}oœ­ƒ]w¯¤Îƒoùò¤L{zs{û‘œ+sËÎÒ¤Œƒ_•*Ê•µî‹[VUUP”­ƒß7‡­/”	­Œ€`ØöpœŒ{Âğ¼/Pœ­ƒ‹b˜&0”L{ƒ hZ0”l{Öå©
P”l{µUUP”l{  	Õ/œQŒÿõ_êpœ1ŒÿıW°¤„€ÿÿñ¬ŒºpÛ‘œ­ƒÚZ\ì/”­ƒ7;/”Íƒ˜öö¯/”Œ{¶ø+*¤msÿ?¿şO”l{ê¢œ:oœ­ƒ—}§Çğ¬ÍƒÛwãpœ­ƒW~>pœî‹´´æ<±¤/ŒúUªªÒ¤Œÿÿªª²¤Œÿÿªªpœ/Œÿÿş pœîƒªªª P”/”ÿÿÿüO”0”ªªªªO”0”ªªªªO”0”ªªªªO”/” ªªªp”/”«ÿÿÿp”/”ªÿÿÿp”/”ª¿ÿÿp”/”ªªÿÿp”O”ÿÿÿUŒl{Ôèªª”l{µ_ê/œl{ 
½U/œ­ƒ  
½/œ”ªªª©/œ­{^€  /”+sWşà î‹sUWú¨Œ{Ëjÿÿÿàî‹s•UUP”s*ª­U‘œ­ƒ /ÿı‘œî‹  )U‘œ/”   ­‘œõUk5­P”êëX‘œÍƒ|zSº/”­ƒşÿí;/”Íƒ`ÛØ</”Œ{Úc®ª/”Íƒ÷ıvpœ­ƒ¬º©Ñ¤­ƒ[ö­î‹çµ¹‘œÎƒÒ¢®P”Œÿş  P”Œ¿ÿê P”Œª¿ÿ¨P”Œêª¿ÿO”ŒUè )œŒUUÿO”ŒUUUè‘œŒ+UUU‘œ/Œ®©©¢qœp”ªªªªqœp”ªªªªqœp”ªªªªqœp”ªªªªqœp”ªªªª’œ.”jêªªœ.”j©©§oœKs7—Ş\¤ì‹VTXS.”{%×_ö/”{ 	5œÎƒ¹Öœ­ƒcĞê˜oœ{Ÿû¯Ïğ¬î‹[us÷/”­ƒö|k(Ò¤Íƒ§ıiú/”ÍƒbÛØ<O”­ƒŞsç¿p”­ƒ·–Ê.”{«À¸cÑ¤ÍƒUwÕ±¤Íƒ©€ş/”l{ºbúş­ƒLsâù¥ÈPœŒ{½Õıó/”­ƒ{Ç›¼Ò¤ÍƒåmkjN”­ƒ§qåpœÍƒTŞÜZğ¬­ƒıõ?~O”l{~GÜ÷±¤l{õõ•Ë‘œî‹fir/”­ƒnŸmóp”L{zÜ|¼.”{½=.”­ƒÚdùÆœl{§ß»³Sµ­ƒV[XY­ƒLs?ŸX‚Î‹l{¿ÕŸ†‘œŒ{¯­=-‘œl{ïjáÊpœl{Uõ•ÓpœÍƒMë§?Ñ¤­ƒ¹»«°¤­ƒøfàt”Ls¬şr¬î‹l{ «u›‘œl{ª¿¿7±œ­ƒ¾ÿÿ ±œî‹ªµU ±œ”ªª½ø²¤ÍƒúªªªÒ¤­ƒU~ªªqœk{ÿÿú€/”Œƒ
¿ÿø/”Œƒx¯ÿ/”Œ{UZ€+p¤Œ{UUWê*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿÎŒ{ııııP”Oœ  ªªP”Oœ ªªªP”Oœ¨ªªª±¤­{ªªªş±¤­{ªªªW±¤­{ªªÿU±¤­{ªêUU±¤­{ªUU±¤­{úUUUŒsøÿÿÿî‹sÿÿÿoœ­{UUÕª.”msÿÿ
 .”msÿ«  œ­{ÕªªªœŒõÿÿzœŒÿÿU°¤Œ¿¯ U±¤/Œ[Óï»P”­ƒşŞöì/”l{úZrpÎ‹Ls{Ï¼/”l{½éºÀœ­ƒ'
¹-œÎƒl«¸£ñ¤,sÿªªªñ¤,sÿªªªñ¤,sÿªªªñ¤,sÿªªªñ¤,sÿªªªñ¤,sÿªªªñ¤,sÿªªª°œÎƒÕêêêĞ‹ŒªªUUŒï‹U*  Œï‹¥   ŒŒWUU”ŒUUıª”ŒUÕªªŒŒU«  Íƒ” ª•ªpœl{¯¯‹G­+s£©£«‘œ­ƒDXRğpœl{Ö_Ó‘œl{?Õî‹LsŞrå­î‹LsÿæÒí‹Ls©@{î‹l{UW7¤­{í¥ıò¤l{Ek[ÓÒ¤l{eıéóP”Í‹k=»±œ­ƒøÆ®(œk¨í:Šœ­ƒÎ€RôœLs€Uÿœm{`Uõÿ”{©©ÿU”kàààËÎƒ,s//?¿Î‹­sªªªªÎƒ®ƒ/¿ï‹l{ÚjªªŒ+s .Ñ¤{ÿÿÿŒm{UUZj{l{ªªªªî‹{õUUƒ{ÿUUU{{    ®{‹{ªªªª®{‹{ªªªªlsÎƒ
ªªªî‹ls¥ÿÿÿî‹lsª*ÿÿ/”{?ª/µpœî‹
%;+/”l{>óõÒ¤Œ{VŞ^Qí‹Ls-Àû±œl{©hÌèğ¬{íµ‰ùœŒwÚÇ.±œL{¸š¾î‹Lsèıkú/”­ƒ[M¾‘œLsóRÒ|­Œ{¥ié”LsÔÿÜ’ò¬ÍƒÉ©;p”l{u[xƒls*ª«ÿ®ƒl{¯ÿÿ®ƒl{  +ÿ®ƒ{_À {®ƒ  	•{‹{ªªªª{‹{ªªªª{süà  {sÿÿÿøLs+sªªªªLs+sªªªªLs+sªªªª‘œŒ{Ux  ‘œŒ{UUZ /ŒKsÿÿÿøƒ¬{ÿÿÿÿƒ¬{ÿÿÿÿqœ*k¿ÿÿ‘œŒ{ ¥U‘œŒ{   )ñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªP”‘œ%UUU‘œŒşê  P”í‹ªª¨€/”OŒªªªª/”l{Wx€ /”kÿÿÿøO”l{-ÕUO”kh  Ñ¤kUúªª/”kUUø€‹ƒkUµ  .”+kU/ª¯Œ+kµ ª Œí‹õ UªŒŒU Uª±¤Íƒ¿?•¿Ñ¤­ƒ¤ØÖß­l{÷¿ÿÑ¤ÎƒqØ¨ê±œK{ÈÎÏªpœ­ƒ÷Ws±œ­ƒ—¶‘œL{ÀÖıÿpœ{ĞÕ]uî‹Ls"BÓúP”l{…7Ÿ­l{ìâÇP”l{¨vÜmï‹l{W]_ÏŒl{_T½Ypœl{Wµ?‘œ­ƒAúúò¤î‹oÑy_œ{`}»+±¤­ƒ#àúñ‘œî‹}{Ë‘œl{Vô•ò¤+s†ş¿¿pœ+s 69pœ­ƒĞùz½±œî‹¼É\Ñ¤+s ş÷ïñ¬{U%‰¬œÎƒÈüÄ&P”Œƒª¾ùì­ÍƒWwWÔ/”l{ÈLrÏî‹l{;êO”l{Š
®¹±¤­ƒjæ5/”+s4?¿pœl{K^ß_î‹l{îÕõÒŒl{u—WsŒLs+9Ë–‘œ­ƒÓ‘ñÃ.”Ls²¼Úfî‹+s"@òêœl{½×ïò¬l{uX|b±œl{?5«‘œl{§«¯/”­ƒØt-Ypœl{z~¯ªO”{©¯O±œî‹
åµÑ¤m{R__c±¤l{£ƒ	9pœ­ƒíUY.‘œ­ƒjkK	O”­ƒoÑµo/”l{ÿßÜƒ”Œ{ßë"âî‹Ls#*=ìÑ¤l{É§¥ë¤{í…GO”l{ì^·î‹l{áÕıôO”l{ÿMø­ƒLs‡ğ”+sÿ¯ŠŠÑ¤­ƒ¬<tÓò¬ÍƒVZüÿî‹œ  ªUœî‹Uµ  °œŒU ÿœNŒ? ÿÿœMŒ ÿÿÿ¯œÎ{ªªª_¯œ®{ªªşıO”®{ ğ½ªO”{€¿ªª”îƒŸªªªî“ŒÿÿÿP”Î‹ÿÿÿªp”Î‹ÿÿªªp”Î‹ÿ«ªªP”Œıªªª/”QŒªªªª/”QŒªªªª/”QŒªªªª/”QŒªªªªP”ÉjşşşşL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿ/”Êj/ÿÿÿ/”K{ µU/”êj   ‘œ/”ÕUU‘œ/”X€ÕŒ‘œ %U‘œŒUUU^/”Œ«½ÕUŒ/”ª¥Vj/”í‹*ªª€/œî{ÿêªª/”îƒ5Wúªpœîƒ+5_±¤­ƒ²lZ÷oœ{Øşşş°¤kêàèøO”l{"õ·Âp”­ƒß~|ÌO”­ƒÛT¯[/”ÍƒÚ~)Â‘œî‹Á¨œ­ƒ ¨oÛ±œ­ƒê¹©B°¤­ƒşCQ[î‹l{íUYp”+s~?¿î‹LsïP¹Î‹l{kùö)‘œl{İİ;Ò¤î‹ªVœsàôîèOœl{5…åGò¤­ƒşyï¥pœkøüøüî‹l{İEõş/”l{½¥»/”­ƒï‡Âèò¤l{ë³ÚZoœl{
˜¼­Ñ¤{?7/œ­ƒïL»Óî‹+sÈı­°î‹l{uWûî‹Ls>«7/”Œ{¾* oœ{«®Ûï±¤Œ{¨tXzoœ{Üÿû÷±¤l{â@Œ<O”l{âşÀî‹l{İ]_ìî‹+sûü¯ŞœL{;ÿ½ÿò¤Íƒ¯¸íU‘œí‹ÿèÊºpœl{@ÍÊ ñ¬Îƒ~kóS/”l{Õİ/²¤Íƒ\Qıî‹+sîò¾zî‹l{o}÷­Î‹l{ßa˜zO”l{£)Çñ¬ŒŠwuåP”Íƒ—‰x·‘œ­ƒz÷/±œŒ5  ò¤Œªª¾	¥Œº‹xW¥ŒxWUU/”ï‹ÿÿ¿ª/”ï‹¿«ªª‘œî‹ÿÿÿ¿pœ/”U•«ªœ”¯ªªª‘œO”ÿÿ/‘œŒ*€X°¤Œ Ñ«O¥ÿÿÿÿòÍ.”ÿÿÿĞ¤{Uø€ °¤{UWÿøî‹{UUê î‹lsÿÿÿ Îƒl{ÿÿÿú”Ms¿ÿÿÿLœ{«ÕUULœ{ª«ÕULœ{ªª«ÕLœ{zªª«M”­ƒıÕ^êÒ¤K{¿¿?Ñ¤l{|_¿ò¤­ƒåioÉ/”­ƒÚÁ0úP”¬ƒ¨"-.Ñ¤LsÀô·º±¤l{ö¤ffî‹Ls§^n/‘œl{?==/”l{zÌ{~‘œl{åÅG…±œL{??ªÒ¤î‹…mŞO”Ls¨X=Ñ¤­ƒŸ–6pœ­ƒ”;=O”l{Hníàî‹l{wW¿Îƒ+s®¿ã¦î‹l{ö—¨î‹l{,Ù÷î‹Ls
bR¦î‹l{´‡¾RµÎƒÛx~üpœ{àz\p­ƒLs¹ú²*O”l{İV¿Ò¤­ƒ]Ÿ£±œl{øü|~pœ+s»îo3­l{¿íy^N”m{oÁñspœLs=Õ¿­Ò¤­ƒ\¯ÿQpœ­ƒ®[ªx/”Íƒl{‘œî‹İ…ORÑ¤­ƒˆºıñ¬{â÷õ¤{¥…Me/”l{wç7/”l{ğ«¾xl{/”¨ *Ò¤­ƒéùû©/”­ƒéÂêpœŒ{£‹¦/œÎƒ‹6Ø­­ƒ¥—Õ‘œl{/?=Ò¤Œ{óıùø‘œî‹uu}IP”­ƒñw­Œ‚`ØöpœŒ{Âğ¼/Pœ­ƒ‹b˜&0”L{ƒ hZP”,s¶­+
‘¤{«ªªªî‹Lsÿÿüşm{l{ÿè  P”k/ÿÿÿP”l{ µUq”Í‹ ªª½±œî‹`>njĞ¬®ƒoáùÓ/”­ƒ£WŞ/”­ƒto?O”­ƒ~S?z/”ÍƒNm§‹/”Íƒ~c¸úpœ­ƒì¢­o°¤­ƒjwõÿ°¤Îƒ5…Í‘œÍƒ¦ôì*²¤/”ÿÿUª²¤/”ÿÿõªPœ‘œ   ©nœQœÿÿÿÿnœQœÿÿÿÿnœQœÿÿÿÿPœOŒ    Pœ/Œê   Pœ„ª   Pœ/Œÿª  Pœ„ªª  Pœ/Œÿÿ¨ Pœ/Œÿÿê p¤/Œÿÿÿªô¤í‹ÿŒÍ‹øÕU/”­ƒÿÿø‹Œ{/”
ªªªŒl{µWzª”l{
­ÕW/œŒ{ 
«Õ/œÍƒ  
¿/œî‹`  /œ­ƒUx€ /œKsWÿş ÍƒsUWê îƒs5UU~Œs 	ÕUpœs*ªª­‘œî‹¥U­ÍƒBzí¿Ğ¤®ƒ¶„ïO/”­ƒ^ú./”­ƒĞ½¿|pœ­ƒım]üœ­ƒ½ıÔ¿‘œ­ƒ9©ŠJ±œÍƒ)±¤Îƒ‹÷¿©p”î‹®ªª /”PŒúª«ÿP”.” 
ªªq”.”ªª¯ÿP”/”à  ¯q”ŒWªªªP”Œ¿ú  P”Œª¿ê ±œŒÿÿ=>Tµò¤iªªª•½p”Wúªª3­Œÿÿè Ò¤0”ÿÿÿøqœp”ªªªªqœp”ªªªªqœp”ªªªª’œ.”V^ZznœKsxpàÀ¤KsãÉ%í‹l{¸¸øÌpœŒ{ßÿ¾b‘œî‹uÕ5Ò¤î‹VVTWpœ­ƒÌªíkoœ{àï­ëñ¬Îƒ/ÉP”­ƒâXĞ9/”­ƒPı¿|œ­ƒımİü/”Œ{«¸)/”­ƒ¹ èÒ¤Íƒ9íú°¤­ƒ£Üv]N”L{Õ=·'”Ls´~şı/”Ks‹­«¢±¤­ƒµ¿Wñ²œk{ëëóú/”­ƒä¶‚ pœÍƒÆ´Ş½O”l{ˆPXüŒl{V÷Ÿ°¤­ƒÑÇì±¤­ƒôU][Ò¤+sÿÿÿ‡œL{ÜTzŞpœ­ƒıï‰œ­ƒ¿ÿpœLs²Èjú±œ­ƒbé©oœ{esZî‹Ls»Wş‘œ­ƒÕııœL{ÊâŠHî‹l{çmµÏî‹‘œ ’ªÒ¤î‹Ì"Ï±œl{@+ÿë/”l{?€Ãi”Ksï_ÿ?î‹Lsºı¿,±œl{UU_SµLsª¯UU±œ+s  +U±œ+s   ­Ñ¤P”şªªªÑ¤P”ÿúªª±œ”jª¨ Ò¤­ƒWêªªÒ¤Í‹UUúªpœÍ‹­UUx/”Œƒx¯ÿ/”Œ{UZ€+p¤Œ{UUWê*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ*|-{ÿÿÿÿ±¤­{«ëUU±¤­{ªUU±¤­{úUUUŒsøÿÿÿÎ{­{ÿÿÿÿî‹sÿÿÿoœ­{UUÕª.”msÿÿ
 œ­{Uıªªœ­{Õªª*p”Ì‹¯ª* ’”.”UU¯ª’”.”Uıªª’”.”U«ªª’”.”ÿªªªÒœÎƒªªªÿÒœ­ƒªªêUÒœ­ƒªª_U­ƒp”•¥  Ñ¤Œu-§±¤­ƒÔ\~ş/”l{bÿj`î‹l{µ%—±/”l{ª¯â†pœî‹·½ËN±œî‹šº±¤O”ª ÿÿ±¤O”ª ÿÿ±¤p”ª Uıœ³¤ ª  Õ¤œUÿUUœ³¤ ª  ï¬Q”ªÿÿÿÑ¤O”jzÿÿ”ŒU¯ªªqœî‹ÕÿÿÒ¤­ƒÿÿ¿ Ò¤­ƒÿÿ
 Ò¤­ƒÿ«  Ò¤­ƒ¿   ²¤+k
  zÖ£1ªªªÿœl{jªè©Ñ¤Îƒái«ëœî‹Àúk/”+sãPğ°pœl{­ƒk£¡«Î‹+s«©¼)Îƒl{ù©¸øŒl{3©µ÷œl{	¦¥°¤,sù*¤¦pœ­ƒ¸Xt´P”­ƒ‹€/”l{ÔÏº"‘œ­ƒŠ­£MO”­ƒäìb_î‹l{¨úşÿ¬ƒ{ª* ¨Î‹Œ{ÿÿ«ªÎ‹Œ{oªªª­ƒMs¿üğ î‹msªªª«Î‹­sªªªªÎƒ®ƒ /ï‹l{šjªª­ƒP”ªª¨ /Œ®ƒşúêªŒm{UVZj/”m{	 /”/”ªªªªÑ¤/”­UUU±¤/”
UUU±¤/” õUU±¤î‹ Zÿÿ±¤î‹ U_ÿ±¤­{ ÿÿª±¤î‹À•Õ*P”­ƒœ{}û.‘œ­ƒZShß‘œl{/‹Ñ¤+s²úşôÑ¤l{)·­¯Ñ¤Îƒ­	Ï‘œl{DgGÑî‹l{û(±¤Œ{¿§¯P”Ksô¶ëÒ¤ƒ[_XTO”l{ç÷W)ò¤l{úPÜúÎ‹+sö^xà­{+sª«¥Õl{m{jªªªƒlsª¯ÿÿƒls*ª«¿®ƒl{¯ÿÿ®ƒl{ø€+ÿÎ‹{UU^ï{‹{ªªªª{+sà   {sÿşøÀLs+sªªªªLs+sªªªªtµ/”ÿÿÿõ¤‘œÿÿÿÿ±¤P”jªªª­¬{Wêªª‘œŒ{UW  ‘œ*kÿÿÿ ƒ¬{ÿÿÿÿƒ¬{ÿÿÿÿqœ*k¿ÿÿ‘œŒ{ ¥U‘œŒ{   )ñœÑ›ªªªªñœÑ›ªªªªñœÑ›ªªªªP”‘œ%UUU‘œŒşê  P”í‹ªª¨€Ñ¤kêªªª/”l{U^` O”k¿ÿÿşO”l{ 5Uœ®{ªªª«/”j{h   /Œ({ÿşà Œj{%UU^q”jƒª«µUP”Í‹ª¨4µÍƒ¿_ÿ.”Œ{ƒ/ÅÑ¤{/-Ê~‘œ¬ƒ0ß»×‘œ­ƒ¾¾õ?pœ­ƒ—°3T±œL{s\wî‹+s,º›[l{î‹¨¦F¢Í‹Ls†´—î‹Lsú×:İœl{4ßë	P”l{|T|Œ+s~Â«ú”LsÖØ÷ßŒl{¡‘œÍƒ6±œ­ƒœÖ:~œ­ƒCXîVÑ¤ÍƒÛı>±œ­ƒpkZşŒl{}	·m”,sÙcŞÿ/”l{‡µÿ×±¤l{=á^P”L{xßi‘œÍƒc¼]‘œ¬ƒ­ƒ±¤Íƒ®öOpœl{ï/µ¦ò¤­ƒwä~Vî‹l{"ß^]î‹LsÎ¨¯–î‹l{
ü„íOœL{-mõu‘œl{”Õ÷UŒl{¹Ö’ î‹l{œUÛĞ¤l{Õ?WŒLs‹¬‰Éœl{2³ÚRî‹l{ïó¶Í‹Ls†´—ï‹l{^UUŒKsÄzÊãpœ­ƒ:+ö±œî‹Õƒ¥oœ{¶Ø·¿/”l{£ŠokpœÍƒTÏkİ‘œ­ƒçR^±œl{\Xpzpœl{ı>fœ­ƒèîX¼ò¤Íƒí-µıpœŒ{ÙcÜüO”­ƒÆ­Ş·/”Œ{¢*	å/”+s>øB¢±¤l{èûÕUŒ,sÏ­#=”Ls®·lîŒl{÷'ÕïœLsmÎkQî‹Lsı{ß/”+sƒ®·—±œl{²ò‹ÁœŒ{¡	œîƒ ªª\¯œÎ{ªª~U¯œ®{ªúUıO”®{€W½ª/”Î{_½ªª/”Î{½ªªªÎ“ŒÿÿÿUp”Î‹ÿÿÿªp”Î‹ÿÿªªP”ŒU¯ªªP”Œ¯ªªª/”QŒªªªª/”QŒªªªª/”QŒªªªªP””ªªªúP”ŒªªªÿP”ŒªªÿÿP”ŒªúÿÿP”Œêÿÿÿ0”ÉjşşşşL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿL{K{ÿÿÿÿŒƒ+s?ÿÿÿ/”K{-UU/”K{  µ‘œ/”ÕUU‘œ/”à ÕŒ‘œ 	•U‘œŒUUWzPœîƒ«¿ÿÿP”Œşr+¿pœî‹ÿÿ×zpœî‹¿í/”­ƒ„‡´×/”­ƒì×3×oœ­ƒ¼[ÊcpœŒ{êêvê‘œ­ƒ\Hì\oœ{¶Ø·¿‘œŒ{9«bpœl{ ˆë¹±¤ÍƒŞWpœ
kˆúêú”Ls³o(­ƒKs ÒŒKsk½o.”LsÙsßİpœl{w¥·5Ò¤­ƒ¹*«ïpœ­ƒì_k±¤l{¬øºú±¤+sïı©œŒ{¬O”Lsì¨÷ö.”,seÌzõO”­ƒõyİÒ¤Œ{o¿7—œl{ĞPø~O”l{-Í©ı‘œÍƒMıœŒ{ëöRØ­ƒêj  ; O”l{×{×ŒLs&ÉO”l{(ª›z/”­ƒÃâ0¦œ­ƒãÉÆ­pœŒ{Vÿ:Şœ­ƒì[ÊcÒ¤­ƒ|óg¯O”L{Z@Êú.”Lsö\×÷Î‹k£ªnëî‹+sªâ¹‘œL{"/ÿWp”ƒ( €%Ñ¤Íƒóî KO”l{üó\Ë±œl{o=épœLs_sXxÎ‹l{Æ½×õî‹+s²*‰å/”l{Ç×yßœ­ƒ¿W²œŒµÁò¤ï‹ªâ	ò¤ï‹	pW¥ŒxWUU/”ï‹ÿ·«/”Œµ«ªªpœ/”UUÕ©/”‘œ  ªª±¤Îƒªªªz‘œî‹ªê6‘œ/”/ `‘œŒ€`VU/”î‹üÿÿÿq½M{¿¿¿¿Ñ«O¥ÿÿÿÿÑ«O¥ÿÿÿÿÑ«O¥ÿÿÿÿ0µŒjªªª°¤­ƒÿõTPî‹­ƒ  ¯õŒ¬ƒªªªÿŒ­ƒªª¿”{Uúªªî‹lsÿú  î‹{UUê î‹ls¿ÿÿ Lœ{«UUU/”+s~‹/ïO”,s±3p”­ƒÊ¢Ğú/”Œ{2*	çpœ­ƒ&şËNpœÍƒ+/GŒsÌ©ƒ/ŒKsê-|¦±œ­ƒ%¯.”,soÈpÊÑ¤L{­íé9pœKs
†/”l{Ø^æ}ò¤l{=íéü¤­ƒõ¦Õ±¤Íƒ­ÇKêpœl{ºªİú/”Ls—8úŞî‹+sí¿åóÍƒ,s"~î‹l{ik8çî‹l{æÅöu±¤l{÷µ;µÑ¤l{¨jˆÊ±œŒ{PC¯P”Ks_êï`.”Ls&ìµì‘œ­ƒ«Ijpœl{öş}Ş±¤l{İÕTUÎƒ+s²şŠÓŒ+s³n ‘œ+sÿÿ=­­ƒõ6•Õñ¤LsÓóÿî‘œ­ƒ·)?åœLlscreen"
 *                button on their titlebars).
 *    "1"       - Enable Spaces support (FULLSCREEN_DESKTOP will use them and
 *                SDL_WINDOW_RESIZABLE windows will offer the "fullscreen"
 *                button on their titlebars).
 *
 *  The default value is "1". Spaces are disabled regardless of this hint if
 *   the OS isn't at least Mac OS X Lion (10.7). This hint must be set before
 *   any windows are created.
 */
#define SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES    "SDL_VIDEO_MAC_FULLSCREEN_SPACES"

/**
 *  \brief Minimize your SDL_Window if it loses key focus when in fullscreen mode. Defaults to false.
 *  \warning  Before SDL 2.0.14, this defaulted to true! In 2.0.14, we're
 *            seeing if "true" causes more problems than it solves in modern times.
 *
 */
#define SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS   "SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS"

/**
 *  \brief  A variable controlling whether the libdecor Wayland backend is allowed to be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - libdecor use is disabled.
 *    "1"       - libdecor use is enabled (default).
 *
 *  libdecor is used over xdg-shell when xdg-decoration protocol is unavailable.
 */
#define SDL_HINT_VIDEO_WAYLAND_ALLOW_LIBDECOR "SDL_VIDEO_WAYLAND_ALLOW_LIBDECOR"

/**
*  \brief  A variable that is the address of another SDL_Window* (as a hex string formatted with "%p").
*  
*  If this hint is set before SDL_CreateWindowFrom() and the SDL_Window* it is set to has
*  SDL_WINDOW_OPENGL set (and running on WGL only, currently), then two things will occur on the newly 
*  created SDL_Window:
*
*  1. Its pixel format will be set to the same pixel format as this SDL_Window.  This is
*  needed for example when sharing an OpenGL context across multiple windows.
*
*  2. The flag SDL_WINDOW_OPENGL will be set on the new window so it can be used for
*  OpenGL rendering.
*
*  This variable can be set to the following values:
*    The address (as a string "%p") of the SDL_Window* that new windows created with SDL_CreateWindowFrom() should
*    share a pixel format with.
*/
#define SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT    "SDL_VIDEO_WINDOW_SHARE_PIXEL_FORMAT"

/**
*  \brief  A variable specifying which shader compiler to preload when using the Chrome ANGLE binaries
*
*  SDL has EGL and OpenGL ES2 support on Windows via the ANGLE project. It
*  can use two different sets of binaries, those compiled by the user from source
*  or those provided by the Chrome browser. In the later case, these binaries require
*  that SDL loads a DLL providing the shader compiler.
*
*  This variable can be set to the following values:
*    "d3dcompiler_46.dll" - default, best for Vista or later.
*    "d3dcompiler_43.dll" - for XP support.
*    "none" - do not load any library, useful if you compiled ANGLE from source and included the compiler in your binaries.
*
*/
#define SDL_HINT_VIDEO_WIN_D3DCOMPILER              "SDL_VIDEO_WIN_D3DCOMPILER"

/**
 * \brief A variable controlling whether X11 should use GLX or EGL by default
 *
 * This variable can be set to the following values:
 * "0" - Use GLX
 * "1" - Use EGL
 *
 * By default SDL will use GLX when both are present.
 */
#define SDL_HINT_VIDEO_X11_FORCE_EGL "SDL_VIDEO_X11_FORCE_EGL"

/**
 * \brief A variable controlling whether the X11 _NET_WM_BYPASS_COMPOSITOR hint should be used.
 * 
 * This variable can be set to the following values:
 * "0" - Disable _NET_WM_BYPASS_COMPOSITOR
 * "1" - Enable _NET_WM_BYPASS_COMPOSITOR
 * 
 * By default SDL will use _NET_WM_BYPASS_COMPOSITOR
 * 
 */
#define SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR "SDL_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR"

/**
 *  \brief  A variable controlling whether the X11 _NET_WM_PING protocol should be supported.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable _NET_WM_PING
 *    "1"       - Enable _NET_WM_PING
 *
 *  By default SDL will use _NET_WM_PING, but for applications that know they
 *  will not always be able to respond to ping requests in a timely manner they can
 *  turn it off to avoid the window manager thinking the app is hung.
 *  The hint is checked in CreateWindow.
 */
#define SDL_HINT_VIDEO_X11_NET_WM_PING      "SDL_VIDEO_X11_NET_WM_PING"

/**
 *  \brief  A variable forcing the visual ID chosen for new X11 windows
 *
 */
#define SDL_HINT_VIDEO_X11_WINDOW_VISUALID      "SDL_VIDEO_X11_WINDOW_VISUALID"

/**
 *  \brief  A variable controlling whether the X11 Xinerama extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable Xinerama
 *    "1"       - Enable Xinerama
 *
 *  By default SDL will use Xinerama if it is available.
 */
#define SDL_HINT_VIDEO_X11_XINERAMA         "SDL_VIDEO_X11_XINERAMA"

/**
 *  \brief  A variable controlling whether the X11 XRandR extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable XRandR
 *    "1"       - Enable XRandR
 *
 *  By default SDL will not use XRandR because of window manager issues.
 */
#define SDL_HINT_VIDEO_X11_XRANDR           "SDL_VIDEO_X11_XRANDR"

/**
 *  \brief  A variable controlling whether the X11 VidMode extension should be used.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable XVidMode
 *    "1"       - Enable XVidMode
 *
 *  By default SDL will use XVidMode if it is available.
 */
#define SDL_HINT_VIDEO_X11_XVIDMODE         "SDL_VIDEO_X11_XVIDMODE"

/**
 *  \brief  Controls how the fact chunk affects the loading of a WAVE file.
 *
 *  The fact chunk stores information about the number of samples of a WAVE
 *  file. The Standards Update from Microsoft notes that this value can be used
 *  to 'determine the length of the data in seconds'. This is especially useful
 *  for compressed formats (for which this is a mandatory chunk) if they produce
 *  multiple sample frames per block and truncating the block is not allowed.
 *  The fact chunk can exactly specify how many sample frames there should be
 *  in this case.
 *
 *  Unfortunately, most application seem to ignore the fact chunk and so SDL
 *  ignores it by default as well.
 *
 *  This variable can be set to the following values:
 *
 *    "truncate"    - Use the number of samples to truncate the wave data if
 *                    the fact chunk is present and valid
 *    "strict"      - Like "truncate", but raise an error if the fact chunk
 *                    is invalid, not present for non-PCM formats, or if the
 *                    data chunk doesn't have that many samples
 *    "ignorezero"  - Like "truncate", but ignore fact chunk if the number of
 *                    samples is zero
 *    "ignore"      - Ignore fact chunk entirely (default)
 */
#define SDL_HINT_WAVE_FACT_CHUNK   "SDL_WAVE_FACT_CHUNK"

/**
 *  \brief  Controls how the size of the RIFF chunk affects the loading of a WAVE file.
 *
 *  The size of the RIFF chunk (which includes all the sub-chunks of the WAVE
 *  file) is not always reliable. In case the size is wrong, it's possible to
 *  just ignore it and step through the chunks until a fixed limit is reached.
 *
 *  Note that files that have trailing data unrelated to the WAVE file or
 *  corrupt files may slow down the loading process without a reliable boundary.
 *  By default, SDL stops after 10000 chunks to prevent wasting time. Use the
 *  environment variable SDL_WAVE_CHUNK_LIMIT to adjust this value.
 *
 *  This variable can be set to the following values:
 *
 *    "force"        - Always use the RIFF chunk size as a boundary for the chunk search
 *    "ignorezero"   - Like "force", but a zero size searches up to 4 GiB (default)
 *    "ignore"       - Ignore the RIFF chunk size and always search up to 4 GiB
 *    "maximum"      - Search for chunks until the end of file (not recommended)
 */
#define SDL_HINT_WAVE_RIFF_CHUNK_SIZE   "SDL_WAVE_RIFF_CHUNK_SIZE"

/**
 *  \brief  Controls how a truncated WAVE file is handled.
 *
 *  A WAVE file is considered truncated if any of the chunks are incomplete or
 *  the data chunk size is not a multiple of the block size. By default, SDL
 *  decodes until the first incomplete block, as most applications seem to do.
 *
 *  This variable can be set to the following values:
 *
 *    "verystrict" - Raise an error if the file is truncated
 *    "strict"     - Like "verystrict", but the size of the RIFF chunk is ignored
 *    "dropframe"  - Decode until the first incomplete sample frame
 *    "dropblock"  - Decode until the first incomplete block (default)
 */
#define SDL_HINT_WAVE_TRUNCATION   "SDL_WAVE_TRUNCATION"

/**
 * \brief Tell SDL not to name threads on Windows with the 0x406D1388 Exception.
 *        The 0x406D1388 Exception is a trick used to inform Visual Studio of a
 *        thread's name, but it tends to cause problems with other debuggers,
 *        and the .NET runtime. Note that SDL 2.0.6 and later will still use
 *        the (safer) SetThreadDescription API, introduced in the Windows 10
 *        Creators Update, if available.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will raise the 0x406D1388 Exception to name threads.
 *               This is the default behavior of SDL <= 2.0.4.
 *   "1"       - SDL will not raise this exception, and threads will be unnamed. (default)
 *               This is necessary with .NET languages or debuggers that aren't Visual Studio.
 */
#define SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING "SDL_WINDOWS_DISABLE_THREAD_NAMING"

/**
 *  \brief  A variable controlling whether the windows message loop is processed by SDL 
 *
 *  This variable can be set to the following values:
 *    "0"       - The window message loop is not run
 *    "1"       - The window message loop is processed in SDL_PumpEvents()
 *
 *  By default SDL will process the windows message loop
 */
#define SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP "SDL_WINDOWS_ENABLE_MESSAGELOOP"

/**
 * \brief Force SDL to use Critical Sections for mutexes on Windows.
 *        On Windows 7 and newer, Slim Reader/Writer Locks are available.
 *        They offer better performance, allocate no kernel ressources and
 *        use less memory. SDL will fall back to Critical Sections on older
 *        OS versions or if forced to by this hint.
 *
 *  This variable can be set to the following values:
 *    "0"       - Use SRW Locks when available. If not, fall back to Critical Sections. (default)
 *    "1"       - Force the use of Critical Sections in all cases.
 *
 */
#define SDL_HINT_WINDOWS_FORCE_MUTEX_CRITICAL_SECTIONS "SDL_WINDOWS_FORCE_MUTEX_CRITICAL_SECTIONS"

/**
 * \brief Force SDL to use Kernel Semaphores on Windows.
 *        Kernel Semaphores are inter-process and require a context
 *        switch on every interaction. On Windows 8 and newer, the
 *        WaitOnAddress API is available. Using that and atomics to
 *        implement semaphores increases performance.
 *        SDL will fall back to Kernel Objects on older OS versions
 *        or if forced to by this hint.
 *
 *  This variable can be set to the following values:
 *    "0"       - Use Atomics and WaitOnAddress API when available. If not, fall back to Kernel Objects. (default)
 *    "1"       - Force the use of Kernel Objects in all cases.
 *
 */
#define SDL_HINT_WINDOWS_FORCE_SEMAPHORE_KERNEL "SDL_WINDOWS_FORCE_SEMAPHORE_KERNEL"

/**
 * \brief A variable to specify custom icon resource id from RC file on Windows platform 
 */
#define SDL_HINT_WINDOWS_INTRESOURCE_ICON       "SDL_WINDOWS_INTRESOURCE_ICON"
#define SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL "SDL_WINDOWS_INTRESOURCE_ICON_SMALL"

/**
 *  \brief Tell SDL not to generate window-close events for Alt+F4 on Windows.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will generate a window-close event when it sees Alt+F4.
 *   "1"       - SDL will only do normal key handling for Alt+F4.
 */
#define SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4 "SDL_WINDOWS_NO_CLOSE_ON_ALT_F4"

/**
 * \brief Use the D3D9Ex API introduced in Windows Vista, instead of normal D3D9.
 *        Direct3D 9Ex contains changes to state management that can eliminate device
 *        loss errors during scenarios like Alt+Tab or UAC prompts. D3D9Ex may require
 *        some changes to your application to cope with the new behavior, so this
 *        is disabled by default.
 *
 *  This hint must be set before initializing the video subsystem.
 *
 *  For more information on Direct3D 9Ex, see:
 *    - https://docs.microsoft.com/en-us/windows/win32/direct3darticles/graphics-apis-in-windows-vista#direct3d-9ex
 *    - https://docs.microsoft.com/en-us/windows/win32/direct3darticles/direct3d-9ex-improvements
 *
 *  This variable can be set to the following values:
 *    "0"       - Use the original Direct3D 9 API (default)
 *    "1"       - Use the Direct3D 9Ex API on Vista and later (and fall back if D3D9Ex is unavailable)
 *
 */
#define SDL_HINT_WINDOWS_USE_D3D9EX "SDL_WINDOWS_USE_D3D9EX"

/**
 *  \brief  A variable controlling whether the window frame and title bar are interactive when the cursor is hidden 
 *
 *  This variable can be set to the following values:
 *    "0"       - The window frame is not interactive when the cursor is hidden (no move, resize, etc)
 *    "1"       - The window frame is interactive when the cursor is hidden
 *
 *  By default SDL will allow interaction with the window frame when the cursor is hidden
 */
#define SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN    "SDL_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN"

/**
*  \brief  A variable controlling whether the window is activated when the SDL_ShowWindow function is called 
*
*  This variable can be set to the following values:
*    "0"       - The window is activated when the SDL_ShowWindow function is called
*    "1"       - The window is not activated when the SDL_ShowWindow function is called
*
*  By default SDL will activate the window when the SDL_ShowWindow function is called
*/
#define SDL_HINT_WINDOW_NO_ACTIVATION_WHEN_SHOWN    "SDL_WINDOW_NO_ACTIVATION_WHEN_SHOWN"

/** \brief Allows back-button-press events on Windows Phone to be marked as handled
 *
 *  Windows Phone devices typically feature a Back button.  When pressed,
 *  the OS will emit back-button-press events, which apps are expected to
 *  handle in an appropriate manner.  If apps do not explicitly mark these
 *  events as 'Handled', then the OS will invoke its default behavior for
 *  unhandled back-button-press events, which on Windows Phone 8 and 8.1 is to
 *  terminate the app (and attempt to switch to the previous app, or to the
 *  device's home screen).
 *
 *  Setting the SDL_HINT_WINRT_HANDLE_BACK_BUTTON hint to "1" will cause SDL
 *  to mark back-button-press events as Handled, if and when one is sent to
 *  the app.
 *
 *  Internally, Windows Phone sends back button events as parameters to
 *  special back-button-press callback functions.  Apps that need to respond
 *  to back-button-press events are expected to register one or more
 *  callback functions for such, shortly after being launched (during the
 *  app's initialization phase).  After the back button is pressed, the OS
 *  will invoke these callbacks.  If the app's callback(s) do not explicitly
 *  mark the event as handled by the time they return, or if the app never
 *  registers one of these callback, the OS will consider the event
 *  un-handled, and it will apply its default back button behavior (terminate
 *  the app).
 *
 *  SDL registers its own back-button-press callback with the Windows Phone
 *  OS.  This callback will emit a pair of SDL key-press events (SDL_KEYDOWN
 *  and SDL_KEYUP), each with a scancode of SDL_SCANCODE_AC_BACK, after which
 *  it will check the contents of the hint, SDL_HINT_WINRT_HANDLE_BACK_BUTTON.
 *  If the hint's value is set to "1", the back button event's Handled
 *  property will get set to 'true'.  If the hint's value is set to something
 *  else, or if it is unset, SDL will leave the event's Handled property
 *  alone.  (By default, the OS sets this property to 'false', to note.)
 *
 *  SDL apps can either set SDL_HINT_WINRT_HANDLE_BACK_BUTTON well before a
 *  back button is pressed, or can set it in direct-response to a back button
 *  being pressed.
 *
 *  In order to get notified when a back button is pressed, SDL apps should
 *  register a callback function with SDL_AddEventWatch(), and have it listen
 *  for SDL_KEYDOWN events that have a scancode of SDL_SCANCODE_AC_BACK.
 *  (Alternatively, SDL_KEYUP events can be listened-for.  Listening for
 *  either event type is suitable.)  Any value of SDL_HINT_WINRT_HANDLE_BACK_BUTTON
 *  set by such a callback, will be applied to the OS' current
 *  back-button-press event.
 *
 *  More details on back button behavior in Windows Phone apps can be found
 *  at the following page, on Microsoft's developer site:
 *  http://msdn.microsoft.com/en-us/library/windowsphone/develop/jj247550(v=vs.105).aspx
 */
#define SDL_HINT_WINRT_HANDLE_BACK_BUTTON "SDL_WINRT_HANDLE_BACK_BUTTON"

/** \brief Label text for a WinRT app's privacy policy link
 *
 *  Network-enabled WinRT apps must include a privacy policy.  On Windows 8, 8.1, and RT,
 *  Microsoft mandates that this policy be available via the Windows Settings charm.
 *  SDL provides code to add a link there, with its label text being set via the
 *  optional hint, SDL_HINT_WINRT_PRIVACY_POLICY_LABEL.
 *
 *  Please note that a privacy policy's contents are not set via this hint.  A separate
 *  hint, SDL_HINT_WINRT_PRIVACY_POLICY_URL, is used to link to the actual text of the
 *  policy.
 *
 *  The contents of this hint should be encoded as a UTF8 string.
 *
 *  The default value is "Privacy Policy".  This hint should only be set during app
 *  initialization, preferably before any calls to SDL_Init().
 *
 *  For additional information on linking to a privacy policy, see the documentation for
 *  SDL_HINT_WINRT_PRIVACY_POLICY_URL.
 */
#define SDL_HINT_WINRT_PRIVACY_POLICY_LABEL "SDL_WINRT_PRIVACY_POLICY_LABEL"

/**
 *  \brief A URL to a WinRT app's privacy policy
 *
 *  All network-enabled WinRT apps must make a privacy policy available to its
 *  users.  On Windows 8, 8.1, and RT, Microsoft mandates that this policy be
 *  be available in the Windows Settings charm, as accessed from within the app.
 *  SDL provides code to add a URL-based link there, which can point to the app's
 *  privacy policy.
 *
 *  To setup a URL to an app's privacy policy, set SDL_HINT_WINRT_PRIVACY_POLICY_URL
 *  before calling any SDL_Init() functions.  The contents of the hint should
 *  be a valid URL.  For example, "http://www.example.com".
 *
 *  The default value is "", which will prevent SDL from adding a privacy policy
 *  link to the Settings charm.  This hint should only be set during app init.
 *
 *  The label text of an app's "Privacy Policy" link may be customized via another
 *  hint, SDL_HINT_WINRT_PRIVACY_POLICY_LABEL.
 *
 *  Please note that on Windows Phone, Microsoft does not provide standard UI
 *  for displaying a privacy policy link, and as such, SDL_HINT_WINRT_PRIVACY_POLICY_URL
 *  will not get used on that platform.  Network-enabled phone apps should display
 *  their privacy policy through some other, in-app means.
 */
#define SDL_HINT_WINRT_PRIVACY_POLICY_URL "SDL_WINRT_PRIVACY_POLICY_URL"

/**
 *  \brief Mark X11 windows as override-redirect.
 *
 *  If set, this _might_ increase framerate at the expense of the desktop
 *  not working as expected. Override-redirect windows aren't noticed by the
 *  window manager at all.
 *
 *  You should probably only use this for fullscreen windows, and you probably
 *  shouldn't even use it for that. But it's here if you want to try!
 */
#define SDL_HINT_X11_FORCE_OVERRIDE_REDIRECT "SDL_X11_FORCE_OVERRIDE_REDIRECT"

/**
 *  \brief  A variable that lets you disable the detection and use of Xinput gamepad devices
 *
 *  The variable can be set to the following values:
 *    "0"       - Disable XInput detection (only uses direct input)
 *    "1"       - Enable XInput detection (the default)
 */
#define SDL_HINT_XINPUT_ENABLED "SDL_XINPUT_ENABLED"

/**
 *  \brief  A variable that causes SDL to use the old axis and button mapping for XInput devices.
 *
 *  This hint is for backwards compatibility only and will be removed in SDL 2.1
 *
 *  The default value is "0".  This hint must be set before SDL_Init()
 */
#define SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING "SDL_XINPUT_USE_OLD_JOYSTICK_MAPPING"

/**
 *  \brief  A variable that causes SDL to not ignore audio "monitors"
 *
 *  This is currently only used for PulseAudio and ignored elsewhere.
 *
 *  By default, SDL ignores audio devices that aren't associated with physical
 *  hardware. Changing this hint to "1" will expose anything SDL sees that
 *  appears to be an audio source or sink. This will add "devices" to the list
 *  that the user probably doesn't want or need, but it can be useful in
 *  scenarios where you want to hook up SDL to some sort of virtual device,
 *  etc.
 *
 *  The default value is "0".  This hint must be set before SDL_Init().
 *
 *  This hint is available since SDL 2.0.16. Before then, virtual devices are
 *  always ignored.
 */
#define SDL_HINT_AUDIO_INCLUDE_MONITORS "SDL_AUDIO_INCLUDE_MONITORS"


/**
 *  \brief  An enumeration of hint priorities
 */
typedef enum
{
    SDL_HINT_DEFAULT,
    SDL_HINT_NORMAL,
    SDL_HINT_OVERRIDE
} SDL_HintPriority;


/**
 * Set a hint with a specific priority.
 *
 * The priority controls the behavior when setting a hint that already has a
 * value. Hints will replace existing hints of their priority and lower.
 * Environment variables are considered to have override priority.
 *
 * \param name the hint to set
 * \param value the value of the hint variable
 * \param priority the SDL_HintPriority level for the hint
 * \returns SDL_TRUE if the hint was set, SDL_FALSE otherwise.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetHint
 * \sa SDL_SetHint
 */
extern DECLSPEC SDL_bool SDLCALL SDL_SetHintWithPriority(const char *name,
                                                         const char *value,
                                                         SDL_HintPriority priority);

/**
 * Set a hint with normal priority.
 *
 * Hints will not be set if there is an existing override hint or environment
 * variable that takes precedence. You can use SDL_SetHintWithPriority() to
 * set the hint with override priority instead.
 *
 * \param name the hint to set
 * \param value the value of the hint variable
 * \returns SDL_TRUE if the hint was set, SDL_FALSE otherwise.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetHint
 * \sa SDL_SetHintWithPriority
 */
extern DECLSPEC SDL_bool SDLCALL SDL_SetHint(const char *name,
                                             const char *value);

/**
 * Get the value of a hint.
 *
 * \param name the hint to query
 * \returns the string value of a hint or NULL if the hint isn't set.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_SetHint
 * \sa SDL_SetHintWithPriority
 */
extern DECLSPEC const char * SDLCALL SDL_GetHint(const char *name);

/**
 * Get the boolean value of a hint variable.
 *
 * \param name the name of the hint to get the boolean value from
 * \param default_value the value to return if the hint does not exist
 * \returns the boolean value of a hint or the provided default value if the
 *          hint does not exist.
 *
 * \since This function is available since SDL 2.0.5.
 *
 * \sa SDL_GetHint
 * \sa SDL_SetHint
 */
extern DECLSPEC SDL_bool SDLCALL SDL_GetHintBoolean(const char *name, SDL_bool default_value);

/**
 * Type definition of the hint callback function.
 *
 * \param userdata what was passed as `userdata` to SDL_AddHintCallback()
 * \param name what was passed as `name` to SDL_AddHintCallback()
 * \param oldValue the previous hint value
 * \param newValue the new value hint is to be set to
 */
typedef void (SDLCALL *SDL_HintCallback)(void *userdata, const char *name, const char *oldValue, const char *newValue);

/**
 * Add a function to watch a particular hint.
 *
 * \param name the hint to watch
 * \param callback An SDL_HintCallback function that will be called when the
 *                 hint value changes
 * \param userdata a pointer to pass to the callback function
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_DelHintCallback
 */
extern DECLSPEC void SDLCALL SDL_AddHintCallback(const char *name,
                                                 SDL_HintCallback callback,
                                                 void *userdata);

/**
 * Remove a function watching a particular hint.
 *
 * \param name the hint being watched
 * \param callback An SDL_HintCallback function that will be called when the
 *                 hint value changes
 * \param userdata a pointer being passed to the callback function
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_AddHintCallback
 */
extern DECLSPEC void SDLCALL SDL_DelHintCallback(const char *name,
                                                 SDL_HintCallback callback,
                                                 void *userdata);

/**
 * Clear all hints.
 *
 * This function is automatically called during SDL_Quit().
 *
 * \since This function is available since SDL 2.0.0.
 */
extern DECLSPEC void SDLCALL SDL_ClearHints(void);


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_hints_h_ */

/* vi: set ts=4 sw=4 expandtab: */
