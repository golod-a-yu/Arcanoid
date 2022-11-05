/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2022 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_render.h
 *
 *  Header file for SDL 2D rendering functions.
 *
 *  This API supports the following features:
 *      * single pixel points
 *      * single pixel lines
 *      * filled rectangles
 *      * texture images
 *
 *  The primitives may be drawn in opaque, blended, or additive modes.
 *
 *  The texture images may be drawn in opaque, blended, or additive modes.
 *  They can have an additional color tint or alpha modulation applied to
 *  them, and may also be stretched with linear interpolation.
 *
 *  This API is designed to accelerate simple 2D operations. You may
 *  want more functionality such as polygons and particle effects and
 *  in that case you should use SDL's OpenGL/Direct3D support or one
 *  of the many good 3D engines.
 *
 *  These functions must be called from the main thread.
 *  See this bug for details: http://bugzilla.libsdl.org/show_bug.cgi?id=1995
 */

#ifndef SDL_render_h_
#define SDL_render_h_

#include "SDL_stdinc.h"
#include "SDL_rect.h"
#include "SDL_video.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Flags used when creating a rendering context
 */
typedef enum
{
    SDL_RENDERER_SOFTWARE = 0x00000001,         /**< The renderer is a software fallback */
    SDL_RENDERER_ACCELERATED = 0x00000002,      /**< The renderer uses hardware
                                                     acceleration */
    SDL_RENDERER_PRESENTVSYNC = 0x00000004,     /**< Present is synchronized
                                                     with the refresh rate */
    SDL_RENDERER_TARGETTEXTURE = 0x00000008     /**< The renderer supports
                                                     rendering to texture */
} SDL_RendererFlags;

/**
 * Information on the capabilities of a render driver or context.
 */
typedef struct SDL_RendererInfo
{
    const char *name;           /**< The name of the renderer */
    Uint32 flags;               /**< Supported ::SDL_RendererFlags */
    Uint32 num_texture_formats; /**< The number of available texture formats */
    Uint32 texture_formats[16]; /**< The available texture formats */
    int max_texture_width;      /**< The maximum texture width */
    int max_texture_height;     /**< The maximum texture height */
} SDL_RendererInfo;

/**
 *  Vertex structure
 */
typedef struct SDL_Vertex
{
    SDL_FPoint position;        /**< Vertex position, in SDL_Renderer coordinates  */
    SDL_Color  color;           /**< Vertex color */
    SDL_FPoint tex_coord;       /**< Normalized texture coordinates, if needed */
} SDL_Vertex;

/**
 * The scaling mode for a texture.
 */
typedef enum
{
    SDL_ScaleModeNearest, /**< nearest pixel sampling */
    SDL_ScaleModeLinear,  /**< linear filtering */
    SDL_ScaleModeBest     /**< anisotropic filtering */
} SDL_ScaleMode;

/**
 * The access pattern allowed for a texture.
 */
typedef enum
{
    SDL_TEXTUREACCESS_STATIC,    /**< Changes rarely, not lockable */
    SDL_TEXTUREACCESS_STREAMING, /**< Changes frequently, lockable */
    SDL_TEXTUREACCESS_TARGET     /**< Texture can be used as a render target */
} SDL_TextureAccess;

/**
 * The texture channel modulation used in SDL_RenderCopy().
 */
typedef enum
{
    SDL_TEXTUREMODULATE_NONE = 0x00000000,     /**< No modulation */
    SDL_TEXTUREMODULATE_COLOR = 0x00000001,    /**< srcC = srcC * color */
    SDL_TEXTUREMODULATE_ALPHA = 0x00000002     /**< srcA = srcA * alpha */
} SDL_TextureModulate;

/**
 * Flip constants for SDL_RenderCopyEx
 */
typedef enum
{
    SDL_FLIP_NONE = 0x00000000,     /**< Do not flip */
    SDL_FLIP_HORIZONTAL = 0x00000001,    /**< flip horizontally */
    SDL_FLIP_VERTICAL = 0x00000002     /**< flip vertically */
} SDL_RendererFlip;

/**
 * A structure representing rendering state
 */
struct SDL_Renderer;
typedef struct SDL_Renderer SDL_Renderer;

/**
 * An efficient driver-specific representation of pixel data
 */
struct SDL_Texture;
typedef struct SDL_Texture SDL_Texture;

/* Function prototypes */

/**
 * Get the number of 2D rendering drivers available for the current display.
 *
 * A render driver is a set of code that handles rendering and texture
 * management on a particular display. Normally there is only one, but some
 * drivers may have several available with different capabilities.
 *
 * There may be none if SDL was compiled without render support.
 *
 * \returns a number >= 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 * \sa SDL_GetRenderDriverInfo
 */
extern DECLSPEC int SDLCALL SDL_GetNumRenderDrivers(void);

/**
 * Get info about a specific 2D rendering driver for the current display.
 *
 * \param index the index of the driver to query information about
 * \param info an SDL_RendererInfo structure to be filled with information on
 *             the rendering driver
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 * \sa SDL_GetNumRenderDrivers
 */
extern DECLSPEC int SDLCALL SDL_GetRenderDriverInfo(int index,
                                                    SDL_RendererInfo * info);

/**
 * Create a window and default renderer.
 *
 * \param width the width of the window
 * \param height the height of the window
 * \param window_flags the flags used to create the window (see
 *                     SDL_CreateWindow())
 * \param window a pointer filled with the window, or NULL on error
 * \param renderer a pointer filled with the renderer, or NULL on error
 * \returns 0 on success, or -1 on error; call SDL_GetError() for more
 *          information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 * \sa SDL_CreateWindow
 */
extern DECLSPEC int SDLCALL SDL_CreateWindowAndRenderer(
                                int width, int height, Uint32 window_flags,
                                SDL_Window **window, SDL_Renderer **renderer);


/**
 * Create a 2D rendering context for a window.
 *
 * \param window the window where rendering is displayed
 * \param index the index of the rendering driver to initialize, or -1 to
 *              initialize the first one supporting the requested flags
 * \param flags 0, or one or more SDL_RendererFlags OR'd together
 * \returns a valid rendering context or NULL if there was an error; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateSoftwareRenderer
 * \sa SDL_DestroyRenderer
 * \sa SDL_GetNumRenderDrivers
 * \sa SDL_GetRendererInfo
 */
extern DECLSPEC SDL_Renderer * SDLCALL SDL_CreateRenderer(SDL_Window * window,
                                               int index, Uint32 flags);

/**
 * Create a 2D software rendering context for a surface.
 *
 * Two other API which can be used to create SDL_Renderer:
 * SDL_CreateRenderer() and SDL_CreateWindowAndRenderer(). These can _also_
 * create a software renderer, but they are intended to be used with an
 * SDL_Window as the final destination and not an SDL_Surface.
 *
 * \param surface the SDL_Surface structure representing the surface where
 *                rendering is done
 * \returns a valid rendering context or NULL if there was an error; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 * \sa SDL_CreateWindowRenderer
 * \sa SDL_DestroyRenderer
 */
extern DECLSPEC SDL_Renderer * SDLCALL SDL_CreateSoftwareRenderer(SDL_Surface * surface);

/**
 * Get the renderer associated with a window.
 *
 * \param window the window to query
 * \returns the rendering context on success or NULL on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 */
extern DECLSPEC SDL_Renderer * SDLCALL SDL_GetRenderer(SDL_Window * window);

/**
 * Get information about a rendering context.
 *
 * \param renderer the rendering context
 * \param info an SDL_RendererInfo structure filled with information about the
 *             current renderer
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateRenderer
 */
extern DECLSPEC int SDLCALL SDL_GetRendererInfo(SDL_Renderer * renderer,
                                                SDL_RendererInfo * info);

/**
 * Get the output size in pixels of a rendering context.
 *
 * Due to high-dpi displays, you might end up with a rendering context that
 * has more pixels than the window that contains it, so use this instead of
 * SDL_GetWindowSize() to decide how much drawing area you have.
 *
 * \param renderer the rendering context
 * \param w an int filled with the width
 * \param h an int filled with the height
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetRenderer
 */
extern DECLSPEC int SDLCALL SDL_GetRendererOutputSize(SDL_Renderer * renderer,
                                                      int *w, int *h);

/**
 * Create a texture for a rendering context.
 *
 * You can set the texture scaling method by setting
 * `SDL_HINT_RENDER_SCALE_QUALITY` before creating the texture.
 *
 * \param renderer the rendering context
 * \param format one of the enumerated values in SDL_PixelFormatEnum
 * \param access one of the enumerated values in SDL_TextureAccess
 * \param w the width of the texture in pixels
 * \param h the height of the texture in pixels
 * \returns a pointer to the created texture or NULL if no rendering context
 *          was active, the format was unsupported, or the width or height
 *          were out of range; call SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateTextureFromSurface
 * \sa SDL_DestroyTexture
 * \sa SDL_QueryTexture
 * \sa SDL_UpdateTexture
 */
extern DECLSPEC SDL_Texture * SDLCALL SDL_CreateTexture(SDL_Renderer * renderer,
                                                        Uint32 format,
                                                        int access, int w,
                                                        int h);

/**
 * Create a texture from an existing surface.
 *
 * The surface is not modified or freed by this function.
 *
 * The SDL_TextureAccess hint for the created texture is
 * `SDL_TEXTUREACCESS_STATIC`.
 *
 * The pixel format of the created texture may be different from the pixel
 * format of the surface. Use SDL_QueryTexture() to query the pixel format of
 * the texture.
 *
 * \param renderer the rendering context
 * \param surface the SDL_Surface structure containing pixel data used to fill
 *                the texture
 * \returns the created texture or NULL on failure; call SDL_GetError() for
 *          more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateTexture
 * \sa SDL_DestroyTexture
 * \sa SDL_QueryTexture
 */
extern DECLSPEC SDL_Texture * SDLCALL SDL_CreateTextureFromSurface(SDL_Renderer * renderer, SDL_Surface * surface);

/**
 * Query the attributes of a texture.
 *
 * \param texture the texture to query
 * \param format a pointer filled in with the raw format of the texture; the
 *               actual format may differ, but pixel transfers will use this
 *               format (one of the SDL_PixelFormatEnum values)
 * \param access a pointer filled in with the actual access to the texture
 *               (one of the SDL_TextureAccess values)
 * \param w a pointer filled in with the width of the texture in pixels
 * \param h a pointer filled in with the height of the texture in pixels
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateTexture
 */
extern DECLSPEC int SDLCALL SDL_QueryTexture(SDL_Texture * texture,
                                             Uint32 * format, int *access,
                                             int *w, int *h);

/**
 * Set an additional color value multiplied into render copy operations.
 *
 * When this texture is rendered, during the copy operation each source color
 * channel is modulated by the appropriate color value according to the
 * following formula:
 *
 * `srcC = srcC * (color / 255)`
 *
 * Color modulation is not always supported by the renderer; it will return -1
 * if color modulation is not supported.
 *
 * \param texture the texture to update
 * \param r the red color value multiplied into copy operations
 * \param g the green color value multiplied into copy operations
 * \param b the blue color value multiplied into copy operations
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTextureColorMod
 * \sa SDL_SetTextureAlphaMod
 */
extern DECLSPEC int SDLCALL SDL_SetTextureColorMod(SDL_Texture * texture,
                                                   Uint8 r, Uint8 g, Uint8 b);


/**
 * Get the additional color value multiplied into render copy operations.
 *
 * \param texture the texture to query
 * \param r a pointer filled in with the current red color value
 * \param g a pointer filled in with the current green color value
 * \param b a pointer filled in with the current blue color value
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTextureAlphaMod
 * \sa SDL_SetTextureColorMod
 */
extern DECLSPEC int SDLCALL SDL_GetTextureColorMod(SDL_Texture * texture,
                                                   Uint8 * r, Uint8 * g,
                                                   Uint8 * b);

/**
 * Set an additional alpha value multiplied into render copy operations.
 *
 * When this texture is rendered, during the copy operation the source alpha
 * value is modulated by this alpha value according to the following formula:
 *
 * `srcA = srcA * (alpha / 255)`
 *
 * Alpha modulation is not always supported by the renderer; it will return -1
 * if alpha modulation is not supported.
 *
 * \param texture the texture to update
 * \param alpha the source alpha value multiplied into copy operations
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTextureAlphaMod
 * \sa SDL_SetTextureColorMod
 */
extern DECLSPEC int SDLCALL SDL_SetTextureAlphaMod(SDL_Texture * texture,
                                                   Uint8 alpha);

/**
 * Get the additional alpha value multiplied into render copy operations.
 *
 * \param texture the texture to query
 * \param alpha a pointer filled in with the current alpha value
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTextureColorMod
 * \sa SDL_SetTextureAlphaMod
 */
extern DECLSPEC int SDLCALL SDL_GetTextureAlphaMod(SDL_Texture * texture,
                                                   Uint8 * alpha);

/**
 * Set the blend mode for a texture, used by SDL_RenderCopy().
 *
 * If the blend mode is not supported, the closest supported mode is chosen
 * and this function returns -1.
 *
 * \param texture the texture to update
 * \param blendMode the SDL_BlendMode to use for texture blending
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_GetTextureBlendMode
 * \sa SDL_RenderCopy
 */
extern DECLSPEC int SDLCALL SDL_SetTextureBlendMode(SDL_Texture * texture,
                                                    SDL_BlendMode blendMode);

/**
 * Get the blend mode used for texture copy operations.
 *
 * \param texture the texture to query
 * \param blendMode a pointer filled in with the current SDL_BlendMode
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_SetTextureBlendMode
 */
extern DECLSPEC int SDLCALL SDL_GetTextureBlendMode(SDL_Texture * texture,
                                                    SDL_BlendMode *blendMode);

/**
 * Set the scale mode used for texture scale operations.
 *
 * If the scale mode is not supported, the closest supported mode is chosen.
 *
 * \param texture The texture to update.
 * \param scaleMode the SDL_ScaleMode to use for texture scaling.
 * \returns 0 on success, or -1 if the texture is not valid.
 *
 * \since This function is available since SDL 2.0.12.
 *
 * \sa SDL_GetTextureScaleMode
 */
extern DECLSPEC int SDLCALL SDL_SetTextureScaleMode(SDL_Texture * texture,
                                                    SDL_ScaleMode scaleMode);

/**
 * Get the scale mode used for texture scale operations.
 *
 * \param texture the texture to query.
 * \param scaleMode a pointer filled in with the current scale mode.
 * \return 0 on success, or -1 if the texture is not valid.
 *
 * \since This function is available since SDL 2.0.12.
 *
 * \sa SDL_SetTextureScaleMode
 */
extern DECLSPEC int SDLCALL SDL_GetTextureScaleMode(SDL_Texture * texture,
                                                    SDL_ScaleMode *scaleMode);

/**
 * Associate a user-specified pointer with a texture.
 *
 * \param texture the texture to update.
 * \param userdata the pointer to associate with the texture.
 * \returns 0 on success, or -1 if the texture is not valid.
 *
 * \since This function is available since SDL 2.0.18.
 *
 * \sa SDL_GetTextureUserData
 */
extern DECLSPEC int SDLCALL SDL_SetTextureUserData(SDL_Texture * texture,
                                                   void *userdata);

/**
 * Get the user-specified pointer associated with a texture
 *
 * \param texture the texture to query.
 * \return the pointer associated with the texture, or NULL if the texture is
 *         not valid.
 *
 * \since This function is available since SDL 2.0.18.
 *
 * \sa SDL_SetTextureUserData
 */
extern DECLSPEC void * SDLCALL SDL_GetTextureUserData(SDL_Texture * texture);

/**
 * Update the given texture rectangle with new pixel data.
 *
 * The pixel data must be in the pixel format of the texture. Use
 * SDL_QueryTexture() to query the pixel format of the texture.
 *
 * This is a fairly slow function, intended for use with static textures that
 * do not change often.
 *
 * If the texture is intended to be updated often, it is preferred to create
 * the texture as streaming and use the locking functions referenced below.
 * While this function will work with streaming textures, for optimization
 * reasons you may not get the pixels back if you lock the texture afterward.
 *
 * \param texture the texture to update
 * \param rect an SDL_Rect structure representing the area to update, or NULL
 *             to update the entire texture
 * \param pixels the raw pixel data in the format of the texture
 * \param pitch the number of bytes in a row of pixel data, including padding
 *              between lines
 * \returns 0 on success or a negative error code on failure; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.0.
 *
 * \sa SDL_CreateTexture
 * \sa SDL_LockTexture
 * \sa SDL_UnlockTexture
 */
extern DECLSPEC int SDLCALL SDL_UpdateTexture(SDL_Texture * texture,
                                              const SDL_Rect * rect,
                                              const void *pixels, int pitch);

/**
 * Update a rectangle within a planar YV12 or IYUV texture with new pixel
 * data.
 *
 * You can use SDL_UpdateTexture() as long as your pixel data is a contiguous
 * block of Y and U/V planes in the proper order, but this function is
 * available if your pixel data is not contiguous.
 *
 * \param texture the texture to update
 * \param rect a pointer to the rectangle of pixels to update, or NULL to
 *             update the entire texture
 * \param Yplane the raw pixel data for the Y plane
 * \param Ypitch the number of bytes between rows of pixel data for the Y
 *               plane
 * \param Uplane the raw pixel data for the U plane
 * \param Upitch the number of bytes between rows of pixel data for the U
 *               plane
 * \param Vplane the raw pixel data for the V plane
 * \param Vpitch the number of bytes between rows of pixel data for the V
 *               plane
 * \returns 0 on success or -1 if the texture is not valid; call
 *          SDL_GetError() for more information.
 *
 * \since This function is available since SDL 2.0.1.
 *
 * \sa SDL_UpdateTexture
 */
extern DECLSPEC int SDLCALL SDL_UpdateYUVTexture(SDL_Texture * texture,
                                                 const SDL_Rect * rect,
                                                 const Uint8 *Yplane, int Ypitch,
                                                 const Uint8 *Uplane, int Upitch,
                                                 const Uint8 *Vplane, int Vpitch);

/**
 * Update a rectangle within a planar NV12 or NV21 texture with new pixels.
 *
 * You can use SDL_UpdateTexture() as long as your pixel data is a contiguous
 * block of NV12/21 planes in the proper order, but this function is available
 * if your pixel data is not contiguous.
 *
 * \param texture the texture to update
 * \param rect a pointer to the rectangle of pixels to update, or NULL to
 *             update the entire texture.
 * \param Yplane the raw pixel data for the Y plane.
 * \param Ypitch the number of bytes between rows of pixel data for the Y
 *               plane.
 * \param UVplane the raw pixel data for the UV plane.
 * \param UVpitch the number of bytes between rows of pixel data for the UV
 *                plane.
 * \return 0 on success, or -1 if the texture is not valid.
 *
 * \since This function is available since SDL 2.0.16.
 */
extern DECLSPEC int SDLCALL SDL_UpdateNVTexture(SDL_Texture * texture,
                                                 const SDL_Rect * rect,
                                                 const Uint8 *Yplane, int Ypitch,
                                                 const Uint8 *UVplane, int UVpitch);

/**
 * Lock a portion of the texture for **write-only** pixel access.
 *
 * As an optimization, the pixels made available for editing don't necessarily
 * contain the old texture data. This is a write-only operation, and if you
 * need to keep a copy of the texture data you should do that at the
 * application level.
 *
 * You must use SDL_UnlockTexture() to unlock the pixels and apply any
 * changes.
 *
 * \param texture the texture to lock for access, which was created with
 *                `SDL_TEXTUREACCESS_STREAMING`
 * \param rect an SDL_Rect structure representing the area to lock for access;
 *             NULL to lock the entire texture
 * \param pixels this is filled in with a p                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                –º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßZc”Ç%‹Ê¬fª£úaRn¯µÛÄˆ²øÄ=[Å±úg¤ï£ÕiÇ.#ë„äòÏ;¾y§jÕ D…’i@Àch°ß Áä›€Ù,b¤öHåZz óP'AòÍ™SM´#áŸİÓÔ,;®©ĞİUv\™Bš}vÎ0åqà×0Œğc„5x;b‹²š9<êBÁù´TßÑrŠût¤Ñænplóš[oTŸúâäH¯1ó•oH2¾¹ÇZ‹M·ãß&ŒÁ”Ä¹k`6°Yhlh¸ˆ›µ˜šBÔœ]™ÂÏ™ZÌš)yêõ0¾ó¨OMö*9ËfB³Ñt‘QZq
¯èœ®ÑA…¶CJ7Œî7•Ø=Œ@¹«GY•j5¾xñiå#¨—øÏˆß¦ºMn	¬A+ğkcSzÂ!xí•3™ƒViae*X¾ñ~êÚQ•@Ğ¾…Ú>'móY­•Òn¨.^üÊ² Á@›Lí\WÙæ«a}>2$æVãTtF_Y:÷|÷s[50\|<5Q,“¢­1²­)^Ü4F1êƒzÄã`şgæ=ˆ›}4Nr»FŞò‹nÿaác±ÕØ¤Ö±<.Î£tx^–„òæ]c2›mî`PO æ<±fÜQhìè5TH¿wD^'ªûÑ'H·nôá\²Â÷z2ˆQÿ±³v—³£7ì1‚(ˆå–*Êo²‹kÊ‘WAS1VZm™_Zàò»DÉ[ôËF÷­Wc{bXEAŠ„ ú0±ˆÚ|ò{Z¨vgBÛ?52ƒøäAF¶·jv®Î›7LıZö	˜ËæIwtN<´ícÆÄöêˆÒ„xµ€ÏM"Y¶í_¦ÿ/!ñ,ô€tz W®O¿=a‘ŒUC¢Û–GI;ÑşãÑ×¬œõ+;P1[¶‡'X+«¬<5Wk×”mş¸?ğ{<ùÀ—sıw*›ùaIgS”À¤¶a†ÉI]£6ãvø‰ößßÑwßÏğiéør¤r9zæI?´ğ†PsÒ„Ä-Dµ{„;µ‚nq«)‹ıØaª¨F‘é„m?š:-egÜıCı÷#_õ½„KÓ÷Ş›††
¦Gİ]‹Ì0£AœB(4÷>ªÒ )Ø…O¥»áİñÆS~„"vØ:¦8(°9ªÚ¹nz¨9z]aì¹¯ï·š4yãkŒDBşuÈ+ad‡,÷©™€%P\ˆŠc+¬‘ '?} ¼Nû,ÛEƒÔ&ÍÖ’¥~6{l/…†"¹äñ3|Ì‚XÌ¼ÜZF(Ç%0'×” xwwC–”F† ÆidKÈ{Aªçjòe<»E>QO+ ò¥œ¼os0†_7b…&}ş£(`%:q#p](xü'QC\W]ŠŒ"ö"'h>FĞMI¦¿QŸR…k«FE§¢)ÚlrXCÃ“eà?ë‚î×mE[Ìœ5xR–¸Eß~ÑåV€n[¦{{ûT0‹\êõêb³OÎ hÒ-4‹‚h/’/ïÒYw~‚É»ô ô¯ÍË25Ää•'?ªâ­œÉ½)dfó©

l}ˆT±ÆûèZœ“AıÕœƒúYdÀW!
rª·õêl™Ø+èY/NéÌq{ùÄïlDßcö²x¼úœAO@šîuõbä'šjøuLè±z~³ê_’_Ñ¶§>Ú($m§²æk"‚¸ÙC¹üïˆ±ëfu:²¥Šueåài´½äy£Ş¶¡ó€
(–@ÀøıìÕ9*"´V|Òâíuúøp'ÑÖÎ8À¥ƒº”’¸6õXï|$ªë™·ÿRÑ¹u¤–…8sNá ÃúÕ–Ã4Í'öI§ª§gyéX@R—‡ZûµKi¼Dkoé¨s¬µ²"Zîá¨q±°¸”WÉ¤'g™{J"âíù$ô¬¢d<D´ùE±ç¡;IìQÿ„!N&Ü1W ÒK½µ—H¾ğñZ!GÜÕ±J›ï)VAu­W‚Ká“AÓ—aò
‘|y‚Øk…b#%ä:áµCg¹şâfıã'j×"0#÷øtÎeM 8^³;ä2çÈ‹u®<JFè¤¨{(Ü`^o–H5-ÊgÙ$÷“Ó¥ Ú4hh!A.u"›1KùÎ×Ñ^ö gEÅ=wÜ|rP„ÚGo‚•6 x¹)ı½!Şü—İ‚„
J¯]?ÅJFÈ¼kÃ´¶©3¯ÑÏÑLàEŒ˜nqå'ŸPÂ;ñFaz¹1=^ìÍ½Ö6çfÓXXÿ¬ÿkë˜ÏXtÁİHó/Èû©€×½EXÄP­á>Ô]ëdTËoåìR);}ú®Qi[R¥´B0Îœæ®„1açfÑÑ²
#s\'„$}é·L’›@—Y7F­fª	7[§÷®x]ËÛò•Ì¯8İİÃVaêñûš–B5Q<„Aá y—h™ãÓë
Ñfám§!µzÍdbULD·oALF#zfª™5;lê@ÅÂÅN =š^¼üÒ¨düyr)Iu·úo†×Ç“ĞE¸|¶²¤— o&èÊ·ûéq<ğ1šˆ€câªä+¡¥±5ÁŒ	ÇRØwâL’YWD½ï‡u_®¾Â‹îS”rÅÛmÄªX"5ıÃsĞÆ%;k6L¨ª–÷ŞLìxÕÊÆiª’/ded(ƒ´–Oö§za¨ÒJ9B.µ‹´Îã²Èº2ë)q5^Tm^œb¤=ƒ¢Ö°fœ{^*¡p[rä•¯F&İsú²rÔïÉÇpS…•6ŸıK7]Rú„Ö€Q+zGñÉÈWŞ2[m^v©&ÎV=Ïôk©d8àI–s_ªá‰xA[&nä'ãRFWBkŒ®ï¶C°9èR¯À¼-ªúÖêDL®©,½gC,«ÿ ¸kª~n˜åÓ
çÄœ@EQ›Já(­(mwş½*¨İF'e„§+t9®²©7ê¸VØº7§¸äº¿uóBÌAxPU‡¤KÂdÆùø%*ÿ¿Ò˜p˜•LÇ	Ëâ{Ù5 ÊåÂ¢»;:æ™+xû÷M‰Ôjr~ƒ9íme5{‚ŠÒÌ'¥êèUá›ßZ
¤pëñ—œèO¯˜¤” km¼Â‹Å†>î{ì×s«´aKDaØ@l "tSm:·„´ä•²MiÇÎY;çpPK"‹—H”Te#€0ÌöN9l|Ï	L€’’Aï©£Êº¥ÍÿÍõL–fRİ¨£?¨
Tïo¸j
 ¦[2ı‘°Ó.ÛÔB©…ö„B’ÂWs‹ºå¶û9·ŸJK…Ì=Øu~:{î›GÿéÁ?›êmœé`6×—F?1´C9òhÃ,Ù„¾k‡¬¿÷3~/o:¿M2®ÍúŒ@øBHÙr3Åà£Sø¶øêÑ•ıDƒ™±.}X&‹› ^«ê‰C£ç„ËÌS«/§ş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ßş§ËÓŸkxHé§tÚßs‚3÷”xĞê±îşHì3zß±Èİ(3«;,²Ş£–º÷:ï“ße€šŠ4÷]PçNnçâ?1BwùyÚ¢pfÃ°½ImíûÄäËì²]÷Dyì_j±Ì'F”oû€Êxë€Q©&uÑíMjZ$û®t@—:a®F®Ç_¼}=[èö‡j‹·>›ÍMwÂúğŠ
€E ’tş0é1(õìótãäIQa]ß“'CÚ^¾lÃÙŠŒ†"\º˜ĞMÑ˜~¥f\	vØÅ‰ĞÑëC. 6-AùxÃW›Ş…×fîOˆëŸ;†tÅÙ†YmÛ×Öwâ{¼õ‹ü•EBÌ“Ö*şî™çÎÂˆjÁ)á º.£Ã«Ÿ~?ÙÂó›;o”ş¡/Âë˜İ,§BaÉğéB@wÆåšT™EüujM+ıt»úÆ“›F´ë‚jøÍ–=ÎšÑw‡‹±WÒ+Â†elgûõ‹S8@{-»(ôYlĞÇ²Ø.ıÚ5G2!´vózöE/1ñ"ÿF§5
²B™Ãÿê%ˆWíë¢>ŠÖ÷5Œ'¯lâ–æè!¿8Q0q“[³)ffÊ‹®ìx)ôûÓåå¼—Ì[:^ğŸó°%{÷ÉÈ+³,‹±z/?úâ„5 H|% ÿwf>¯.sj®ß'“93K÷1Ÿ†P³ŒºÆ¾S…2ã 
Ş(¨ÜİY‹­[Õ	H¦Ãü«nİÔ»ÄÏ¦ÍI$_ APmn'á„?ño\6 ½fá ‘§ñ•â˜èZ‡ˆÎbÁÃ4-B^j‡(Ñ¶ºÎğ—Ñ;}vÊ$EÃ¤ÎÎŠß¿Tšn§¥ØĞ)Îèj–%t¢'›Ò¬mˆ	76<ÿRĞ…Ş°jÏ™\j;ˆ2á.²]=
Q2ÜfJú<°ìRÕÓqù¦LÌ}ƒÀZÂ‘¢Ù|;&÷$šÒ‰ÁŠègx³S)U'ÍíÛ 1$ìõï¢‚Ï[ ¬™Õ—Ø7u4çJeğ•øOHÙ3Ô´~&K¬~>@%‡\\h¦ªŸäw)%äˆ¥Šl[İgdCUŞqyì”B%hìZç¸ıSìA5ŸÒÇñ"I&¯üGEsËíu¨aÚ¥üºèÉëŠ"+øq+\Ÿ¬®–ÒåÍĞ¡ˆMÕö~“HY.&è¤Éª§hÁùö¡J„Ì 5ŒÜGˆu`
Z^ÚÔ£Ñ£&]úd"º,ï*?¿ììë,¼~Çú¨Àm$%k“oˆ±²·V/ògbó¹•îŞhÍOƒ%7»?°·ŒêtŞ>{3;Y7³G­²ìn´¥%®d¥»Û»ŒÅ¶œAòŠÄn'¯Ì?I‚‘iy‚»õ8ÙíNh2€›yÅÓ´b^Û•*Â]ì|““$mĞ†CËº	¡¤¬`RW)­·®
€ü{›±U/1Ï0Óz‘v÷à5LGg*úÎ¨ÖœŒL%+á$„£ÆĞ½Ñø”o¦Ó®,Q tccK=ãô³í©¥9(ËAr“†/RÉ{ü;O€$²Í&ßfÁ g‡ÅgÓäx@¨’MJˆJÍyÈ°xÇšX“&^X<i‘n¢æá¹§Şù_—„Çò.w¾¸ÆK J”šÈÏ‰év	»+1ÒL~mØ`z­Ô'ôE!˜ˆxÀÉš˜Eh
R*¾²Gta2–ƒX%*o­¢}oò¦ç{ú3¤,¼2È:AøÿZˆÖN#i]ò"èõbøšü~äoå]Æ;:aÆ‡FÈ4´°Yc±‡`ñÌÀ'l¹˜%Ml}BmìÖx¡ÏGœJyà·†Ğ~Öù>7£IJ0ÎD
S1O7Öô¦tƒoµƒ¸ë)qÃ„ÀGoĞöSÑ¯ø5 BYÌ§sı”ıT¡ &„zİ\›ıq»*­:ÂuôKkÿ±?»q<ªRã8Çe¢•¥áö¾=¢BncXJÛÌhål—Y©QµÅ•ˆÙ‹¾«)Oş®"-ş»¯º´1”Ä¨™‡¤³‚{Û¶”kr_,-?ÒiKºT'@\.â¸ I¹5"u~#- TİÜc§³Ò…~æÔÁÈ¸ì
!Z«‡é»x5İ3E"Ä"Ø8,±%šŠ)@†µ¢pQû°ä‡pürë!G½·Áâ-"³´BuF1‡lF’‰m–æ^Ë5Ly`Ğ*¬-K;Q@¹+–UÎ¤6w:>ZœÑÂêÔgEPçÜ_OWpA—Oë®3~C–ü ;›­š$ì4X9p6ŒÎD,wwµ¾C;†, ÇX‚\PeÙ´5¼? Ì¶I 0…ÿZˆÍšê‚òxèTI$"Ö[#géÒ	ŸıpCpWŠÃ&f­º6âf¬•O\Wy½…ˆş˜<uÄF‘¹{6R­J‹;Ú±òÆ¬UD4ZÎÖ}"Ù_´û)Húû/1ƒ–©f¢éjèø~|›'–É(lÿ&'®^±+â…RğÁ-›¸Wñ!î-</6“ÍÀûíéÔ¹º”ã³PAAQ70ÇEšµàí‚ñ§í¾èÛşbs…3™#‹~7Î`‡y~¦Œ4}Ò3Ü+3º~:YY4›dFïï^êïËEÿ4¦ÙvŠ—pïG‹³·»†!:ìÙq3H¦C‘'«R±³!BO Me@æä k3ZLãu4¬3—$6@¬~ÁU:”y–®¤v£_Î	N›”~¹BPè¨Ôbì²¶rŒÉ<™!^U•iÈ–ËøoµÃ‡U–)t?£á5–8ç6ıùÇ~¼«G2È=1q{Œ…æHª™9óóRÓå>äîL¦ïÁ=¶å‡Eo„tªÀî;ğpci¼‚lQ>¹¦2ä d¥ ÿÒ©
îed»vÕcU+W›Tde½’æußQ<]Ğ?	Ôèb–&ˆ¶ùFg}É’¤zVïK]â&GrvÄˆ­ıÌŸ*©® Ìl*%>¸ÕÅ›\¾Ì×bFïfºönÈ.¿1À’S­U ÍšÍ#™Š*‡ôçÒå,Íø¹œTS‰óë>í¦ ş!§”„vÑµÏZ²¥«¢ß›“%©„’¦B•Wë8ökÖdäP23lºÍb‚³TÇ„+•¨
6èßv#@ëñ;Ä'k7Ó+Tä3¥’™£FOo_ÂDÆî‘:|UQöŞå?LÚd„IUPq¡‹cU¬Ü$:t1&“] xŞú_¼‰|Hª3Â¡å¦K$s™š.@ò6‡ùó¯$ü€‹/İF.8,QÔ„¶<ÚDOi'tFNüuá-Ô‡h~9H4´:"XÂ#ÑˆušIäFÙ™LñC¹À$~ñ^WmLràê‰ì ÏO²à Å¼ã{wa@ ªyxM¨PÕ,Ë1ÂÀ+¨
j¥äKÎ'Ôø'K~Ei¤§ˆ3´p?q=Xnme{/hãæ0%Ç6ÒÌL>'äncöA 6¼ÿw•‡œô9_í8‰úCN®­’>/ûSVøgÜY«ó¤Ø–ÛR*ä
"ãÕõZ<0‹ß{Ü¹¼j{Š˜Dm5Zş¨>;¿mÈ&ÁTU¤«Z½Îsõè2Ï¼³"›sO%G·L ^L:&x$rAızşIœŞæ	÷£_2Ö¹ÉgBYsº¡ÑAv÷‡ı(8ÄÊ%xä]Dé `vçìíŠB%b Òô‘¾¬‹Ş £êu¿]CE¦vµª×¾ÿ0ãYÁ˜æ91#/Lpy3„¬Çï®ãzß2J;šgTˆÜ.n¥‡ l”e}è.Ëß…’f46_“.Cº5vâ”ÿ‘ı*á	T"\õA+êİ¢!M1Î·_êñöÍÂş; VŠ‰ß°+œ9
¨DÎÌÚÿEZï Îñ)ÙñîÉkeG!¼…5Ãî­Ç¥ÁOtõÿ¥…³R¯>çlÈ¶»ş­|hô‚'¥»c$;Cm¹ö" ó0n\ypI8Ù‰C¾`wL3Iƒîš¶=¹ı&ØvÅF~€ÿŞ)s?ŞËé«‹ÍF• §í½µjOC,Â0db¡yêjy…ªÍk.{²€Mqyä­ Yš’#x6r-V°`ÎÛ±µÿ²?2Ô”•X_0¶p¡²ì•¢!!?‰Œ¿›‹`è+ŞG”^ÿ#ãM~£x‹TÃo÷©m1Fè2ô$2ƒşÙçôS!M²a 2kâ4#¾×Ã …÷>t2€<`5Ô©êlŸS•]£Óêaş>_ùÛh&ÆD÷8v~{Æ
÷ƒZA9İY]¿÷÷Åu‰f9ƒœ^léí*…#*Ë†”=hhË»k&s¿
O®PĞÊ¼*U >ö³Å¶¹~›˜£o]õQ,rifõ¹e‚‹Æ¢Êõ±®Ò·ê~B±!9Z.œEv¡Šå.“7„—eâ§Q´zÕÈIÑõIâ÷ãhI Éü63öÍß ÕƒjsY8¸P 	š=É7wjÖÈÙ¨y@Bÿ.¤<H±¥8 ÏÛÀ]M†ÙbR
S Q09.%®šø¯Ò^ñYMT:¾Ô±VÌ`–år¿áî¤µ<´…A% ®÷vA†Ê4oxé=­™ çö]«,Çhñ£â°Ó½Œõ|®
ŠÃ÷LóT]ùuYÇXÕgÏÚµ\Z…:‘I§5ò¡~bq)Ÿ Â8‡—7êQè¸k–k†zkŠgé¤vMøí¿Î1'K!P»²c_Åş%äİ!¸'Ïİ)ÍÍœF[@ç.†ÕBÖæÕŒæ2 ƒ…|mŞØ'ˆE¹(/ÎÚ/?ÅûhL˜î D0„á›ùxÖË1'ü¹cøˆè9<BİÇyç¥ì+TM910áQşšc'l„í
=nlÒÎDAä %ı˜ùœ|òÙ>VîòşdZ›µhcA$ÇõëâÎ8«ı-a$»Iéïwå_3ÇÙ±€å¬A©DÖ®†íqX/÷y·T:ƒö$:»Ò¡CZµrNà5şb$43{ª{„	+ÏÀ´R	·”^"2§Í¯s{¹ıƒÓB™¨Ü%“[çş	§5©Œ`Ù24A/¢ß0‡«R_[ÇÂ÷Ë±†û¸®vC¨A¿dcZÍĞÄ’±şxb«^çs3–ÕüM¤x&:“Ràú}DöÑK¡ısğ¸b¸c}˜7Ö°òG 1‡ bõfó®%íµå0ä$9Lw¨$®ãïz%tVÚU“¦Ç‘÷\Î0µ¢"6Å‡r­î!ÊPkôp)"êTVÍ×Õj›ßœNèilRh®/ÕŞ“‡€mBTq·‰–#8FtEV„y£CÚ¿Ğ¨Wh¿R@â—É0&Ù\LjˆLì®‘ìg>aB\ı+Z'{$`àxÏğ) “f0º2Zz¾ÉV¸ø r9¹ÍÉO“4u(Æ‘¶?áä*ÍA:A’–yır½hé0İñ(]Œk&Á)#F¬{wø©Pê‡ûIškh*PûËjjà:­æø‰„'šÜGë?S½Z”ˆ$öŒ'²‘`ƒ‹×¤¸*¤w:ü/¡±§ITkšÒ¶ª… kM§ê¦ˆ¬«É8ÜSF!'S²> Cb1+^ol|o¶#E˜;G;ÆğşÒÄw:$ûvQRö¢=J Y7»sd°«-ôCiNê/n
ı³¾0T\aˆî¬'êA65Ÿ±R‰úğ.ªØï}@‰¸¿ÁIM«Å0·Ş¼pG,Ú¼­ˆëê.YÒÚ²ìV¡E¾@İòİL.,&úk¬xÄ1Õ ß$å[^²V³@D—ê4]äÊÑ8š` `z%çàuø4r/Æ¡ÄWÖĞƒÎ± *ùaÔ'p_ßÑÔú—àólY6!ZD3ÎÄÜa? Õ:Õ?Gm4’º!BïL[4•Æw¸OlÂ”ÈçJ\tæF!h›ñTGy–í…Ï5«Oùg:÷›ÏÍ^FÂ”nC§sƒ©üè%3¶dC™¯%4Êr÷u–ÀÃÅ™0ºOKŠzU9—<¸ˆå½—ˆ!6ÿ[Î[—À¤¹Õ &ºö8Y1à;¼H¤j—æúYÑ¤R©İœ…<“ ÓCÄ¬b«4ğ#Vÿuô:^ÇF`.ì%SMfæç9â”rÇ9Ô`%SoÏöË«eœõ”„š>|PÜ¯„KB\¢¿Š"Xè&ä£–c2Æù+®çÔ1D^Š7Íƒ¸È/+XÊD=r—A«lò|°Bšâ‘wáUÒÍğ0ŞHÁ/­Î=f|Põš‹õÍ=\4á«J¸ÿ±U‚6üÛMÌ<Æi©cKíéƒ–‹F°ğ: aGc1ÙÊ©U«Ü®G¤•ús°;ÛòoSù›¹-ÚèW,»›õÎ ^O¦>¦È=wáüœ¿ï·Û'4'4É9hH1j©­x—„½+(å¯]¸JŸ³Ğ}Ès—º%ÙvíGR×#gz¸·¼„ÏÁk4TÙKÂÚ$Î‚ÌÂ§bşI-i$ª¼)º©M~IÈJ5dŠ¤:Fà47&¾,«z ÿĞˆÀPÇ7 bdŒoøjvÏ‰+›-®T˜ø:ÖøRú¥ˆ¯UãF\’N@ÄIŞé{=ræÖ“AÕ ë.Hğ`,:=¦Ò{&0÷h›ÖW`Ğ=DÕñÿƒ6)å8ïºlYUGÈjs]ê§G¤+yŒ¢ÂY¡fËœ)Q«'R/PF¸?Ç¦Ø|¬âõlÔ$ûCt-)¹²øy®hÓJëég-œ‡\J´!ëĞp8hÏ˜0DB(?(ÁbŸëq«um½‚|/ÖT:é÷hWí+—¹Iwe«äÊú™4)åEtß¾Œ«d¿'.ÈI¤@HÀ\×ræESj'ld%À[fİ¤55M'wíçÉÅ>rJôWÎ@ß½»ø¦ßì2rŸå,Kx®Œ
h:t¼ïåi°“Bı4Eâ(Ë%öUO ØÎ¨‡¤¥œk±Æàn¼$NÆ²0ók!ØV{ş/×da‰í-gˆ›Zùÿ°Än²—§³1&j4kš“F¤g–8PÈRÂ¬ ’8®Ÿ…N00°&ıê¤ó@Jkæıi8:"ı–:†—Ì!É]ßKû*jªş4ÌÜÉ¡pñ(%+±FNğ2lf#®Ó•ÒJ²‚Dòæ Ğ‡G¶ª‚ô¡2VÅÕAC~+¤Å×du£Â`æ†Ö€ÒÉëúO}YÎmäşE®w²÷\µîõ :m}:"ƒÑ€¨CÛ<Dçøã#öWñ‰›—8¹2Ì7„*©õé<5s,u	ÌıR³ÇP$Q•;€X
ğ?ş¶;W—š«Rˆ¸ß,lZ–´Ô_÷¾L•vìÍiï–PÊ=qc,Òû7lË	,®wßëõ²á>§-†}î‹,ï¶ÉŠ<0†‹…¥Ns1Z^Oç,›‡ÚœÆóÛ-l™VÄucÔØn-s=– ·+,£C¤é«75o ^Ös¯fÀÌ¦Ø£µS“,í>`¶	 ½»ŒÉÆ"=7T‘UgôŒ&õH›à¶paT%­ºâr¬p1Ÿ#I#½Ä„ş7«³Ï3Òäc`Va¢‹å¤÷P&IÄ}:‚-ºƒ»á™¯g“¼A{ÖuŠr®½äÔş¯6åëk!„‰7¨kìd­±öCƒ4*ÿ…$‚Q&Ô%Ğ÷‹7-—¸Õjp@‹æ(êxÈ­3°µçÊîO¸_¼s@hÕ7?/Í¶i?'ĞLo’|Áşg_ô©vWÙ«ê·ŠºÒKNA›'5eâLXœ÷ƒÆpGÆX4CgâÉ¯°®i‚Êo²Ø=ùfßÖß¾:jSE\½#âvñV¹x¥|ú€ˆR#Ê‹¾¸çm n]ëƒõQ^@ÄÇ´\hLıRÄ/, –R7ïôÎh}¦eÅ@?õx¢Û:«-ù Ù(ÂÓ‚•ùmL½©ŒÓµ)„à*İÔV	òöFÏød%“(G´éW-¢Ñ^ßéßz6´å¸L#@eV‹–œl?:¥ÛÙèºX#¿X-`gK(ºK3¶&SM£^vìp˜­]™O…¾~{^ì²m œüH*q
ç½óƒ¢şå7xvôØ”/Ød{c/iÎK”ÃFo`œâ]İ8içÄŠåW-ê|í×ÊO¡x“üĞÛüZT.ò°rÈFm÷/¥ÜœU4%.G:ËªõÚL¯¹ƒíÔøà 9İÉÇ6C*="tØÈò»ö‚@¥¡„jŠc6Ô„Ô!Ş5ÊÏ—a„šÒİ+ó]¿Úr ÌQÕÊÌÿa-˜ SkIPr¡yz¼ìÅYá·#Ú¤Ó-S˜,™<×â{HÚ'Ob÷|Y=v‰¦¿c¡ã3"P%—î	Äto*ÎAõR'X`g¸LŠóÛ;Ìêu‡(aO½S‚pyÃŒm®BAÔú1H×˜ÑB{Ò»Kæ'‡qA2şÀ­YÑ¶×¢éq¼ÇZ!•ÿu=Œ¯~ë’ˆ2½ÒijVCK„äÌ8P	u…«Q³Şë±4["e,ÁEçj }“5J-ç¢¥5|œƒœ™yç~;º‹ fÁ*¶ÃÜaMkHTZ3ç×ıÊ¢ãÜø4|Ï³ü¼­aIu¿í+­Ï½™JRËñÖİø è0GGÿòáIÖOm/ˆóRaßUk§>„«Ì¸Ÿ&ğïœ.¶‰e—+x,ğÔ&RdZƒ~g-W¢ÜòÅóU‘‡Ò…­‚ŞNCŒŒßeåK$…È+V¼à?î¯N[sÇ?¹†t·ÕÙ]«Ø,+İ?@ +Ö¤ŸKÉë"æ „/jx+8ußÌ+a'=ˆã:Œû"_`WøKÛˆÏÃÔ‘º¾ÔÕ1@h8¼yéÙœjºü+0èŞ•+e"8Ğ°Ñ<':¹¯§ü‹ö~3«\X¦}"%ğzÙFDöbÏ–iøTuÔujªUË{ÁÕGEL’I°ê'ªÑ¹$ò)ô‹`A¼×5é> É¬jgsxåglfií.réœ2_. +á¶<vy­½’¿Üµ/‡À+1®Ñ9«Ü4>¡-™H!Ê¿2y ]eg¼H=úÿ 
w•w– K™G:¾„¹$óq2R/ÈK…<³wÚLY\™Ñ®ØaŸ™J&1˜­ïÊP?‡w¾©“ y¸]¬/1Ç„}Q7÷ş#	•–ôœ”ZIØ*:\ĞÂı|"¯X2øpìŸT±1k3BÙüZÈbb €ç‘\õuô#Ó6&˜â~CW¥u£
1UOCQ5Å÷²ØòA«³ğa>9'+jfëPåî~R­™„Fê,Kv®á‘möP›–¼ğ ¼4ü*yÍkª!“ÿçZü2VHÌ_7*±¬ºàö
Ã¢øX×nb!7ëxŠÃ^ŒBÈÌ¾¬¹ˆ¼LaöëÑ11YDRKPîf<¢°W·ãø,,¥FbÓÎâkE3ìÓ"¤ Èã–³v=‚C50_?K2ŞYVHaDêl?³ æÇ(UvÀ'xdY¡w^FÓ5/-DÌÈ#‹ï²-U%Av0ËYGç…EkıF¥Sf­|OVƒNØC½‹N—ãØùDdCÑuá§Î´b9˜+f1R—åÙÅØ§öÔôEÆàhŠÄIO»¤ÄÍït«‘šv†gÖ6W».)CR6|9ááv ğµÎ÷CmT rŒÜFrQÏÊİÒM&çæ5ÀÇ.e`«û€—|{I”Ÿ<ŒI.F$Êp lÒ}“.'®3lÄ8m§xrGÏwÖÇÒ^®qáÚ8mÖn £õMò¾ÙÉSú-b©äÙÈH¥ät:ˆı¢±Å²|£‚‘]çª•I¯ÃFØ“#|¯CÒNÓ^Ìé©ÅÌt æÓ
;5´k=ª %} ÷ò¬Sá•ä:aœXÓ¥†,ïQ/gßËï0	i±QR‚íú°02..-seøn¿­Zôèsù…®ğŒ8Å€bC¾båìTğIn÷z«?îOìÑ
m oDà|˜ Lx±Ú*¿™]e8R®4±X@†iã(pAMk$ŞË—hBy:`¡ñj’ş¹&q¦Ğ†Ÿ§*ë%©nxz[ÂĞ}¼kê?K.~2Kûµ}ƒâ½ïr¸™O­(°é à—´÷ÀDcø0{˜øQáÊì—Úuó»ñÆ9f´ô¹¸{3)öÌ9ZE$h¯8—·ïY}ï Ø~OÖÉ,Q0 çÒSÅ'DuÚJ ­mV¡æ"”~>ó¬İ˜o DX+¹w•œ£öí?{4ÉëìèÍæBbôÍ|@ßÕìûp²MŠ@2ñ`&UR’µlWx{¦•şöêLıpi
B÷õHÙá‚ILóCÙ“ønŞzAù7.Œ\C©PŸ˜XéX‹ÿouçFÒGoR1Óõ¡9D$Ñ¨>7“:cb®SÄ1µ^ÕB)6£AæIø€Vû"§¦'”v‘[sFbe¥ùFÌ¥B
‘Dù <tß,+ Ä&g÷—€«TşĞ~² Rñš%QCê§È‘Ñ·jTâ_ QJOŒî¸Ã×M›Í0ÊS*9)~4)»1y¬-ÇŸrEC”<yŠm5p‚bó[ÔAÄé±H)C€µ4’Ud¨YóÍ™¥×ÜíÍ½}eıŞıÜ‹øW šìõİü¹XEGâH²M,ÖUxıé´za×*^+y†ˆ/å¦k<‰•3,r)…ÎŠ·ÙÓ]áF<3B}@¹`İìÁ‰ø­3•P|Ï&0Ä>`c”™¡	VËæ…Àº?°YEšøàD=³8ñsÈ:¼Ã´şëøv6I•Ÿ¡««6ÖXó²=9ÉqÎÃ…OLsú˜	²sÕ ¼òô×Ûi¥BohÇ¹Îò1‡‚è(urPİ‘“W‹jVş*ˆ3=¾•¥7îĞlº	‹hğƒQ-¹2$b(p®K|$K´h•ĞĞ8„ïˆ^k	¬¿ªlƒ¯ÄRÀ¦È:cB	0F‹~Î©H¡óßîæUÌ6±Y¾£G£=4ÔÕ…#	¡Úu,HìFWEF Ò hÂ‹—O&0O+ÎŞhäşƒ¿Ü,İ’;÷zğOWµ¾“ÒDdipÎéGoóûŒW<yVâ;ï.ëÄpõè†Ï†:\·‚œ¾¹åBŠH/ŸjÌŒpŸ‹> 9¢(D#ÖĞö<Ò b0›c^ä?k6¸·à85D“	İĞ†@ˆÌï\G[¥½…×O
°q_›.CşêÊûTFiw1~2³kàNÚh>Ç–æ‚+ğ"|y1"ÑÊÂQÑñ•6,‚,Ã¦.°Š”(îTİHø‰^5¿SUô}`£†‰óş–l`. (ºjLqşBºD‹—mWM†áÈ<G/µ{8Şºc3ùµ ërFÕ+ØâÌBîA@ z5õj°ØŸn³-…9{õ”k™™WF@LöˆÜ?|’h=8pÔ©¢0°É§hîI;ÊûØ²Ë­ÍÌ;0àÊæuXäBšÛ?™òÔCê@Ä”å¸¨h@27l*i¦ªÅ‡sÌ±Dæo}SXgÆ1î^Ó8˜J~ò¸Ü³pOh£7’X:nİãy" m{o+oXTÔñÎè‡p‘c‚phLÓ”op(pp€)u]}ãcZÆØº£Œ(ÚÔ*T…Á·±-Võïªœ·,0…h[ôîÄ(Òóº$©×ãA‡±é2«ÄÍgR®Èò`<6À~ŠÁº[6ªêô½Œn4/Kš[R&bUwØIËÍ’£¨¶ZëËm"Qÿ}Ê<éŒs˜;Ä
ÄâÒŞ%©©ÕõaL?v W$»¾sjÉ5¿jŸÌcó>ü–\W·ñ¾ÑT·í@;dD&€âğ±²¶B@(Ò¶àş!`ïql@}st:;„À¦<*É:kXè‚:0’Å 3ÿ
§÷¥X›ÌXJĞ¶1©›yÅbÃÛWÎ³=~¬tŞÀ¢U^3ÂV“Ç†ßÒœq3õa–QÏˆ°54[’¨J@G¹òú6»à¶äwúf?lx§‚Ú7Îë'. Zñ ©'àÒÛQ‹sÛµ*-Ü~8ó@åúè"« {Üu‡;1ñè4'Û0Ú‘+„ŸöAÒA, !¿_ö¥2_il“
VG_û`µ´¨ƒ6ûaÿaœĞ¥Ç40¦JüÚ‹ã•¬à`ãXSšÔ¢sèP±­ª
"dÊ3£û1·ƒ¯{/7ŠzŒ¡9–íéM/š«­k_ëë[«'#`?>“DìÊ 2Tq³U(ò6ˆ)y\+çZı_`¸‚qÍ h—r$S°a<Â³Ã¡3×Èø”¤˜'P%“JRá+èò4£ééŸ¿¤Ò9ÕY÷Èçã×íĞµ|ß¸Ô²²äoÿÿVø‹§r‚-m™[¬­	I¤KSáœ®‰Ğ|›u¿°0nâÍ`"T‡7üûüÓşN{˜Ù£ÖñdVMXx6ı;+˜Æä „3y¦hôşVÑ9{sS½“ÇÂ=,‘QM;2ş…>e4–V!¼j=°|ø4Bpf´ú%dtãêºue×ViÄ&mÑ\¿‚eı#šÑµÎ¿ğjj²|—\³%R{\[&9.©,H((d¿9¤iŒ›òtÖ´7}ÚsU§±'¹xñ	ÈÇz.œ²ê-îËŒ´0ú£Xæ>;%¡
ŒF~d™"Ô‘	‹;wÑIÏ'Z'D¾L¸}:9{ák`¡/5FJn8¦°¿ÌïªÌ·X™ C÷é"mÂ©ğëÌê Ûæh1Íg(v8)…ö¯2^è†§œĞ¥ë²5=bıø¿úƒ¥úı®Ò{â]r µ…1ŒÜĞz/²ea²Œé@>kÍ>ég	ÓÓÒş`ÂbíYGä5¿“Œ\t¨µÇ³b¶Æå²Lê½†vQ%<gú;cw„±üÿj`<JK+!„Y&uÅzo=QqÑ›¿Â+•¹(§ÎŠ\zrvÉfY|›õòt¦!-í¡ZÄKÄO[×mÈ\şm˜&DÌ¶aËXBEy'÷Û&¹f`1tl±Æ2Ë×Ü , µ/Uè’Üº ºÃû&Æs‰  a‡mTş‹¼ó—;zÕÚ‚!v;F3Ë£ŞbƒÔïyUùà‡İˆĞ7´¡ú„iù†ÊÑ½B¶²OMu˜B·áí˜û´ıâ@©›Cİa=ƒ*oº`™_t+2Ç±Ñğ$^Çjz¶Ét"ë`Å7_xÒ…ÑJ•ÛÇ@ØÌ§·©o…öø•){DZ<ªÕËÀvWpşdVúƒ0V•ŒIÎŠ”#~µÛ|qº/ô§4`$yüN1…—¸Dİ¥v¡R~^œä§/KerN´X˜ÈZOJàå1ó+"9"ÏªPq™ÑºÖá‹!|sbø)ğñf=Ÿø)İßê×”íkş&n¦†'ËÀëœŠ‚‡Æéÿ‘!ËÌ1ÅAæ%àÃìKn• É|³üf>¿_7şÔiŸ•ïŒââ#BV­\ «Ø #GE\ËiÓúFôìõA×{ÁH‰òÊJNØQ|H…krÿ;*€›Ğ7À¸í¸…ÖÊ¯n­÷ap=µLŠ"
ÔÇÍ;¦ü¿W‘<˜òÔ*K;i}¦°½›G¦™Uœªµ‡pBå™òb5<;¬|ÿ	«VÚíş/,‘¾ö[pÙñ‹¾ š²’¸êÀìë=õ‘¡+ÖX¤f1õu:8mÓÁK,:~şJµæ*ÿ×?b‡«Î¼#&[Ğ¤›6N„Öd*˜OÑ›ig·ÃKG„~»a)&¹+Ÿ„†J Hã¦|F[ïÉ2aÈ‚Tı«¼èÇJiG17dí¦ñç“±šôşÒÉ FWw=•'å¯s/åª|x"9‹ÂæM5Ÿf²ÿ>K˜8PÖ¶9º]h[(Í«f”‰ĞštöŒ’i €ÃèP/I¡"•¯v@´Éûx°, ¾G.Ê2\åN¨ãPß©¹%F¦»ß×'‹Ï§äß›+¦èĞ±ø[oN.ÑÅIÊœnbºÂ<üí]ÈKUt^2
ı­±ë¥¬iÒûÃP¿Cèb$!×ÀªI=tú/. >Ş‡€–ï/úºN9ôœ•ËRÀ*¥w±’¦İşJbÒ^6æî;ãHÿTƒî(f*€—TXŸ.ğd4.Ê™©†0ìˆ¼½i×»­F™(Ñ§:@•gøë5™bPÅ=n*|Şfa@8ª1”„	ş•¯³|mz•ãDG±÷>yæ%ìŸkéÁiJ¸UÔš[+ğ-½^ĞVwÂõ; ~Ò,æŒ™Üç(ëDDE{ûÃvÅy]qçK ã7PÜÆWÖ6— 5–ä¡¹˜Å¥AX<QpCq.+r6ÿBXÆ»Ê™0˜8H‹KQ
4ÏG‚ÌQò®‘{•¾È­Q%İ®å™<Ë» °‹8Ü2ğ¿2`SECPXÖè§Â ÚO!óÏˆ,rÃèækÏeª£Óû¯ÆÂpêËSŸlî®=2ÑyÓô¨ì–JORÕtÚGPÕ@NIw—ÄMõ•pFÇ&AÁó39fßm“aµCzª$ÿÜ €÷ğ~*i–J„çc·É®ç ¤£µ•·,œó­À*+_&™É,_:úÎÌX·Èw<zkò_<Xi*.—ò9ŠîÇÎãÃE¢¯+ÔV™We‡@°¬K†ª‚3Å/Wú!r
ÙôÔRM…ïgĞ>Zà€ÔÚ|à–3úııhÇc¥aéù”0	ÿÏÎmC»ÔÅ%‰Å/ÑU¯÷=PµG¦TÄCrI²oø Éúxz‹ë°,ˆÍ$1İxÚ¬,¸3sGö~ÜFk²­¥İû&qÀâ-ûj°†ğd"ØĞ=·ı-úqCoİaèqæ¨:ËOOwŞ\
lñYÎïx‰Âàf©	RpHEØí£×´2ïœ(VÓÂ”ÄH.XÔÒğo“:R¤’ö,İ};Ú—.Azíå@õğm&ôVÀbïı^©ÇŞx-_˜ğóŸxşY‡t7¼zªïõ›÷°cŒşËU4‹¾ö(K>Qô7¾øÔ»)ºvç*ŠfğQFC?³7’5Ø‹;—˜Õ'óô£0]÷*“ñÖ„ÜY£óH I¼r»d“‡zÃçòKÑ‹7	 ´£cqç*’…Ï´¼ª–'‰¬Ÿ4Dõi?I¬L­KÔ§Š€&!‚×‚¿
}ií(ÒÕ‚»Èqx†ı#Qcáô•j.¶Í’hDæ¤6:+Sâ()`UÏi	â¯ÒvÉ£*8
?~¹GS˜¤(cøµ_0“™qæP›Ù;Õî_€ª9>@Ú^/”=#¨òUÔ¿«Óã4¶—àGnŠUêŞF’Hû;ü¸ítC/ŒDUÓÍŞ!ö:³lÎNÆDíìF!<Õ‡?Èê\2²¾e½R-’*“ª*šQ¸§Î"ÀYàh_’ãü5V¤;R÷³Ğû)f@7euï@å${yé
%æ†@yÄ…/‘K–ÂÏaÚˆÓéŞ€Ü³æûwí…M[Èy›ÜÓp|ç`¢ª4'Œø‹Ü17¶ÚÏÅ1§´:?‡ãúyÉ™½]åü¢tØÃ£ğÛLı¦Fiƒ†¼]‡ÑíM³t¬QæümĞcPrFë!ö8#ÄävÙ¢–²ËÒ­Q÷“^*½l4Ò V‚’Õÿ¬å#Òœ!Ö63û;ŒÓ[ì÷Ø§7)sMã¨ÒB›.‘	4Øƒ¬#xÎ‰ÖÌK/ÀÒBÇçôúM—‚ql~µŠ¢DĞ¯D’Ê)*WSár‰b(
Æ‹;ÎÁ\œ±­°âSzy’MK¹%EÒ’‰¨y|˜Ú€×Y­Æ%,0­¸Ô˜Í±Ä:bä¤ÈB\	 ,H|ëèOµñÌäEÒòªÎ²&t&ò¥úÄš´ÕßÚó›´ÔÜ+#ß§[E?%aë|=ëØT—4©A¥¸Wb·ÔúAh²¶.«J'Zàÿ·œK‹8VµÁub.÷w“"RfQg¬ÒrÉ5,Y»óqzW_<ıöü´.l#ñ@éú8"¥b¢¾Œ ñkã£Y§«î1×¿]X ZFsâ‚»hõ.Õ´úÈ5aâ—œêÆnÚ?^«(+yw¿|Sh,"ıƒ9Ê ö>+Gİx¢Ğæ<!çˆ±ú~ü1£üˆ„C†‡!dâ0WFEÔmX?…Ãœ4=Q1îb&ÚG‰G†™E˜%9Öd°ˆÜáyš8
5Û0¢à›^ßt"ş_+á|ö%ïñr³°ãFnëQ`&Xã³¯ÍšMóO×›¨E@LcÏ\Iòñ¤1³Æï¥$M»³†2s¶¼¥n‚ RÊ¡_9$|}Ú½4Æá÷¢b!ºFüF:ş¨ñµr‘‘`ztŠÎùTİ»ºY-êŠ}SS“ÃdËÃ®è¥6šâÁÎK–¼ûÂ…½ÚC`Ãÿm
+·–nÜ•(ğdİèÍ}ÀTJ(JdGRV¢khï<¿}9«×;ü×96RG`¡„÷ltÏ˜Š³A¦~“â_Ñ:Ö‡4V<9·V¨q({9ŒF1·I^òûŒ¾N«w…" 8¼&[nØµ÷b\¨Y ª€°p‰ÄóUà¾zå‹¤{ùyç‰&HFëº]H<¤1ÎñTO1™A”„í ”Up¨0¿Ošm‚-â