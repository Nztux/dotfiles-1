//------------------------------------------------------------
// DWM Configuration file
// Copyright (c) 2017 - blackcat <blackcat@dracos-linux.org>
// Updated on: 16-06-2017 06:51 AM
//------------------------------------------------------------

#include <X11/XF86keysym.h>

// Patches
#include "patches/restart.c"
#include "patches/zoomswap.c"
#include "patches/moveresize.c"
#include "patches/gaplessgrid.c"

// Appearance
#define NUMCOLORS 7
static const char colors[NUMCOLORS][MAXCOLORS][8] = {
//	 Border    Foreground  Background
   { "#515151", "#C5C8C6", "#1C1F22" },  // 1 = normal empty
   { "#C5C8C6", "#6e6e6e", "#1C1F22" },  // 2 = selected
   { "#000000", "#C5C8C6", "#1C1F22" },  // 3 = Occupied tag
   { "#000000", "#C5C8C6", "#1C1F22" },  // 4 = Layoutbar
   { "#000000", "#6e6e6e", "#1C1F22" },  // 5 = Titlebar
   { "#000000", "#C5C8C6", "#C5C8C6" },  // 6 = Status Text
   { "#000000", "#C5C8C6", "#C5C8C6" },  // 7 = Status Icon
};

static const char *fonts[]			     = { "drift:pixelsize=11", "Siji" };
static const unsigned int borderpx 		 = 1; 		// Border pixel of windows
static const unsigned int snap 			 = 11; 		// Snap pixel
static const unsigned int tagpadding 	 = 16; 		// Space between tags
static const unsigned int tagspacing 	 = 9; 		// Inner padding of tags
static const unsigned int gappx			 = 2; 		// Gaps pixel between windows
static const unsigned int systraypinning = 1; 		// 0 means sloppy systray follows selected monitor
static const unsigned int systrayspacing = 0; 		// Systray spacing
static const int systraypinningfailfirst = 1; 		// 0 means display systray on the last monitor
static const int showsystray 			 = 0; 		// 0 means no systray
static const Bool showbar 			     = False;	// False means no bar
static const Bool topbar 			     = True; 	// False means bottom bar

// Tags
static const char *tags[] = { " MAIN ", " WEB ", " FILES "," MISC "};

static const Rule rules[] = {
//	 Class		Instance    Title       Tags	      Isfloating   Monitor
	{ "Gcolor2",	NULL,       NULL,       0,            1,           -1 },
	{ "feh",		NULL,       NULL,       0,	      	  1,           -1 },
};

static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

// Layout Icons
static const Layout layouts[] = {
//	 Symbol    Arrange function */
	{ "",     NULL },
	{ "",     tile },
	{ "",     monocle },
	{ "",    	gaplessgrid },
};

// Key Definitions
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// Helper
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands
static char dmenumon[2] = "0";
static const char *dmenucmd[]   = { "dmenu_run", "-b","-p", "MENU", "-fn", "drift:pixelsize=12", "-lh", "24","-nf", "#D0D3D1", "-nb", "#1C1F22", "-sf", "#000000", "-sb", "#D0D3D1", NULL };
static const char *termcmd[]    = { "urxvt", NULL };
static const char *volup[]      = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *voldown[]    = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *scrot[]	= { "scrot", NULL };
static const char *oblogout[] = {"oblogout", NULL};

// Keybind
static Key keys[] = {
// Modifier				Key							Function        Argument
{ MODKEY|ShiftMask,     XK_d,						spawn,          {.v = dmenucmd } },
{ MODKEY|ShiftMask,     XK_Return,					spawn,          {.v = termcmd } },
{ MODKEY,				XK_q,						spawn,			{.v = oblogout } },
{ 0,					XF86XK_AudioRaiseVolume,	spawn,          {.v = volup } },
{ 0,					XF86XK_AudioLowerVolume,	spawn,          {.v = voldown } },
{ 0,					XK_Print,					spawn,			{.v = scrot } },
{ MODKEY|ShiftMask,		XK_b,						togglebar,		{0} },
{ MODKEY,               XK_Tab,     				focusstack,     {.i = +1 } },
{ MODKEY|ShiftMask,     XK_j,						movestack,      {.i = +1 } },
{ MODKEY|ShiftMask,     XK_k,						movestack,      {.i = -1 } },
{ MODKEY,               XK_i,						incnmaster,     {.i = +1 } },
{ MODKEY,               XK_d,						incnmaster,     {.i = -1 } },
{ MODKEY,               XK_h,						setmfact,       {.f = -0.05} },
{ MODKEY,               XK_l,						setmfact,       {.f = +0.05} },
{ MODKEY|ShiftMask,		XK_u,						setcfact,		{.f = -0.25} },
{ MODKEY|ShiftMask,		XK_i,						setcfact,		{.f = +0.25} },
{ MODKEY,				XK_o,						setcfact,		{.f =  0.00} },
{ MODKEY,				XK_Up,						moveresize,			{.v = "0x -25y 0w 0h"} },
{ MODKEY,				XK_Down,					moveresize,			{.v = "0x 25y 0w 0h"} },
{ MODKEY,				XK_Left,					moveresize,			{.v = "-25x 0y 0w 0h"} },
{ MODKEY,				XK_Right,					moveresize,			{.v = "25x 0y 0w 0h"} },
{ MODKEY|ShiftMask,		XK_Up,						moveresize,			{.v = "0x 0y 0w -25h"} },
{ MODKEY|ShiftMask,		XK_Down,					moveresize,			{.v = "0x 0y 0w 25h"} },
{ MODKEY|ShiftMask,		XK_Left,					moveresize,			{.v = "0x 0y -25w 0h"} },
{ MODKEY|ShiftMask,		XK_Right, 					moveresize, {.v = "0x 0y 25w 0h"} },
{ MODKEY,				XK_w,						killclient,     {0} },
{ MODKEY,               XK_f,						setlayout,      {.v = &layouts[0]} },
{ MODKEY,               XK_t,						setlayout,      {.v = &layouts[1]} },
{ MODKEY,               XK_m,						setlayout,      {.v = &layouts[2]} },
{ MODKEY,               XK_g,						setlayout,      {.v = &layouts[3]} },
{ MODKEY,				XK_u,						togglefullscreen,{0} },
{ MODKEY|ShiftMask,		XK_space,					togglefloating,	{0} },
{ MODKEY,				XK_0,						view,			{.ui = ~0 } },
{ MODKEY|ShiftMask,		XK_0,						tag,			{.ui = ~0 } },
{ MODKEY,				XK_comma,					focusmon,		{.i = -1 } },
{ MODKEY,				XK_period,					focusmon,		{.i = +1 } },
{ MODKEY|ShiftMask,		XK_comma,					tagmon,			{.i = -1 } },
{ MODKEY|ShiftMask,		XK_period,					tagmon,			{.i = +1 } },
TAGKEYS(				XK_1,						0)
TAGKEYS(				XK_2,						1)
TAGKEYS(				XK_3,						2)
TAGKEYS(				XK_4,						3)
{ MODKEY|ShiftMask,		XK_q,						quit,			{0} },
{ MODKEY|ShiftMask,		XK_r,						restart,		{0} },
};

// Button Definitions
static Button buttons[] = {
//	 Click                event mask      button          function        argument
{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
{ ClkTagBar,            0,              Button1,        view,           {0} },
{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
