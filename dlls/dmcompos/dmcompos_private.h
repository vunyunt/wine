/* DirectMusicComposer Private Include
 *
 * Copyright (C) 2003-2004 Rok Mandeljc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_DMCOMPOS_PRIVATE_H
#define __WINE_DMCOMPOS_PRIVATE_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define COBJMACROS

#include "windef.h"
#include "winbase.h"
#include "winnt.h"
#include "wingdi.h"
#include "winuser.h"

#include "wine/debug.h"
#include "wine/list.h"
#include "winreg.h"
#include "objbase.h"

#include "dmusici.h"
#include "dmusicf.h"
#include "dmusics.h"

/*****************************************************************************
 * ClassFactory
 */
extern HRESULT WINAPI create_dmchordmap(REFIID riid, void **ret_iface) DECLSPEC_HIDDEN;
extern HRESULT WINAPI create_dmcomposer(REFIID riid, void **ret_iface) DECLSPEC_HIDDEN;
extern HRESULT WINAPI create_dmchordmaptrack(REFIID riid, void **ret_iface) DECLSPEC_HIDDEN;
extern HRESULT WINAPI create_dmsignposttrack(REFIID riid, void **ret_iface) DECLSPEC_HIDDEN;

/**********************************************************************
 * Dll lifetime tracking declaration for dmcompos.dll
 */
extern LONG DMCOMPOS_refCount DECLSPEC_HIDDEN;
static inline void DMCOMPOS_LockModule(void) { InterlockedIncrement( &DMCOMPOS_refCount ); }
static inline void DMCOMPOS_UnlockModule(void) { InterlockedDecrement( &DMCOMPOS_refCount ); }

/*****************************************************************************
 * Misc.
 */
/* for simpler reading */
typedef struct _DMUS_PRIVATE_CHUNK {
	FOURCC fccID; /* FOURCC ID of the chunk */
	DWORD dwSize; /* size of the chunk */
} DMUS_PRIVATE_CHUNK, *LPDMUS_PRIVATE_CHUNK;

#endif	/* __WINE_DMCOMPOS_PRIVATE_H */
