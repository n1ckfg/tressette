/*
    Tressette
    Copyright (C) 2005-2012  Igor Sarzi Sartori

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

//main.cpp
#include <StdAfx.h>
#include "win_type_global.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "EngineApp.h"

#include <string>

#ifdef WIN32
	#include <direct.h>
#endif


#include "ErrorMsg.h"

	

////////////////////////////////////////
//       main
/*! Entry point to start the application
// \param int argc : 
// \param char *argv[] : 
*/
int main(int argc, char *argv[])
{
 
    cEngineApp app;

#ifdef WIN32

    // app name and set the directory on installed application
    std::string strAppName;
    strAppName = argv[0];
    int iPos = strAppName.find_last_of('\\'); 
    int iLen = strAppName.length(); 
    std::string strDirname = strAppName.substr(0, iPos);
    app.SetApplicationDir(strDirname);
    _chdir(strDirname.c_str() );
#endif
    try
    {
        // init application
        app.Init();
        // uncomment this to start with the correct menu
        app.MainLoop();
        // to be removed: goto play game
        //app.PlayGame();
        //app.ShowOptions();


    }
    catch(Error::Init err)
    {
        // init error
#ifdef WIN32
        ::MessageBox(NULL, "Initialization Error, look on stderr.txt for more informations\nThe application is not correctly installed", "Application Error", MB_OK); 
#endif
        std::cerr << "Application initialization error: " << err.strErrMsg.c_str() << std::endl;   

        exit(EXIT_FAILURE);
    }
    catch(Error::Generic err)
    {
        char errBuffer[512];
        sprintf(errBuffer, "A critical error is occured and the program will be terminated.\nError detail: \n%s ", err.strErrMsg.c_str());
#ifdef WIN32
        ::MessageBox(NULL, errBuffer, "Application Error", MB_OK | MB_ICONERROR); 
#endif
        std::cerr << "Application  error: " << err.strErrMsg.c_str() << std::endl;   

        exit(EXIT_FAILURE);

    }
    
    return EXIT_SUCCESS;
}

