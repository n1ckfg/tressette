/*
    Tressette
    Copyright (C) 2005  Igor Sarzi Sartori

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Igor Sarzi Sartori
    www.invido.it
    6colpiunbucosolo@gmx.net
*/


// OptionDeckGfx.h: interface for the OptionDeckGfx class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OptionDeckGfx_H__A046DEBA_EC10_4D5D_A499_EF9A331516FD__INCLUDED_)
#define AFX_OptionDeckGfx_H__A046DEBA_EC10_4D5D_A499_EF9A331516FD__INCLUDED_

#include "win_type_global.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include "cTipoDiMazzo.h"
#include "cCardGfx.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class cButtonGfx;
class cComboGfx;

//! calss OptionDeckGfx
class OptionDeckGfx  
{
    typedef std::vector<STRING> VCT_STRING;
    enum
    {
        MYIDOK = 0,
        MYIDCANCEL = 1,
        MYIDCOMBODECK = 2
    };
public:
	OptionDeckGfx();
	virtual ~OptionDeckGfx();

    //! init control
    void Init(SDL_Rect* pRect, SDL_Surface*  pScreen, TTF_Font* pFontTxt, TTF_Font* pFontWinCtrl);
    //! shows the control
    void Show(SDL_Surface* pScene_background);
    //! button click callback
    void ButCmdClicked(int iButID);
    //! set caption text
    void SetCaption(STRING& strCaption){m_strHeaderText = strCaption;}
    //! combobox callback
    void ComboCmdClicked(int iButID);

private:
    void  loadCardPac(cTipoDiMazzo::eTypeMazzo eType, SDL_Surface** ppsurf_DestDeck, cCardGfx* pCard);


private:
    //! rectangle of the options control
    SDL_Rect        m_rctOptBox; 
    //! text on the messagebox
    SDL_Surface*    m_pSurf_Bar;
    //! surface screen
    SDL_Surface*    m_pScreen;
    //! text font
    TTF_Font*	    m_pFontText;
    //! button font
    TTF_Font*	    m_pFontCtrl;
    //! current text color
    SDL_Color       m_colCurrent;
    //! button 1
    cButtonGfx*     m_pBtOK;
    //! button 2
    cButtonGfx*     m_pBtCancel;
    //! terminated flag
    BOOL            m_bTerminated;
    //! result of click
    int             m_iResult;
    //! header text
    STRING          m_strHeaderText;
    //! combo deck selection
    cComboGfx*      m_pComboDeck;
    //! deck info
    cTipoDiMazzo*   m_pDeckType;
    //! store all surface for each deck
    SDL_Surface*    m_pDeckAll[cTipoDiMazzo::NUM_OF_MAZZI];
    //! a card for each deck
    cCardGfx        m_CardOnEachDeck[3][cTipoDiMazzo::NUM_OF_MAZZI];
};

#endif // !defined(AFX_OptionDeckGfx_H__A046DEBA_EC10_4D5D_A499_EF9A331516FD__INCLUDED_)
