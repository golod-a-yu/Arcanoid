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
 * \param pixels this is filled in with a p                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ���:������ӟkxH�t���s�3���x
�蜮�A��CJ7��7��=��@��GY��j5�x�i��#����ψ���Mn	�A+�k
�G�]��0�A�B(�4�>�Ҡ)؅O������S~�"v�:�8(�9�ڹnz�9z]a칯﷚4y�k�DB�u�+ad�,�����%P\��c+����'?}��N�,�E��&�֒�~6{l/��"���3|̂X���ZF(�%0'ה xwwC��F� �i�dK�{A��j�e<�E>QO+�򥜼os0�_7b�&}��(`�%:q#p](x�'QC\W]��"�"'h>F�MI��Q�R�k�FE���)�lrXCÓe��?����mE[̜5xR��E�~��V�n[�{{�T0�\����b�O��h�-4��h/�/��Yw~�ɞ�������25��'?�⭜ɽ�)df�

l�}�T����Z��A�՜���Yd�W!
r����l�
(�@�����9*"�V|���u��p'���8�������6�X�|$�뙷�Rѹu���8sN���Ֆ�4�'�I���gy�X@R��Z��Ki�Dko�s���"Z���q����Wɤ'g�{J"���$���d<D��E��;I
�|y��k�b#%�:᝵Cg���f��'j�"0#���t�eM 8^�;�2�ȋu�<JF褨{(�`^o�H5-�g�$���� �4hh!A.u"�1K����^� gE�=w�|rP��Go��6 x�)��!���݂�
J�]?�JFȼkô��3����L��E��nq�'��P�;�Faz�1=^�ͽ�6�f�XX����k��Xt��H�/����׽EX�P��>�]�dT�o��R);}��Qi[R��B0Μ殄1a�f�Ѳ
�#s\'�$}�L��@�Y7F�f�	7[���x]���̯8���Va�����B5Q�<�A�
�f�m�!�z�dbULD�oALF#zf��5;l�@���N =�^��Ҩd�yr)Iu��o��Ǔ�E�|���� o&�ʷ��q<�1���c���+����5��	�R�w�L�YWD��u_�����S�rŝ�mĐ�X"5��s��%;k6L�����L�x���i��/de��d(���O��za��J9B.�����Ⱥ2
�Ĝ
��p���O���� km���>��{��s��aKDa�@l�"tSm:������Mi���Y;�p�PK"��H�Te#�0��N9l|�	L���A謹ʺ�����L�fR���?�
T�o�j
� �[2����.��B�����B��Ws�����9��JK��=�u~:{��G���?��m��`6חF?1�C9�h�,ل�k�����3~/�o:�M2
�E��t�0�1(���t��IQa]ߓ'C�^�l�����"\����M��~�f\	v�ŉ���C.�6-A�x�W�ޅ�f�O��;�t�نYm���w�{�����EB̓�*����j�)� �.�ë�~?���;o���/���,�Ba���B@�w�嚞T�E��ujM+�t��Ɠ�F���j�͖=Κ�w���W�+elg���S8@{-�(�Yl�ǲ�.��5G2!�v�z�
�B����%�W��>���5�'�l➖��!�8Q0q�[�)ffʋ��x)����弗�[:^��%{���+�,��z/?��5 H|% �wf>��.sj��'�9�3K�1��P���ƾS�2� 
�(���Y��[�	H����n�Ի�Ϧ�I$_ APmn'�?�o\6 �f� �����Z���b��4-B^j�(������;}v�$Eä�Ί߿T�n����)��j�%t�'���m�	76<�RЅ��jϙ\j;
Q2�fJ�<��R��q��L�}��Z����|;&�$�҉���gx�S)U'��� 1$���[ ��՗�7��u4�Je��OH�3Դ~&K�~>@%�\\h����w�)%䈥�l[�gdCU�qy�B%h�Z��S�A5����"I&��GEs��u�aڥ�����"+��q+\�������С�M��~��HY.&�ɪ�h����J�̠5��G�u`
Z^�ԣѣ&]�d"�,��*?����,�~����m$%k�o�����V/�gb�����h�O�%7�?����t�>{3;Y7�G����n��%�d��ۻ�Ŷ�A��n'��?I��iy���8��Nh2��y�Ӵb^�ە*�]�|��$mІC˺	���`RW)���
��{��U/1�0�z�v��5LGg*�Ψ֜�L%+�$���ня
R*��Gta2��X%*o��}o��{�3�,��2�:A��Z��N#i]�"��b���~�o�]�;:aƇF�4��Yc��`����'l��%Ml}Bm��x��G�Jy����~��>7�IJ0�D
S1O7���t��o����)qÄ��Go��Sѯ�5 BY̧s���T� &�z�\��q��*�:�u�Kk��?�q<�R�8Ǎe�
!Z���x5�3E"�"�8,
�ed�v�cU+W�Tde���u�Q<]�?	��b�&����Fg}ɒ�zV�K]�&GrvĈ����*�� �l*%>��ś\���bF�f��
6��v#@�
j���K�'��'K~Ei���3���p?q=Xnme{/h��0%�6��L>'�nc�A 6��w����9�_�8��CN���>/�SV�g�Y��ؖېR*�
"���Z<0��{ܹ�j{���Dm5Z��>;�m�&�TU��Z�ΐs��2ϼ�"�sO%�G�L�^L:&x$rA�z�I���	��_2���gBYs��юAv���(8��%x�]D� `v���B%b ������� ��u�]CE�v��׾�0�Y���91��#/Lpy3�����z�2J;�gT��.n��� l��e}�.�߅�f46_�.C�5v����*�	T"\�A+��
�D����EZ� ��)����keG!���5������Ot�����R�>�l������|h�'��c$;Cm��" �0n\ypI8ىC�`wL3I�=��&�v�F~���)s?��髋�F� �����jOC,�0db�y�jy���k.{��Mqy� Y��#�x6r-V�`�۱����?2Ԕ�X_0�p��앢!!?�����`�+�G�^�#�M~�x�T�o��m1F�2�$2�����S!M��a 2k�4#��à��>t2�<`5ԩ�l�S�]���a�>�_��h&�D�8v~{�
��ZA9�Y]����u�f9
O�P�ʼ*U >�����~���o]��Q,rif��e��Ƣ����ҷ�~B�!9Z.��Ev���.�7��e⧐Q�z��I��I���hI� ��63��� ՃjsY8��P�	�=�7wj��٨y@B�.�<H��8����]M��bR
S Q
���L�T]�uY�X�g�ڵ\Z�:�I�5�~bq)� �8��7�Q��k�k�zk�g��vM����1'K!P��c_��%��!�'��)�͜F[@�.��B��Ռ�2 ��|m��'�E�(/��/?��hL���D0���x��1'��c���9<B��y��+TM910�Q��c'l��
=nl��DA� %�����|��>V���dZ��hcA$�����8��-a$�I��w�_3�ٱ���A�D����qX/�y�T:��$:�ҡCZ�rN�5�b$43{�{�	+���R	��^"2�ͯs{����B����%�[��	�5��`�24A/��0��R_[ǁ��˱�����vC�A�dcZ��Ē��xb�^�s3����M�x&:�R��}D��
^ol|o�#E�;G;���Ґ�w:$�vQR��=�J Y7�sd��-�CiN�/n
���0T\a��'�A65��R���.���}@�����IM��0���pG�,ڼ����
h:t���i��B�4E�(��%�UO �������k���n�$NƲ0�k!�V{�/�da��-g��Z���Ďn����1&��j4k��F�g�8P�R¬ �8���N00�&���@Jk��i8:"��:���!�]�K��*j��4��ɡp�(%+�FN�2lf#�ӕ�J��D��� ЇG�����2V��AC~+���du��`�ր����O}Y�m��E�w��\��� :m}:"�р�C�<�D���#�W񉛗8�2�7�*���<5s,u	��R��P$Q�;�X
�?��;W���R���,lZ���_��L�v��i�P�=qc,��7l�	,�

w�w� K�G:���$�q2R/�K�<�w�LY\�Ѯ�a��J&1����P?�w�����y�]�/1��}Q7��#	�����ZI�*:\���|"�X2�p�T�1k3B��Z�bb ���\�u�#�6
1UOCQ5�����A����a>9'+jf�P��~R���F�,Kv��m�P���� �4�*y�k�!���Z��2VH�_7*�����
�â�X�nb
;5�k=��%}���S�
m�o
B��H��IL�C���n�zA�7.�\C�P��X�X��ou�F�GoR1���9D$Ѩ>7�:cb�S�1�^�B)6�A�I��V�"��'�v�[sFbe��F���B
�D� <t�,+ ��&g����T��~� R�%QC�ȑѷ�jT�_ QJO����M��0�S*9)~4)�1y�-ǟrEC�<y�m5p�b�[�A��H)
�q_�.C����TFiw1~2�k�N�h>ǖ恂+�"|y1"���Q��6,�,��.���(�T�H��^5��SU�}`�
����%����aL?�v�W$��sj�5�j���c�>��\W���T��@;dD&��𱲶B@(Ҷ��!`�ql@}st:;����<*��:kX�:0�� 3�
���X��XJж1��y�b��Wγ=~�t���U^3�V�ǆ�Ҝq3�a�Qψ�54[��J@G����6���w�f?lx���7��'. Z� �'���Q�s۵*-�~8�@���"��{�u�;1��4'�0ڑ+���A�A, !�_��2_il�
VG_�`����6�a�a�Х�40�J��ڋ㕬�`�XS�Ԣs�P���
"d�3���1���{/7�z��9���M/���k_��[��'#`?>�D�� 2Tq�U(�6�)y�\+�Z
�F~d�"��	�;w�I�'Z'D�L�}:9{�k`�/5FJn8������X���C��"m©
��(�Ί\zrv�fY|���t�!-��Z�K�O[��m�\�m�&D��aˎXBEy�'��&�f`1tl��2���� , �/U�ܺ ���&�s� �a�mT����;z����!v;F3ˣ�b��
���;���W�<���*K;i}����G��U����pB��b5<;��|�	�V���/,���[p�� ��������=���+�X�f1�u:8m��K,:~�J��
�����륬i���P�C��b$!מ���I=t�/. >އ���/��N9����R�*�w�����Jb�^6��;�H�T��(f*���TX�.�d4.ʙ���0숼��i׻�F�(ѧ:@�g��5�bP�=n*|�fa@8�1��	����|mz��DG��>�y�%�k��iJ�U��[+�-�^�Vw��; ~�,挙��(�DDE{��v�y]q�K��7P��W�6� 5�䡹��ťAX<QpCq.+r6�BXƻʙ0�8H�KQ
4��G��Q�{��ȭQ%ݮ�<�� ��8�2�2`SECPX��� �O!�ψ,r���k�e�������p�ˁS�l�=2�y����JOR�t�GP�@NIw��M
���RM��g�>Z����|��3���h�c�a���0	�ϝ�mC����%��/�U��=P�G�T�CrI�o� ���xz��,��$1�xڬ,�3sG�~�Fk�����&q��-�j���d"��=��-�qCo�a�q���:�OOw�\
l��Y���x���f�	RpHE؞����2�(V��H.X���o�:R���,�};ڗ.�Az��@��m&�V�b��^���x-_���x�Y�t7�z������c���U4����(K>Q�7��Ի)�v�*�f�QFC?�7�5؋;���'���0]�*��ք�Y����H�I�r�d���z���K�ы7	���cq�*��ϴ���'���4D�i?I�L�Kԧ��&!�ׂ�
}i�(�Ղ��qx��#Qc���j.����hD�6:�+S�()`U�i	��vɁ�*�8
?~�GS��(c��_0��q�P��;��_��9>@�^/�=#��U������4���Gn�U��F�H�;���tC/�DU���!�:�l�N�D��F!<Շ?��\2��e�R-��*��*�Q���"�Y�h_���5V��;R����)f@7eu�@�${y�
%�@yą/�K���aڈ��ހܳ��w�M�[�y���p|�`��4'����17����1��:?���yə�]���t�ã��L��Fi���]���M�t�Q��m�cPrF�!�8#��v�����ҭQ��^*�l4� V������#Ҝ!�63�;��[��ا7)sM��B�.�	4���#xΉ��K/��B����M��ql~���DЯD��)*WS�r�b(
Ƌ;��\�����Szy�MK�
5�0���^�t"�_+�|�%��r���Fn�Q`&X㳯͚M�Oכ�E@Lc�\I��1���$M���2s���n� Rʡ_9$|}ڽ4�����b!��F�F:���r��`zt���Tݻ�Y-�}SS��d�î�6����K�����C`��m
+��nܕ(�d���}�TJ(JdGRV�kh�<�}9��;��96RG`���ltϘ��A�~��_�:և4V<9�V�q(�{9�F1�I^����N�w�" 