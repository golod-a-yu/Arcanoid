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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         s%����Ls���*/�Ls�⯯{w�����b���΃l{�>oꮃl{��j��l{Y�/���m/��{'		/�@p\/���+O�ls  �`O�Ls\WU�q��b�+��p�K������
���*
��UUՕO��VUUU����������Pp����U���j���p�,cW�  p�,c�x p�,c  %^p�,c   	p�q� *����P���op�k�
��/����N�����~�(/���i��p���5���p������
p�����/�/�΃k�,O�c�#�������p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p��U ��p�΃ ��p���U ��p���5 ��p��� ���0�+��������������������{^�  򤌃UW� Ҥ��UUUx��K{
���̓+{  
��Ls����l{~�����+kW�� ��+k�~����b  /�Ѥ+s���Ѥ̓� 	��/����Pp�����}����z)"�����=@P����o[����nۙ1���������΋�:(���s�
R�Ѥ�{
 U����{  U����{  ���탪��U�틪�����������������������������W����O�Z����.�U���n�r� Ҥ-��/�Ѥ�{�X�*Ҭ+k����P��{/���P�΃*��p�� 
��p�/�V` 
�/�-�W3�� 
��T��x`rꐜm{��+�����z����b(���l{�y�/�Ls��+��������p/���n[�p����ڿ��΃�M����+s����/�k� �����6�Ҥ��{����,s����΃+s����p�Ls��)
����l�/��{оz�O��b�j�΋l{}���΋+k�����l{}YQ�p�s����Ls	&���L{���/��{}���/�l{~�/�+k����/��{���U������//�l{}���/�l{���Ҥ����<*Ҥ��R��0�̓��~/�Ks(�Ҥl{U;����l{T���l{P� Z��P�������l�����΋΃�� ΋͋ ���΋͋������{������{������{������{������{������{������{������{������{������{������{������{�����
k����p�ls  ��p���  _Up�Ls ���p�Ls ���
kp�U���p�Ls����O����UUU͋�{����͋�{����͋�{����͋�{����͋�{����l{��VP��Z���
kP���VU����U� ���̓� ���/��¦����t���/�k򨐠��{�Ά�/��{괯�P�������p��3�2S������V��� U�
���U��������Ҥp�����Ҥq�Z���Ҥq������/�����T�,sZ������I�������I������+sUU� ��+sUU� ��+sUU��'R0���UU'R0���UUO�+s	5  P�Ls~��Ҥ̓��������# ��O�l{��p/��{�1ḑ�l{[Q��΋Ls����΃L{z^���l{���Ҥ����4</�L{-�����������{Z\x�΋Ls괯�q�Ls�_OOp��{��]�p�l{��Ѥ�w�������{��R���̓�������{�mY΃s" ��K{��  ��΃���%�_����UUW_�����UUU0�����%U/�s��h@�j�b�����j�b�����b�jj���n��j-�UU.��j���.��b�����b��7���l{�-��p�+s~�.���l{�����l{*r���l{���
Ҥl{��ǫҤ�{kr�А������*��l{Zxtr�l{E���Ҥl{����Ҥl{���벤Ks����l{���󤭃����p����:j
/�l{_ܘ����j�:�ୃ�j����L{+k
�����+s/����l{������l{������l{���̓L{�����l{��UUO�l{/��/��{   �/��{  ��/��{  ��/��{  ��/��{ ���/��{ ���/��b �����{�����Ms����΋�s����΋�s����΋�s����΋�s����΋�s������΃���Z��{����p���UUU����UU�����UU�����U������U������U���p�,s����p�s����p�s����/���U���/���U��W�,s�*�l{���pҤl{*�z�O�Lsv��Xp�l{�����%�XБ������W�Ls�����Ls.�?�O�,s�� P���f2����{�H*b�����t������Mai�����Ǎ��l{^���l{+�W�0�Ls���+Ҥ�{���wo�΃o��/�Ls� ��������/��{�jNR΃Ls{�*"΃l{�[�P�l{����������ܱ��{��/)p��b����p�̓;�Ҥl{����΃Ls~���/�Ls�-�>P������.������/⑜���r~�k�:��Ls�݊�/��{�^���l{��'��Ls���Ҥ�>�Ҥ�{��?��ls����k��+bo�l{-�>�Ҥ�fG�oP�l{n*�>/�Ls����/�m{?/�������;P������w��΃���L{�X���Ls�=��΃l{���z΃Ls_�*"���{�-�Ls�|�
Ҥ���'��Ѥl{Ή�-�l{�h���Ls��"��l{������l{\���΃L{-n8��΃yo���l{W���l{UU��/�k����c΋��UU΋Ls��  ΋Ls�  ΋Ls�   /��������͋�����͋�����͋�����͋�����͋�����͋�����͋�����͋�����͋�����͋�����͋�����͋����/�΋�5/��^�  /��{��������������UU.������O��_���O��UU_����5UUWR���U1�/�����Ѥ�*����P�_����������P������/�P�����/�P������������/�������P��.����������Ҭ�z���������� /�l{�p�p�l{��(��ʢzҤ������/��{����/�̓*�֋p�΃�W�
P���#8�p�Lsh�Ѥl{��2ꑜ̓��7��l{ 
��p�΃Tw��/�Lsz��Lsxz�+���i��zѬ�{�럽o��{�ʷO����� ��������j�l{T���΃l{-	l�P�l{_�/��΃5�n�{p��Z*�����w�t��l{�+�P�l{���΃l{�*�'��m{7_]���sx���Ls�v���Ls�(���k�H�S�l{�V�WP�l{��������E��p���"��葜̓ W�������+����߻ n��U�We�����"����ݝh����U��p�΃Uw��/�΃���/��� �����l{������l{������l{������l{������l{����Ҥ΋�UU+�΋�U�/�΃�)`\Ь̓XWUU͋�s����q�̓UUխP�̓��x�����z�/���5  ��ʋ������������l�
���M�����^ꭃ/��������ꪪ�/�k{WZ�
s̓������+s+��0���?���0��� ��0��UUWq��U^�m{O������
����΃������  ��΋�5�����RZx*������9��l{L@���,k?��7�Ls��(�/�m{v�?T������g�m{�*v�΋Ls�h�
t�m{U��߱���|�o��,k��*��Ls8ߣ�΋�{��|���l{sj�'��l{�/��΃l{B�%*/��{%�%�Ҥ΃���k���p.�Ls��!����W5/�����zX]^��l{տʀ΃l{
�����l{��?Ҥm{V�\W�Ls��K�Ls�?�e��l{m�0�l{���\��l{]Q��΃l{+[��Ls�[��Ls�����Ls��-�Ls��J�΋Ls��(�{{���l{��/��{�Jh(/��������{(�>�����O�Lsp\V�q��b�+��P�l{h����
���*
/�l��������7%-���������������@�� �����UZ������UTq���
��Up��s 
�����j��Up�,cW� 
p�,c�x ��,k�����΃m~�}/�̓�-�>/�΃���{/�΃U���/�̓+[�P����[�p�΃_��VO��{������NՐ�΃� ����{�� ����{�� ����{�� ��������P�/����P�/�����P�/�����P�/�����P�/�����P�/�����P�/�����P�/�����P�/�����P�/�����P�/���?Ҥ/���������?���򤑜+�UU�������1�Ҥ���U��*�����W����{^�  򤌃UW� Ҥ��UUUx�l{���/���UZ��/���UUV���+s�  ��+sUz����+k�~���Ls��ɫp���﷪�/��z�wd/�΃Vھ�/�΃�/n����۟5'�����-�ґ��{.�&��̓�
���U�  ������� ������� ��������O�I{������{����̃.�j���틲��   ��� Օ�p�������q�p�����n�r�/�����-�j���o�K{�ѤO�B/��Ѥ�{�X�*Ҭ+k����P��{/��P�΃(�%p�� 
��p�/�V` 
��,s�r��l{���V/�Ls⠚��Ls�H�P��{�=�-���U��q���X���/�΃�n�p���~n�p�΃f�X��΃��O��{��"�����.i��/�l{������l{{��Ls=/*
��c��/��{+��r�Ls����,s溉��Ls���/��{v����j����p�Ls??��L{����k��( �l{���U�,s��&c�Ls��/�Ls���?����/����Ls����p��{������+	Ҥ�{���[/�Ls~��O�,s/��p����7�������`�H�����͋����΋͋������{������{������{������{������{������{������{������{������{������{������{������{������{������{������{����틍{����͋�{�����
k��������UUU*����UUU��
k��� ����UU������UU������U�������U�������ժ��p�u� �����T� �����T� �����T� �����T� ���3���U��~�P�� �UҤ�n6�߱�΃��z//�k�蠴�l{U!�/������]���j����������/�\�^�/��U�U4��{��������UU���_UU���UUU���ZUU����UUU�����P���UUU�P���UUU�P���UUU�P���UUU�P���UUU�P���UUU���P�U
��󬭃��zJ���{��?)���{�b˱��{j�;*��l{�Zz]O�l{�=�����{RSkN��LsZ�*{u-W�P�Ls^�Ҥl{�1���{��g5��΃�J ���{>V�WP�L{�?o?����u����{Դ_Ҥl{������{*/h}Ҥ��c�U�S�Ls����O�l{c[��{f
��{��VZ΃m{  %΃�������̓��� ͋΃�����UW_��m��������j`pPX�j�b�����j�b�����j�b�����j�b�����b�jj���n��j-�UUO�+s�z)�����?�鑜��+�Ҥ+s4|��q��{u�UҤm{Wv�%�΃�9�����{������{�ǃϱ�����!�Ҥ�O�]P���~����{I�px�Ls�*���{�%�p�΃�.}WҤ���o�~�+s#�S/�kj�խ�k����Lss����,sLsj����{+s?��̓L{�ꩥ��l{����-�,{������l{���̓L{�����Ls��  ��Ls��� ��Ls����/��{���ୃ΃���Z��{����p���UUU����UU�����UU�����U������U������U����΃�����΃�����΃�����΃�����΃����P�Ls����P�Ls���WP�Ls���UP�Ls���UP�,s���UP�Ls���UP�Ks�W�UKs � 
k�{��U�
k�{��U���Ks-�
�p�l{%�)	����r�z��l{����Ҥ+s?<Zp�Ls�Zx�΋Ls������,s/��7�Ls��?�����=�����΃�/�TP�l{�'������:|���{��#P���u�
���{��~��Ls~v���l{���Ր������s/��{����p�΃e�ʻ�����Tt��Ls�"����Ls���΃+s�*��/��{�9��P�����?+��ms����P�l{6��/��{�r8,p��{`�K�/�m{V��_/�Ls�뷵/����g�Yp�����P��{�`�l{_���m{zox��Lsj�v�/�Ls��wҤ�j��߿p�������p�Ls:}��/�Ls�?�^/�,s�����m{q�"Α�m{��( /�Ls炯�/�k��Bj�l{��R���l{#+�񑜭����PҤl{������Z���Ls�\h�΋Ls�-�z��Ls��/�Ls_�}p�l{w��_P�l{	��+��l{*�-P����i���Ls�z�.��Lsx=y�΃+s����΃+s�����������P���V� P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  P��z��  /�K{

 �/��r   O����/��X�  /��{��� p����������UU�����U/��_����/� ����{����Ф�s/��Ф�  �Ѥ�*����P�_����������P������/�P������������Ӝ/�������/�5�_�����ͱ�����?Ҥ�z�������!��lO����W۲/��{烧��l{�"b�/���tv�/�����교�΃�۱���.p�������
���{"h|�/��{���Lsrl��΃+s���l{}�?WҤ����L/�Ls��/��{6�*�����'��Lsp�^���+s�(��΃+s��.O�l{���Ҥ΃i{y�/�ls�
b?����o鋫������J��Ls��v�΋Ls�����Ls�.�������$��Ls����Ls�?��Ҥl{�7-�P�Ls���jO��{��ٳ��΃M�Mkq��{��|t/����w���l{��ޑ���(-�]������.�Ҥ������/��{,�jA�Ls���~P����/�[q���[~TU/����U�(��΋_� ��΋UU�����Uu�?Ҥ�U- Ҥ/� ���/�p�B�̓�pVU͋�s����q�̓UUխP�̓��x�����z�/���5  �����������  �^���`x��������������������l�
���M�����^ꭃ/�����p��jꪪ��*s�����{K{?����+s +�������UU0���  %O�0�	5UWO������ O����_���
���p�l{����/���i;�ޱ�΃��%�P�l{�p��/�Ls����Ls�~����Ls��-P�Lsl��~΋Ls�{���l{5�͑�l{-�O�/�Ls�
b��Lsڭ��Ls���̓,s���΃+s����΃Ls%�ޝ��l{�����l{������l{jʁnҤ��Cԛ�Ҥ��ڪ�kp��{��ߺ/�Ls�����Ls��rv�l{VW����{=��K�Ls��$��Ls�ط��,sͪ��.�Ls�_�/�,s/��l{}in��+s����΃l{m�_΋Ls���J�Ls�b���,s6��O��{UW�/��{~/q����{w��wp�������l{�J �Ls/���IRO�Ls�`P�q��b�+��p�l{h����ꂪ�*
/�l��������xVU��	���������������`�����   ���΋�   ����Ux  p�K{��X �l{���T�l� 
��q���
��Ҥ΃�ڗ���m�|�/��{*�j�/���������Y�N�P���s_�}/���i;��/��{��J/��{����Ҥ����;�������Vp���U����/�UU����/�UU����/�UU����/�UU����/�UU����/�UU����/�UU��p���U��p���U��p���U��p������P�/�����P�/�����ќ,sjjjz/�s-�UU��+s +�U��s  
�Ҥ/�����Ҥ���UUU򤑜*��U�������1�Ҥ���U�Ѥ�����Ѥ��������Wꪪ򤌃UW� Ѥ���UUx/����
�U/���UZ�	/�l{���`�������/��{�|�/��{�/��P���w��w/��{������l{��ϏҤ����t���΃��r�P��{  V���������/� 
����/�  *����   ���������O���UUU���U�  ��U���������q�p�����q�p�����q�p�����n�r�/n�+sx`��p��b/O������VѤO�B/��Ѥ�{�X�*򬭃�UU\��̓�������;nO�l{X��^��,k��2@/�Ls�xT��L{7��:p�Ls�{���l{�������g̨~/�������P�������O�����n�/��{��p���l{��/�ls����΋Lsr�w��Ls߸#P�l{�//����\t���,s�븮�Ls�����Ls~?-��Ls���k���{��/�Ls~��z�Ls'.���Ls����/�l{��{��,s�?&�΃Ls��7:/�Ls�*�O�m{5��㱜�{E��j΃Lsrj/��{b�=둜��.�ip��{�p�BO�m{[��/�Ls��p��{�~�
���{�.�b�{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� �{P��U� 4�P�U�����4������򤪪���򤪪���򤪪���򤪪����4����*4�p�����p�u���� 4�P����U4�p���U��̓����T�P���UU4�P��_UUҤP���UU��/����q�O�����q�O�����p�΃� @����{���$p�l{���K��{\]�΋LsR�F/��{����p�΃�nP�l{�	���U������U������U�������������������P����_p�0�  ��Ҥ���zz�Ҥ���UU�Ҥ���UU�Ҥ���UU�Ҥ���UU�Ҥ���UU�Ҥ���UU�Ҥ���UU�p�l{`�zҤl{mͳ��Ls���ᑜ�{0����l{&�
�O�m{��녑�l{f�o[΃Ls�����j����Ѥ�{뭥�Ҥ�������{	��������{�{WWZ呜Ls��'��L{��B�p�Ls5Gw��L{���XѤ�{�~=5ҤLs���/��j����l{Zi���l{-��/���j������{UUW_΃m{	�U΃���ꪩ͋����UU͋�������W_���Ls^ �(J�   �(J�   �(J�   �(J�   �(J�   �LsU ����l{��.���~|�΃������k������Ls��P�+s==�������9�I/�Ls���l{�ϯ�p�Ls�����Ls�-}oP�l{�899P�Ls�t����Ls&�+��+s����Ҥ�{��}��l{R��ĭ�kVX��l{k��^�m{k?�UkL{����Lss����Ls+s������k������Ls�%խ�l{����-�,{����-�,{�����ћ�����ћ�����ћ�����ћ����P���	UUU���{��  ���{��  ������� p�΃��`P�Ls���W���b����P�Ls��UUP�Ls�UU��j �����j�����{s����+|�r����+|�r����+|�r����+|�r����+|�r�����{+s�����{+s����{+s��� �{+s�� ��LsU+��΃+s� ��΃l{��*_������#P������/��{b4��Ҥl{JHZrp�l{s��U�Ls���O�,s#�ܾ���{q�UW{�Vu���{X���l{�|T\/�Ls�*kϱ�L{��mE�L{�w�W��l{z�Z��l{���_΋Ls�����m{2X��l{����Ҭl{��-��l{:�K+s&:��΃l{����O�l{����O�΃���u������΋��VW��+sܤ���Ls� ����;���P���ZvxdO��{���*P�����>	���*ꑜ�����R�Ls{8���Ls��r΃Lsk�4���l{��'UO�Ls��(���{������{��Tu΃l{�����l{�c�/�Ls��ˏ��������P����g���Ls`�|�Ҥ̓Omkl{��ߔ����i��p���������΃�ɩ/��{~hO�΃+s&���΃l{�����Ls9��K�m{��dב��{�5������>�&P���>�p�l{x��V�Ls�{��΃l{�ơ���+s��6?���{���VҤ�����T4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����4��j����P�K{PXXW/��j/���/�K{ �U/��j   O������/�}�UUp��U_˿��UUU_��j��������U.��ꪪ�O��U����UU^త�	�UUФ�s  /��o������P�_����������P���������������P�_��Ҥ�5�_Ҥ/���SMҤ̓�r�~P��{����/�������/��{	n �/��{b�h�/�΃�=��/�΃�������I����%)rp�΃N��=��΃W_�Ep�l{�|_�m{�����Ls=����{U�m��l{��=�Ҥ�U�V_p����&?����?;�Ls����΃+s ��+O�Ls���/��{�������R��/�����p�΃�2�R��Ksʀ�r��Ls{�$�΃+s��/�Ls��.p���1��v����T�ۑ�l{�� ���΋�ZwҤ��_pK�P����4��p�΃	O�p�+k�許�΃e��P�������/��{%V��3�l{����p�΃u��4/�Ls��j���Ls�k�,s����Ҥ�{9�-��/���*�Ҥ/����_Ҥ/�W�	Ҥ/�- ��/��p�-�̓.`\�̓XWUUq�̓UUխP�̓��x�����z�/���5  ��Ҝ���*���  hW����VUU������
��������������������������������������l�
���M�����^ꭃ/�����/�l{^z���*s���ୃKs
���΋�{����q�����U������/�0� 5UO�����,�������x/�΃��ꗑ�iMa����W����l{Է���Ls�J��/�Ls/�Ls��読�Ls�������G-鱜΃Pv��/�,s��8��LsX8���Lsn(�r��,sx��΃+s�
�̓Ls�� �l{���v΋ls�������A�������򈉑�̓��xn/�ls���k΋k	p���Ls{�j�/�Ls��0��l{�pt΋ls����΋l{��w��Ls僋+p�Ls��}7��l{������!*y�����Wӂ�l{����΋ls����l{���7��l{�'(����݀*ԑ���>"����̓ ���p��{������΃���]������'�P�Ks�(��l{p�)����
���*
/�l������K{`������յ5%O��VUUU���������`��p��{��/��͋
'��q�U_����q��U_���q� UP���p ���L{Uh  p�Ks�5( ��΋$��O�m{킂+/�����O�/��{ʨ�O��{衪�O��{?���/�΃���/�΃{��/��[7TU�����+!���/�������.�����p�/�� ����/�����p�/�����O�O�    O�O�    O�O�    O�O�������Ћ������Ћ������Ћ������Ћ������Ћ������Ћ����/�s`�  /�sUW��̓sUUUxL{�b*���O�s+�UUp�s 
�Ց���  �Ҥ/�����Ҥ����UUҤ����U�������1�Ҥ���U�Ѥ�/���Ѥ�������Wꪪ򤌃�W� 򤌃��������Ԭ��/���H��/�Ls>*��/��{����O��{������΃�+��/�΃z�?摜������΃^ ����{Uz 
���{�Uz P�ms +��P�ms  +���΃*�����/������/� 
����/�  *�P�������q�p�����q�p�����q�p�������M��ꪪ��.�j���o�Ks7��\��틮�^Q���+�UФP����-ѤO�B/��Ѥ�{�Xª����(��bp�,s�����Ls��//�l{���v��Ls�+)��̓���J/��{���/��{�����΃UWWO��������P���z�?����v=籜��ؼ��Lsl���/�Ls_���/�����/��΃���8p�����t{��T��Ls����΋Lsn���/��{�*�ϱ�����:�/�Ls�R����{���/��{ﾪ����{ON?=�Lsƿ��΃l{:��/�Ls��?P�����q����{MKJ{�Lsn���p�Ls;�)㑜�*������:��"����
V
Ҥ�v�-U���;J�W�����j�Z/���x��/��{UZ�+p��{UUW�*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{�������{����4�P���UU4�P��_UU��̓������������탠���o�P�����o�P�����o�P�����o�P�����o�P�����o�P�����O�P�����O�P�����O�P�����P�O� ���P�O� �����/�������/�o�?����6<�P�̓[�7�΋Ls{(��΃+s����O�m{�=�����{��;;��΃������0�������0������������p�0�����Λ������Λ������Λ������P�k{�``@��Js �����Js �����Js �����Js �����Js �����Js ��΃k{�U� �l{/��/��{�^*���l{!��!��΋��nM΋Ls�
.�Ls>�=6�l{��bx΃l{��쫑�l{sz�q��{{QUU{�Ug�{��U�p�Lsи��΋Lso(��P�l{;���̓b���p��{"�/�L{����m{��````/�Ls;+�,s������l{���l{Zj���l{5�Ѥ�{������{UUW_΃m{-�UU΃m{  %΃�����틮������΋   ���������  �^�m{ ����l{���O�Ls��������������Ʈ�����z�Ҥ��[_TW�Ls����p��{�/==��LsB�葜���?6���z��i/�Ls~��ޮ�Ks�����l{/-�Ls����3�m{Q[�^��l{��ϣ��l{A�|^΋Ls��^�{l{/��{l{x   �{+sz�� ��k�^���jl{����Lss����Ls+s����Ls+s������k/����+s���-�,{�������{ �U���{   )�ћ�����ћ�����ћ�����ћ�����ћ�����ћ����P���%UUU��̓j�� ��l{W���/��b��  /�LsUU� /�LsUUU��{+s��* �{�j��  �{+s��  �{+s�
  �{s�   �{+s*   �{�{�����{�{�����{�{�����{l{   �듍{UUU���{UU����{U� ��l{7�����̓��H�/��tJ�Xq�̓u��]��������p���`_�_��{ep.�Ls��z��l{�y�O�Ls���Ҥ��ұ��p��{���|P�+s߾�ӭ�Lsi�n{v��Ѥl{{}!Ҥl{݅��̓%o��o�m{~����l{_�� ��l{MiVR�,s������Ls !�퐜���m��p���m�w
Ѥ΃�חⱜ��#/�+sj�Hꑜl{�zkG�Ls�/�p��{
����΃L�� ���7�������*`Z���������N����l{U�YU��Ls�J��/�,s���O��{9�퐜΃��O��̓�Nuw�+k�?�>΋ls�*����Ls����P�l{]����l{���P�̓�촭o�m{�𿟑�̓�=%�l{�ZzX��',?p�l{�
�����m��/�l{;�k�΃l{�1��.�m{���w��Ls����Ls��zp����1�!p�̓����p��{~���΃+s�⭃+k ��..��{����Ls<�޽��̓$��d��l{�� T��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U��l{�� U���{�� ������U ���΃�U��p�΃�U���΃�ժ��
s����L{K{����L{K{������+s?���/�K{-UU/�K{  �O������/���UU���Ux����UUW`��j���.�����U.������O��_���O��UU_����5UUWR�����U1�/������P�_������������������0�_�-���-=��/������/���۬���l{��/�΃*�%���΃kry�O��{ң��/��{������Z�P���ܼ_~��l{�B��s��j�΃Ls�1��.�m{���w̓LsK��B������%표�{*��BҤ��k{�/�������p���CrRR΃Ls"��.�m{���/��{,>ޫp���%�-������|�/�̓zȪj���{��f�O�Lsh`��΃+s�>����{�=mw/����|�O�����k�������џҤ���?�?{ ����l{��%����{�����΃﮿�Ѥ΃jps�O���R���������M����}|���Ls<[�Ҥ��~�m�,s��z�΃Ls�1<�.�m{���w/�l{	�������v�Ҥ/��%	 Ҥ/��p��/�\�B�̓�pVUq�̓UUխP�̓��x�����z�/���5  󤱜UUU屜��  ����������/������/������/������P�̓j���L��{��UUL��{���UL��{����̓L�������������������������l�
���M�����^����ꪫ�/�k{WZꪭ�+s������Ks
��P�l{����*s������(������l��{/�����%x��΃�����l{��Ok��Ls�ȑ��Ls���?���{��a��������].�m{�ݭ��̓�kbKo�΃_�v�/�Ls���N�Ls� ��p�l{uyGO΃+s�>ƾ.��{o=}w�Ls�x|��Ls��i��Ls�=�7Ҥ���=��p�Ls-:P����l���Ls�r��P�l{����.��{��Y������%?Ҥl{�wh�Ls����΋Ls��Zl΃l{_vW�Ls/��P������m��agW��̓ɵ�Ҥ��j������{�:���l{��uݑ�����ݝ�������4��l{������]p�����W������������`~���L{�`��P���_��/�l����ꑜ��_�����{�������=--���������`��p��{��/P����b�&P�L{ (Ь������� ����Q���
���q�_����q�U_����/���( p��{4�OJ/����2����{*�j�P������o����cgUO���kǕj/�����&xO�΃����/���^�j�Ҥl{����Ҥ���������U���������P�O�����p�/����p�/�����O�P���� O�P�����O�P�����O�P�����O�P�����O�O� ���O�O� ���O�O���UUO�O�    /���   �/������p���~���/�+k_�� /�sUW���{�j���ୃ�j/���O�s*��Up�s 
�����  )U��/�   Ҥ���UUUҤ����U��������Ѥ����� �����fn/��{���/�������P�����ٽ��΃���}/�����+���O|�Q��΃^���/�Z�^�p�/�U~�����UU����+UU��� �UU��΃~ ����΃U~����{�Uz
P�ms +�౤�{����q�p�����q�p�����q�p�����q�p�����q�p�����L�r�����n�+sx`����Ks�ɍ%������P��������+�U���@�{���{N�k.�m{�Z��O�΃u���/�l{T��/�l{�+�������~�P�����ѽФ΃���}/����w�/�����a��΃_�-����a��~�k�����Ls���/����6E����=�籤̓�^V�������r�/��{z�P��l{����k������{�O������\�]p�l{���ؐ����zS�O�����瞱�Ls*�����,s����΃+s���l�Ls�:�ޑ����QkG��Ls���KO�l{�bo_��̓}�표�{�N�걜��Nr/���p�~��l{����P����6?���b���Ҥ��U~��p�k�����.���
��V/���x��/��{UZ�+p��{UUW�*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����ƌ{����o�P�����o�P�����o�P�����o�P�����O�P�����O�P�����O�P�����P�O� ���P�O� ���P�O��������{�������{���W���{���U���{��UU���{�UUP��{�UUU��Lk���+Ҥ�{���*������/�����~��l{uZ�~��Ls�ͦЬ�{�%����̓��ѤLs��b�P�l{  U�P�l{  U�P�l{  U�P�l{  U�P�l{  U�P�l{  U�P�l{  U�P��j�����k{UU�0�k{UU��0�k{U����k{�  �������Ћ���ZU����� ����  �p��{jϾҤ���!�ᑜ̓{C�h΋Lsl��z��l{���/��{�msUN�m{���u/�+s��ףּLs�8��k���?��l{�_GE/�+s����Ls�?���΃�-�Ѥ΃���Ҥl{��z�ҤK{ꪵ����{"��{))))�k����,s��΃ZZj��l{Zj��P�l{����Ѥ�{������{UUW_�{m{?���΃m{	�U�ns***+�  �^�m{ ����m{����O�Ls���O�Ls� ������^�UP���_� UP����* �p����ｑ����?�O�l{���|�Ls�?��p�Ls	�#p�l{������̓���쑜l{#��LP�+s���/�Ls紐�Ѥl{��K뱜�j��?p�l{���Ѥ΃��o��l{v�����LsU^ �Ls�U_��{Ls
%x�{�{�����{�{�����{l{x   �{s����Lss����Ls+s����Ls+s�����{s/�����Ls���Ս��{�������{����q�*k������{ �U���{   )�ћ�����ћ�����ћ�����ћ�����ћ����P���%UUU����� P�틪���/�O��������{Vz��O�+k�����{+s  ��O�,k��_/�k��Ux�{�b ����{	J ���/�jR�����{�b ���퓋R����퓋R����퓋R������k�UU-��+s�u�?Ѥ͋�^�:/����b�ɑ����������*n�����x+�����{}v����{U���l{U��u�l{�U3�򬭃������l{�T�?�����V����Ls(����Ls�ֻ��Ls������{캥�򤭃�eE��΃~�r�p����W�P�l{�P��l{��޾�+s6{Ͽ��wdY���{"J���l{�����΃���M����X���p���Ǡ)��������6p�΃�(�P�l{ a��N�,s��O�l{��3�΃��������O�l{]UWT/�l{�]��/�l{�]/�l{�h�l{�����+s`�c��l{5U3찤Ls�����Ls��޳��l{=�5-��̓����p����Tz��Ls�ǡ�.��{j��;�k�ڋ���l{�-㟑����VX�p����=���������/�Ls�R�*O�Lsw�^�Ls�`�z�+s��&�Ѥ����	MO��{�z�:p����\��/�Ls�ml`/�Ls_n��p�Ls�b�N�l{��oű���T��<�{p����Ks�U�UUKs�U�UUKs�U�UUKs�U�UUKs�U�UUo����U��o����U�
�����U��Ϝ���U�������ժ����U�����΋U���N�ϋ����N�ϋ����������0������p�΋����p�΋����P��ի��P��j����L{K{����L{K{����L{K{����L{K{����L{K{�����K{�UU/�K{  -�/��r   ��/��UU��������΃����/���UUU.�����U�/�����O��_���/��U_�/��5UWz���/�U1�����P�_������/n�x�΃��\�����l/T�/���)���/�������/���喫
����]ǽ�O�ls긇�����5����|�s�p���/����l{�_��΋l{��׮��Ls�P
*.�Lsw�~p�
k������{���Ѥ,s�j�hҤ̓yn�5p������б�l{r�z���Ls�B.�΃+s�똀o�Ls��z�p������#Ϭ΃��/�p�����>9p�̓���l{�v~|��Lsc��΃+s�b�o�Ls�!�O�Ls����Ѥ�����Ф΃���wp�l{w����l{���摜l{�U}����n*�����{**���K{��������5����Z�c�l{p��

p�l{�==�����^wv���Ls6�+.�Lsw�~�k���Ѥl{/�=��/��\�
�̓/`\Ф̓PW��P�̓��x�����z�/���5  4���UU�����pWҤ�pWUU/������/������/�����*�������Ѥ/�������/��/Ф�{U^� Ф�j�������{�����Ms����L��{��UUL��{���UL��{����̓L�������������l�
���M�����^����z����k{U^耭�Ks*���q��{�����Ls�8��/�Ks��"o����]��񤭃�[�z�l{sQۭ�l{���P�l{��7/��l{�x���Ls�m��O�K{��?��̓j\�Ѥ�{�ڱ�l{e��So���{uulҤ��sv~|��Lsk
:�΋Ls��z�N�L{��m�΋k���.�l{=u>�O�l{�����s����p����l�΃l{�=}�΃+s��
��,s���?���{�Or�Ls�ߩ�o�Ls�p?��l{�Um@�l{�U��/����=�������_ï��Ms�?��O�l{�":�����zǏФ��;��z��l{[���l{�%������C�h?����_{� �����ݷ��{��\}o���]w���΃o���L{zs{���+s���Ҥ��_�*ʕ��[VUUP����7��/�	���`��p��{��/P����b�&0�L{��hZ0�l{��
P�l{�UUP�l{  	�/�Q���_�p�1���W���������pۑ����Z\�/���7;/�̓����/��{��+*��ms�?��O�l{ꢜ:o����}���̓�w�p���W~>p���<��/��U��Ҥ������������p�/���� p��� P�/�����O�0�����O�0�����O�0�����O�/� ���p�/�����p�/�����p�/�����p�/�����p�O����U�l{�說�l{�_�/�l{ 
�U/���  
�/������/��{^�  /�+sW�� �sUW���{�j�����s�UUP�s*��U���� /�����  )U��/�   ����Uk5�P���X��̓|zS�/������;/�̓`��</��{�c��/�̓��vp�������Ѥ��[���絍���΃Ң�P����  P����� P������P��꪿�O��U� )���UU�O��UUU葜�+UUU��/�����q�p�����q�p�����q�p�����q�p�����q�p�������.�jꪪ��.�j���o�Ks7��\���VTXS.��{%�_�/��{�	5��΃�֐���c��o��{������[us�/����|k(Ҥ̓��i�/�̓b��<O����s�p������.��{���cѤ̓Uw���̓����/�l{�b����Ls����P��{����/���{Ǜ�Ҥ̓�mkjN����q�p�̓T��Z𬭃��?~O�l{~G����l{���ˑ��fir/���n�m�p�L{z�|�.��{��=.����d�Ɛ�l{�߻�S���V[XY��Ls?�X�΋l{�՟����{��=-��l{�j��p�l{U���p�̓M�?Ѥ�����������f�t�Ls��r��l{ �u���l{���7������� ���U ���������̓����Ҥ��U~��q�k{����/���
���/���x��/��{UZ�+p��{UUW�*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����*|-{����Ό{����P�O� ���P�O� ���P�O��������{�������{���W���{���U���{��UU���{�UU���{�UUU��s����s���o��{UUժ.�ms��
 .�ms��  ���{ժ��������z�����U����� U��/�[��P�������/�l{�Zrp΋Ls{��/�l{�������'
�-��΃l����,s�����,s�����,s�����,s�����,s�����,s�����,s������΃����Ћ���UU��U*  �  ���WUU��UU����Uժ���U�  ̓� ���p�l{���G�+s��������DXR�p�l{�_ӑ�l{?��Ls�r��Ls����Ls�@�{�l{UW7���{���l{Ek[�Ҥl{e���P�͋k=������Ʈ(��k��:�����΀R�Ls�U���m{`U����{���U�k����΃,s//?�΋�s����΃��/��l{�j���+s .Ѥ�{����m{UUZj�{l{����{�UU���{�UUU�{�{    �{�{�����{�{����ls΃
����ls�����ls�*��/��{?�/�p��
%;+/�l{>��Ҥ�{V�^Q�Ls-����l{�h���{�����w��.��L{����Ls��k�/���[M���Ls�R�|��{��i��Ls��ܒ�̓��;p�l{u[x��ls*�����l{�����l{  +����{_� �{��  	��{�{�����{�{�����{s��  �{s����Ls+s����Ls+s����Ls+s�������{Ux  ���{UUZ /�Ks�������{�������{����q�*k������{ �U���{   )�ћ�����ћ�����ћ�����ћ����P���%UUU����� P�틪���/�O�����/�l{Wx� /�k����O�l{-�UO�kh  ѤkU���/�kUU����kU�  .�+kU/���+k� � ��� U���U U���̓�?��Ѥ�������l{���Ѥ΃qب걜K{��Ϫp����Ws���������L{����p��{��]u�Ls"B��P�l{�7��l{��ǞP�l{�v�m�l{W]_��l{_T�Yp�l{W�?����A�����o�y_���{`}�+����#����}{ˑ�l{V���+s����p�+s 69p�����z����\Ѥ+s�����{U%����΃���&P��������̓WwW�/�l{�Lr��l{;�O�l{�
������j�5/�+s4?�p�l{K^�_�l{�����l{u�Ws�Ls+9˖����ӑ��.�Ls���f�+s"@�ꐜl{����l{uX|b��l{?5���l{���/����t-Yp�l{z~��O��{��O���
�Ѥm{R__c��l{��	9p����UY.����jkK	O���oѵo/�l{��܃��{��"��Ls#*=�Ѥl{ɧ�됤�{��GO�l{�^��l{����O�l{�M���Ls���+s����Ѥ���<t��̓VZ���  �U���U� ����U����N�?�����M��������{���_���{����O��{ �O��{�������������P�΋����p�΋����p�΋����P������/�Q�����/�Q�����/�Q�����/�Q�����P��j����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{����/��j/���/�K{ �U/��j   ��/��UU��/�X����� %U���UUU^/�����U�/���Vj/��*���/��{�ꪪ/��5W��p��+5_�����lZ�o��{������k����O�l{"���p����~|�O����T�[/�̓�~)����������o۱���깩B�����CQ[�l{�UYp�+s~?��Ls�P�΋l{k��)��l{��;�ҤV��s����O�l{5��G򤭃�y�p�k�����l{�E��/�l{���/�������l{��Zo�l{
���Ѥ�{?7/�����L���+s�����l{uW��Ls>�7/��{�*�o��{���ﱤ�{�tXzo��{������l{�@�<O�l{����l{�]_��+s���ސ�L{;����̓���U�����ʺp�l{@�� �΃~k�S/�l{���/��̓\Q��+s��z�l{o}��΋l{�a�zO�l{�)����wu�P�̓��x�����z�/���5 ������	����xW��xWUU/������/�����������p�/�U������������O���/���*�X����ѫO�������.����Ф�{U�� ���{UW��{UU� �ls����΃l{�����Ms����L��{��UUL��{���UL��{����L��{z���M�����^�ҤK{��?Ѥl{|_�򤭃�io�/�����0�P����"-.ѤLs������l{��ff�Ls�^n/��l{?==/�l{z�{~��l{��G���L{??�Ҥ��m�O�Ls�X=Ѥ����6p����;=O�l{Hn���l{wW�΃+s����l{�����l{�,���Ls
bR��l{���R�΃�x~�p��{�z\p��Ls���*O�l{�V��Ҥ��]����l{��|~p�+s��o3�l{��y^N�m{o��sp�Ls=տ�Ҥ��\��Qp����[�x/�̓l{���݅ORѤ������{������{��Me/�l{�w�7/�l{�xl{/�� *Ҥ������/������p��{���/��΃�6������Ց�l{/�?=Ҥ�{�������uu}IP������w���`��p��{��/P����b�&0�L{��hZP�,s��+
���{�����Ls����m{l{��  P�k/���P�l{ �Uq�͋ ������`>njЬ��o���/����W�/���to?O���~S?z/�̓Nm��/�̓~c��p���좭o����jw����΃5�͑�̓���*��/���U���/�����P���   �n�Q�����n�Q�����n�Q�����P�O��   P�/��   P���   P�/���  P����  P�/���� P�/���� p�/����������͋���U/��������{/�
����l{�Wz��l{
��W/��{ 
��/�̓  
�/��`  /���Ux� /�KsW���̓sUW��s5UU~�s 	�Up�s*�������U�̓Bz�Ф�����O/����^�./���н�|p����m]�������Կ����9��J��̓)��΃����p����/�P�����P�.� 
��q�.�����P�/��  �q��W���P����  P����� �����=>T��i�����p�W���3����� Ҥ0�����q�p�����q�p�����q�p�������.�V^Zzn�Ksxp����Ks�ɍ%�l{����p��{���b���u�5Ҥ�VVTWp���̪�ko��{����΃/���P����X�9/���P��|�����m��/��{��)/�������Ҥ̓9���������v]N�L{�=�'�Ls�~��/�Ks����������W�k{����/���䶂 p�̓ƴ޽O�l{�PX��l{V��������챤���U][Ҥ+s������L{�Tz�p����������p�Ls��j�����b驏o��{esZ�Ls�W����������L{��H�l{�m��� ��Ҥ��"���l{@+��/�l{?��i�Ks�_�?�Ls���,��l{UU_S�Ls��UU��+s  +U��+s   �ѤP�����ѤP��������j�� Ҥ��WꪪҤ͋UU��p�͋�UUx/���x��/��{UZ�+p��{UUW�*|-{����*|-{����*|-{����*|-{����*|-{����*|-{�������{��UU���{�UU���{�UUU��s�����{�{����s���o��{UUժ.�ms��
 ���{U������{ժ�*p�̋��* ��.�UU����.�U�����.�U�����.�����Ҝ΃����Ҝ�����UҜ����_U��p���  Ѥ�u-������\~�/�l{b�j`�l{�%��/�l{���p���N�������O�� ����O�� ����p�� U����� �  դ��U�UU���� �  �Q�����ѤO�jz����U���q�����Ҥ����� Ҥ����
 Ҥ����  Ҥ���   ��+k
  z֣1������l{j��Ѥ΃�i�된���k/�+s�P�p�l{��k���΋+s���)΃l{�����l{3�����l{	�����,s�*��p����Xt�P�����/�l{�Ϻ"�������MO�����b_�l{�������{�* �΋�{����΋�{o�����Ms��� �ms����΋�s����΃�� /�l{�j����P�����/�������m{UVZj/�m{	 /�/�����Ѥ/��UUU��/�
UUU��/� �UU��� Z����� U_����{ ���������*P������{}�.�����ZShߑ�l{/�Ѥ+s����Ѥl{)���Ѥ΃�	Ϗ��l{DgG��l{�(���{���P�Ks���Ҥ��[_XTO�l{��W)�l{�P��΋+s�^x�{+s����l{m{j�����ls������ls*�����l{�����l{��+�΋�{UU^�{�{�����{+s�   �{s����Ls+s����Ls+s����t�/���������������P�j�����{Wꪪ���{UW� ��*k�������{�������{����q�*k������{ �U���{   )�ћ�����ћ�����ћ����P���%UUU����� P�틪���Ѥkꪪ�/�l{U^` O�k����O�l{ 5U���{����/�j{h   /�({��� �j{%UU^q�j����UP�͋��4�̓�_�.��{�/�Ѥ�{/-�~����0߻ב������?p�����3T��L{s\w�+s,��[l{�F�͋Ls����Ls��:ݐ�l{4��	P�l{|T|�+s~«��Ls�����l{�����̓6���������:~����CX�VѤ̓��>�����pkZ��l{}	�m�,s�c��/�l{���ױ�l{=��^P�L{x�i��̓c�]���������̓��Op�l{�/��򤭃w�~V�l{"�^]�LsΨ���l{
���O�L{-m�u��l{���U�l{�֒ �l{��U�Фl{�?W�Ls���ɐ�l{2��R�l{���͋Ls����l{^UU�Ks�z��p���:+�����Ճ��o��{�ط�/�l{��okp�̓T�kݑ�����R^��l{\Xpzp�l{�>f������X��̓�-��p��{�c��O���ƭ޷/��{�*	�/�+s>�B���l{���U�,sϭ#=�Ls��l��l{�'�Lsm�kQ�Ls�{�/�+s������l{������{�	��� ��\���{��~U���{��U�O��{�W��/��{_���/��{����Γ����Up�΋����p�΋����P��U���P������/�Q�����/�Q�����/�Q�����P������P������P������P������P������0��j����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{����L{K{������+s?���/�K{-UU/�K{  ���/��UU��/�� ���� 	�U���UUWzP����P���r+�p�����zp����/�������/�����3�o����[�cp��{��vꑜ��\H�\o��{�ط����{9��bp�l{��빱�̓�Wp�
k�����Ls�o(���Ks ��Ksk�o.�Ls�s��p�l{w��5Ҥ���*��p����_k��l{������+s������{�O�Ls���.�,se�z�O����y�Ҥ�{o�7���l{�P�~O�l{-ͩ���̓M�����{��Rح��j  ; O�l{�{��Ls�&�O�l{(��z/�����0�������ƭp��{V�:ސ����[�cҤ��|�g�O�L{Z@��.�Ls�\��΋k��n��+s�⹑�L{"/�Wp���(��%Ѥ̓�� KO�l{��\˱�l{o=�p�Ls_sXx΋l{ƽ���+s�*��/�l{��yߐ������W�������	�	pW��xWUU/�����/������p�/�UUթ/��� �����΃���z���6��/�/ `����`VU/������q�M{����ѫO�����ѫO�����ѫO�����0��j���������TP�  �����������������{U����ls��  {UU� �ls����L��{�UUU/�+s~�/�O�,s�3p���ʢ��/��{2*	�p���&��Np�̓+/G�s̩�/�Ks�-|�����%�.�,so�p�ѤL{���9p�Ks
�/�l{�^�}�l{=���������ձ�̓��K�p�l{����/�Ls�8���+s���̓,s"~�l{ik8��l{���u��l{��;�Ѥl{�j�ʱ��{PC��P�Ks_��`.�Ls&�쑜���Ijp�l{��}ޱ�l{��TU΃+s�����+s�n ��+s��=����6���Ls������)?吜Llscreen"
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
