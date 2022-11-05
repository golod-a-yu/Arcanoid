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
 *  \file SDL_hints.h
 *
 *  Official documentation for SDL configuration variables
 *
 *  This file contains functions to set and get configuration hints,
 *  as well as listing each of them alphabetically.
 *
 *  The convention for naming hints is SDL_HINT_X, where "SDL_X" is
 *  the environment variable that can be used to override the default.
 *
 *  In general these hints are just that - they may or may not be
 *  supported or applicable on any given platform, but they provide
 *  a way for an application or user to give the library a hint as
 *  to how they would like the library to work.
 */

#ifndef SDL_hints_h_
#define SDL_hints_h_

#include "SDL_stdinc.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \brief  A variable controlling whether the Android / iOS built-in
 *  accelerometer should be listed as a joystick device.
 *
 *  This variable can be set to the following values:
 *    "0"       - The accelerometer is not listed as a joystick
 *    "1"       - The accelerometer is available as a 3 axis joystick (the default).
 */
#define SDL_HINT_ACCELEROMETER_AS_JOYSTICK "SDL_ACCELEROMETER_AS_JOYSTICK"

/**
 *  \brief Specify the behavior of Alt+Tab while the keyboard is grabbed.
 *
 * By default, SDL emulates Alt+Tab functionality while the keyboard is grabbed
 * and your window is full-screen. This prevents the user from getting stuck in
 * your application if you've enabled keyboard grab.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL will not handle Alt+Tab. Your application is responsible
                 for handling Alt+Tab while the keyboard is grabbed.
 *   "1"       - SDL will minimize your window when Alt+Tab is pressed (default)
*/
#define SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED "SDL_ALLOW_ALT_TAB_WHILE_GRABBED"

/**
 *  \brief If set to "0" then never set the top most bit on a SDL Window, even if the video mode expects it.
 *      This is a debugging aid for developers and not expected to be used by end users. The default is "1"
 *
 *  This variable can be set to the following values:
 *    "0"       - don't allow topmost
 *    "1"       - allow topmost
 */
#define SDL_HINT_ALLOW_TOPMOST "SDL_ALLOW_TOPMOST"

/**
 * \brief Android APK expansion main file version. Should be a string number like "1", "2" etc.
 *
 * Must be set together with SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION.
 *
 * If both hints were set then SDL_RWFromFile() will look into expansion files
 * after a given relative path was not found in the internal storage and assets.
 *
 * By default this hint is not set and the APK expansion files are not searched.
 */
#define SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION"
 
/**
 * \brief Android APK expansion patch file version. Should be a string number like "1", "2" etc.
 *
 * Must be set together with SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION.
 *
 * If both hints were set then SDL_RWFromFile() will look into expansion files
 * after a given relative path was not found in the internal storage and assets.
 *
 * By default this hint is not set and the APK expansion files are not searched.
 */
#define SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION "SDL_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION"

/**
 * \brief A variable to control whether the event loop will block itself when the app is paused.
 *
 * The variable can be set to the following values:
 *   "0"       - Non blocking.
 *   "1"       - Blocking. (default)
 *
 * The value should be set before SDL is initialized.
 */
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE "SDL_ANDROID_BLOCK_ON_PAUSE"

/**
 * \brief A variable to control whether SDL will pause audio in background
 *        (Requires SDL_ANDROID_BLOCK_ON_PAUSE as "Non blocking")
 *
 * The variable can be set to the following values:
 *   "0"       - Non paused.
 *   "1"       - Paused. (default)
 *
 * The value should be set before SDL is initialized.
 */
#define SDL_HINT_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO "SDL_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO"

/**
 * \brief A variable to control whether we trap the Android back button to handle it manually.
 *        This is necessary for the right mouse button to work on some Android devices, or
 *        to be able to trap the back button for use in your code reliably.  If set to true,
 *        the back button will show up as an SDL_KEYDOWN / SDL_KEYUP pair with a keycode of 
 *        SDL_SCANCODE_AC_BACK.
 *
 * The variable can be set to the following values:
 *   "0"       - Back button will be handled as usual for system. (default)
 *   "1"       - Back button will be trapped, allowing you to handle the key press
 *               manually.  (This will also let right mouse click work on systems 
 *               where the right mouse button functions as back.)
 *
 * The value of this hint is used at runtime, so it can be changed at any time.
 */
#define SDL_HINT_ANDROID_TRAP_BACK_BUTTON "SDL_ANDROID_TRAP_BACK_BUTTON"

/**
 *  \brief Specify an application name.
 * 
 * This hint lets you specify the application name sent to the OS when
 * required. For example, this will often appear in volume control applets for
 * audio streams, and in lists of applications which are inhibiting the
 * screensaver.  You should use a string that describes your program ("My Game
 * 2: The Revenge")
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: probably the application's name or "SDL Application" if SDL
 * doesn't have any better information.
 *
 * Note that, for audio streams, this can be overridden with
 * SDL_HINT_AUDIO_DEVICE_APP_NAME.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_APP_NAME "SDL_APP_NAME"

/**
 *  \brief  A variable controlling whether controllers used with the Apple TV
 *  generate UI events.
 *
 * When UI events are generated by controller input, the app will be
 * backgrounded when the Apple TV remote's menu button is pressed, and when the
 * pause or B buttons on gamepads are pressed.
 *
 * More information about properly making use of controllers for the Apple TV
 * can be found here:
 * https://developer.apple.com/tvos/human-interface-guidelines/remote-and-controllers/
 *
 *  This variable can be set to the following values:
 *    "0"       - Controller input does not generate UI events (the default).
 *    "1"       - Controller input generates UI events.
 */
#define SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS "SDL_APPLE_TV_CONTROLLER_UI_EVENTS"

/**
 * \brief  A variable controlling whether the Apple TV remote's joystick axes
 *         will automatically match the rotation of the remote.
 *
 *  This variable can be set to the following values:
 *    "0"       - Remote orientation does not affect joystick axes (the default).
 *    "1"       - Joystick axes are based on the orientation of the remote.
 */
#define SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION "SDL_APPLE_TV_REMOTE_ALLOW_ROTATION"

/**
 *  \brief  A variable controlling the audio category on iOS and Mac OS X
 *
 *  This variable can be set to the following values:
 *
 *    "ambient"     - Use the AVAudioSessionCategoryAmbient audio category, will be muted by the phone mute switch (default)
 *    "playback"    - Use the AVAudioSessionCategoryPlayback category
 *
 *  For more information, see Apple's documentation:
 *  https://developer.apple.com/library/content/documentation/Audio/Conceptual/AudioSessionProgrammingGuide/AudioSessionCategoriesandModes/AudioSessionCategoriesandModes.html
 */
#define SDL_HINT_AUDIO_CATEGORY   "SDL_AUDIO_CATEGORY"

/**
 *  \brief Specify an application name for an audio device.
 *
 * Some audio backends (such as PulseAudio) allow you to describe your audio
 * stream. Among other things, this description might show up in a system
 * control panel that lets the user adjust the volume on specific audio
 * streams instead of using one giant master volume slider.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your program ("My Game 2: The Revenge")
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: this will be the name set with SDL_HINT_APP_NAME, if that hint is
 * set. Otherwise, it'll probably the application's name or "SDL Application"
 * if SDL doesn't have any better information.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_APP_NAME "SDL_AUDIO_DEVICE_APP_NAME"

/**
 *  \brief Specify an application name for an audio device.
 *
 * Some audio backends (such as PulseAudio) allow you to describe your audio
 * stream. Among other things, this description might show up in a system
 * control panel that lets the user adjust the volume on specific audio
 * streams instead of using one giant master volume slider.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your what your program is playing ("audio stream" is
 * probably sufficient in many cases, but this could be useful for something
 * like "team chat" if you have a headset playing VoIP audio separately).
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: "audio stream" or something similar.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_STREAM_NAME "SDL_AUDIO_DEVICE_STREAM_NAME"

/**
 *  \brief Specify an application role for an audio device.
 *
 * Some audio backends (such as Pipewire) allow you to describe the role of
 * your audio stream. Among other things, this description might show up in
 * a system control panel or software for displaying and manipulating media
 * playback/capture graphs.
 *
 * This hints lets you transmit that information to the OS. The contents of
 * this hint are used while opening an audio device. You should use a string
 * that describes your what your program is playing (Game, Music, Movie,
 * etc...).
 *
 * Setting this to "" or leaving it unset will have SDL use a reasonable
 * default: "Game" or something similar.
 *
 * On targets where this is not supported, this hint does nothing.
 */
#define SDL_HINT_AUDIO_DEVICE_STREAM_ROLE "SDL_AUDIO_DEVICE_STREAM_ROLE"

/**
 *  \brief  A variable controlling speed/quality tradeoff of audio resampling.
 *
 *  If available, SDL can use libsamplerate ( http://www.mega-nerd.com/SRC/ )
 *  to handle audio resampling. There are different resampling modes available
 *  that produce different levels of quality, using more CPU.
 *
 *  If this hint isn't specified to a valid setting, or libsamplerate isn't
 *  available, SDL will use the default, internal resampling algorithm.
 *
 *  Note that this is currently only applicable to resampling audio that is
 *  being written to a device for playback or audio being read from a device
 *  for capture. SDL_AudioCVT always uses the default resampler (although this
 *  might change for SDL 2.1).
 *
 *  This hint is currently only checked at audio subsystem initialization.
 *
 *  This variable can be set to the following values:
 *
 *    "0" or "default" - Use SDL's internal resampling (Default when not set - low quality, fast)
 *    "1" or "fast"    - Use fast, slightly higher quality resampling, if available
 *    "2" or "medium"  - Use medium quality resampling, if available
 *    "3" or "best"    - Use high quality resampling, if available
 */
#define SDL_HINT_AUDIO_RESAMPLING_MODE   "SDL_AUDIO_RESAMPLING_MODE"

/**
 *  \brief  A variable controlling whether SDL updates joystick state when getting input events
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - You'll call SDL_JoystickUpdate() manually
 *    "1"     - SDL will automatically call SDL_JoystickUpdate() (default)
 *
 *  This hint can be toggled on and off at runtime.
 */
#define SDL_HINT_AUTO_UPDATE_JOYSTICKS  "SDL_AUTO_UPDATE_JOYSTICKS"

/**
 *  \brief  A variable controlling whether SDL updates sensor state when getting input events
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - You'll call SDL_SensorUpdate() manually
 *    "1"     - SDL will automatically call SDL_SensorUpdate() (default)
 *
 *  This hint can be toggled on and off at runtime.
 */
#define SDL_HINT_AUTO_UPDATE_SENSORS    "SDL_AUTO_UPDATE_SENSORS"

/**
 *  \brief Prevent SDL from using version 4 of the bitmap header when saving BMPs.
 *
 * The bitmap header version 4 is required for proper alpha channel support and
 * SDL will use it when required. Should this not be desired, this hint can
 * force the use of the 40 byte header version which is supported everywhere.
 *
 * The variable can be set to the following values:
 *   "0"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file with an alpha mask. SDL will use the bitmap
 *               header version 4 and set the alpha mask accordingly.
 *   "1"       - Surfaces with a colorkey or an alpha channel are saved to a
 *               32-bit BMP file without an alpha mask. The alpha channel data
 *               will be in the file, but applications are going to ignore it.
 *
 * The default value is "0".
 */
#define SDL_HINT_BMP_SAVE_LEGACY_FORMAT "SDL_BMP_SAVE_LEGACY_FORMAT"

/**
 *  \brief Override for SDL_GetDisplayUsableBounds()
 *
 *  If set, this hint will override the expected results for
 *  SDL_GetDisplayUsableBounds() for display index 0. Generally you don't want
 *  to do this, but this allows an embedded system to request that some of the
 *  screen be reserved for other uses when paired with a well-behaved
 *  application.
 *
 *  The contents of this hint must be 4 comma-separated integers, the first
 *  is the bounds x, then y, width and height, in that order.
 */
#define SDL_HINT_DISPLAY_USABLE_BOUNDS "SDL_DISPLAY_USABLE_BOUNDS"

/**
 *  \brief Disable giving back control to the browser automatically
 *  when running with asyncify
 *
 * With -s ASYNCIFY, SDL2 calls emscripten_sleep during operations
 * such as refreshing the screen or polling events.
 *
 * This hint only applies to the emscripten platform
 *
 * The variable can be set to the following values:
 *    "0"       - Disable emscripten_sleep calls (if you give back browser control manually or use asyncify for other purposes)
 *    "1"       - Enable emscripten_sleep calls (the default)
 */
#define SDL_HINT_EMSCRIPTEN_ASYNCIFY   "SDL_EMSCRIPTEN_ASYNCIFY"

/**
 *  \brief override the binding element for keyboard inputs for Emscripten builds
 *
 * This hint only applies to the emscripten platform
 *
 * The variable can be one of
 *    "#window"      - The javascript window object (this is the default)
 *    "#document"    - The javascript document object
 *    "#screen"      - the javascript window.screen object
 *    "#canvas"      - the WebGL canvas element
 *    any other string without a leading # sign applies to the element on the page with that ID.
 */
#define SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT   "SDL_EMSCRIPTEN_KEYBOARD_ELEMENT"

/**
 *  \brief  A variable that controls whether Steam Controllers should be exposed using the SDL joystick and game controller APIs
 *
 *  The variable can be set to the following values:
 *    "0"       - Do not scan for Steam Controllers
 *    "1"       - Scan for Steam Controllers (the default)
 *
 *  The default value is "1".  This hint must be set before initializing the joystick subsystem.
 */
#define SDL_HINT_ENABLE_STEAM_CONTROLLERS "SDL_ENABLE_STEAM_CONTROLLERS"

/**
 *  \brief  A variable controlling whether SDL logs all events pushed onto its internal queue.
 *
 *  This variable can be set to the following values:
 *
 *    "0"     - Don't log any events (default)
 *    "1"     - Log all events except mouse and finger motion, which are pretty spammy.
 *    "2"     - Log all events.
 *
 *  This is generally meant to be used to debug SDL itself, but can be useful
 *  for application developers that need better visibility into what is going
 *  on in the event queue. Logged events are sent through SDL_Log(), which
 *  means by default they appear on stdout on most platforms or maybe
 *  OutputDebugString() on Windows, and can be funneled by the app with
 *  SDL_LogSetOutputFunction(), etc.
 *
 *  This hint can be toggled on and off at runtime, if you only need to log
 *  events for a small subset of program execution.
 */
#define SDL_HINT_EVENT_LOGGING   "SDL_EVENT_LOGGING"

/**
 *  \brief  A variable controlling how 3D acceleration is used to accelerate the SDL screen surface.
 *
 *  SDL can try to accelerate the SDL screen surface by using streaming
 *  textures with a 3D rendering engine.  This variable controls whether and
 *  how this is done.
 *
 *  This variable can be set to the following values:
 *    "0"       - Disable 3D acceleration
 *    "1"       - Enable 3D acceleration, using the default renderer.
 *    "X"       - Enable 3D acceleration, using X where X is one of the valid rendering drivers.  (e.g. "direct3d", "opengl", etc.)
 *
 *  By default SDL tries to make a best guess for each platform whether
 *  to use acceleration or not.
 */
#define SDL_HINT_FRAMEBUFFER_ACCELERATION   "SDL_FRAMEBUFFER_ACCELERATION"

/**
 *  \brief  A variable that lets you manually hint extra gamecontroller db entries.
 *
 *  The variable should be newline delimited rows of gamecontroller config data, see SDL_gamecontroller.h
 *
 *  This hint must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 *  You can update mappings after the system is initialized with SDL_GameControllerMappingForGUID() and SDL_GameControllerAddMapping()
 */
#define SDL_HINT_GAMECONTROLLERCONFIG "SDL_GAMECONTROLLERCONFIG"

/**
 *  \brief  A variable that lets you provide a file with extra gamecontroller db entries.
 *
 *  The file should contain lines of gamecontroller config data, see SDL_gamecontroller.h
 *
 *  This hint must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 *  You can update mappings after the system is initialized with SDL_GameControllerMappingForGUID() and SDL_GameControllerAddMapping()
 */
#define SDL_HINT_GAMECONTROLLERCONFIG_FILE "SDL_GAMECONTROLLERCONFIG_FILE"

/**
 *  \brief  A variable that overrides the automatic controller type detection
 *
 *  The variable should be comma separated entries, in the form: VID/PID=type
 *
 *  The VID and PID should be hexadecimal with exactly 4 digits, e.g. 0x00fd
 *
 *  The type should be one of:
 *      Xbox360
 *      XboxOne
 *      PS3
 *      PS4
 *      PS5
 *      SwitchPro
 *
 *  This hint affects what driver is used, and must be set before calling SDL_Init(SDL_INIT_GAMECONTROLLER)
 */
#define SDL_HINT_GAMECONTROLLERTYPE "SDL_GAMECONTROLLERTYPE"

/**
 *  \brief  A variable containing a list of devices to skip when scanning for game controllers.
 *
 *  The format of the string is a comma separated list of USB VID/PID pairs
 *  in hexadecimal form, e.g.
 *
 *      0xAAAA/0xBBBB,0xCCCC/0xDDDD
 *
 *  The variable can also take the form of @file, in which case the named
 *  file will be loaded and interpreted as the value of the variable.
 */
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES "SDL_GAMECONTROLLER_IGNORE_DEVICES"

/**
 *  \brief  If set, all devices will be skipped when scanning for game controllers except for the ones listed in this variable.
 *
 *  The format of the string is a comma separated list of USB VID/PID pairs
 *  in hexadecimal form, e.g.
 *
 *      0xAAAA/0xBBBB,0xCCCC/0xDDDD
 *
 *  The variable can also take the form of @file, in which case the named
 *  file will be loaded and interpreted as the value of the variable.
 */
#define SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT "SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"

/**
 *  \brief  If set, game controller face buttons report their values according to their labels instead of their positional layout.
 * 
 *  For example, on Nintendo Switch controllers, normally you'd get:
 *
 *      (Y)
 *  (X)     (B)
 *      (A)
 *
 *  but if this hint is set, you'll get:
 *
 *      (X)
 *  (Y)     (A)
 *      (B)
 *
 *  The variable can be set to the following values:
 *    "0"       - Report the face buttons by position, as though they were on an Xbox controller.
 *    "1"       - Report the face buttons by label instead of position
 *
 *  The default value is "1".  This hint may be set at any time.
 */
#define SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS "SDL_GAMECONTROLLER_USE_BUTTON_LABELS"

/**
 *  \brief  A variable controlling whether grabbing input grabs the keyboard
 *
 *  This variable can be set to the following values:
 *    "0"       - Grab will affect only the mouse
 *    "1"       - Grab will affect mouse and keyboard
 *
 *  By default SDL will not grab the keyboard so system shortcuts still work.
 */
#define SDL_HINT_GRAB_KEYBOARD              "SDL_GRAB_KEYBOARD"

/**
 *  \brief  A variable controlling whether the idle timer is disabled on iOS.
 *
 *  When an iOS app does not receive touches for some time, the screen is
 *  dimmed automatically. For games where the accelerometer is the only input
 *  this is problematic. This functionality can be disabled by setting this
 *  hint.
 *
 *  As of SDL 2.0.4, SDL_EnableScreenSaver() and SDL_DisableScreenSaver()
 *  accomplish the same thing on iOS. They should be preferred over this hint.
 *
 *  This variable can be set to the following values:
 *    "0"       - Enable idle timer
 *    "1"       - Disable idle timer
 */
#define SDL_HINT_IDLE_TIMER_DISABLED "SDL_IOS_IDLE_TIMER_DISABLED"

/**
 * \brief A variable to control whether certain IMEs should handle text editing internally instead of sending SDL_TEXTEDITING events.
 *
 * The variable can be set to the following values:
 *   "0"       - SDL_TEXTEDITING events are sent, and it is the application's
 *               responsibility to render the text from these events and 
 *               differentiate it somehow from committed text. (default)
 *   "1"       - If supported by the IME then SDL_TEXTEDITING events are not sent, 
 *               and text that is being composed will be rendered in its own UI.
 */
#define SDL_HINT_IME_INTERNAL_EDITING "SDL_IME_INTERNAL_EDITING"

/**
 * \brief A variable to control whether certain IMEs should show native UI components (such as the Candidate List) instead of suppressing them.
 *
 * The variable can be set to the following values:
 *   "0"       - Native UI components are not display. (default)
 *   "1"       - Native UI components are displayed.
 */
#define SDL_HINT_IME_SHOW_UI "SDL_IME_SHOW_UI"

/**
 * \brief  A variable controlling whether the home indicator bar on iPhone X
 *         should be hidden.
 *
 *  This variable can be set to the following values:
 *    "0"       - The indicator bar is not hidden (default for windowed applications)
 *    "1"       - The indicator bar is hidden and is shown when the screen is touched (useful for movie playback applications)
 *    "2"       - The indicator bar is dim and the first swipe makes it visible and the second swipe performs the "home" action (default for fullscreen applications)
 */
#define SDL_HINT_IOS_HIDE_HOME_INDICATOR "SDL_IOS_HIDE_HOME_INDICATOR"

/**
 *  \brief  A variable that lets you enable joystick (and gamecontroller) events even when your app is in the background.
 *
 *  The variable can be set to the following values:
 *    "0"       - DisINDX( 	                 @   ∏  Ë      Z t   a   r ÿÿ                                "˝     h V     !¸     ê•?lÿ ∑•?lÿ¿ràéÎlÿ ∑•?lÿ        §              
 S D L _ m a i n . h e ˝     x b     !¸     e	?lÿe	?lÿÔ~éÎlÿe	?lÿ        %               S D L _ m e s s a g e b o x . h V     C˝     h X     !¸     ˛2?lÿ˛2?lÿH¥≥éÎlÿ˛2?lÿ @      „?               S D L _ m o u s e . h >˝     h X     !¸     D•?lÿD•?lÿíÆéÎlÿD•?lÿ @      Œ7               S D L _ m u Z e x . h X¸     p `     !¸     üy≥ÿ>lÿüy≥ÿ>lÿÙ~oãÎlÿüy≥ÿ>lÿ       F               S D L _ o p e n g l e s 2 . h ^˝     Ä n     !¸     jF8%?lÿ¨ª8%?lÿã∑:%?lÿ¨ª8%?lÿ ê     áÅ              S D L _ o p e n g l e s 2 _ g l 2 e x t . h   /˝     à x     !¸     ÆB?lÿÆB?lÿ◊B§éÎlÿÆB?lÿ 0      &'               S D L _ o p e n g l e s 2 _ k h r p l a t f o r m . h F˝     p Z     !¸     ÊYê?lÿÊYê?lÿX–éÎlÿÊYê?lÿ `       _               S D L _ p i x e l s . h       ˝     p ^   Z !¸     QPG?lÿQPG?lÿçDâãÎlÿQPG?lÿ        æ               S D L _ p l a t f o r m . h   !˝     h V     !¸     7üõ?lÿI∆õ?lÿàøÖéÎlÿI∆õ?lÿ        ã              
 S D L _ r e c t . h   :¸     p ^     !¸     '“>lÿ9+'“>lÿπªnãÎlÿ9+'“>lÿà       Ñ                S D L _ r e v i s i o n . h   J˝     h X     !¸     †)s?lÿ†)s?lÿ‚Ö‡éÎlÿ†)s?lÿ p      „n               S D L _ r w o p s . h ?˝     p ^     !¸     9}?lÿ9}?lÿ¢T≤éÎlÿ9}?lÿ @      ñ;               S D L _ s c Z n c o d e . h   -˝     p Z     !¸     5LÍ?lÿ5LÍ?lÿ∫;ùéÎlÿ5LÍ?lÿ 0      ˆ#               S D L _ s e n s o r . h       ˝     h X     !¸     Çz'?lÿè°'?lÿìúÉãÎlÿè°'?lÿ                       S D L _ s h a p e . h I˝     p Z     !¸     ë‡N?lÿP?lÿ––éÎlÿP?lÿ p      ‰c               S D L _ s t d i n c . h       3˝     h X     !¸     EÜÄ?lÿY≠Ä?lÿ˛®éÎlÿY≠Ä?lÿ 0      A,               S D L _ s y s w m . h ˝     x d     !¸     È	?lÿ-	?lÿ“ÇéÎlÿ-	?lÿ      Z µ               S D L _ t e s t _ c o m m o n . h h  £¸     x b     !¸     ÓeHı>lÿÓeHı>lÿòrãÎlÿÓeHı>lÿ       9               S D L _ t e s t _ c r c 3 2 . h      7˝     x d     !¸     y´?lÿy´?lÿ∫‰¨éÎlÿy´?lÿ @      ì3               S D L _ t e s t _ f u z z e r . h h  Z¸     x d     !¸     ⁄óÒ€>lÿ⁄óÒ€>lÿ«qãÎlÿ⁄óÒ€>lÿ       ˚               S D L _ t e s t _ m e m o r y . h    K˝     p Z     !¸     Bbt?lÿBbt?lÿ¬f∂éÎlÿBbt?lÿ P      @C               S D L _ t h Z e a d . h      H˝     h X     !¸     q6b?lÿq6b?lÿ«tÜéÎlÿq6b?lÿ        z               S D L _ t i m e r . h  ˝     p \     !¸     ŸHÖ?lÿŸHÖ?lÿ´xéÎlÿŸHÖ?lÿ                       S D L _ v e r s i o n . h     ]˝     h X     !¸     ◊◊–$?lÿj9÷$?lÿø
>ïÎlÿj9÷$?lÿ 0      -              S D L _ v i d e o . h *˝     p Z     !¸     UŸ?lÿUŸ?lÿI£öéÎlÿUŸ?lÿ 0      \!               S D L _ v u l k a n . h                                   UŸ?lÿUŸ?lÿ™f⁄?lÿUŸ?lZ  0      \!               S D L _ v u l k a n . h                     UŸ?lÿUŸ?lÿ™f⁄?lÿUŸ?lÿ 0      \!               S D L _ v u l k a n . h                     UŸ?lÿUŸ?lÿ™f⁄?lÿUŸ?lÿ 0      \!               S D L _ v u l k a n . h                     UŸ?lÿUŸ?lÿ™f⁄?lÿUŸ?lÿ 0      \!               S D L _ v u l k a n . h                     !¸     UŸ?lÿUŸ?lÿ™f⁄?lÿUŸ?lÿ 0      \!               S D L _ v u l k a n . h                     zÜÓÙ>lÿéÆÓÙ>lZ ∞ÖÔÙ>lÿéÆÓÙ>lÿ       £               S D L _ t e s t _ a s s e r t . h h  ˝     x d     !¸     È	?lÿ-	?lÿZ:?lÿ-	?lÿ        µ               S D L _ t e s t _ c o m m o n . h h  e¸     x f     !¸     òL*„>lÿòL*„>lÿÂõ3„>lÿòL*„>lÿ       s               S D L _ t e s t _ c o m p a r e . h  £¸     x b     !¸     ÓeHı>lÿÓeHı>lÿŒ?Iı>lÿÓeHı>lÿ       9               S D L _ t e s t _ c r c 3 2 . h                                                                          Z INDX( 	                @   –  Ë       . ÿÿ                                       ˝     p Z     !¸     —	?lÿ—	?lÿB≤xãÎlÿ—	?lÿ        K               b e g i n _ c o d e . h       #˝     ` L     !¸     ˛”Æ?lÿ˛”Æ?lÿ£rïéÎlÿ˛”Æ?lÿ        ~               S D L . h     6˝     p Z     !¸     0≥ö?lÿ0≥ö?lÿ%¨éÎlÿ0≥ö?lÿ @      ó0               S D L _ a s s e r t . h       0˝     p Z     !¸     Ó¬?lÿÓ¬?lÿ®≠éÎlÿÓ¬?lÿ @      ˘4               S D L _ a t o m i c  h       +˝     p `     !¸     x)‰?lÿéP‰?lÿxúéÎlÿéP‰?lÿ 0      m#               S D L _ b l e n d m o d e . h $˝     p Z     !¸     P«?lÿ.w«?lÿìôéÎlÿ.w«?lÿ 0      ›                S D L _ c o n f i g . h       G˝     x f     !¸     Îaú?lÿÎaú?lÿ˙ÕéÎlÿÎaú?lÿ P      +H               S D L _ c o n f i g . h . c m a k e   1˝     p `     !¸     jÏP?lÿ|Q?lÿWT•éÎlÿ|Q?lÿ 0      Ä'               S D L _ c o n f i g . h . i n Ë¸     x h     !¸     Iz«?lÿIz«?lÿM}ãÎl Iz«?lÿ                       S D L _ c o n f i g _ m a c o s x . h ˝     à r     !¸     ïÛ≈?lÿïÛ≈?lÿ±WyãÎlÿïÛ≈?lÿ        ⁄               S D L _ c o n f i g _ m a c o s x . h . o r i g       ˝     Ä j     !¸     Ò?lÿÒ?lÿá›ÄãÎlÿÒ?lÿ        …               S D L _ c o n f i g _ w i n d o w s . h      ˝    
 x f     !¸     Ôd(?lÿå(?lÿ†HáãÎlÿå(?lÿ        >               S D L _ c o n f i g _ w i n r t . h  B˝     p \     !¸     ï≈1?lÿ≠2?lÿâµéÎlÿ≠2?l  P      G@               S D L _ c p u i n f o . h   	 )˝     p Z     !¸     ¥É»?lÿ¥É»?lÿﬂôéÎlÿ¥É»?lÿ 0      ﬁ                S D L _ e n d i a n . h     	 Á¸     h X     !¸     :@îˇ>lÿBgîˇ>lÿ[wãÎlÿBgîˇ>lÿ        9               S D L _ e r r o r . h ˝    	 x b     !¸     ‚Û?lÿ8	Ù?lÿÊÓwãÎlÿ8	Ù?lÿ        »               S D L _ f i l e s y s t e m . h      D˝     p Z     !¸     r‰]?lÿû^?lÿ<®ªéÎlÿû^?lÿ P      ≤E               S D L _ h i d a p i . h . h  .˝     p ^     !¸     ^?lÿ^?lÿÒF¢éÎlÿ^?lÿ 0      ∑&               S D L _ k e y b o a r d . h  A˝     p \     !¸     pˇ?lÿpˇ?lÿÌ≤éÎlÿpˇ?lÿ @      <               S D L _ k e y c o d e . h                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      INDX( 	                 @   ò  Ë      ó G ÿG     P ÿ                                ¿     p Z     A     8À ã[ÿí±å[ÿÉºce?lÿqêö≈\ÿ P     ÍK              I M G _ 4 4 7 9 . J P G       ¬     p Z     A     /
6å[ÿ+8äå[ÿgcÈl?lÿû…õ≈\ÿ †     0ò              I M G _ 4 4 8 0 . J P G       ô     p Z     A     /ÉMÖ[ÿ‚3èÖ[ÿâ„ëÖ[ÿ`‰ú≈\ÿ 0     ¢+              I M G _ 4 4 8 1 . J P G       ﬁ     p Z     A     —eví[ÿÉÏƒí[ÿÒ»í[ÿÔ≠Íå±kÿ †      Üí               I M ó _ 4 4 8 2 . J P G       ú     p Z     A     	ÆæÖ[ÿ‰9	Ü[ÿ˜Ö÷D?lÿó/†≈\ÿ Ä     çt              I M G _ 4 4 8 3 . J P G       â     p Z     A     íÜôÇ[ÿ£⁄⁄Ç[ÿ•é›Ç[ÿ3k°≈\ÿ       ˛              I M G _ 4 4 8 4 . J P G       ≈     p Z     A     U=≥å[ÿπ˛å[ÿ†Ç@m?lÿâ¢≈\ÿ P     @              I M G _ 4 4 8 5 . J P G       û     p Z     A     +á7è[ÿ¢Ü}è[ÿ«Ètü?lÿÇø£≈\ÿ †     zô              I M G _ 4 4 8 6 . J P G       ]ﬁ     x b     A     ˘ÚkÂ˛[ÿ}IûÂ˛[ó ﬁñ.øbÿ•≈\ÿ                         I M G _ 4 4 8 7   ( 2 ) . J P G      j    p Z     A     w¡q/øbÿL©¡/øbÿ:~√/øbÿàrUç±kÿ      „              I M G _ 4 4 8 7 . J P G . J P `ﬁ     x b     A     ∫Â˛[ÿÓ;ËÂ˛[ÿ'ó.øbÿU)¶≈\ÿ                         I M G _ 4 4 8 8   ( 2 ) . J P G      m    p Z     A     ∆¬	0øbÿ§\0øbÿéÂ]0øbÿõÁßç±kÿ ∞     ®              I M G _ 4 4 8 8 . J P G . J P Uﬁ     x b     A     ≥%Â˛[ÿª£KÂ˛[ÿ<,ó.øbÿ|ß≈\ÿ                         I M ó _ 4 4 8 9   ( 2 ) . J P G      b    p Z     A     Wa◊.øbÿ7’F/øbÿ#™H/øbÿ,QØç±kÿ –     ‰Œ              I M G _ 4 4 8 9 . J P G . J P ^ﬁ     x b     A     ÃmÂ˛[ÿ¬cñÂ˛[ÿ^zó.øbÿ≥»®≈\ÿ                         I M G _ 4 4 9 0   ( 2 ) . J P G      k    p Z     A     F”|/øbÿ´”/øbÿ_’/øbÿ–0±ç±kÿ      rÍ              I M G _ 4 4 9 0 . J P G . J P aﬁ     x b     A     §óøÂ˛[ÿm@˘Â˛[ÿq°ó.øbÿæ‚©≈\ÿ                         I M G _ 4 4 9 1   ( 2 ) . J P G      l    p Z   ó A     Z`˚/øbÿ’Æ90øbÿµÉ;0øbÿÚ'¸ç±kÿ      Ÿ              I M G _ 4 4 9 1 . J P G . J P Zﬁ     x b     A     ÜU%Â˛[ÿ±NÂ˛[ÿF›ó.øbÿº´≈\ÿ                         I M G _ 4 4 9 2   ( 2 ) . J P G      ˚ﬂ     p Z     A     }Ω–.øbÿÍ<M/øbÿƒO/øbÿ4qé±kÿ ¿     √∞              I M G _ 4 4 9 2 . J P G . J P cﬁ     x b     A     È°Ê˛[ÿWüOÊ˛[ÿ+ò.øbÿH¨≈\ÿ                         I M G _ 4 4 9 6   ( 2 ) . J P G      w    p Z     A     *
û3øbÿÒ%	4øbÿp4øbÿÊ˜é±kÿ ∞   ó .£              I M G _ 4 4 9 6 . J P G . J P gﬁ     x b     A     DrÊ˛[ÿ†äΩÊ˛[ÿ?+ò.øbÿ
z≠≈\ÿ                         I M G _ 4 4 9 7   ( 2 ) . J P G      r    p Z     A     ›ä2øbÿ)T–2øbÿ◊≤“2øbÿé¢Té±kÿ      |Î              I M G _ 4 4 9 7 . J P G . J P dﬁ     x b     A     /:Ê˛[ÿ84^Ê˛[ÿPRò.øbÿ√°Æ≈\ÿ                         I M G _ 4 4 9 8   ( 2 ) . J P G      s    p Z     A     „§2øbÿé°w2øbÿ\ z2øbÿ’çZé±kÿ ‡     i›              I M G _ 4 4 9 8 . J P G . J ó hﬁ     x b     A     CwÊ˛[ÿ©gªÊ˛[ÿx†ò.øbÿ‰¿Ø≈\ÿ                         I M G _ 4 4 9 9   ( 2 ) . J P G      t    p Z     A     Â®æ2øbÿXØ33øbÿª˚53øbÿ_∆[é±kÿ      +	              I M G _ 4 4 9 9 . J P G . J P eﬁ     x b     A     ËkÊ˛[ÿ)f®Ê˛[ÿà«ò.øbÿ$⁄∞≈\ÿ                         I M G _ 4 5 0 0   ( 2 ) . J P G      v    p Z     A     Ü{k3øbÿ´ß◊3øbÿ‹⁄3øbÿ‰¿áé±kÿ @     ï<              I M G _ 4 5 0 0 . J P G . J P jﬁ     x b     A     ¿w√Ê˛[ÿ£\¸Ê˛[ÿôÓò.øbó R≤≈\ÿ                         I M G _ 4 5 0 1   ( 2 ) . J P G       u    p Z     A     –—ˇ2øbÿ,€l3øbÿ>%o3øbÿJ–Æé±kÿ      5
              I M G _ 4 5 0 1 . J P G . J P _ﬁ     x b     A     §Â˛[ÿÍ‰Â˛[ÿ¨ô.øbÿ¥≈\ÿ                         I M G _ 4 5 0 2   ( 2 ) . J P G       x    p Z     A     ®p4øbÿßZz4øbÿ∆§|4øbÿtØé±kÿ –     §√              I M G _ 4 5 0 2 . J P G                     rÍ              I M G _ 4 4 9 0 . J P G . J P                             ó INDX( 	 [|â          @   8	  Ë       G                                            æ     p Z     A     B%Rã[ÿ·Íõã[ÿ1´Ìlÿ\& Aô\ÿ P     A              I M G _ 4 3 7 2 . J P G       Ï     p Z     A     YQñ[ÿ6Aµñ[ÿºu∏ñ[ÿ∑È Aô\ÿ ê"     óà"              I M G _ 4 3 7 3 . J P G       Í     p Z     A     :2”ï[ÿü7ñ[ÿT|~é\ÿgI"Aô\ÿ ¿"     êµ"              I M G _ 4 3 7 4 . J P G       Ø     x b     A     ËeŒà[ÿ˘„â[ÿ›ë&¯ÏlÿÒB±kÿ Ä     :y              I M  _ 4 3 7 5   ( 2 ) . J P G       9    p Z     A     w‰´~ÌlÿﬁÌlÿZvÌlÿﬁÌlÿ Ä     :y              I M G _ 4 3 7 5 . J P G . J P À     x b     A     -≥ç[ÿˇ–é[ÿP¿ÃPÌlÿ®%Aô\ÿ P     àC              I M G _ 4 3 7 6   ( 2 ) . J P G     Ñ     p Z     A     `QﬁÅ[ÿè}
Ç[ÿΩÒÏlÿ;A&Aô\ÿ P     >N              I M G _ 4 3 7 7 . J P G       Å     p Z     A     }_åÅ[ÿ±}©Å[ÿÖ⁄ÏlÿÃy'Aô\ÿ –     eƒ              I M G _ 4 3 7 8 . J P G            p Z     A     ¨GÅ[ÿ⁄ÒlÅ[ÿej’Ïlÿÿ«(Aô\ÿ 0     R.              I M G _ 4 3 7 9 . J P G       bﬁ     x b     A     !åÊ˛[ÿ˚ﬂLÊ˛[ÿ®hHˇÎlÿj *Aô\ÿ                         I M G _ 4 3 8 1   ( 2 ) . J P G     q    p Z     A     èPf1øbÿSì÷1øbÿÍg”Ïlÿ*6˙B±kÿ ¿     ∏              I M G _ 4 3 8 1 . J P G . J P \ﬁ     x b     A     a)Â˛[ÿ ÄÂ˛[ÿ¡∂HˇÎlÿ`+Aô\ÿ                         I M G _ 4 3 8 2   ( 2 ) . J P G     y    p Z     A     ˆQ4øbÿÑ÷˛4øbÿﬂÌ?Ìlÿ˚ˇB±kÿ       bÛ             I M G _ 4 3 8 2 . J P G       ñ     p Z     A     mXËÑ[ÿ'/2Ö[ÿˆ˘|”Ïlÿûò,Aô\ÿ      F              I M G _ 4 3 8 4 . J P G       ç     p Z     A     Ä>*É[ÿÆrbÉ[ÿÃqD«ÏlÿqF.Aô\ÿ Ä     ƒ|              I M G _ 4 3 8 5 . J P G       ó     p Z     A     ±OÈÑ[ÿ)'Ö[ÿ)@H”ÏlÿÂW/Aô\ÿ                    I M G _ 4 3 8 6 . J P G       ¨     x b     A     ÕëYà[ÿg"¢à[ÿæµ˜Ïlÿ‘fıE±kÿ Ä     q              I M G _ 4 3 8 7   ( 2 ) . J P G       7    p Z    A     _ø&~Ìlÿûcu~ÌlÿŸˆw~Ìlÿûcu~Ìlÿ Ä     q              I M G _ 4 3 8 7 . J P G       ï     p Z     A     >ÅÑ[ÿå±ÀÑ[ÿêù9”Ïlÿhﬁ1Aô\ÿ      œÍ              I M G _ 4 3 8 8 . J P G       è     p Z     A     ÑΩåÉ[ÿzV∆É[ÿ1L÷“Ïlÿ 3Aô\ÿ ∞     ∞ß              I M G _ 4 3 8 9 . J P G                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 INDX( 	 fyâ          @   †	  Ë       G ÿG ÿ                                      L     p Z     A     Õ¨&Ü[ÿÅ—gÜ[ÿX∂⁄Ïlÿa5Aô\ÿ ê     ÃÖ              I M G _ 4 3 9 1 . J P G       ì     p Z     A     *Œ\Ñ[ÿHõ©Ñ[ÿ˙03”Ïlÿ¶ô6Aô\ÿ      Ó‡              I M G _ 4 3 9 2 . J P G       õ     p Z     A     •v∫Ö[ÿﬂ•Ü[ÿ⁄ÒM◊Ïlÿ´7Aô\ÿ p     m              I M G _ 4 3 9 3 . J P G       ∑     p Z     A     Oƒ0ä[ÿ¸5qä[ÿYîÌlÿ≠„8Aô\ÿ                    I M  _ 4 3 9 4 . J P G       í     p Z     A     ûdÉ[ÿJ(/Ñ[ÿ@)”Ïlÿ≤M±kÿ –     ¯œ              I M G _ 4 3 9 5 . J P G       ö     p Z     A     ˇsaÖ[ÿÄvòÖ[ÿ‰–”ÏlÿÅÊÆM±kÿ `      X              I M G _ 4 3 9 6 . J P G       ™     x b     A     FÍá[ÿ©Ì9à[ÿæî<ÒÏlÿU√™M±kÿ p     jk              I M G _ 4 3 9 7   ( 2 ) . J P G     5    p Z     A     úÑô}Ìlÿ1¢‚}ÌlÿÅaÂ}Ìlÿ1¢‚}Ìlÿ p     jk              I M G _ 4 3 9 7 . J P G . J P ≠     x b     A     Óc`à[ ˇ©µà[ÿ÷XŒ˜Ïlÿùê¶M±kÿ Ä     Ås              I M G _ 4 3 9 8   ( 2 ) . J P G     8    p Z     A     •À´~Ìlÿæ[ÌlÿI	Ìlÿæ[Ìlÿ Ä     Ås              I M G _ 4 3 9 8 . J P G       Ö     p Z     A     ß>·Å[ÿ„‰Ç[ÿõíoÏlÿÿÚ°M±kÿ ‡     ⁄◊              I M G _ 4 3 9 9 . J P G       ª     p Z     A     #º≤ä[ÿ|¡
ã[ÿ… •ÌlÿØ·ûM±kÿ @     F;              I M G _ 4 4 0 0 . J P G       ƒ     p Z     A     W/£å[ÿlø„å[ÿ˝&@i?lÿF‘õM±kÿ       ˚              I M  _ 4 4 0 1 . J P G       º     p Z     A     ôÎ9ã[ÿSπÅã[ÿ¶√∫ÌlÿÓÒñM±kÿ P     ¿A              I M G _ 4 4 0 2 . J P G       Ã     x b     A     Ç9é[ÿä(Çé[ÿ˙y[Ìlÿﬁ}ìM±kÿ p     ◊f              I M G _ 4 4 0 3   ( 2 ) . J P G           p Z     A     €|òç[ÿLŸé[ÿÅ≤KÌlÿspêM±kÿ      $Î              I M G _ 4 4 0 4 . J P G       «     p Z     A     ™úç[ÿ¨¸nç[ÿÒœÑm?lÿ %çM±kÿ P     ıN              I M G _ 4 4 0 5 . J P G       ø     p Z     A     Y¨ã[ ≥ıÁã[ÿ6K”ÌlÿÅCàM±kÿ P     xI              I M G _ 4 4 0 6 . J P G       π     p Z     A     u¬üä[ÿÇ∆˙ä[ÿ(æ7Ìlÿ0]ÑM±kÿ @     8;              I M G _ 4 4 0 7 . J P G       ¥     p Z     A     2ùâ[ÿ\©·â[ÿO®Z Ìlÿ~M±kÿ ‡     é›              I M G _ 4 4 0 8 . J P G       ”     x b     A     Yè…è[ÿ¡m$ê[ÿ˚ï£iÌlÿNì]J±kÿ      ^Ë              I M G _ 4 4 0 9   ( 2 ) . J P G                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         INDX( 	 Òπâ          @   †	  Ë       G    ÿ                                      ê     p Z     A     R8©É[ÿ”˚2Ñ[ÿ˜)J±kÿRˆ3J±kÿ ¿+     \Ω+              I M G _ 4 4 1 1 . J P G       †     p Z     A     FZnÜ[ÿÊø⁄Ü[ÿ7áﬁÜ[ÿÇãTJ±kÿ @*     ‘=*              I M G _ 4 4 1 2 . J P G       ∂     p Z     A     ’ä[ÿ|íxä[ÿwÍ|ä[ÿù}M±kÿ –(     Õ(              I M G _ 4 4 1 3 . J P G       …     p Z     A     éøyç[ÿ∫˝é[ÿ’é[ÿN∂N±kÿ ‡&     U‹&              I M  _ 4 4 1 4 . J P G       Ω     p Z     A     WÕGã[ÿÇ&»ã[ÿ}Ãã[ÿb“ÑM±kÿ  (     ‘(              I M G _ 4 4 1 5 . J P G       ‰     p Z     A     ¢ç/î[ÿMåvî[ÿNº8»ÌlÿË?¡O±kÿ  $     ›$              I M G _ 4 4 1 6 . J P G       q    x b     A     º?‚ºÌlÿ˝ÆFΩÌlÿ≥1JΩÌlÿ˝ÆFΩÌlÿ –%     6√%              I M G _ 4 4 1 7   ( 2 ) . J P G     œ     x b     A     å!Ãé[ÿoÏ8è[ÿÖJÌÌlÿÕ·V±kÿ –%     6√%              I M G _ 4 4 1 7   ( 3 ) . J P G     ¿    p Z     A     F-g˜ÌlÿP˚Ìlÿ∆˚ÌlÿP˚Ìlÿ –%     6√%              I M G _ 4 4 1 7 . J P G       Â     p Z     A     $qÑî[ÿ"zÊî[ÿïñkîÌlÿäJ‡V±kÿ P!     ,J!              I M G _ 4 4 1 8 . J P G       Œ     x b     A     E±é[ÿãÎè[ÿúÜ@[ÌlÿcGk±kÿ p     h              I M G _ 4 4 1 9   ( 2 ) . J P G     G    p Z     A      äÓÖÌlÿE‹ÄÜÌlÿ	√ÉÜÌlÿE‹ÄÜÌlÿ p     h              I M G _ 4 4 1 9 . J P G       °     p Z     A     √LíÜ[ÿÛú”Ü[ÿJº€ÏlÿÏEk±kÿ      ‚             I M G _ 4 4 2 0 . J P G       á     p Z     A     ÅΩaÇ[ÿZXéÇ[ÿ[˙#ÏlÿN>Dk±kÿ ‡     	€              I M G _ 4 4 2 1 . J P G       å     p Z     A     v˝
É[ÿ≤§:É[ÿEc»∆ÏlÿÜkBk±kÿ †     ?û              I M G _ 4 4 2 2 . J P G       ë     p Z     A     ΩIËÉ[ÿX5Ñ[ÿÁÏ˛“Ïlÿ–‰@k±kÿ ∞     x™              I M G _ 4 4 2 3 . J P G       ä     p Z     A     √1ƒÇ[ÿ:É[ÿn
=øÏlÿ∫!?k±kÿ       î              I M G _ 4 4 2 4 . J P G       Ç     p Z     A     +èÅ[ e>∏Å[ÿCÛÏlÿª%=k±kÿ 0     t               I M G _ 4 4 2 5 . J P G       ’     p Z     A     ™3Oê[ÿiçê[ÿ*5ØiÌlÿo;k±kÿ 0     &              I M G _ 4 4 2 6 . J P G       ∏     p Z     A     –πCä[ÿ‹»Çä[ÿû°	Ìlÿ+ö9k±kÿ       W              I M G _ 4 4 2 7 . J P G       l    x b     A     gµ√∂ÌlÿÂÕX∑ÌlÿŒS\∑ÌlÿÂÕX∑Ìlÿ ¿&     «≥&              I M G _ 4 4 2 8   ( 2 ) . J P G                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         INDX( 	 ÷Á â          @     Ë                                                     Õ     x b     A     8ù:é[ÿuùé[ÿ‹XdÓlÿTÏ7k±kÿ ¿&     «≥&              I M G _ 4 4 2 8   ( 3 ) . J P G     “    p Z     A     ömÓlÿ‚Ólÿ£aÂÓlÿ‚Ólÿ ¿&     «≥&              I M G _ 4 4 2 8 . J P G       ÷     p Z     A     ±∑ê[ÿ÷r¸ê[ÿìjÌlÿ°e6k±kÿ `     µ\              I M G _ 4 4 2 9 . J P G       „     p Z     A     é⁄¯ì[ÿZî[ÿ>√◊çÌlÿ⁄∑4k±kÿ @!     r=!             I M G _ 4 4 3 0 . J P G       —     x b     A     ≈ÌUè[ÿ:Ωòè[ÿ=LøÌlÿ
3k±kÿ p     &a              I M G _ 4 4 3 1   ( 2 ) . J P G     /    p Z     A     uI{ÉÌlÿ$”ŒÉÌlÿZk—ÉÌlÿ$”ŒÉÌlÿ p     &a              I M G _ 4 4 3 1 . J P G       Ÿ     p Z     A     †ôbë[ÿü¥∫ë[ÿo˛É÷ÌlÿßΩ1k±kÿ ‡$     œ÷$              I M G _ 4 4 3 2 . J P G       ‹     x b     A     lí[ÿ”Lí[ÿËjîÑÌlÿô/k±kÿ 0      ä+               I M G _ 4 4 3 3   ( 2 ) . J P G     Y    p Z    A     Ø-üúÌlÿDhùÌlÿÕúùÌlÿDhùÌlÿ 0      ä+               I M G _ 4 4 3 3 . J P G       Ê     p Z     A     œä¢î[ÿ0q	ï[ÿíc∏¿ÌlÿØ˙!k±kÿ †#     ıó#              I M G _ 4 4 3 4 . J P G       ⁄     p Z     A     Öˆíë[ÿ‚ë[ÿq'Ë~ÌlÿXÜù±kÿ –     ¡√              I M G _ 4 4 3 5 . J P G       É     p Z     A     û–Å[ÿÇè4Ç[ÿôpƒÙÓlÿØ˙!k±kÿ ê,     Câ,              I M G _ 4 4 3 6 . J P G       ◊     p Z     A     F…ê[ÿ;˘6ë[ÿä$’ŸÌlÿr/k±kÿ $     ©Ë$             I M G _ 4 4 3 7 . J P G       g    x b     A     ?)¨Ìlÿ
§¨Ìlÿ≠ß¨Ìlÿ
§¨Ìlÿ Ä%     √p%              I M G _ 4 4 3 8   ( 2 ) . J P G     ‘     x b     A     Ä{.ê[ÿ]Òûê[ÿ¸ÀJÏÌlÿû™0k±kÿ Ä%     √p%              I M G _ 4 4 3 8   ( 3 ) . J P G     æ    p Z     A     Éö≥ÌlÿèÇ9ÒÌlÿ1=ÒÌlÿèÇ9ÒÌlÿ Ä%     √p%              I M G _ 4 4 3 8 . J P G       €     p Z     A     íÏë[ÿY5í[ÿO“÷ÌlÿÈª2k±kÿ ‡$     Ï—$              I M G _ 4 4 3 9 . J P G       i    x b    A     Îª”¨Ìlÿ$j∂Ìlÿ†Å∂Ìlÿ$j∂Ìlÿ †%     @ê%              I M G _ 4 4 4 0   ( 2 ) . J P G     “     x b     A     ;¶´è[ÿêl	ê[ÿ¡πaÏÌlÿÇÙ3k±kÿ †%     @ê%              I M G _ 4 4 4 0   ( 3 ) . J P G     Ω    p Z     A     }kÀÏÌlÿi˛ZÌÌlÿNlÌlÿi˛ZÌÌlÿ †%     @ê%              I M G _ 4 4 4 0 . J P G       u     p Z     A     ÎG`Ä[ÿO+Ä[ÿüöıÄ[ÿ˚HÍP±kÿ p-     öb-              I M G _ 4 4 4 1 . J P G       ã     p Z     A     wF¯Ç[ÿ€åÉ[ÿ@°hÌÓlÿ&w7k±kÿ `,    ◊],              I M G _ 4 4 4 2 . J P G       à     p Z     A     ÍÊeÇ[ÿp Ç[ÿwLmÌÓlÿL9k±kÿ p,     ta,              I M G _ 4 4 4 3 . J P G       ù     p Z     A     ∆Ö[ÿÒDHÜ[ÿ≈ü∑µÓlÿƒ˘:k±kÿ *     	Ë*              I M G _ 4 4 4 4 . J P G       ≥     x b     A     ∞3hâ[ÿ´S´â[ÿ/ã¸Ïlÿ‚à<k±kÿ ¿     Q∫              I M G _ 4 4 4 5   ( 2 ) . J P G     ?    p Z     A     ùCÉÌlÿ…∂oÉÌlÿ"vrÉÌlÿ…∂oÉÌlÿ ¿     Q∫              I M G _ 4 4 4 5 . J P G   ( 2                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    C) (EGLDisplay dpy, EGLStreamKHR stream);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglStreamConsumerGLTextureExternalKHR (EGLDisplay dpy, EGLStreamKHR stream);
EGLAPI EGLBoolean EGLAPIENTRY eglStreamConsumerAcquireKHR (EGLDisplay dpy, EGLStreamKHR stream);
EGLAPI EGLBoolean EGLAPIENTRY eglStreamConsumerReleaseKHR (EGLDisplay dpy, EGLStreamKHR stream);
#endif
#endif /* EGL_KHR_stream */
#endif /* EGL_KHR_stream_consumer_gltexture */

#ifndef EGL_KHR_stream_cross_process_fd
#define EGL_KHR_stream_cross_process_fd 1
typedef int EGLNativeFileDescriptorKHR;
#ifdef EGL_KHR_stream
#define EGL_NO_FILE_DESCRIPTOR_KHR        EGL_CAST(EGLNativeFileDescriptorKHR,-1)
typedef EGLNativeFileDescriptorKHR (EGLAPIENTRYP PFNEGLGETSTREAMFILEDESCRIPTORKHRPROC) (EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLStreamKHR (EGLAPIENTRYP PFNEGLCREATESTREAMFROMFILEDESCRIPTORKHRPROC) (EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLNativeFileDescriptorKHR EGLAPIENTRY eglGetStreamFileDescriptorKHR (EGLDisplay dpy, EGLStreamKHR stream);
EGLAPI EGLStreamKHR EGLAPIENTRY eglCreateStreamFromFileDescriptorKHR (EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor);
#endif
#endif /* EGL_KHR_stream */
#endif /* EGL_KHR_stream_cross_process_fd */

#ifndef EGL_KHR_stream_fifo
#define EGL_KHR_stream_fifo 1
#ifdef EGL_KHR_stream
#define EGL_STREAM_FIFO_LENGTH_KHR        0x31FC
#define EGL_STREAM_TIME_NOW_KHR           0x31FD
#define EGL_STREAM_TIME_CONSUMER_KHR      0x31FE
#define EGL_STREAM_TIME_PRODUCER_KHR      0x31FF
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYSTREAMTIMEKHRPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR *value);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryStreamTimeKHR (EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR *value);
#endif
#endif /* EGL_KHR_stream */
#endif /* EGL_KHR_stream_fifo */

#ifndef EGL_KHR_stream_producer_aldatalocator
#define EGL_KHR_stream_producer_aldatalocator 1
#ifdef EGL_KHR_stream
#endif /* EGL_KHR_stream */
#endif /* EGL_KHR_stream_producer_aldatalocator */

#ifndef EGL_KHR_stream_producer_eglsurface
#define EGL_KHR_stream_producer_eglsurface 1
#ifdef EGL_KHR_stream
#define EGL_STREAM_BIT_KHR                0x0800
typedef EGLSurface (EGLAPIENTRYP PFNEGLCREATESTREAMPRODUCERSURFACEKHRPROC) (EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLSurface EGLAPIENTRY eglCreateStreamProducerSurfaceKHR (EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint *attrib_list);
#endif
#endif /* EGL_KHR_stream */
#endif /* EGL_KHR_stream_producer_eglsurface */

#ifndef EGL_KHR_surfaceless_context
#define EGL_KHR_surfaceless_context 1
#endif /* EGL_KHR_surfaceless_context */

#ifndef EGL_KHR_swap_buffers_with_damage
#define EGL_KHR_swap_buffers_with_damage 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC) (EGLDisplay dpy, EGLSurface surface, const EGLint *rects, EGLint n_rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersWithDamageKHR (EGLDisplay dpy, EGLSurface surface, const EGLint *rects, EGLint n_rects);
#endif
#endif /* EGL_KHR_swap_buffers_with_damage */

#ifndef EGL_KHR_vg_parent_image
#define EGL_KHR_vg_parent_image 1
#define EGL_VG_PARENT_IMAGE_KHR           0x30BA
#endif /* EGL_KHR_vg_parent_image */

#ifndef EGL_KHR_wait_sync
#define EGL_KHR_wait_sync 1
typedef EGLint (EGLAPIENTRYP PFNEGLWAITSYNCKHRPROC) (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLint EGLAPIENTRY eglWaitSyncKHR (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
#endif
#endif /* EGL_KHR_wait_sync */

#ifndef EGL_ANDROID_GLES_layers
#define EGL_ANDROID_GLES_layers 1
#endif /* EGL_ANDROID_GLES_layers */

#ifndef EGL_ANDROID_blob_cache
#define EGL_ANDROID_blob_cache 1
typedef khronos_ssize_t EGLsizeiANDROID;
typedef void (*EGLSetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, const void *value, EGLsizeiANDROID valueSize);
typedef EGLsizeiANDROID (*EGLGetBlobFuncANDROID) (const void *key, EGLsizeiANDROID keySize, void *value, EGLsizeiANDROID valueSize);
typedef void (EGLAPIENTRYP PFNEGLSETBLOBCACHEFUNCSANDROIDPROC) (EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI void EGLAPIENTRY eglSetBlobCacheFuncsANDROID (EGLDisplay dpy, EGLSetBlobFuncANDROID set, EGLGetBlobFuncANDROID get);
#endif
#endif /* EGL_ANDROID_blob_cache */

#ifndef EGL_ANDROID_create_native_client_buffer
#define EGL_ANDROID_create_native_client_buffer 1
#define EGL_NATIVE_BUFFER_USAGE_ANDROID   0x3143
#define EGL_NATIVE_BUFFER_USAGE_PROTECTED_BIT_ANDROID 0x00000001
#define EGL_NATIVE_BUFFER_USAGE_RENDERBUFFER_BIT_ANDROID 0x00000002
#define EGL_NATIVE_BUFFER_USAGE_TEXTURE_BIT_ANDROID 0x00000004
typedef EGLClientBuffer (EGLAPIENTRYP PFNEGLCREATENATIVECLIENTBUFFERANDROIDPROC) (const EGLint *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLClientBuffer EGLAPIENTRY eglCreateNativeClientBufferANDROID (const EGLint *attrib_list);
#endif
#endif /* EGL_ANDROID_create_native_client_buffer */

#ifndef EGL_ANDROID_framebuffer_target
#define EGL_ANDROID_framebuffer_target 1
#define EGL_FRAMEBUFFER_TARGET_ANDROID    0x3147
#endif /* EGL_ANDROID_framebuffer_target */

#ifndef EGL_ANDROID_front_buffer_auto_refresh
#define EGL_ANDROID_front_buffer_auto_refresh 1
#define EGL_FRONT_BUFFER_AUTO_REFRESH_ANDROID 0x314C
#endif /* EGL_ANDROID_front_buffer_auto_refresh */

#ifndef EGL_ANDROID_get_frame_timestamps
#define EGL_ANDROID_get_frame_timestamps 1
typedef khronos_stime_nanoseconds_t EGLnsecsANDROID;
#define EGL_TIMESTAMP_PENDING_ANDROID     EGL_CAST(EGLnsecsANDROID,-2)
#define EGL_TIMESTAMP_INVALID_ANDROID     EGL_CAST(EGLnsecsANDROID,-1)
#define EGL_TIMESTAMPS_ANDROID            0x3430
#define EGL_COMPOSITE_DEADLINE_ANDROID    0x3431
#define EGL_COMPOSITE_INTERVAL_ANDROID    0x3432
#define EGL_COMPOSITE_TO_PRESENT_LATENCY_ANDROID 0x3433
#define EGL_REQUESTED_PRESENT_TIME_ANDROID 0x3434
#define EGL_RENDERING_COMPLETE_TIME_ANDROID 0x3435
#define EGL_COMPOSITION_LATCH_TIME_ANDROID 0x3436
#define EGL_FIRST_COMPOSITION_START_TIME_ANDROID 0x3437
#define EGL_LAST_COMPOSITION_START_TIME_ANDROID 0x3438
#define EGL_FIRST_COMPOSITION_GPU_FINISHED_TIME_ANDROID 0x3439
#define EGL_DISPLAY_PRESENT_TIME_ANDROID  0x343A
#define EGL_DEQUEUE_READY_TIME_ANDROID    0x343B
#define EGL_READS_DONE_TIME_ANDROID       0x343C
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETCOMPOSITORTIMINGSUPPORTEDANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLint name);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETCOMPOSITORTIMINGANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLint numTimestamps,  const EGLint *names, EGLnsecsANDROID *values);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETNEXTFRAMEIDANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLuint64KHR *frameId);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETFRAMETIMESTAMPSUPPORTEDANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLint timestamp);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETFRAMETIMESTAMPSANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLuint64KHR frameId, EGLint numTimestamps,  const EGLint *timestamps, EGLnsecsANDROID *values);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglGetCompositorTimingSupportedANDROID (EGLDisplay dpy, EGLSurface surface, EGLint name);
EGLAPI EGLBoolean EGLAPIENTRY eglGetCompositorTimingANDROID (EGLDisplay dpy, EGLSurface surface, EGLint numTimestamps,  const EGLint *names, EGLnsecsANDROID *values);
EGLAPI EGLBoolean EGLAPIENTRY eglGetNextFrameIdANDROID (EGLDisplay dpy, EGLSurface surface, EGLuint64KHR *frameId);
EGLAPI EGLBoolean EGLAPIENTRY eglGetFrameTimestampSupportedANDROID (EGLDisplay dpy, EGLSurface surface, EGLint timestamp);
EGLAPI EGLBoolean EGLAPIENTRY eglGetFrameTimestampsANDROID (EGLDisplay dpy, EGLSurface surface, EGLuint64KHR frameId, EGLint numTimestamps,  const EGLint *timestamps, EGLnsecsANDROID *values);
#endif
#endif /* EGL_ANDROID_get_frame_timestamps */

#ifndef EGL_ANDROID_get_native_client_buffer
#define EGL_ANDROID_get_native_client_buffer 1
struct AHardwareBuffer;
typedef EGLClientBuffer (EGLAPIENTRYP PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC) (const struct AHardwareBuffer *buffer);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLClientBuffer EGLAPIENTRY eglGetNativeClientBufferANDROID (const struct AHardwareBuffer *buffer);
#endif
#endif /* EGL_ANDROID_get_native_client_buffer */

#ifndef EGL_ANDROID_image_native_buffer
#define EGL_ANDROID_image_native_buffer 1
#define EGL_NATIVE_BUFFER_ANDROID         0x3140
#endif /* EGL_ANDROID_image_native_buffer */

#ifndef EGL_ANDROID_native_fence_sync
#define EGL_ANDROID_native_fence_sync 1
#define EGL_SYNC_NATIVE_FENCE_ANDROID     0x3144
#define EGL_SYNC_NATIVE_FENCE_FD_ANDROID  0x3145
#define EGL_SYNC_NATIVE_FENCE_SIGNALED_ANDROID 0x3146
#define EGL_NO_NATIVE_FENCE_FD_ANDROID    -1
typedef EGLint (EGLAPIENTRYP PFNEGLDUPNATIVEFENCEFDANDROIDPROC) (EGLDisplay dpy, EGLSyncKHR sync);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLint EGLAPIENTRY eglDupNativeFenceFDANDROID (EGLDisplay dpy, EGLSyncKHR sync);
#endif
#endif /* EGL_ANDROID_native_fence_sync */

#ifndef EGL_ANDROID_presentation_time
#define EGL_ANDROID_presentation_time 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLPRESENTATIONTIMEANDROIDPROC) (EGLDisplay dpy, EGLSurface surface, EGLnsecsANDROID time);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglPresentationTimeANDROID (EGLDisplay dpy, EGLSurface surface, EGLnsecsANDROID time);
#endif
#endif /* EGL_ANDROID_presentation_time */

#ifndef EGL_ANDROID_recordable
#define EGL_ANDROID_recordable 1
#define EGL_RECORDABLE_ANDROID            0x3142
#endif /* EGL_ANDROID_recordable */

#ifndef EGL_ANGLE_d3d_share_handle_client_buffer
#define EGL_ANGLE_d3d_share_handle_client_buffer 1
#define EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE 0x3200
#endif /* EGL_ANGLE_d3d_share_handle_client_buffer */

#ifndef EGL_ANGLE_device_d3d
#define EGL_ANGLE_device_d3d 1
#define EGL_D3D9_DEVICE_ANGLE             0x33A0
#define EGL_D3D11_DEVICE_ANGLE            0x33A1
#endif /* EGL_ANGLE_device_d3d */

#ifndef EGL_ANGLE_query_surface_pointer
#define EGL_ANGLE_query_surface_pointer 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYSURFACEPOINTERANGLEPROC) (EGLDisplay dpy, EGLSurface surface, EGLint attribute, void **value);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurfacePointerANGLE (EGLDisplay dpy, EGLSurface surface, EGLint attribute, void **value);
#endif
#endif /* EGL_ANGLE_query_surface_pointer */

#ifndef EGL_ANGLE_surface_d3d_texture_2d_share_handle
#define EGL_ANGLE_surface_d3d_texture_2d_share_handle 1
#endif /* EGL_ANGLE_surface_d3d_texture_2d_share_handle */

#ifndef EGL_ANGLE_sync_control_rate
#define EGL_ANGLE_sync_control_rate 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETMSCRATEANGLEPROC) (EGLDisplay dpy, EGLSurface surface, EGLint *numerator, EGLint *denominator);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglGetMscRateANGLE (EGLDisplay dpy, EGLSurface surface, EGLint *numerator, EGLint *denominator);
#endif
#endif /* EGL_ANGLE_sync_control_rate */

#ifndef EGL_ANGLE_window_fixed_size
#define EGL_ANGLE_window_fixed_size 1
#define EGL_FIXED_SIZE_ANGLE              0x3201
#endif /* EGL_ANGLE_window_fixed_size */

#ifndef EGL_ARM_image_format
#define EGL_ARM_image_format 1
#define EGL_COLOR_COMPONENT_TYPE_UNSIGNED_INTEGER_ARM 0x3287
#define EGL_COLOR_COMPONENT_TYPE_INTEGER_ARM 0x3288
#endif /* EGL_ARM_image_format */

#ifndef EGL_ARM_implicit_external_sync
#define EGL_ARM_implicit_external_sync 1
#define EGL_SYNC_PRIOR_COMMANDS_IMPLICIT_EXTERNAL_ARM 0x328A
#endif /* EGL_ARM_implicit_external_sync */

#ifndef EGL_ARM_pixmap_multisample_discard
#define EGL_ARM_pixmap_multisample_discard 1
#define EGL_DISCARD_SAMPLES_ARM           0x3286
#endif /* EGL_ARM_pixmap_multisample_discard */

#ifndef EGL_EXT_bind_to_front
#define EGL_EXT_bind_to_front 1
#define EGL_FRONT_BUFFER_EXT              0x3464
#endif /* EGL_EXT_bind_to_front */

#ifndef EGL_EXT_buffer_age
#define EGL_EXT_buffer_age 1
#define EGL_BUFFER_AGE_EXT                0x313D
#endif /* EGL_EXT_buffer_age */

#ifndef EGL_EXT_client_extensions
#define EGL_EXT_client_extensions 1
#endif /* EGL_EXT_client_extensions */

#ifndef EGL_EXT_client_sync
#define EGL_EXT_client_sync 1
#define EGL_SYNC_CLIENT_EXT               0x3364
#define EGL_SYNC_CLIENT_SIGNAL_EXT        0x3365
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCLIENTSIGNALSYNCEXTPROC) (EGLDisplay dpy, EGLSync sync, const EGLAttrib *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglClientSignalSyncEXT (EGLDisplay dpy, EGLSync sync, const EGLAttrib *attrib_list);
#endif
#endif /* EGL_EXT_client_sync */

#ifndef EGL_EXT_compositor
#define EGL_EXT_compositor 1
#define EGL_PRIMARY_COMPOSITOR_CONTEXT_EXT 0x3460
#define EGL_EXTERNAL_REF_ID_EXT           0x3461
#define EGL_COMPOSITOR_DROP_NEWEST_FRAME_EXT 0x3462
#define EGL_COMPOSITOR_KEEP_NEWEST_FRAME_EXT 0x3463
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSETCONTEXTLISTEXTPROC) (const EGLint *external_ref_ids, EGLint num_entries);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSETCONTEXTATTRIBUTESEXTPROC) (EGLint external_ref_id, const EGLint *context_attributes, EGLint num_entries);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSETWINDOWLISTEXTPROC) (EGLint external_ref_id, const EGLint *external_win_ids, EGLint num_entries);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSETWINDOWATTRIBUTESEXTPROC) (EGLint external_win_id, const EGLint *window_attributes, EGLint num_entries);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORBINDTEXWINDOWEXTPROC) (EGLint external_win_id);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSETSIZEEXTPROC) (EGLint external_win_id, EGLint width, EGLint height);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLCOMPOSITORSWAPPOLICYEXTPROC) (EGLint external_win_id, EGLint policy);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSetContextListEXT (const EGLint *external_ref_ids, EGLint num_entries);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSetContextAttributesEXT (EGLint external_ref_id, const EGLint *context_attributes, EGLint num_entries);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSetWindowListEXT (EGLint external_ref_id, const EGLint *external_win_ids, EGLint num_entries);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSetWindowAttributesEXT (EGLint external_win_id, const EGLint *window_attributes, EGLint num_entries);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorBindTexWindowEXT (EGLint external_win_id);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSetSizeEXT (EGLint external_win_id, EGLint width, EGLint height);
EGLAPI EGLBoolean EGLAPIENTRY eglCompositorSwapPolicyEXT (EGLint external_win_id, EGLint policy);
#endif
#endif /* EGL_EXT_compositor */

#ifndef EGL_EXT_config_select_group
#define EGL_EXT_config_select_group 1
#define EGL_CONFIG_SELECT_GROUP_EXT       0x34C0
#endif /* EGL_EXT_config_select_group */

#ifndef EGL_EXT_create_context_robustness
#define EGL_EXT_create_context_robustness 1
#define EGL_CONTEXT_OPENGL_ROBUST_ACCESS_EXT 0x30BF
#define EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_EXT 0x3138
#define EGL_NO_RESET_NOTIFICATION_EXT     0x31BE
#define EGL_LOSE_CONTEXT_ON_RESET_EXT     0x31BF
#endif /* EGL_EXT_create_context_robustness */

#ifndef EGL_EXT_device_base
#define EGL_EXT_device_base 1
typedef void *EGLDeviceEXT;
#define EGL_NO_DEVICE_EXT                 EGL_CAST(EGLDeviceEXT,0)
#define EGL_BAD_DEVICE_EXT                0x322B
#define EGL_DEVICE_EXT                    0x322C
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDEVICEATTRIBEXTPROC) (EGLDeviceEXT device, EGLint attribute, EGLAttrib *value);
typedef const char *(EGLAPIENTRYP PFNEGLQUERYDEVICESTRINGEXTPROC) (EGLDeviceEXT device, EGLint name);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDEVICESEXTPROC) (EGLint max_devices, EGLDeviceEXT *devices, EGLint *num_devices);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDISPLAYATTRIBEXTPROC) (EGLDisplay dpy, EGLint attribute, EGLAttrib *value);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDeviceAttribEXT (EGLDeviceEXT device, EGLint attribute, EGLAttrib *value);
EGLAPI const char *EGLAPIENTRY eglQueryDeviceStringEXT (EGLDeviceEXT device, EGLint name);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDevicesEXT (EGLint max_devices, EGLDeviceEXT *devices, EGLint *num_devices);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDisplayAttribEXT (EGLDisplay dpy, EGLint attribute, EGLAttrib *value);
#endif
#endif /* EGL_EXT_device_base */

#ifndef EGL_EXT_device_drm
#define EGL_EXT_device_drm 1
#define EGL_DRM_DEVICE_FILE_EXT           0x3233
#define EGL_DRM_MASTER_FD_EXT             0x333C
#endif /* EGL_EXT_device_drm */

#ifndef EGL_EXT_device_drm_render_node
#define EGL_EXT_device_drm_render_node 1
#define EGL_DRM_RENDER_NODE_FILE_EXT      0x3377
#endif /* EGL_EXT_device_drm_render_node */

#ifndef EGL_EXT_device_enumeration
#define EGL_EXT_device_enumeration 1
#endif /* EGL_EXT_device_enumeration */

#ifndef EGL_EXT_device_openwf
#define EGL_EXT_device_openwf 1
#define EGL_OPENWF_DEVICE_ID_EXT          0x3237
#define EGL_OPENWF_DEVICE_EXT             0x333D
#endif /* EGL_EXT_device_openwf */

#ifndef EGL_EXT_device_persistent_id
#define EGL_EXT_device_persistent_id 1
#define EGL_DEVICE_UUID_EXT               0x335C
#define EGL_DRIVER_UUID_EXT               0x335D
#define EGL_DRIVER_NAME_EXT               0x335E
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDEVICEBINARYEXTPROC) (EGLDeviceEXT device, EGLint name, EGLint max_size, void *value, EGLint *size);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDeviceBinaryEXT (EGLDeviceEXT device, EGLint name, EGLint max_size, void *value, EGLint *size);
#endif
#endif /* EGL_EXT_device_persistent_id */

#ifndef EGL_EXT_device_query
#define EGL_EXT_device_query 1
#endif /* EGL_EXT_device_query */

#ifndef EGL_EXT_device_query_name
#define EGL_EXT_device_query_name 1
#define EGL_RENDERER_EXT                  0x335F
#endif /* EGL_EXT_device_query_name */

#ifndef EGL_EXT_gl_colorspace_bt2020_linear
#define EGL_EXT_gl_colorspace_bt2020_linear 1
#define EGL_GL_COLORSPACE_BT2020_LINEAR_EXT 0x333F
#endif /* EGL_EXT_gl_colorspace_bt2020_linear */

#ifndef EGL_EXT_gl_colorspace_bt2020_pq
#define EGL_EXT_gl_colorspace_bt2020_pq 1
#define EGL_GL_COLORSPACE_BT2020_PQ_EXT   0x3340
#endif /* EGL_EXT_gl_colorspace_bt2020_pq */

#ifndef EGL_EXT_gl_colorspace_display_p3
#define EGL_EXT_gl_colorspace_display_p3 1
#define EGL_GL_COLORSPACE_DISPLAY_P3_EXT  0x3363
#endif /* EGL_EXT_gl_colorspace_display_p3 */

#ifndef EGL_EXT_gl_colorspace_display_p3_linear
#define EGL_EXT_gl_colorspace_display_p3_linear 1
#define EGL_GL_COLORSPACE_DISPLAY_P3_LINEAR_EXT 0x3362
#endif /* EGL_EXT_gl_colorspace_display_p3_linear */

#ifndef EGL_EXT_gl_colorspace_display_p3_passthrough
#define EGL_EXT_gl_colorspace_display_p3_passthrough 1
#define EGL_GL_COLORSPACE_DISPLAY_P3_PASSTHROUGH_EXT 0x3490
#endif /* EGL_EXT_gl_colorspace_display_p3_passthrough */

#ifndef EGL_EXT_gl_colorspace_scrgb
#define EGL_EXT_gl_colorspace_scrgb 1
#define EGL_GL_COLORSPACE_SCRGB_EXT       0x3351
#endif /* EGL_EXT_gl_colorspace_scrgb */

#ifndef EGL_EXT_gl_colorspace_scrgb_linear
#define EGL_EXT_gl_colorspace_scrgb_linear 1
#define EGL_GL_COLORSPACE_SCRGB_LINEAR_EXT 0x3350
#endif /* EGL_EXT_gl_colorspace_scrgb_linear */

#ifndef EGL_EXT_image_dma_buf_import
#define EGL_EXT_image_dma_buf_import 1
#define EGL_LINUX_DMA_BUF_EXT             0x3270
#define EGL_LINUX_DRM_FOURCC_EXT          0x3271
#define EGL_DMA_BUF_PLANE0_FD_EXT         0x3272
#define EGL_DMA_BUF_PLANE0_OFFSET_EXT     0x3273
#define EGL_DMA_BUF_PLANE0_PITCH_EXT      0x3274
#define EGL_DMA_BUF_PLANE1_FD_EXT         0x3275
#define EGL_DMA_BUF_PLANE1_OFFSET_EXT     0x3276
#define EGL_DMA_BUF_PLANE1_PITCH_EXT      0x3277
#define EGL_DMA_BUF_PLANE2_FD_EXT         0x3278
#define EGL_DMA_BUF_PLANE2_OFFSET_EXT     0x3279
#define EGL_DMA_BUF_PLANE2_PITCH_EXT      0x327A
#define EGL_YUV_COLOR_SPACE_HINT_EXT      0x327B
#define EGL_SAMPLE_RANGE_HINT_EXT         0x327C
#define EGL_YUV_CHROMA_HORIZONTAL_SITING_HINT_EXT 0x327D
#define EGL_YUV_CHROMA_VERTICAL_SITING_HINT_EXT 0x327E
#define EGL_ITU_REC601_EXT                0x327F
#define EGL_ITU_REC709_EXT                0x3280
#define EGL_ITU_REC2020_EXT               0x3281
#define EGL_YUV_FULL_RANGE_EXT            0x3282
#define EGL_YUV_NARROW_RANGE_EXT          0x3283
#define EGL_YUV_CHROMA_SITING_0_EXT       0x3284
#define EGL_YUV_CHROMA_SITING_0_5_EXT     0x3285
#endif /* EGL_EXT_image_dma_buf_import */

#ifndef EGL_EXT_image_dma_buf_import_modifiers
#define EGL_EXT_image_dma_buf_import_modifiers 1
#define EGL_DMA_BUF_PLANE3_FD_EXT         0x3440
#define EGL_DMA_BUF_PLANE3_OFFSET_EXT     0x3441
#define EGL_DMA_BUF_PLANE3_PITCH_EXT      0x3442
#define EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT 0x3443
#define EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT 0x3444
#define EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT 0x3445
#define EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT 0x3446
#define EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT 0x3447
#define EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT 0x3448
#define EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT 0x3449
#define EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT 0x344A
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDMABUFFORMATSEXTPROC) (EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDMABUFMODIFIERSEXTPROC) (EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDmaBufFormatsEXT (EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDmaBufModifiersEXT (EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers);
#endif
#endif /* EGL_EXT_image_dma_buf_import_modifiers */

#ifndef EGL_EXT_image_gl_colorspace
#define EGL_EXT_image_gl_colorspace 1
#define EGL_GL_COLORSPACE_DEFAULT_EXT     0x314D
#endif /* EGL_EXT_image_gl_colorspace */

#ifndef EGL_EXT_image_implicit_sync_control
#define EGL_EXT_image_implicit_sync_control 1
#define EGL_IMPORT_SYNC_TYPE_EXT          0x3470
#define EGL_IMPORT_IMPLICIT_SYNC_EXT      0x3471
#define EGL_IMPORT_EXPLICIT_SYNC_EXT      0x3472
#endif /* EGL_EXT_image_implicit_sync_control */

#ifndef EGL_EXT_multiview_window
#define EGL_EXT_multiview_window 1
#define EGL_MULTIVIEW_VIEW_COUNT_EXT      0x3134
#endif /* EGL_EXT_multiview_window */

#ifndef EGL_EXT_output_base
#define EGL_EXT_output_base 1
typedef void *EGLOutputLayerEXT;
typedef void *EGLOutputPortEXT;
#define EGL_NO_OUTPUT_LAYER_EXT           EGL_CAST(EGLOutputLayerEXT,0)
#define EGL_NO_OUTPUT_PORT_EXT            EGL_CAST(EGLOutputPortEXT,0)
#define EGL_BAD_OUTPUT_LAYER_EXT          0x322D
#define EGL_BAD_OUTPUT_PORT_EXT           0x322E
#define EGL_SWAP_INTERVAL_EXT             0x322F
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETOUTPUTLAYERSEXTPROC) (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputLayerEXT *layers, EGLint max_layers, EGLint *num_layers);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETOUTPUTPORTSEXTPROC) (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputPortEXT *ports, EGLint max_ports, EGLint *num_ports);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLOUTPUTLAYERATTRIBEXTPROC) (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib value);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYOUTPUTLAYERATTRIBEXTPROC) (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib *value);
typedef const char *(EGLAPIENTRYP PFNEGLQUERYOUTPUTLAYERSTRINGEXTPROC) (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint name);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLOUTPUTPORTATTRIBEXTPROC) (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib value);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYOUTPUTPORTATTRIBEXTPROC) (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib *value);
typedef const char *(EGLAPIENTRYP PFNEGLQUERYOUTPUTPORTSTRINGEXTPROC) (EGLDisplay dpy, EGLOutputPortEXT port, EGLint name);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglGetOutputLayersEXT (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputLayerEXT *layers, EGLint max_layers, EGLint *num_layers);
EGLAPI EGLBoolean EGLAPIENTRY eglGetOutputPortsEXT (EGLDisplay dpy, const EGLAttrib *attrib_list, EGLOutputPortEXT *ports, EGLint max_ports, EGLint *num_ports);
EGLAPI EGLBoolean EGLAPIENTRY eglOutputLayerAttribEXT (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib value);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryOutputLayerAttribEXT (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib *value);
EGLAPI const char *EGLAPIENTRY eglQueryOutputLayerStringEXT (EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint name);
EGLAPI EGLBoolean EGLAPIENTRY eglOutputPortAttribEXT (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib value);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryOutputPortAttribEXT (EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib *value);
EGLAPI const char *EGLAPIENTRY eglQueryOutputPortStringEXT (EGLDisplay dpy, EGLOutputPortEXT port, EGLint name);
#endif
#endif /* EGL_EXT_output_base */

#ifndef EGL_EXT_output_drm
#define EGL_EXT_output_drm 1
#define EGL_DRM_CRTC_EXT                  0x3234
#define EGL_DRM_PLANE_EXT                 0x3235
#define EGL_DRM_CONNECTOR_EXT             0x3236
#endif /* EGL_EXT_output_drm */

#ifndef EGL_EXT_output_openwf
#define EGL_EXT_output_openwf 1
#define EGL_OPENWF_PIPELINE_ID_EXT        0x3238
#define EGL_OPENWF_PORT_ID_EXT            0x3239
#endif /* EGL_EXT_output_openwf */

#ifndef EGL_EXT_pixel_format_float
#define EGL_EXT_pixel_format_float 1
#define EGL_COLOR_COMPONENT_TYPE_EXT      0x3339
#define EGL_COLOR_COMPONENT_TYPE_FIXED_EXT 0x333A
#define EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT 0x333B
#endif /* EGL_EXT_pixel_format_float */

#ifndef EGL_EXT_platform_base
#define EGL_EXT_platform_base 1
typedef EGLDisplay (EGLAPIENTRYP PFNEGLGETPLATFORMDISPLAYEXTPROC) (EGLenum platform, void *native_display, const EGLint *attrib_list);
typedef EGLSurface (EGLAPIENTRYP PFNEGLCREATEPLATFORMWINDOWSURFACEEXTPROC) (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list);
typedef EGLSurface (EGLAPIENTRYP PFNEGLCREATEPLATFORMPIXMAPSURFACEEXTPROC) (EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLDisplay EGLAPIENTRY eglGetPlatformDisplayEXT (EGLenum platform, void *native_display, const EGLint *attrib_list);
EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurfaceEXT (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLint *attrib_list);
EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurfaceEXT (EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLint *attrib_list);
#endif
#endif /* EGL_EXT_platform_base */

#ifndef EGL_EXT_platform_device
#define EGL_EXT_platform_device 1
#define EGL_PLATFORM_DEVICE_EXT           0x313F
#endif /* EGL_EXT_platform_device */

#ifndef EGL_EXT_platform_wayland
#define EGL_EXT_platform_wayland 1
#define EGL_PLATFORM_WAYLAND_EXT          0x31D8
#endif /* EGL_EXT_platform_wayland */

#ifndef EGL_EXT_platform_x11
#define EGL_EXT_platform_x11 1
#define EGL_PLATFORM_X11_EXT              0x31D5
#define EGL_PLATFORM_X11_SCREEN_EXT       0x31D6
#endif /* EGL_EXT_platform_x11 */

#ifndef EGL_EXT_platform_xcb
#define EGL_EXT_platform_xcb 1
#define EGL_PLATFORM_XCB_EXT              0x31DC
#define EGL_PLATFORM_XCB_SCREEN_EXT       0x31DE
#endif /* EGL_EXT_platform_xcb */

#ifndef EGL_EXT_present_opaque
#define EGL_EXT_present_opaque 1
#define EGL_PRESENT_OPAQUE_EXT            0x31DF
#endif /* EGL_EXT_present_opaque */

#ifndef EGL_EXT_protected_content
#define EGL_EXT_protected_content 1
#define EGL_PROTECTED_CONTENT_EXT         0x32C0
#endif /* EGL_EXT_protected_content */

#ifndef EGL_EXT_protected_surface
#define EGL_EXT_protected_surface 1
#endif /* EGL_EXT_protected_surface */

#ifndef EGL_EXT_stream_consumer_egloutput
#define EGL_EXT_stream_consumer_egloutput 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMCONSUMEROUTPUTEXTPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLOutputLayerEXT layer);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglStreamConsumerOutputEXT (EGLDisplay dpy, EGLStreamKHR stream, EGLOutputLayerEXT layer);
#endif
#endif /* EGL_EXT_stream_consumer_egloutput */

#ifndef EGL_EXT_surface_CTA861_3_metadata
#define EGL_EXT_surface_CTA861_3_metadata 1
#define EGL_CTA861_3_MAX_CONTENT_LIGHT_LEVEL_EXT 0x3360
#define EGL_CTA861_3_MAX_FRAME_AVERAGE_LEVEL_EXT 0x3361
#endif /* EGL_EXT_surface_CTA861_3_metadata */

#ifndef EGL_EXT_surface_SMPTE2086_metadata
#define EGL_EXT_surface_SMPTE2086_metadata 1
#define EGL_SMPTE2086_DISPLAY_PRIMARY_RX_EXT 0x3341
#define EGL_SMPTE2086_DISPLAY_PRIMARY_RY_EXT 0x3342
#define EGL_SMPTE2086_DISPLAY_PRIMARY_GX_EXT 0x3343
#define EGL_SMPTE2086_DISPLAY_PRIMARY_GY_EXT 0x3344
#define EGL_SMPTE2086_DISPLAY_PRIMARY_BX_EXT 0x3345
#define EGL_SMPTE2086_DISPLAY_PRIMARY_BY_EXT 0x3346
#define EGL_SMPTE2086_WHITE_POINT_X_EXT   0x3347
#define EGL_SMPTE2086_WHITE_POINT_Y_EXT   0x3348
#define EGL_SMPTE2086_MAX_LUMINANCE_EXT   0x3349
#define EGL_SMPTE2086_MIN_LUMINANCE_EXT   0x334A
#define EGL_METADATA_SCALING_EXT          50000
#endif /* EGL_EXT_surface_SMPTE2086_metadata */

#ifndef EGL_EXT_swap_buffers_with_damage
#define EGL_EXT_swap_buffers_with_damage 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSWAPBUFFERSWITHDAMAGEEXTPROC) (EGLDisplay dpy, EGLSurface surface, const EGLint *rects, EGLint n_rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersWithDamageEXT (EGLDisplay dpy, EGLSurface surface, const EGLint *rects, EGLint n_rects);
#endif
#endif /* EGL_EXT_swap_buffers_with_damage */

#ifndef EGL_EXT_sync_reuse
#define EGL_EXT_sync_reuse 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLUNSIGNALSYNCEXTPROC) (EGLDisplay dpy, EGLSync sync, const EGLAttrib *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglUnsignalSyncEXT (EGLDisplay dpy, EGLSync sync, const EGLAttrib *attrib_list);
#endif
#endif /* EGL_EXT_sync_reuse */

#ifndef EGL_EXT_yuv_surface
#define EGL_EXT_yuv_surface 1
#define EGL_YUV_ORDER_EXT                 0x3301
#define EGL_YUV_NUMBER_OF_PLANES_EXT      0x3311
#define EGL_YUV_SUBSAMPLE_EXT             0x3312
#define EGL_YUV_DEPTH_RANGE_EXT           0x3317
#define EGL_YUV_CSC_STANDARD_EXT          0x330A
#define EGL_YUV_PLANE_BPP_EXT             0x331A
#define EGL_YUV_BUFFER_EXT                0x3300
#define EGL_YUV_ORDER_YUV_EXT             0x3302
#define EGL_YUV_ORDER_YVU_EXT             0x3303
#define EGL_YUV_ORDER_YUYV_EXT            0x3304
#define EGL_YUV_ORDER_UYVY_EXT            0x3305
#define EGL_YUV_ORDER_YVYU_EXT            0x3306
#define EGL_YUV_ORDER_VYUY_EXT            0x3307
#define EGL_YUV_ORDER_AYUV_EXT            0x3308
#define EGL_YUV_SUBSAMPLE_4_2_0_EXT       0x3313
#define EGL_YUV_SUBSAMPLE_4_2_2_EXT       0x3314
#define EGL_YUV_SUBSAMPLE_4_4_4_EXT       0x3315
#define EGL_YUV_DEPTH_RANGE_LIMITED_EXT   0x3318
#define EGL_YUV_DEPTH_RANGE_FULL_EXT      0x3319
#define EGL_YUV_CSC_STANDARD_601_EXT      0x330B
#define EGL_YUV_CSC_STANDARD_709_EXT      0x330C
#define EGL_YUV_CSC_STANDARD_2020_EXT     0x330D
#define EGL_YUV_PLANE_BPP_0_EXT           0x331B
#define EGL_YUV_PLANE_BPP_8_EXT           0x331C
#define EGL_YUV_PLANE_BPP_10_EXT          0x331D
#endif /* EGL_EXT_yuv_surface */

#ifndef EGL_HI_clientpixmap
#define EGL_HI_clientpixmap 1
struct EGLClientPixmapHI {
    void  *pData;
    EGLint iWidth;
    EGLint iHeight;
    EGLint iStride;
};
#define EGL_CLIENT_PIXMAP_POINTER_HI      0x8F74
typedef EGLSurface (EGLAPIENTRYP PFNEGLCREATEPIXMAPSURFACEHIPROC) (EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI *pixmap);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLSurface EGLAPIENTRY eglCreatePixmapSurfaceHI (EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI *pixmap);
#endif
#endif /* EGL_HI_clientpixmap */

#ifndef EGL_HI_colorformats
#define EGL_HI_colorformats 1
#define EGL_COLOR_FORMAT_HI               0x8F70
#define EGL_COLOR_RGB_HI                  0x8F71
#define EGL_COLOR_RGBA_HI                 0x8F72
#define EGL_COLOR_ARGB_HI                 0x8F73
#endif /* EGL_HI_colorformats */

#ifndef EGL_IMG_context_priority
#define EGL_IMG_context_priority 1
#define EGL_CONTEXT_PRIORITY_LEVEL_IMG    0x3100
#define EGL_CONTEXT_PRIORITY_HIGH_IMG     0x3101
#define EGL_CONTEXT_PRIORITY_MEDIUM_IMG   0x3102
#define EGL_CONTEXT_PRIORITY_LOW_IMG      0x3103
#endif /* EGL_IMG_context_priority */

#ifndef EGL_IMG_image_plane_attribs
#define EGL_IMG_image_plane_attribs 1
#define EGL_NATIVE_BUFFER_MULTIPLANE_SEPARATE_IMG 0x3105
#define EGL_NATIVE_BUFFER_PLANE_OFFSET_IMG 0x3106
#endif /* EGL_IMG_image_plane_attribs */

#ifndef EGL_MESA_drm_image
#define EGL_MESA_drm_image 1
#define EGL_DRM_BUFFER_FORMAT_MESA        0x31D0
#define EGL_DRM_BUFFER_USE_MESA           0x31D1
#define EGL_DRM_BUFFER_FORMAT_ARGB32_MESA 0x31D2
#define EGL_DRM_BUFFER_MESA               0x31D3
#define EGL_DRM_BUFFER_STRIDE_MESA        0x31D4
#define EGL_DRM_BUFFER_USE_SCANOUT_MESA   0x00000001
#define EGL_DRM_BUFFER_USE_SHARE_MESA     0x00000002
#define EGL_DRM_BUFFER_USE_CURSOR_MESA    0x00000004
typedef EGLImageKHR (EGLAPIENTRYP PFNEGLCREATEDRMIMAGEMESAPROC) (EGLDisplay dpy, const EGLint *attrib_list);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLEXPORTDRMIMAGEMESAPROC) (EGLDisplay dpy, EGLImageKHR image, EGLint *name, EGLint *handle, EGLint *stride);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLImageKHR EGLAPIENTRY eglCreateDRMImageMESA (EGLDisplay dpy, const EGLint *attrib_list);
EGLAPI EGLBoolean EGLAPIENTRY eglExportDRMImageMESA (EGLDisplay dpy, EGLImageKHR image, EGLint *name, EGLint *handle, EGLint *stride);
#endif
#endif /* EGL_MESA_drm_image */

#ifndef EGL_MESA_image_dma_buf_export
#define EGL_MESA_image_dma_buf_export 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLEXPORTDMABUFIMAGEQUERYMESAPROC) (EGLDisplay dpy, EGLImageKHR image, int *fourcc, int *num_planes, EGLuint64KHR *modifiers);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLEXPORTDMABUFIMAGEMESAPROC) (EGLDisplay dpy, EGLImageKHR image, int *fds, EGLint *strides, EGLint *offsets);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglExportDMABUFImageQueryMESA (EGLDisplay dpy, EGLImageKHR image, int *fourcc, int *num_planes, EGLuint64KHR *modifiers);
EGLAPI EGLBoolean EGLAPIENTRY eglExportDMABUFImageMESA (EGLDisplay dpy, EGLImageKHR image, int *fds, EGLint *strides, EGLint *offsets);
#endif
#endif /* EGL_MESA_image_dma_buf_export */

#ifndef EGL_MESA_platform_gbm
#define EGL_MESA_platform_gbm 1
#define EGL_PLATFORM_GBM_MESA             0x31D7
#endif /* EGL_MESA_platform_gbm */

#ifndef EGL_MESA_platform_surfaceless
#define EGL_MESA_platform_surfaceless 1
#define EGL_PLATFORM_SURFACELESS_MESA     0x31DD
#endif /* EGL_MESA_platform_surfaceless */

#ifndef EGL_MESA_query_driver
#define EGL_MESA_query_driver 1
typedef char *(EGLAPIENTRYP PFNEGLGETDISPLAYDRIVERCONFIGPROC) (EGLDisplay dpy);
typedef const char *(EGLAPIENTRYP PFNEGLGETDISPLAYDRIVERNAMEPROC) (EGLDisplay dpy);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI char *EGLAPIENTRY eglGetDisplayDriverConfig (EGLDisplay dpy);
EGLAPI const char *EGLAPIENTRY eglGetDisplayDriverName (EGLDisplay dpy);
#endif
#endif /* EGL_MESA_query_driver */

#ifndef EGL_NOK_swap_region
#define EGL_NOK_swap_region 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSWAPBUFFERSREGIONNOKPROC) (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersRegionNOK (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects);
#endif
#endif /* EGL_NOK_swap_region */

#ifndef EGL_NOK_swap_region2
#define EGL_NOK_swap_region2 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSWAPBUFFERSREGION2NOKPROC) (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffersRegion2NOK (EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint *rects);
#endif
#endif /* EGL_NOK_swap_region2 */

#ifndef EGL_NOK_texture_from_pixmap
#define EGL_NOK_texture_from_pixmap 1
#define EGL_Y_INVERTED_NOK                0x307F
#endif /* EGL_NOK_texture_from_pixmap */

#ifndef EGL_NV_3dvision_surface
#define EGL_NV_3dvision_surface 1
#define EGL_AUTO_STEREO_NV                0x3136
#endif /* EGL_NV_3dvision_surface */

#ifndef EGL_NV_context_priority_realtime
#define EGL_NV_context_priority_realtime 1
#define EGL_CONTEXT_PRIORITY_REALTIME_NV  0x3357
#endif /* EGL_NV_context_priority_realtime */

#ifndef EGL_NV_coverage_sample
#define EGL_NV_coverage_sample 1
#define EGL_COVERAGE_BUFFERS_NV           0x30E0
#define EGL_COVERAGE_SAMPLES_NV           0x30E1
#endif /* EGL_NV_coverage_sample */

#ifndef EGL_NV_coverage_sample_resolve
#define EGL_NV_coverage_sample_resolve 1
#define EGL_COVERAGE_SAMPLE_RESOLVE_NV    0x3131
#define EGL_COVERAGE_SAMPLE_RESOLVE_DEFAULT_NV 0x3132
#define EGL_COVERAGE_SAMPLE_RESOLVE_NONE_NV 0x3133
#endif /* EGL_NV_coverage_sample_resolve */

#ifndef EGL_NV_cuda_event
#define EGL_NV_cuda_event 1
#define EGL_CUDA_EVENT_HANDLE_NV          0x323B
#define EGL_SYNC_CUDA_EVENT_NV            0x323C
#define EGL_SYNC_CUDA_EVENT_COMPLETE_NV   0x323D
#endif /* EGL_NV_cuda_event */

#ifndef EGL_NV_depth_nonlinear
#define EGL_NV_depth_nonlinear 1
#define EGL_DEPTH_ENCODING_NV             0x30E2
#define EGL_DEPTH_ENCODING_NONE_NV        0
#define EGL_DEPTH_ENCODING_NONLINEAR_NV   0x30E3
#endif /* EGL_NV_depth_nonlinear */

#ifndef EGL_NV_device_cuda
#define EGL_NV_device_cuda 1
#define EGL_CUDA_DEVICE_NV                0x323A
#endif /* EGL_NV_device_cuda */

#ifndef EGL_NV_native_query
#define EGL_NV_native_query 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYNATIVEDISPLAYNVPROC) (EGLDisplay dpy, EGLNativeDisplayType *display_id);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYNATIVEWINDOWNVPROC) (EGLDisplay dpy, EGLSurface surf, EGLNativeWindowType *window);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYNATIVEPIXMAPNVPROC) (EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType *pixmap);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryNativeDisplayNV (EGLDisplay dpy, EGLNativeDisplayType *display_id);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryNativeWindowNV (EGLDisplay dpy, EGLSurface surf, EGLNativeWindowType *window);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryNativePixmapNV (EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType *pixmap);
#endif
#endif /* EGL_NV_native_query */

#ifndef EGL_NV_post_convert_rounding
#define EGL_NV_post_convert_rounding 1
#endif /* EGL_NV_post_convert_rounding */

#ifndef EGL_NV_post_sub_buffer
#define EGL_NV_post_sub_buffer 1
#define EGL_POST_SUB_BUFFER_SUPPORTED_NV  0x30BE
typedef EGLBoolean (EGLAPIENTRYP PFNEGLPOSTSUBBUFFERNVPROC) (EGLDisplay dpy, EGLSurface surface, EGLint x, EGLint y, EGLint width, EGLint height);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglPostSubBufferNV (EGLDisplay dpy, EGLSurface surface, EGLint x, EGLint y, EGLint width, EGLint height);
#endif
#endif /* EGL_NV_post_sub_buffer */

#ifndef EGL_NV_quadruple_buffer
#define EGL_NV_quadruple_buffer 1
#define EGL_QUADRUPLE_BUFFER_NV           0x3231
#endif /* EGL_NV_quadruple_buffer */

#ifndef EGL_NV_robustness_video_memory_purge
#define EGL_NV_robustness_video_memory_purge 1
#define EGL_GENERATE_RESET_ON_VIDEO_MEMORY_PURGE_NV 0x334C
#endif /* EGL_NV_robustness_video_memory_purge */

#ifndef EGL_NV_stream_consumer_eglimage
#define EGL_NV_stream_consumer_eglimage 1
#define EGL_STREAM_CONSUMER_IMAGE_NV      0x3373
#define EGL_STREAM_IMAGE_ADD_NV           0x3374
#define EGL_STREAM_IMAGE_REMOVE_NV        0x3375
#define EGL_STREAM_IMAGE_AVAILABLE_NV     0x3376
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMIMAGECONSUMERCONNECTNVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLint num_modifiers, EGLuint64KHR *modifiers, EGLAttrib *attrib_list);
typedef EGLint (EGLAPIENTRYP PFNEGLQUERYSTREAMCONSUMEREVENTNVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLTime timeout, EGLenum *event, EGLAttrib *aux);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMACQUIREIMAGENVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLImage *pImage, EGLSync sync);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMRELEASEIMAGENVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLImage image, EGLSync sync);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglStreamImageConsumerConnectNV (EGLDisplay dpy, EGLStreamKHR stream, EGLint num_modifiers, EGLuint64KHR *modifiers, EGLAttrib *attrib_list);
EGLAPI EGLint EGLAPIENTRY eglQueryStreamConsumerEventNV (EGLDisplay dpy, EGLStreamKHR stream, EGLTime timeout, EGLenum *event, EGLAttrib *aux);
EGLAPI EGLBoolean EGLAPIENTRY eglStreamAcquireImageNV (EGLDisplay dpy, EGLStreamKHR stream, EGLImage *pImage, EGLSync sync);
EGLAPI EGLBoolean EGLAPIENTRY eglStreamReleaseImageNV (EGLDisplay dpy, EGLStreamKHR stream, EGLImage image, EGLSync sync);
#endif
#endif /* EGL_NV_stream_consumer_eglimage */

#ifndef EGL_NV_stream_consumer_gltexture_yuv
#define EGL_NV_stream_consumer_gltexture_yuv 1
#define EGL_YUV_PLANE0_TEXTURE_UNIT_NV    0x332C
#define EGL_YUV_PLANE1_TEXTURE_UNIT_NV    0x332D
#define EGL_YUV_PLANE2_TEXTURE_UNIT_NV    0x332E
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMCONSUMERGLTEXTUREEXTERNALATTRIBSNVPROC) (EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglStreamConsumerGLTextureExternalAttribsNV (EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib *attrib_list);
#endif
#endif /* EGL_NV_stream_consumer_gltexture_yuv */

#ifndef EGL_NV_stream_cross_display
#define EGL_NV_stream_cross_display 1
#define EGL_STREAM_CROSS_DISPLAY_NV       0x334E
#endif /* EGL_NV_stream_cross_display */

#ifndef EGL_NV_stream_cross_object
#define EGL_NV_stream_cross_object 1
#define EGL_STREAM_CROSS_OBJECT_NV        0x334D
#endif /* EGL_NV_stream_cross_object */

#ifndef EGL_NV_stream_cross_partition
#define EGL_NV_stream_cross_partition 1
#define EGL_STREAM_CROSS_PARTITION_NV     0x323F
#endif /* EGL_NV_stream_cross_partition */

#ifndef EGL_NV_stream_cross_process
#define EGL_NV_stream_cross_process 1
#define EGL_STREAM_CROSS_PROCESS_NV       0x3245
#endif /* EGL_NV_stream_cross_process */

#ifndef EGL_NV_stream_cross_system
#define EGL_NV_stream_cross_system 1
#define EGL_STREAM_CROSS_SYSTEM_NV        0x334F
#endif /* EGL_NV_stream_cross_system */

#ifndef EGL_NV_stream_dma
#define EGL_NV_stream_dma 1
#define EGL_STREAM_DMA_NV                 0x3371
#define EGL_STREAM_DMA_SERVER_NV          0x3372
#endif /* EGL_NV_stream_dma */

#ifndef EGL_NV_stream_fifo_next
#define EGL_NV_stream_fifo_next 1
#define EGL_PENDING_FRAME_NV              0x3329
#define EGL_STREAM_TIME_PENDING_NV        0x332A
#endif /* EGL_NV_stream_fifo_next */

#ifndef EGL_NV_stream_fifo_synchronous
#define EGL_NV_stream_fifo_synchronous 1
#define EGL_STREAM_FIFO_SYNCHRONOUS_NV    0x3336
#endif /* EGL_NV_stream_fifo_synchronous */

#ifndef EGL_NV_stream_flush
#define EGL_NV_stream_flush 1
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSTREAMFLUSHNVPROC) (EGLDisplay dpy, EGLStreamKHR stream);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglStreamFlushNV (EGLDisplay dpy, EGLStreamKHR stream);
#endif
#endif /* EGL_NV_stream_flush */

#ifndef EGL_NV_stream_frame_limits
#define EGL_NV_stream_frame_limits 1
#define EGL_PRODUCER_MAX_FRAME_HINT_NV    0x3337
#define EGL_CONSUMER_MAX_FRAME_HINT_NV    0x3338
#endif /* EGL_NV_stream_frame_limits */

#ifndef EGL_NV_stream_metadata
#define EGL_NV_stream_metadata 1
#define EGL_MAX_STREAM_METADATA_BLOCKS_NV 0x3250
#define EGL_MAX_STREAM_METADATA_BLOCK_SIZE_NV 0x3251
#define EGL_MAX_STREAM_METADATA_TOTAL_SIZE_NV 0x3252
#define EGL_PRODUCER_METADATA_NV          0x3253
#define EGL_CONSUMER_METADATA_NV          0x3254
#define EGL_PENDING_METADATA_NV           0x3328
#define EGL_METADATA0_SIZE_NV             0x3255
#define EGL_METADATA1_SIZE_NV             0x3256
#define EGL_METADATA2_SIZE_NV             0x3257
#define EGL_METADATA3_SIZE_NV             0x3258
#define EGL_METADATA0_TYPE_NV             0x3259
#define EGL_METADATA1_TYPE_NV             0x325A
#define EGL_METADATA2_TYPE_NV             0x325B
#define EGL_METADATA3_TYPE_NV             0x325C
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDISPLAYATTRIBNVPROC) (EGLDisplay dpy, EGLint attribute, EGLAttrib *value);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSETSTREAMMETADATANVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLint n, EGLint offset, EGLint size, const void *data);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYSTREAMMETADATANVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLenum name, EGLint n, EGLint offset, EGLint size, void *data);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglQueryDisplayAttribNV (EGLDisplay dpy, EGLint attribute, EGLAttrib *value);
EGLAPI EGLBoolean EGLAPIENTRY eglSetStreamMetadataNV (EGLDisplay dpy, EGLStreamKHR stream, EGLint n, EGLint offset, EGLint size, const void *data);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryStreamMetadataNV (EGLDisplay dpy, EGLStreamKHR stream, EGLenum name, EGLint n, EGLint offset, EGLint size, void *data);
#endif
#endif /* EGL_NV_stream_metadata */

#ifndef EGL_NV_stream_origin
#define EGL_NV_stream_origin 1
#define EGL_STREAM_FRAME_ORIGIN_X_NV      0x3366
#define EGL_STREAM_FRAME_ORIGIN_Y_NV      0x3367
#define EGL_STREAM_FRAME_MAJOR_AXIS_NV    0x3368
#define EGL_CONSUMER_AUTO_ORIENTATION_NV  0x3369
#define EGL_PRODUCER_AUTO_ORIENTATION_NV  0x336A
#define EGL_LEFT_NV                       0x336B
#define EGL_RIGHT_NV                      0x336C
#define EGL_TOP_NV                        0x336D
#define EGL_BOTTOM_NV                     0x336E
#define EGL_X_AXIS_NV                     0x336F
#define EGL_Y_AXIS_NV                     0x3370
#endif /* EGL_NV_stream_origin */

#ifndef EGL_NV_stream_remote
#define EGL_NV_stream_remote 1
#define EGL_STREAM_STATE_INITIALIZING_NV  0x3240
#define EGL_STREAM_TYPE_NV                0x3241
#define EGL_STREAM_PROTOCOL_NV            0x3242
#define EGL_STREAM_ENDPOINT_NV            0x3243
#define EGL_STREAM_LOCAL_NV               0x3244
#define EGL_STREAM_PRODUCER_NV            0x3247
#define EGL_STREAM_CONSUMER_NV            0x3248
#define EGL_STREAM_PROTOCOL_FD_NV         0x3246
#endif /* EGL_NV_stream_remote */

#ifndef EGL_NV_stream_reset
#define EGL_NV_stream_reset 1
#define EGL_SUPPORT_RESET_NV              0x3334
#define EGL_SUPPORT_REUSE_NV              0x3335
typedef EGLBoolean (EGLAPIENTRYP PFNEGLRESETSTREAMNVPROC) (EGLDisplay dpy, EGLStreamKHR stream);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglResetStreamNV (EGLDisplay dpy, EGLStreamKHR stream);
#endif
#endif /* EGL_NV_stream_reset */

#ifndef EGL_NV_stream_socket
#define EGL_NV_stream_socket 1
#define EGL_STREAM_PROTOCOL_SOCKET_NV     0x324B
#define EGL_SOCKET_HANDLE_NV              0x324C
#define EGL_SOCKET_TYPE_NV                0x324D
#endif /* EGL_NV_stream_socket */

#ifndef EGL_NV_stream_socket_inet
#define EGL_NV_stream_socket_inet 1
#define EGL_SOCKET_TYPE_INET_NV           0x324F
#endif /* EGL_NV_stream_socket_inet */

#ifndef EGL_NV_stream_socket_unix
#define EGL_NV_stream_socket_unix 1
#define EGL_SOCKET_TYPE_UNIX_NV           0x324E
#endif /* EGL_NV_stream_socket_unix */

#ifndef EGL_NV_stream_sync
#define EGL_NV_stream_sync 1
#define EGL_SYNC_NEW_FRAME_NV             0x321F
typedef EGLSyncKHR (EGLAPIENTRYP PFNEGLCREATESTREAMSYNCNVPROC) (EGLDisplay dpy, EGLStreamKHR stream, EGLenum type, const EGLint *attrib_list);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLSyncKHR EGLAPIENTRY eglCreateStreamSyncNV (EGLDisplay dpy, EGLStreamKHR stream, EGLenum type, const EGLint *attrib_list);
#endif
#endif /* EGL_NV_stream_sync */

#ifndef EGL_NV_sync
#define EGL_NV_sync 1
typedef void *EGLSyncNV;
typedef khronos_utime_nanoseconds_t EGLTimeNV;
#ifdef KHRONOS_SUPPORT_INT64
#define EGL_SYNC_PRIOR_COMMANDS_COMPLETE_NV 0x30E6
#define EGL_SYNC_STATUS_NV                0x30E7
#define EGL_SIGNALED_NV                   0x30E8
#define EGL_UNSIGNALED_NV                 0x30E9
#define EGL_SYNC_FLUSH_COMMANDS_BIT_NV    0x0001
#define EGL_FOREVER_NV                    0xFFFFFFFFFFFFFFFFull
#define EGL_ALREADY_SIGNALED_NV           0x30EA
#define EGL_TIMEOUT_EXPIRED_NV            0x30EB
#define EGL_CONDITION_SATISFIED_NV        0x30EC
#define EGL_SYNC_TYPE_NV                  0x30ED
#define EGL_SYNC_CONDITION_NV             0x30EE
#define EGL_SYNC_FENCE_NV                 0x30EF
#define EGL_NO_SYNC_NV                    EGL_CAST(EGLSyncNV,0)
typedef EGLSyncNV (EGLAPIENTRYP PFNEGLCREATEFENCESYNCNVPROC) (EGLDisplay dpy, EGLenum condition, const EGLint *attrib_list);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLDESTROYSYNCNVPROC) (EGLSyncNV sync);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLFENCENVPROC) (EGLSyncNV sync);
typedef EGLint (EGLAPIENTRYP PFNEGLCLIENTWAITSYNCNVPROC) (EGLSyncNV sync, EGLint flags, EGLTimeNV timeout);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLSIGNALSYNCNVPROC) (EGLSyncNV sync, EGLenum mode);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLGETSYNCATTRIBNVPROC) (EGLSyncNV sync, EGLint attribute, EGLint *value);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLSyncNV EGLAPIENTRY eglCreateFenceSyncNV (EGLDisplay dpy, EGLenum condition, const EGLint *attrib_list);
EGLAPI EGLBoolean EGLAPIENTRY eglDestroySyncNV (EGLSyncNV sync);
EGLAPI EGLBoolean EGLAPIENTRY eglFenceNV (EGLSyncNV sync);
EGLAPI EGLint EGLAPIENTRY eglClientWaitSyncNV (EGLSyncNV sync, EGLint flags, EGLTimeNV timeout);
EGLAPI EGLBoolean EGLAPIENTRY eglSignalSyncNV (EGLSyncNV sync, EGLenum mode);
EGLAPI EGLBoolean EGLAPIENTRY eglGetSyncAttribNV (EGLSyncNV sync, EGLint attribute, EGLint *value);
#endif
#endif /* KHRONOS_SUPPORT_INT64 */
#endif /* EGL_NV_sync */

#ifndef EGL_NV_system_time
#define EGL_NV_system_time 1
typedef khronos_utime_nanoseconds_t EGLuint64NV;
#ifdef KHRONOS_SUPPORT_INT64
typedef EGLuint64NV (EGLAPIENTRYP PFNEGLGETSYSTEMTIMEFREQUENCYNVPROC) (void);
typedef EGLuint64NV (EGLAPIENTRYP PFNEGLGETSYSTEMTIMENVPROC) (void);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLuint64NV EGLAPIENTRY eglGetSystemTimeFrequencyNV (void);
EGLAPI EGLuint64NV EGLAPIENTRY eglGetSystemTimeNV (void);
#endif
#endif /* KHRONOS_SUPPORT_INT64 */
#endif /* EGL_NV_system_time */

#ifndef EGL_NV_triple_buffer
#define EGL_NV_triple_buffer 1
#define EGL_TRIPLE_BUFFER_NV              0x3230
#endif /* EGL_NV_triple_buffer */

#ifndef EGL_TIZEN_image_native_buffer
#define EGL_TIZEN_image_native_buffer 1
#define EGL_NATIVE_BUFFER_TIZEN           0x32A0
#endif /* EGL_TIZEN_image_native_buffer */

#ifndef EGL_TIZEN_image_native_surface
#define EGL_TIZEN_image_native_surface 1
#define EGL_NATIVE_SURFACE_TIZEN          0x32A1
#endif /* EGL_TIZEN_image_native_surface */

#ifndef EGL_WL_bind_wayland_display
#define EGL_WL_bind_wayland_display 1
#define PFNEGLBINDWAYLANDDISPLAYWL PFNEGLBINDWAYLANDDISPLAYWLPROC
#define PFNEGLUNBINDWAYLANDDISPLAYWL PFNEGLUNBINDWAYLANDDISPLAYWLPROC
#define PFNEGLQUERYWAYLANDBUFFERWL PFNEGLQUERYWAYLANDBUFFERWLPROC
struct wl_display;
struct wl_resource;
#define EGL_WAYLAND_BUFFER_WL             0x31D5
#define EGL_WAYLAND_PLANE_WL              0x31D6
#define EGL_TEXTURE_Y_U_V_WL              0x31D7
#define EGL_TEXTURE_Y_UV_WL               0x31D8
#define EGL_TEXTURE_Y_XUXV_WL             0x31D9
#define EGL_TEXTURE_EXTERNAL_WL           0x31DA
#define EGL_WAYLAND_Y_INVERTED_WL         0x31DB
typedef EGLBoolean (EGLAPIENTRYP PFNEGLBINDWAYLANDDISPLAYWLPROC) (EGLDisplay dpy, struct wl_display *display);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLUNBINDWAYLANDDISPLAYWLPROC) (EGLDisplay dpy, struct wl_display *display);
typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYWAYLANDBUFFERWLPROC) (EGLDisplay dpy, struct wl_resource *buffer, EGLint attribute, EGLint *value);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI EGLBoolean EGLAPIENTRY eglBindWaylandDisplayWL (EGLDisplay dpy, struct wl_display *display);
EGLAPI EGLBoolean EGLAPIENTRY eglUnbindWaylandDisplayWL (EGLDisplay dpy, struct wl_display *display);
EGLAPI EGLBoolean EGLAPIENTRY eglQueryWaylandBufferWL (EGLDisplay dpy, struct wl_resource *buffer, EGLint attribute, EGLint *value);
#endif
#endif /* EGL_WL_bind_wayland_display */

#ifndef EGL_WL_create_wayland_buffer_from_image
#define EGL_WL_create_wayland_buffer_from_image 1
#define PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWL PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWLPROC
struct wl_buffer;
typedef struct wl_buffer *(EGLAPIENTRYP PFNEGLCREATEWAYLANDBUFFERFROMIMAGEWLPROC) (EGLDisplay dpy, EGLImageKHR image);
#ifdef EGL_EGLEXT_PROTOTYPES
EGLAPI struct wl_buffer *EGLAPIENTRY eglCreateWaylandBufferFromImageWL (EGLDisplay dpy, EGLImageKHR image);
#endif
#endif /* EGL_WL_create_wayland_buffer_from_image */

#ifdef __cplusplus
}
#endif

#endif /* __eglext_h_ */

#endif /* _MSC_VER */
