/***************************************************************
 * Name:      Tetris_Revival___v0_1App.cpp
 * Purpose:   Code for Application Class
 * Author:    Lazarox, greyFox, sLoK ()
 * Created:   2008-05-17
 * Copyright: Lazarox, greyFox, sLoK ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Tetris_Revival___v0_1App.h"

//(*AppHeaders
#include "Tetris_Revival___v0_1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Tetris_Revival___v0_1App);

bool Tetris_Revival___v0_1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Tetris_Revival___v0_1Frame* Frame = new Tetris_Revival___v0_1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
